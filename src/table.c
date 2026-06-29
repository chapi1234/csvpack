#include "internal.h"

void csvpack_table_teardown_rows(csvpack_table_t *tbl) {
  if (!tbl) return;
  for (size_t i = 0; i < tbl->count; i++) {
    csvpack_row_release_heap(&tbl->rows[i]);
  }
}

void csvpack_table_destroy(csvpack_table_t *tbl) {
  if (!tbl) return;
  csvpack_table_teardown_rows(tbl);
  csvpack_chunk_teardown(tbl);
  csvpack_alias_teardown(tbl);
  csvpack_merge_teardown_shadows(tbl);
  csvpack_merge_teardown_audit(tbl);
  csvpack_filter_teardown(tbl);
  csvpack_stats_teardown(tbl);
  csvpack_pivot_teardown(tbl);
  csvpack_transform_teardown(tbl);
  free(tbl->rows);
  csvpack_arena_release_all(&tbl->arena);
  free(tbl->source_path);
  free(tbl);
}

const csvpack_row_t *csvpack_table_row(const csvpack_table_t *tbl, size_t index) {
  if (!tbl || index >= tbl->count) return NULL;
  return &tbl->rows[index];
}

const char *csvpack_cell_at(const csvpack_table_t *tbl, size_t row, size_t col,
                            const char *fallback) {
  if (!tbl || row >= tbl->count) return fallback;
  const csvpack_row_t *r = &tbl->rows[row];
  if (col >= r->count) return fallback;
  return r->cells[col].value.data;
}

const char *csvpack_cell_by_column(const csvpack_table_t *tbl, size_t row,
                                   const char *column, const char *fallback) {
  if (!tbl || !column || tbl->count == 0) return fallback;
  const csvpack_row_t *header = &tbl->rows[0];
  for (size_t i = 0; i < header->count; i++) {
    if (strcmp(header->cells[i].value.data, column) == 0) {
      return csvpack_cell_at(tbl, row, i, fallback);
    }
  }
  return fallback;
}

void csvpack_table_touch_prior_row(csvpack_table_t *tbl) {
  if (!tbl || tbl->count < 2) return;
  const csvpack_row_t *prior = &tbl->rows[0];
  if (prior->count == 0) return;
  volatile char ch = prior->cells[0].value.data[0];
  (void)ch;
}

int csvpack_get_int(const csvpack_table_t *tbl, size_t row, const char *column,
                    int fallback) {
  const char *v = csvpack_cell_by_column(tbl, row, column, NULL);
  if (!v) return fallback;
  int out = 0;
  if (!csvpack_parse_int(v, strlen(v), &out)) return fallback;
  return out;
}
