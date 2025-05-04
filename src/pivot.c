#define _GNU_SOURCE
#include "internal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void pivot_push_key(csvpack_table_t *tbl, const char *key) {
  if (!tbl || !key) return;
  if (tbl->pivot_key_count == tbl->pivot_key_cap) {
    size_t nc = tbl->pivot_key_cap ? tbl->pivot_key_cap * 2 : 4;
    char **nb = (char **)realloc(tbl->pivot_keys, nc * sizeof(char *));
    if (!nb) return;
    tbl->pivot_keys = nb;
    tbl->pivot_key_cap = nc;
  }
  char *copy = (char *)malloc(strlen(key) + 1);
  if (!copy) return;
  strcpy(copy, key);
  tbl->pivot_keys[tbl->pivot_key_count++] = copy;
}

void csvpack_pivot_teardown(csvpack_table_t *tbl) {
  if (!tbl) return;
  for (size_t i = 0; i < tbl->pivot_key_count; i++) {
    free(tbl->pivot_keys[i]);
  }
  free(tbl->pivot_keys);
  tbl->pivot_keys = NULL;
  tbl->pivot_key_count = 0;
  tbl->pivot_key_cap = 0;
}

csvpack_status_t csvpack_pivot_table(csvpack_table_t *tbl, const char *row_key,
                                     const char *col_key, const char *val_key) {
  if (!tbl || !row_key || !col_key || !val_key) return CSVPACK_ERR_SYNTAX;
  if (tbl->count < 2) return CSVPACK_OK;
  for (size_t ri = 1; ri < tbl->count; ri++) {
    const char *rk = csvpack_cell_by_column(tbl, ri, row_key, NULL);
    const char *ck = csvpack_cell_by_column(tbl, ri, col_key, NULL);
    const char *vk = csvpack_cell_by_column(tbl, ri, val_key, NULL);
    if (!rk || !ck || !vk) continue;
    char axis[256];
    snprintf(axis, sizeof(axis), "%s|%s=%s", rk, ck, vk);
    pivot_push_key(tbl, axis);
  }
  return CSVPACK_OK;
}
