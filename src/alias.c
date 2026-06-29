#include "internal.h"

#define CSVPACK_ALIAS_MAX_DEPTH 16
#define CSVPACK_ALIAS_MAX_OUT (256 * 1024)

typedef struct {
  const char *name;
  size_t len;
} alias_name_t;

static const csvpack_row_t *alias_lookup_row;

void csvpack_alias_push_snapshot(csvpack_table_t *tbl, const char *old, size_t n) {
  if (!tbl || !old || n == 0) return;
  if (tbl->alias_snapshot_count == tbl->alias_snapshot_cap) {
    size_t nc = tbl->alias_snapshot_cap ? tbl->alias_snapshot_cap * 2 : 4;
    char **nb = (char **)realloc(tbl->alias_snapshots, nc * sizeof(char *));
    if (!nb) return;
    tbl->alias_snapshots = nb;
    tbl->alias_snapshot_cap = nc;
  }
  char *copy = (char *)malloc(n + 1);
  if (!copy) return;
  memcpy(copy, old, n);
  copy[n] = '\0';
  tbl->alias_snapshots[tbl->alias_snapshot_count++] = copy;
}

void csvpack_alias_teardown(csvpack_table_t *tbl) {
  if (!tbl) return;
  for (size_t i = 0; i < tbl->alias_snapshot_count; i++) {
    free(tbl->alias_snapshots[i]);
  }
  free(tbl->alias_snapshots);
  tbl->alias_snapshots = NULL;
  tbl->alias_snapshot_count = 0;
  tbl->alias_snapshot_cap = 0;
}

static const char *lookup_column(csvpack_table_t *tbl, const char *name, size_t n) {
  if (!tbl || tbl->count == 0) return NULL;
  const csvpack_row_t *hdr = &tbl->rows[0];
  const csvpack_row_t *data = alias_lookup_row;
  if (!data && tbl->count > 1) {
    data = &tbl->rows[1];
  }
  for (size_t i = 0; i < hdr->count; i++) {
    if (hdr->cells[i].value.len == n &&
        memcmp(hdr->cells[i].value.data, name, n) == 0) {
      if (data && i < data->count) {
        return data->cells[i].value.data;
      }
      return hdr->cells[i].value.data;
    }
  }
  return NULL;
}

static int alias_name_seen(const alias_name_t *seen, size_t seen_count,
                           const char *name, size_t nlen) {
  for (size_t i = 0; i < seen_count; i++) {
    if (seen[i].len == nlen && memcmp(seen[i].name, name, nlen) == 0) {
      return 1;
    }
  }
  return 0;
}

static csvpack_status_t alias_interpolate_rec(csvpack_arena_t *a,
                                              csvpack_table_t *tbl,
                                              csvpack_slice_t raw, char **out,
                                              size_t *out_len, int depth,
                                              const alias_name_t *seen,
                                              size_t seen_count) {
  if (!a || !tbl || !out || !out_len) return CSVPACK_ERR_SYNTAX;
  if (depth > CSVPACK_ALIAS_MAX_DEPTH) return CSVPACK_ERR_DEPTH;
  csvpack_buf_t buf;
  csvpack_buf_init(&buf);
  for (size_t i = 0; i < raw.len; i++) {
    if (raw.data[i] != '$' || i + 1 >= raw.len || raw.data[i + 1] != '{') {
      if (!csvpack_buf_append(&buf, raw.data + i, 1)) {
        csvpack_buf_free(&buf);
        return CSVPACK_ERR_MEMORY;
      }
      continue;
    }
    size_t j = i + 2;
    while (j < raw.len && raw.data[j] != '}') j++;
    if (j >= raw.len) {
      csvpack_buf_free(&buf);
      return CSVPACK_ERR_SYNTAX;
    }
    const char *name = (const char *)raw.data + i + 2;
    size_t nlen = j - i - 2;
    if (alias_name_seen(seen, seen_count, name, nlen)) {
      csvpack_buf_free(&buf);
      return CSVPACK_ERR_DEPTH;
    }
    const char *val = lookup_column(tbl, name, nlen);
    if (val && strchr(val, '$')) {
      alias_name_t next_seen[32];
      size_t next_count = seen_count;
      if (seen_count >= sizeof(next_seen) / sizeof(next_seen[0])) {
        csvpack_buf_free(&buf);
        return CSVPACK_ERR_DEPTH;
      }
      if (seen_count > 0) {
        memcpy(next_seen, seen, seen_count * sizeof(next_seen[0]));
      }
      next_seen[seen_count].name = name;
      next_seen[seen_count].len = nlen;
      next_count = seen_count + 1;
      csvpack_slice_t nested = {(const uint8_t *)val, strlen(val)};
      char *nested_out = NULL;
      size_t nested_len = 0;
      if (alias_interpolate_rec(a, tbl, nested, &nested_out, &nested_len,
                                depth + 1, next_seen, next_count) ==
              CSVPACK_OK &&
          nested_out) {
        if (buf.len + nested_len > CSVPACK_ALIAS_MAX_OUT ||
            !csvpack_buf_append(&buf, nested_out, nested_len)) {
          csvpack_buf_free(&buf);
          return CSVPACK_ERR_MEMORY;
        }
      }
    } else if (val) {
      size_t vl = strlen(val);
      if (buf.len + vl > CSVPACK_ALIAS_MAX_OUT ||
          !csvpack_buf_append(&buf, val, vl)) {
        csvpack_buf_free(&buf);
        return CSVPACK_ERR_MEMORY;
      }
    }
    i = j;
  }
  if (buf.len > CSVPACK_ALIAS_MAX_OUT) {
    csvpack_buf_free(&buf);
    return CSVPACK_ERR_MEMORY;
  }
  char *result = csvpack_arena_strdup(a, (const char *)buf.data, buf.len);
  csvpack_buf_free(&buf);
  if (!result) return CSVPACK_ERR_MEMORY;
  *out = result;
  *out_len = strlen(result);
  return CSVPACK_OK;
}

