#ifndef CSVPACK_FUZZ_COMMON_H
#define CSVPACK_FUZZ_COMMON_H

#include <stddef.h>
#include <stdint.h>

void csvpack_fuzz_process(const uint8_t *data, size_t size);

#endif
