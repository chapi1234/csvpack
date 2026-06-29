#include <stdint.h>
#include "csvpack_fuzz_common.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  csvpack_fuzz_process(data, size);
  return 0;
}