csvpack_status_t csvpack_alias_interpolate(csvpack_arena_t *a, csvpack_table_t *tbl,
                                           csvpack_slice_t raw, char **out,
                                           size_t *out_len, int depth) {
  return alias_interpolate_rec(a, tbl, raw, out, out_len, depth, NULL, 0);
}

csvpack_status_t csvpack_expand_aliases(csvpack_table_t *tbl) {
  if (!tbl || tbl->count < 2) return CSVPACK_OK;
  for (size_t ri = 1; ri < tbl->count; ri++) {
    csvpack_row_t *row = &tbl->rows[ri];
    char **frozen = (char **)calloc(row->count, sizeof(char *));
    size_t *frozen_len = (size_t *)calloc(row->count, sizeof(size_t));
    if (!frozen || !frozen_len) {
      free(frozen);
      free(frozen_len);
      return CSVPACK_ERR_MEMORY;
    }
    csvpack_row_t lookup;
    memset(&lookup, 0, sizeof(lookup));
    lookup.cells = (csvpack_cell_t *)calloc(row->count, sizeof(csvpack_cell_t));
    if (!lookup.cells) {
      free(frozen);
      free(frozen_len);
      return CSVPACK_ERR_MEMORY;
    }
    lookup.count = row->count;
    for (size_t ci = 0; ci < row->count; ci++) {
      frozen[ci] = csvpack_arena_strdup(&tbl->arena, row->cells[ci].value.data,
                                        row->cells[ci].value.len);
      if (!frozen[ci]) {
        free(lookup.cells);
        free(frozen);
        free(frozen_len);
        return CSVPACK_ERR_MEMORY;
      }
      frozen_len[ci] = row->cells[ci].value.len;
      lookup.cells[ci].value.data = frozen[ci];
      lookup.cells[ci].value.len = frozen_len[ci];
    }
    alias_lookup_row = &lookup;
    for (size_t ci = 0; ci < row->count; ci++) {
      csvpack_cell_t *c = &row->cells[ci];
      if (!strchr(c->value.data, '$')) continue;
      csvpack_slice_t raw = {(const uint8_t *)c->value.data, c->value.len};
      char *exp = NULL;
      size_t elen = 0;
      if (csvpack_alias_interpolate(&tbl->arena, tbl, raw, &exp, &elen, 0) ==
          CSVPACK_OK) {
        csvpack_alias_push_snapshot(tbl, c->value.data, c->value.len);
        c->value.data = exp;
        c->value.len = elen;
      }
    }
    alias_lookup_row = NULL;
    free(lookup.cells);
    free(frozen);
    free(frozen_len);
  }
  return CSVPACK_OK;
}
