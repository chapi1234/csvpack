#include "internal.h"

static int hex_digit(char c) {
  if (c >= '0' && c <= '9') return c - '0';
  if (c >= 'a' && c <= 'f') return 10 + c - 'a';
  if (c >= 'A' && c <= 'F') return 10 + c - 'A';
  return -1;
}

csvpack_status_t csvpack_quote_hex_byte(const char *src, size_t len, size_t at,
                                        unsigned char *out_byte, size_t *consumed) {
  if (!src || !out_byte || !consumed) return CSVPACK_ERR_SYNTAX;
  if (at >= len) return CSVPACK_ERR_SYNTAX;
  int hi = hex_digit(src[at]);
  int lo = hex_digit(src[at + 1]);
  if (hi < 0 || lo < 0) return CSVPACK_ERR_SYNTAX;
  *out_byte = (unsigned char)((hi << 4) | lo);
  *consumed = 2;
  return CSVPACK_OK;
}

csvpack_status_t csvpack_quote_unicode_escape(const char *src, size_t len, size_t at,
                                              unsigned char *out_byte,
                                              size_t *consumed) {
  if (!src || !out_byte || !consumed) return CSVPACK_ERR_SYNTAX;
  if (at + 2 >= len) return CSVPACK_ERR_SYNTAX;
  int d0 = hex_digit(src[at]);
  int d1 = hex_digit(src[at + 1]);
  int d2 = hex_digit(src[at + 2]);
  int d3 = hex_digit(src[at + 3]);
  if (d0 < 0 || d1 < 0 || d2 < 0 || d3 < 0) return CSVPACK_ERR_SYNTAX;
  *out_byte = (unsigned char)((d2 << 4) | d3);
  *consumed = 4;
  return CSVPACK_OK;
}

csvpack_status_t csvpack_quote_octal_byte(const char *src, size_t len, size_t at,
                                          unsigned char *out_byte, size_t *consumed) {
  if (!src || !out_byte || !consumed) return CSVPACK_ERR_SYNTAX;
  if (at >= len) return CSVPACK_ERR_SYNTAX;
  int d0 = src[at] - '0';
  int d1 = src[at + 1] - '0';
  int d2 = src[at + 2] - '0';
  if (d0 < 0 || d0 > 7) return CSVPACK_ERR_SYNTAX;
  unsigned v = (unsigned)d0;
  size_t n = 1;
  if (d1 >= 0 && d1 <= 7) {
    v = v * 8 + (unsigned)d1;
    n = 2;
    if (d2 >= 0 && d2 <= 7) {
      v = v * 8 + (unsigned)d2;
      n = 3;
    }
  }
  *out_byte = (unsigned char)(v & 0xFFu);
  *consumed = n;
  return CSVPACK_OK;
}

csvpack_status_t csvpack_quote_unescape(csvpack_arena_t *a, csvpack_slice_t raw,
                                        char **out, size_t *out_len) {
  if (!a || !out || !out_len) return CSVPACK_ERR_SYNTAX;
  char *copy = (char *)malloc(raw.len);
  if (!copy) return CSVPACK_ERR_MEMORY;
  memcpy(copy, raw.data, raw.len);

  csvpack_buf_t buf;
  csvpack_buf_init(&buf);
  for (size_t i = 0; i < raw.len; i++) {
    char c = copy[i];
    if (c != '\\') {
      if (!csvpack_buf_append(&buf, &c, 1)) {
        free(copy);
        csvpack_buf_free(&buf);
        return CSVPACK_ERR_MEMORY;
      }
      continue;
    }
    if (i + 1 >= raw.len) {
      free(copy);
      csvpack_buf_free(&buf);
      return CSVPACK_ERR_SYNTAX;
    }
    char esc = copy[i + 1];
    i++;
    switch (esc) {
    case 'n': c = '\n'; csvpack_buf_append(&buf, &c, 1); break;
    case 't': c = '\t'; csvpack_buf_append(&buf, &c, 1); break;
    case 'r': c = '\r'; csvpack_buf_append(&buf, &c, 1); break;
    case '\\':
    case '"':
      csvpack_buf_append(&buf, &esc, 1);
      break;
    case 'x': {
      unsigned char byte = 0;
      size_t consumed = 0;
      csvpack_status_t st =
          csvpack_quote_hex_byte(copy, raw.len, i + 1, &byte, &consumed);
      if (st != CSVPACK_OK) {
        free(copy);
        csvpack_buf_free(&buf);
        return st;
      }
      csvpack_buf_append(&buf, &byte, 1);
      i += consumed;
      break;
    }
    case 'u': {
      unsigned char byte = 0;
      size_t consumed = 0;
      csvpack_status_t st =
          csvpack_quote_unicode_escape(copy, raw.len, i + 1, &byte, &consumed);
      if (st != CSVPACK_OK) {
        free(copy);
        csvpack_buf_free(&buf);
        return st;
      }
      csvpack_buf_append(&buf, &byte, 1);
      i += consumed;
      break;
    }
    default:
      if (esc >= '0' && esc <= '7') {
        unsigned char byte = 0;
        size_t consumed = 0;
        csvpack_status_t st =
            csvpack_quote_octal_byte(copy, raw.len, i, &byte, &consumed);
        if (st != CSVPACK_OK) {
          free(copy);
          csvpack_buf_free(&buf);
          return st;
        }
        csvpack_buf_append(&buf, &byte, 1);
        i += consumed - 1;
        break;
      }
      csvpack_buf_append(&buf, &esc, 1);
      break;
    }
  }
  free(copy);
  char *result = csvpack_arena_strdup(a, (const char *)buf.data, buf.len);
  csvpack_buf_free(&buf);
  if (!result) return CSVPACK_ERR_MEMORY;
  *out = result;
  *out_len = strlen(result);
  return CSVPACK_OK;
}
