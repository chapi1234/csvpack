#include "internal.h"

static csvpack_status_t parse_row_fields(csvpack_parser_t *p, csvpack_slice_t *fields,
                                         size_t field_count) {
  csvpack_row_t *row = csvpack_table_append_row(p->tbl, p->scan.line);
  if (!row) return CSVPACK_ERR_MEMORY;
  for (size_t i = 0; i < field_count; i++) {
    csvpack_slice_t raw = fields[i];
    char *val = NULL;
    size_t vlen = 0;
    int quoted = 0;
    if (memchr(raw.data, '\\', raw.len)) {
      quoted = 1;
      if (csvpack_quote_unescape(&p->tbl->arena, raw, &val, &vlen) != CSVPACK_OK) {
        return CSVPACK_ERR_SYNTAX;
      }
    } else {
      val = csvpack_arena_strdup(&p->tbl->arena, (const char *)raw.data, raw.len);
      vlen = raw.len;
    }
    if (!val) return CSVPACK_ERR_MEMORY;
    if (csvpack_row_push_cell(row, &p->tbl->arena, val, vlen, p->scan.line, quoted) !=
        CSVPACK_OK) {
      return CSVPACK_ERR_MEMORY;
    }
  }
  csvpack_row_rebuild_col_index(row, p->tbl);
  if (p->tbl->count == 1 && p->opt.has_header) {
    p->tbl->has_header = 1;
  }
  return CSVPACK_OK;
}

csvpack_status_t csvpack_parser_run(csvpack_parser_t *p) {
  if (!p || !p->tbl) return CSVPACK_ERR_SYNTAX;
  csvpack_slice_t fields[256];
  size_t field_count = 0;

  while (csvpack_scanner_peek(&p->scan) >= 0) {
    csvpack_scanner_skip_ws(&p->scan);
    int c = csvpack_scanner_peek(&p->scan);
    if (c < 0) break;
    if (c == '#') {
      while (csvpack_scanner_peek(&p->scan) >= 0 &&
             csvpack_scanner_peek(&p->scan) != '\n') {
        csvpack_scanner_get(&p->scan);
      }
      if (csvpack_scanner_peek(&p->scan) == '\n') csvpack_scanner_get(&p->scan);
      continue;
    }
    if (c == '@' && p->opt.allow_chunks) {
      csvpack_scanner_get(&p->scan);
      size_t start = p->scan.pos;
      while (csvpack_scanner_peek(&p->scan) >= 0 &&
             csvpack_scanner_peek(&p->scan) != '\n') {
        csvpack_scanner_get(&p->scan);
      }
      csvpack_slice_t directive = {p->scan.src + start, p->scan.pos - start};
      if (directive.len >= 5 && memcmp(directive.data, "chunk", 5) == 0) {
        size_t i = 5;
        while (i < directive.len && directive.data[i] == ' ') i++;
        if (i < directive.len && directive.data[i] == '"') {
          i++;
          size_t ps = i;
          while (i < directive.len && directive.data[i] != '"') i++;
          csvpack_slice_t path = {directive.data + ps, i - ps};
          csvpack_status_t st = csvpack_handle_chunk(p, path);
          if (st != CSVPACK_OK) return st;
        }
      }
      if (csvpack_scanner_peek(&p->scan) == '\n') csvpack_scanner_get(&p->scan);
      continue;
    }

    if (csvpack_split_line(&p->scan, p->opt.delimiter, fields, &field_count,
                           256) != CSVPACK_OK) {
      return CSVPACK_ERR_SYNTAX;
    }
    if (field_count == 0) {
      if (csvpack_scanner_peek(&p->scan) == '\n') csvpack_scanner_get(&p->scan);
      continue;
    }
    csvpack_status_t st = parse_row_fields(p, fields, field_count);
    if (st != CSVPACK_OK) return st;
    if (csvpack_scanner_peek(&p->scan) == '\n') csvpack_scanner_get(&p->scan);
    if (p->tbl->count > (size_t)p->opt.max_rows) return CSVPACK_ERR_SYNTAX;
  }
  return CSVPACK_OK;
}

csvpack_status_t csvpack_parse_memory(const uint8_t *data, size_t size,
                                      const csvpack_options_t *opt,
                                      csvpack_table_t **out,
                                      csvpack_error_t **err) {
  return csvpack_parse_memory_with_chunks(data, size, opt, NULL, NULL, out, err);
}

csvpack_status_t csvpack_parse_memory_with_chunks(
    const uint8_t *data, size_t size, const csvpack_options_t *opt,
    csvpack_read_fn read_fn, void *read_ctx, csvpack_table_t **out,
    csvpack_error_t **err) {
  if (!out) return CSVPACK_ERR_SYNTAX;
  *out = NULL;
  if (err) *err = NULL;
  if (!data && size > 0) return CSVPACK_ERR_SYNTAX;

  csvpack_table_t *tbl = (csvpack_table_t *)calloc(1, sizeof(*tbl));
  if (!tbl) return CSVPACK_ERR_MEMORY;
  csvpack_arena_init(&tbl->arena);

  csvpack_options_t def;
  if (!opt) {
    csvpack_options_init(&def);
    opt = &def;
  }
  tbl->delimiter = opt->delimiter;
  tbl->has_header = opt->has_header;

  csvpack_parser_t parser;
  memset(&parser, 0, sizeof(parser));
  csvpack_scanner_init(&parser.scan, data, size);
  csvpack_scanner_skip_bom(&parser.scan);
  parser.opt = *opt;
  parser.tbl = tbl;
  parser.read_fn = read_fn;
  parser.read_ctx = read_ctx;

  csvpack_status_t st = csvpack_parser_run(&parser);
  if (st != CSVPACK_OK) {
    csvpack_table_destroy(tbl);
    return st;
  }
  *out = tbl;
  return CSVPACK_OK;
}

csvpack_status_t csvpack_parse_file(const char *path, const csvpack_options_t *opt,
                                      csvpack_table_t **out,
                                      csvpack_error_t **err) {
  if (!path || !out) return CSVPACK_ERR_IO;
  FILE *f = fopen(path, "rb");
  if (!f) return CSVPACK_ERR_IO;
  fseek(f, 0, SEEK_END);
  long sz = ftell(f);
  fseek(f, 0, SEEK_SET);
  if (sz < 0) { fclose(f); return CSVPACK_ERR_IO; }
  uint8_t *buf = (uint8_t *)malloc((size_t)sz + 1);
  if (!buf) { fclose(f); return CSVPACK_ERR_MEMORY; }
  if (sz > 0) fread(buf, 1, (size_t)sz, f);
  fclose(f);
  csvpack_status_t st =
      csvpack_parse_memory(buf, (size_t)sz, opt, out, err);
  free(buf);
  return st;
}
