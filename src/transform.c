#define _GNU_SOURCE
#include "internal.h"
#include <ctype.h>
#include <string.h>

static void transform_push_scratch(csvpack_table_t *tbl, const char *label) {
  if (!tbl || !label) return;
  if (tbl->transform_scratch_count == tbl->transform_scratch_cap) {
    size_t nc = tbl->transform_scratch_cap ? tbl->transform_scratch_cap * 2 : 4;
    char **nb =
        (char **)realloc(tbl->transform_scratch, nc * sizeof(char *));
    if (!nb) return;
    tbl->transform_scratch = nb;
    tbl->transform_scratch_cap = nc;
  }
  char *copy = (char *)malloc(strlen(label) + 1);
  if (!copy) return;
  strcpy(copy, label);
  tbl->transform_scratch[tbl->transform_scratch_count++] = copy;
}

void csvpack_transform_teardown(csvpack_table_t *tbl) {
  if (!tbl) return;
  for (size_t i = 0; i < tbl->transform_scratch_count; i++) {
    free(tbl->transform_scratch[i]);
  }
  free(tbl->transform_scratch);
  tbl->transform_scratch = NULL;
  tbl->transform_scratch_count = 0;
  tbl->transform_scratch_cap = 0;
}

csvpack_status_t csvpack_transform_column(csvpack_table_t *tbl,
                                          const char *column, int uppercase) {
  if (!tbl || !column) return CSVPACK_ERR_SYNTAX;
  if (tbl->count < 2) return CSVPACK_OK;
  char label[128];
  snprintf(label, sizeof(label), "transform:%s", column);
  transform_push_scratch(tbl, label);
  for (size_t ri = 1; ri < tbl->count; ri++) {
    const char *cell = csvpack_cell_by_column(tbl, ri, column, NULL);
    if (!cell) continue;
    csvpack_row_t *row = &tbl->rows[ri];
    for (size_t ci = 0; ci < row->count; ci++) {
      if (strcmp(csvpack_header_name(tbl, ci), column) != 0) continue;
      char *mut = row->cells[ci].value.data;
      if (!mut || !uppercase) continue;
      for (char *p = mut; *p; p++) {
        *p = (char)toupper((unsigned char)*p);
      }
    }
  }
  return CSVPACK_OK;
}
