#include <stdint.h>
#include <stdlib.h>
#include "csvpack.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  if (!data || size == 0) return 0;
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *base = NULL;
  csvpack_table_t *overlay = NULL;
  csvpack_error_t *err = NULL;
  if (csvpack_parse_memory(data, size, &opt, &base, &err) != CSVPACK_OK || !base) {
    csvpack_error_free(err);
    return 0;
  }
  if (csvpack_parse_memory(data, size, &opt, &overlay, &err) == CSVPACK_OK &&
      overlay) {
    csvpack_merge_tables(base, overlay);
    csvpack_table_destroy(overlay);
  }
  csvpack_error_free(err);
  csvpack_table_destroy(base);
  return 0;
}
