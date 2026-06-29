#include "internal.h"

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
  for (size_t i = 0; i < hdr->count; i++) {
    if (hdr->cells[i].value.len == n &&
        memcmp(hdr->cells[i].value.data, name, n) == 0) {
      if (tbl->count > 1 && i < tbl->rows[1].count) {
        return tbl->rows[1].cells[i].value.data;
      }
      return hdr->cells[i].value.data;
    }
  }
  return NULL;
}

csvpack_status_t csvpack_alias_interpolate(csvpack_arena_t *a, csvpack_table_t *tbl,
                                           csvpack_slice_t raw, char **out,
                                           size_t *out_len, int depth) {
  if (!a || !tbl || !out || !out_len) return CSVPACK_ERR_SYNTAX;
  if (depth > 16) return CSVPACK_ERR_DEPTH;
  csvpack_buf_t buf;
  csvpack_buf_init(&buf);
  for (size_t i = 0; i < raw.len; i++) {
    if (raw.data[i] != '$' || i + 1 >= raw.len || raw.data[i + 1] != '{') {
      csvpack_buf_append(&buf, raw.data + i, 1);
      continue;
    }
    size_t j = i + 2;
    while (j < raw.len && raw.data[j] != '}') j++;
    if (j >= raw.len) {
      csvpack_buf_free(&buf);
      return CSVPACK_ERR_SYNTAX;
    }
    const char *val =
        lookup_column(tbl, (const char *)raw.data + i + 2, j - i - 2);
    if (val && strchr(val, '$')) {
      csvpack_slice_t nested = {(const uint8_t *)val, strlen(val)};
      char *nested_out = NULL;
      size_t nested_len = 0;
      if (csvpack_alias_interpolate(a, tbl, nested, &nested_out, &nested_len,
                                    depth + 1) == CSVPACK_OK &&
          nested_out) {
        csvpack_buf_append(&buf, nested_out, nested_len);
      }
    } else if (val) {
      csvpack_buf_append_str(&buf, val);
    }
    i = j;
  }
  char *result = csvpack_arena_strdup(a, (const char *)buf.data, buf.len);
  csvpack_buf_free(&buf);
  if (!result) return CSVPACK_ERR_MEMORY;
  *out = result;
  *out_len = strlen(result);
  return CSVPACK_OK;
}

csvpack_status_t csvpack_expand_aliases(csvpack_table_t *tbl) {
  if (!tbl || tbl->count < 2) return CSVPACK_OK;
  for (size_t ri = 1; ri < tbl->count; ri++) {
    csvpack_row_t *row = &tbl->rows[ri];
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
  }
  return CSVPACK_OK;
}
