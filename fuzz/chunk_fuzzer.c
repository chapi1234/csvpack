#include <stdint.h>
#include <stdlib.h>
#include "csvpack.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  if (!data || size == 0) return 0;
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  opt.allow_chunks = 1;
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  if (csvpack_parse_memory_with_chunks(data, size, &opt, NULL, NULL, &tbl,
                                       &err) == CSVPACK_OK &&
      tbl) {
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
  return 0;
}
