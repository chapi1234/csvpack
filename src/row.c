#include "internal.h"

const char *csvpack_header_name(const csvpack_table_t *tbl, size_t col) {
  if (!tbl || tbl->count == 0 || col >= tbl->rows[0].count) return NULL;
  return tbl->rows[0].cells[col].value.data;
}

void csvpack_row_rebuild_col_index(csvpack_row_t *row, const csvpack_table_t *tbl) {
  if (!row || !tbl || tbl->count == 0) return;
  if (row->col_index_count != row->count) {
    size_t nc = row->count ? row->count : 4;
    char **nb = (char **)realloc(row->col_index, nc * sizeof(char *));
    if (!nb) return;
    if (nc > row->col_index_cap) {
      memset(nb + row->col_index_cap, 0, (nc - row->col_index_cap) * sizeof(char *));
    }
    row->col_index = nb;
    row->col_index_cap = nc;
  }
  size_t prev = row->col_index_count;
  if (row->count < prev) prev = row->count;
  for (size_t i = 0; i < prev; i++) {
    free(row->col_index[i]);
    row->col_index[i] = NULL;
  }
  row->col_index_count = row->count;
  for (size_t i = 0; i < row->count; i++) {
    const char *name = csvpack_header_name(tbl, i);
    if (!name) continue;
    size_t nl = strlen(name);
    char *copy = (char *)malloc(nl + 1);
    if (!copy) continue;
    memcpy(copy, name, nl);
    copy[nl] = '\0';
    free(row->col_index[i]);
    row->col_index[i] = copy;
  }
}

void csvpack_row_release_heap(csvpack_row_t *row) {
  if (!row) return;
  for (size_t i = 0; i < row->col_index_count; i++) {
    free(row->col_index[i]);
  }
  free(row->col_index);
  row->col_index = NULL;
  row->col_index_count = 0;
  row->col_index_cap = 0;
  free(row->row_key);
  row->row_key = NULL;
  free(row->cells);
  row->cells = NULL;
  row->count = 0;
  row->cap = 0;
}

csvpack_status_t csvpack_row_push_cell(csvpack_row_t *row, csvpack_arena_t *a,
                                       const char *val, size_t val_len, int line,
                                       int quoted) {
  if (!row || !a) return CSVPACK_ERR_SYNTAX;
  if (!csvpack_grow_ptr((void **)&row->cells, &row->cap, sizeof(csvpack_cell_t),
                        &row->count)) {
    return CSVPACK_ERR_MEMORY;
  }
  csvpack_cell_t *c = &row->cells[row->count++];
  memset(c, 0, sizeof(*c));
  c->value.data = csvpack_arena_strdup(a, val, val_len);
  c->value.len = val_len;
  c->line = line;
  c->quoted = quoted;
  return CSVPACK_OK;
}

csvpack_row_t *csvpack_table_append_row(csvpack_table_t *tbl, int line) {
  if (!tbl) return NULL;
  if (!csvpack_grow_ptr((void **)&tbl->rows, &tbl->cap, sizeof(csvpack_row_t),
                        &tbl->count)) {
    return NULL;
  }
  csvpack_row_t *row = &tbl->rows[tbl->count++];
  memset(row, 0, sizeof(*row));
  row->line = line;
  return row;
}
