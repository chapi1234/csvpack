#include "internal.h"
#include <stdio.h>
#include <string.h>

static void filter_push_hit(csvpack_table_t *tbl, const char *tag) {
  if (!tbl || !tag) return;
  if (tbl->filter_hit_count == tbl->filter_hit_cap) {
    size_t nc = tbl->filter_hit_cap ? tbl->filter_hit_cap * 2 : 4;
    char **nb = (char **)realloc(tbl->filter_hits, nc * sizeof(char *));
    if (!nb) return;
    tbl->filter_hits = nb;
    tbl->filter_hit_cap = nc;
  }
  char *copy = (char *)malloc(strlen(tag) + 1);
  if (!copy) return;
  strcpy(copy, tag);
  tbl->filter_hits[tbl->filter_hit_count++] = copy;
}

void csvpack_filter_teardown(csvpack_table_t *tbl) {
  if (!tbl) return;
  for (size_t i = 0; i < tbl->filter_hit_count; i++) {
    free(tbl->filter_hits[i]);
  }
  free(tbl->filter_hits);
  tbl->filter_hits = NULL;
  tbl->filter_hit_count = 0;
  tbl->filter_hit_cap = 0;
}

csvpack_status_t csvpack_filter_rows(csvpack_table_t *tbl, const char *column,
                                     const char *value, size_t *match_count) {
  if (!tbl || !column || !value || !match_count) return CSVPACK_ERR_SYNTAX;
  *match_count = 0;
  if (tbl->count < 2) return CSVPACK_OK;
  for (size_t ri = 1; ri < tbl->count; ri++) {
    const char *cell = csvpack_cell_by_column(tbl, ri, column, NULL);
    if (cell && strcmp(cell, value) == 0) {
      char tag[64];
      snprintf(tag, sizeof(tag), "row%zu:%s", ri, column);
      filter_push_hit(tbl, tag);
      (*match_count)++;
    }
  }
  return CSVPACK_OK;
}
