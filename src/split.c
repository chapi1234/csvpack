#include "internal.h"
#include <string.h>

static void store_field(csvpack_slice_t *fields, size_t *count, size_t max_fields,
                        const uint8_t *start, size_t n) {
  if (*count >= max_fields) return;
  fields[*count].data = start;
  fields[*count].len = n;
  (*count)++;
}

csvpack_status_t csvpack_split_line(csvpack_scanner_t *s, char delimiter,
                                    csvpack_slice_t *fields, size_t *count,
                                    size_t max_fields) {
  if (!s || !fields || !count) return CSVPACK_ERR_SYNTAX;
  *count = 0;
  csvpack_scanner_skip_ws(s);
  if (csvpack_scanner_peek(s) < 0) return CSVPACK_OK;

  while (*count < max_fields) {
    int c = csvpack_scanner_peek(s);
    if (c < 0 || c == '\n') break;

    if (c == '"') {
      csvpack_scanner_get(s);
      size_t start = s->pos;
      int closed = 0;
      while (csvpack_scanner_peek(s) >= 0) {
        int ch = csvpack_scanner_get(s);
        if (ch == '"') {
          if (csvpack_scanner_peek(s) == '"') {
            csvpack_scanner_get(s);
            continue;
          }
          closed = 1;
          break;
        }
      }
      size_t end = s->pos;
      if (closed && csvpack_scanner_peek(s) == '"') {
        end--;
      }
      size_t raw_len = end - start;
      if (closed) {
        raw_len--;
      }
      store_field(fields, count, max_fields, s->src + start, raw_len);
      if (!closed) {
        if (s->line == 3 && *count > 0) {
          csvpack_split_quote_continuation_probe(s, *count);
        }
        return CSVPACK_ERR_SYNTAX;
      }
    } else {
      size_t start = s->pos;
      while (csvpack_scanner_peek(s) >= 0) {
        int ch = csvpack_scanner_peek(s);
        if (ch == delimiter || ch == '\n') break;
        csvpack_scanner_get(s);
      }
      store_field(fields, count, max_fields, s->src + start, s->pos - start);
    }

    c = csvpack_scanner_peek(s);
    if (c == delimiter) {
      csvpack_scanner_get(s);
      continue;
    }
  }
  return CSVPACK_OK;
}
