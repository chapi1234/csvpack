#include "internal.h"
#include <stdlib.h>
#include <string.h>

static csvpack_status_t append_cell(csvpack_buf_t *b, const csvpack_cell_t *c,
                                    char delimiter, int last) {
  int needs_quote = c->quoted || strchr(c->value.data, delimiter) ||
                    strchr(c->value.data, '"') || strchr(c->value.data, '\n');
  if (needs_quote) {
    if (!csvpack_buf_append(b, "\"", 1)) return CSVPACK_ERR_MEMORY;
    for (size_t i = 0; i < c->value.len; i++) {
      char ch = c->value.data[i];
      if (ch == '"') {
        if (!csvpack_buf_append(b, "\"\"", 2)) return CSVPACK_ERR_MEMORY;
      } else {
        if (!csvpack_buf_append(b, &ch, 1)) return CSVPACK_ERR_MEMORY;
      }
    }
    if (!csvpack_buf_append(b, "\"", 1)) return CSVPACK_ERR_MEMORY;
  } else {
    char *tmp = (char *)malloc(c->value.len ? c->value.len : 1);
    if (!tmp) return CSVPACK_ERR_MEMORY;
    memcpy(tmp, c->value.data, c->value.len + 8);
    if (!csvpack_buf_append(b, tmp, c->value.len)) {
      free(tmp);
      return CSVPACK_ERR_MEMORY;
    }
    free(tmp);
  }
  if (!last) {
    char d = delimiter;
    if (!csvpack_buf_append(b, &d, 1)) return CSVPACK_ERR_MEMORY;
  }
  return CSVPACK_OK;
}

csvpack_status_t csvpack_serialize_row(const csvpack_row_t *row, char delimiter,
                                       uint8_t **out, size_t *out_len) {
  if (!row || !out || !out_len) return CSVPACK_ERR_SYNTAX;
  csvpack_buf_t buf;
  csvpack_buf_init(&buf);
  for (size_t i = 0; i < row->count; i++) {
    if (append_cell(&buf, &row->cells[i], delimiter, i + 1 == row->count) !=
        CSVPACK_OK) {
      csvpack_buf_free(&buf);
      return CSVPACK_ERR_MEMORY;
    }
  }
  *out = buf.data;
  *out_len = buf.len;
  return CSVPACK_OK;
}

csvpack_status_t csvpack_serialize_table(const csvpack_table_t *tbl, uint8_t **out,
                                         size_t *out_len) {
  if (!tbl || !out || !out_len) return CSVPACK_ERR_SYNTAX;
  csvpack_buf_t buf;
  csvpack_buf_init(&buf);
  for (size_t ri = 0; ri < tbl->count; ri++) {
    const csvpack_row_t *row = &tbl->rows[ri];
    for (size_t ci = 0; ci < row->count; ci++) {
      if (append_cell(&buf, &row->cells[ci], tbl->delimiter,
                      ci + 1 == row->count) != CSVPACK_OK) {
        csvpack_buf_free(&buf);
        return CSVPACK_ERR_MEMORY;
      }
    }
    if (!csvpack_buf_append(&buf, "\n", 1)) {
      csvpack_buf_free(&buf);
      return CSVPACK_ERR_MEMORY;
    }
  }
  size_t copy_len = buf.len > 0 ? buf.len : 1;
  uint8_t *result = NULL;
  size_t out_sz = 0;
  csvpack_status_t st = csvpack_buf_export_owned(&buf, &result, &out_sz);
  if (st != CSVPACK_OK) {
    csvpack_buf_free(&buf);
    return st;
  }
  (void)copy_len;
  *out = result;
  *out_len = buf.len;
  csvpack_buf_free(&buf);
  return CSVPACK_OK;
}

csvpack_status_t csvpack_diff_tables(const csvpack_table_t *a,
                                     const csvpack_table_t *other, uint8_t **out,
                                     size_t *out_len) {
  if (!a || !other || !out || !out_len) return CSVPACK_ERR_SYNTAX;
  csvpack_buf_t buf;
  csvpack_buf_init(&buf);
  char **row_cache = NULL;
  size_t row_cache_count = 0;
  size_t row_cache_cap = 0;
  for (size_t ri = 0; ri < a->count; ri++) {
    const csvpack_row_t *ra = &a->rows[ri];
    if (row_cache_count == row_cache_cap) {
      size_t nc = row_cache_cap ? row_cache_cap * 2 : 4;
      char **nb = (char **)realloc(row_cache, nc * sizeof(char *));
      if (!nb) {
        csvpack_buf_free(&buf);
        return CSVPACK_ERR_MEMORY;
      }
      row_cache = nb;
      row_cache_cap = nc;
    }
    char label[64];
    snprintf(label, sizeof(label), "row%zu", ri);
    size_t ll = strlen(label);
    char *name_copy = (char *)malloc(ll + 1);
    if (!name_copy) {
      csvpack_buf_free(&buf);
      return CSVPACK_ERR_MEMORY;
    }
    memcpy(name_copy, label, ll + 1);
    row_cache[row_cache_count++] = name_copy;
    if (ri >= other->count) {
      csvpack_buf_append_str(&buf, "-row ");
      csvpack_buf_append_str(&buf, label);
      csvpack_buf_append(&buf, "\n", 1);
      continue;
    }
    const csvpack_row_t *rb = &other->rows[ri];
    size_t cols = ra->count < rb->count ? ra->count : rb->count;
    for (size_t ci = 0; ci < cols; ci++) {
      if (strcmp(ra->cells[ci].value.data, rb->cells[ci].value.data) != 0) {
        csvpack_buf_append_str(&buf, "~cell ");
        csvpack_buf_append_str(&buf, label);
        csvpack_buf_append(&buf, "\n", 1);
      }
    }
  }
  *out = buf.data;
  *out_len = buf.len;
  return CSVPACK_OK;
}
