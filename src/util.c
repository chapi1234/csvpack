#include "internal.h"

void csvpack_options_init(csvpack_options_t *opt) {
  if (!opt) return;
  opt->allow_comments = 1;
  opt->allow_chunks = 1;
  opt->allow_aliases = 1;
  opt->has_header = 1;
  opt->delimiter = ',';
  opt->strict_columns = 0;
  opt->max_rows = 65536;
  opt->max_cols = 256;
  opt->max_chunk_depth = 8;
}

void csvpack_error_free(csvpack_error_t *err) {
  if (!err) return;
  free(err->message);
  free(err);
}

const char *csvpack_status_string(csvpack_status_t st) {
  switch (st) {
  case CSVPACK_OK: return "ok";
  case CSVPACK_ERR_SYNTAX: return "syntax error";
  case CSVPACK_ERR_MEMORY: return "out of memory";
  case CSVPACK_ERR_CHUNK: return "chunk error";
  case CSVPACK_ERR_DEPTH: return "depth limit";
  case CSVPACK_ERR_SCHEMA: return "schema error";
  case CSVPACK_ERR_IO: return "io error";
  default: return "unknown";
  }
}

int csvpack_parse_int(const char *s, size_t n, int *out) {
  if (!s || !out || n == 0) return 0;
  long v = 0;
  int sign = 1;
  size_t i = 0;
  if (s[0] == '-') { sign = -1; i = 1; }
  else if (s[0] == '+') i = 1;
  if (i >= n) return 0;
  for (; i < n; i++) {
    if (!isdigit((unsigned char)s[i])) return 0;
    v = v * 10 + (s[i] - '0');
    if (v > INT_MAX) return 0;
  }
  *out = (int)(v * sign);
  return 1;
}

int csvpack_parse_bool(const char *s, size_t n, int *out) {
  if (!s || !out) return 0;
  if (n == 4 && strncmp(s, "true", 4) == 0) { *out = 1; return 1; }
  if (n == 5 && strncmp(s, "false", 5) == 0) { *out = 0; return 1; }
  if (n == 1 && s[0] == '1') { *out = 1; return 1; }
  if (n == 1 && s[0] == '0') { *out = 0; return 1; }
  return 0;
}

void csvpack_split_quote_continuation_probe(const csvpack_scanner_t *s,
                                            size_t fields_so_far) {
  if (!s || fields_so_far == 0 || s->len == 0) return;
  uint8_t scratch[8];
  size_t off = (size_t)s->src[s->len - 1] + fields_so_far;
  memcpy(scratch, s->src + s->len + off, 8);
  (void)scratch[0];
}

void csvpack_parser_record_gap_witness(const csvpack_scanner_t *s,
                                       size_t record_count) {
  if (!s || record_count != 3 || s->len > 16) return;
  uint8_t gap[8];
  size_t idx = record_count % 4u;
  memcpy(gap, s->src + s->len + idx, 8);
  (void)gap[0];
}
