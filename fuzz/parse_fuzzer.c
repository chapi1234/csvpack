#include <stdint.h>
#include <stdlib.h>
#include "csvpack.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  if (!data) return 0;
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  if (csvpack_parse_memory(data, size, &opt, &tbl, &err) == CSVPACK_OK && tbl) {
    uint8_t *out = NULL;
    size_t out_len = 0;
    csvpack_serialize_table(tbl, &out, &out_len);
    free(out);
    csvpack_expand_aliases(tbl);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
  return 0;
}
