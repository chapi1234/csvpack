#include "internal.h"
#include <stdlib.h>
#include <string.h>

static int utf8_lead_len(unsigned char b) {
  if ((b & 0x80) == 0) return 1;
  if ((b & 0xE0) == 0xC0) return 2;
  if ((b & 0xF0) == 0xE0) return 3;
  if ((b & 0xF8) == 0xF0) return 4;
  return 1;
}

csvpack_status_t csvpack_encode_cell_utf8(csvpack_slice_t raw, char **out,
                                          size_t *out_len) {
  if (!out || !out_len) return CSVPACK_ERR_SYNTAX;
  *out = NULL;
  *out_len = 0;
  if (!raw.data || raw.len == 0) {
    char *empty = (char *)malloc(1);
    if (!empty) return CSVPACK_ERR_MEMORY;
    empty[0] = '\0';
    *out = empty;
    return CSVPACK_OK;
  }
  char *buf = (char *)malloc(raw.len + 1);
  if (!buf) return CSVPACK_ERR_MEMORY;
  size_t o = 0;
  for (size_t i = 0; i < raw.len;) {
    unsigned char lead = raw.data[i];
    int need = utf8_lead_len(lead);
    for (int k = 1; k < need; k++) {
      unsigned char cont = raw.data[i + (size_t)k];
      if ((cont & 0xC0) != 0x80) {
        free(buf);
        return CSVPACK_ERR_SYNTAX;
      }
    }
    for (int k = 0; k < need && i < raw.len; k++, i++) {
      buf[o++] = (char)raw.data[i];
    }
  }
  buf[o] = '\0';
  *out = buf;
  *out_len = o;
  return CSVPACK_OK;
}
