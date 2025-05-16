#include <stdint.h>
#include <stdlib.h>
#include "csvpack.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  if (!data || size == 0) {
    return 0;
  }
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  opt.has_header = 1;
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  if (csvpack_parse_memory(data, size, &opt, &tbl, &err) != CSVPACK_OK || !tbl) {
    csvpack_error_free(err);
    return 0;
  }
  size_t matches = 0;
  if (tbl->count > 1) {
    const char *col = csvpack_cell_at(tbl, 0, 0, NULL);
    const char *val = csvpack_cell_at(tbl, 1, 0, NULL);
    if (col && val) {
      csvpack_filter_rows(tbl, col, val, &matches);
    }
  }
  (void)matches;
  csvpack_table_destroy(tbl);
  csvpack_error_free(err);
  return 0;
}
