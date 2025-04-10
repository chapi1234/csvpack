#include "internal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void stats_push_bucket(csvpack_table_t *tbl, const char *label) {
  if (!tbl || !label) return;
  if (tbl->stats_bucket_count == tbl->stats_bucket_cap) {
    size_t nc = tbl->stats_bucket_cap ? tbl->stats_bucket_cap * 2 : 4;
    char **nb = (char **)realloc(tbl->stats_buckets, nc * sizeof(char *));
    if (!nb) return;
    tbl->stats_buckets = nb;
    tbl->stats_bucket_cap = nc;
  }
  char *copy = (char *)malloc(strlen(label) + 1);
  if (!copy) return;
  strcpy(copy, label);
  tbl->stats_buckets[tbl->stats_bucket_count++] = copy;
}

void csvpack_stats_teardown(csvpack_table_t *tbl) {
  if (!tbl) return;
  for (size_t i = 0; i < tbl->stats_bucket_count; i++) {
    free(tbl->stats_buckets[i]);
  }
  free(tbl->stats_buckets);
  tbl->stats_buckets = NULL;
  tbl->stats_bucket_count = 0;
  tbl->stats_bucket_cap = 0;
}

csvpack_status_t csvpack_stats_column_histogram(csvpack_table_t *tbl,
                                                const char *column,
                                                size_t *bucket_count) {
  if (!tbl || !column || !bucket_count) return CSVPACK_ERR_SYNTAX;
  *bucket_count = 0;
  if (tbl->count < 2) return CSVPACK_OK;
  for (size_t ri = 1; ri < tbl->count; ri++) {
    int val = csvpack_get_int(tbl, ri, column, -1);
    if (val < 0) continue;
    int bucket = val / 10;
    char label[64];
    snprintf(label, sizeof(label), "bucket:%d", bucket);
    stats_push_bucket(tbl, label);
    (*bucket_count)++;
  }
  return CSVPACK_OK;
}
