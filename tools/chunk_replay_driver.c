#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csvpack.h"

static size_t fuzz_read(void *ctx, const char *path, uint8_t *buf, size_t cap) {
  (void)ctx;
  (void)path;
  static const char child[] = "id,name\n2,beta\n";
  size_t n = sizeof(child) - 1u;
  if (n > cap) {
    n = cap;
  }
  if (n > 0) {
    memcpy(buf, child, n);
  }
  return n;
}

static const char *find_marker(const uint8_t *data, size_t size, const char *mark) {
  size_t ml = strlen(mark);
  if (size < ml) {
    return NULL;
  }
  for (size_t i = 0; i + ml <= size; i++) {
    if (memcmp(data + i, mark, ml) == 0) {
      return (const char *)(data + i);
    }
  }
  return NULL;
}

static void run_input(const uint8_t *data, size_t size) {
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  opt.allow_chunks = 1;

  const char *split = find_marker(data, size, "---DIFF---");
  if (split) {
    size_t left_len = (size_t)(split - (const char *)data);
    const uint8_t *right = (const uint8_t *)(split + strlen("---DIFF---"));
    size_t right_len = size - left_len - strlen("---DIFF---");
    csvpack_table_t *left = NULL;
    csvpack_table_t *right_tbl = NULL;
    csvpack_error_t *err = NULL;
    if (csvpack_parse_memory_with_chunks(data, left_len, &opt, fuzz_read, NULL,
                                         &left, &err) == CSVPACK_OK &&
        left) {
      if (csvpack_parse_memory_with_chunks(right, right_len, &opt, fuzz_read, NULL,
                                           &right_tbl, &err) == CSVPACK_OK &&
          right_tbl) {
        uint8_t *diff = NULL;
        size_t diff_len = 0;
        csvpack_diff_tables(left, right_tbl, &diff, &diff_len);
        free(diff);
        csvpack_table_destroy(right_tbl);
      }
      csvpack_table_destroy(left);
    }
    csvpack_error_free(err);
    return;
  }

  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  if (csvpack_parse_memory_with_chunks(data, size, &opt, fuzz_read, NULL, &tbl,
                                       &err) == CSVPACK_OK &&
      tbl) {
    if (tbl->count > 5) {
      uint8_t *out = NULL;
      size_t out_len = 0;
      csvpack_serialize_table(tbl, &out, &out_len);
      free(out);
    }
    if (tbl->count >= 2) {
      const char *probe = csvpack_cell_by_column(tbl, 1, "value", NULL);
      if (probe && strlen(probe) > 80) {
        csvpack_query_t q;
        memset(&q, 0, sizeof(q));
        q.table = tbl;
        q.row = 1;
        strncpy(q.column, "value", sizeof(q.column) - 1);
        char qbuf[128];
        csvpack_query_get(&q, qbuf, sizeof(qbuf));
      }
    }
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

int main(int argc, char **argv) {
  const char *path = argc > 1 ? argv[1] : "poc/verified/quoted_continuation_row2.csv";
  FILE *f = fopen(path, "rb");
  if (!f) {
    return 1;
  }
  fseek(f, 0, SEEK_END);
  long sz = ftell(f);
  fseek(f, 0, SEEK_SET);
  if (sz < 0) {
    fclose(f);
    return 1;
  }
  uint8_t *buf = (uint8_t *)malloc((size_t)sz);
  if (!buf) {
    fclose(f);
    return 1;
  }
  if (sz > 0) {
    fread(buf, 1, (size_t)sz, f);
  }
  fclose(f);
  run_input(buf, (size_t)sz);
  free(buf);
  return 0;
}
