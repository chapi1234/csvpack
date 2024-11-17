#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csvpack.h"

int main(int argc, char **argv) {
  const char *path = argc > 1 ? argv[1] : "-";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  csvpack_status_t st;
  if (strcmp(path, "-") == 0) {
    static const char demo[] = "name,score\nalice,10\n";
    st = csvpack_parse_memory((const uint8_t *)demo, strlen(demo), &opt, &tbl, &err);
  } else {
    st = csvpack_parse_file(path, &opt, &tbl, &err);
  }
  if (st != CSVPACK_OK) {
    fprintf(stderr, "parse error: %s\n", csvpack_status_string(st));
    csvpack_error_free(err);
    return 1;
  }
  printf("rows: %zu\n", tbl->count);
  for (size_t r = 0; r < tbl->count; r++) {
    const csvpack_row_t *row = csvpack_table_row(tbl, r);
    for (size_t c = 0; c < row->count; c++) {
      if (c) putchar(',');
      fputs(row->cells[c].value.data, stdout);
    }
    putchar('\n');
  }
  csvpack_table_destroy(tbl);
  csvpack_error_free(err);
  return 0;
}
