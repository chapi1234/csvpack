#include "internal.h"

void csvpack_scanner_init(csvpack_scanner_t *s, const uint8_t *data, size_t len) {
  s->src = data;
  s->len = len;
  s->pos = 0;
  s->line = 1;
  s->column = 1;
}

int csvpack_scanner_peek(const csvpack_scanner_t *s) {
  if (s->pos >= s->len) return -1;
  return (int)s->src[s->pos];
}

int csvpack_scanner_get(csvpack_scanner_t *s) {
  if (s->pos >= s->len) return -1;
  int c = (int)s->src[s->pos++];
  if (c == '\n') {
    s->line++;
    s->column = 1;
  } else {
    s->column++;
  }
  return c;
}

void csvpack_scanner_skip_ws(csvpack_scanner_t *s) {
  for (;;) {
    int c = csvpack_scanner_peek(s);
    if (c == ' ' || c == '\t' || c == '\r') {
      csvpack_scanner_get(s);
      continue;
    }
    break;
  }
}

void csvpack_scanner_skip_bom(csvpack_scanner_t *s) {
  if (!s || s->len < 3) return;
  if (s->src[0] == 0xEF && s->src[1] == 0xBB && s->src[2] == 0xBF) {
    s->pos = 3;
  }
}
