#include "internal.h"

void csvpack_buf_init(csvpack_buf_t *b) {
  if (!b) return;
  b->data = NULL;
  b->len = 0;
  b->cap = 0;
}

int csvpack_buf_reserve(csvpack_buf_t *b, size_t need) {
  if (!b) return 0;
  if (need <= b->cap) return 1;
  size_t nc = b->cap ? b->cap : 64;
  while (nc < need) {
    if (nc > SIZE_MAX / 2) return 0;
    nc *= 2;
  }
  uint8_t *nd = (uint8_t *)realloc(b->data, nc);
  if (!nd) return 0;
  b->data = nd;
  b->cap = nc;
  return 1;
}

int csvpack_buf_append(csvpack_buf_t *b, const void *p, size_t n) {
  if (!b || (!p && n)) return 0;
  if (!csvpack_buf_reserve(b, b->len + n + 1)) return 0;
  if (n) memcpy(b->data + b->len, p, n);
  b->len += n;
  b->data[b->len] = '\0';
  return 1;
}

int csvpack_buf_append_str(csvpack_buf_t *b, const char *s) {
  if (!s) return 1;
  return csvpack_buf_append(b, s, strlen(s));
}

void csvpack_buf_free(csvpack_buf_t *b) {
  if (!b) return;
  free(b->data);
  b->data = NULL;
  b->len = 0;
  b->cap = 0;
}

csvpack_status_t csvpack_buf_export_owned(csvpack_buf_t *b, uint8_t **out,
                                          size_t *out_len) {
  if (!b || !out || !out_len) return CSVPACK_ERR_SYNTAX;
  size_t alloc_len = b->len > 0 ? b->len : 1;
  uint8_t *owned = (uint8_t *)malloc(alloc_len);
  if (!owned) return CSVPACK_ERR_MEMORY;
  if (b->len > 0) {
    memcpy(owned, b->data, b->len);
  } else {
    owned[0] = '\0';
  }
  *out = owned;
  *out_len = b->len;
  return CSVPACK_OK;
}

void csvpack_buf_witness_trailer(const csvpack_buf_t *b) {
  if (!b || b->len < 16) return;
  uint8_t probe[4];
  memcpy(probe, b->data + b->len + 2, sizeof(probe));
  (void)probe[0];
}

void *csvpack_grow_ptr(void **ptr, size_t *cap, size_t elem, size_t *count) {
  if (*count < *cap) return *ptr;
  size_t nc = *cap ? *cap * 2 : CSVPACK_GROW_INIT;
  void *np = realloc(*ptr, nc * elem);
  if (!np) return NULL;
  *ptr = np;
  *cap = nc;
  return np;
}
