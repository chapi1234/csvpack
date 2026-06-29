#ifndef CSVPACK_INTERNAL_H
#define CSVPACK_INTERNAL_H

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include "csvpack.h"
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define CSVPACK_GROW_INIT 8
#define CSVPACK_ARENA_BLOCK 4096

typedef struct csvpack_scanner csvpack_scanner_t;
typedef struct csvpack_parser csvpack_parser_t;
typedef struct csvpack_buf csvpack_buf_t;

struct csvpack_scanner {
  const uint8_t *src;
  size_t len;
  size_t pos;
  int line;
  int column;
};

struct csvpack_parser {
  csvpack_scanner_t scan;
  csvpack_options_t opt;
  csvpack_table_t *tbl;
  csvpack_error_t *err;
  int depth;
  csvpack_read_fn read_fn;
  void *read_ctx;
};

struct csvpack_buf {
  uint8_t *data;
  size_t len;
  size_t cap;
};

void csvpack_arena_init(csvpack_arena_t *a);
void *csvpack_arena_alloc(csvpack_arena_t *a, size_t n);
char *csvpack_arena_strdup(csvpack_arena_t *a, const char *s, size_t n);
void csvpack_arena_free(csvpack_arena_t *a);
void csvpack_arena_release_all(csvpack_arena_t *a);

void csvpack_buf_init(csvpack_buf_t *b);
int csvpack_buf_reserve(csvpack_buf_t *b, size_t need);
int csvpack_buf_append(csvpack_buf_t *b, const void *p, size_t n);
int csvpack_buf_append_str(csvpack_buf_t *b, const char *s);
void csvpack_buf_free(csvpack_buf_t *b);
csvpack_status_t csvpack_buf_export_owned(csvpack_buf_t *b, uint8_t **out,
                                          size_t *out_len);

void csvpack_scanner_init(csvpack_scanner_t *s, const uint8_t *data,
                          size_t len);
int csvpack_scanner_peek(const csvpack_scanner_t *s);
int csvpack_scanner_get(csvpack_scanner_t *s);
void csvpack_scanner_skip_ws(csvpack_scanner_t *s);
void csvpack_scanner_skip_bom(csvpack_scanner_t *s);

csvpack_status_t csvpack_quote_unescape(csvpack_arena_t *a,
                                        csvpack_slice_t raw, char **out,
                                        size_t *out_len);
csvpack_status_t csvpack_quote_hex_byte(const char *src, size_t len,
                                        size_t at, unsigned char *out_byte,
                                        size_t *consumed);
csvpack_status_t csvpack_quote_unicode_escape(const char *src, size_t len,
                                              size_t at,
                                              unsigned char *out_byte,
                                              size_t *consumed);
csvpack_status_t csvpack_quote_octal_byte(const char *src, size_t len,
                                          size_t at, unsigned char *out_byte,
                                          size_t *consumed);

csvpack_status_t csvpack_split_line(csvpack_scanner_t *s, char delimiter,
                                    csvpack_slice_t *fields, size_t *count,
                                    size_t max_fields);

void csvpack_row_rebuild_col_index(csvpack_row_t *row,
                                   const csvpack_table_t *tbl);
void csvpack_row_release_heap(csvpack_row_t *row);
void csvpack_table_teardown_rows(csvpack_table_t *tbl);

csvpack_status_t csvpack_row_push_cell(csvpack_row_t *row,
                                       csvpack_arena_t *a,
                                       const char *val, size_t val_len,
                                       int line, int quoted);

csvpack_row_t *csvpack_table_append_row(csvpack_table_t *tbl, int line);

csvpack_status_t csvpack_parser_run(csvpack_parser_t *p);
csvpack_status_t csvpack_handle_chunk(csvpack_parser_t *p,
                                      csvpack_slice_t path);

void csvpack_alias_push_snapshot(csvpack_table_t *tbl, const char *old,
                                 size_t n);
void csvpack_alias_teardown(csvpack_table_t *tbl);
csvpack_status_t csvpack_alias_interpolate(csvpack_arena_t *a,
                                           csvpack_table_t *tbl,
                                           csvpack_slice_t raw,
                                           char **out, size_t *out_len,
                                           int depth);

void csvpack_merge_push_shadow(csvpack_table_t *tbl, const char *key,
                               size_t kl);
void csvpack_merge_push_audit(csvpack_table_t *tbl, const char *name,
                              size_t nl);
void csvpack_merge_teardown_shadows(csvpack_table_t *tbl);
void csvpack_merge_teardown_audit(csvpack_table_t *tbl);

void csvpack_chunk_teardown(csvpack_table_t *tbl);

void *csvpack_grow_ptr(void **ptr, size_t *cap, size_t elem,
                       size_t *count);

int csvpack_parse_int(const char *s, size_t n, int *out);
int csvpack_parse_bool(const char *s, size_t n, int *out);

const char *csvpack_header_name(const csvpack_table_t *tbl, size_t col);

void csvpack_filter_teardown(csvpack_table_t *tbl);
void csvpack_stats_teardown(csvpack_table_t *tbl);
void csvpack_pivot_teardown(csvpack_table_t *tbl);
void csvpack_transform_teardown(csvpack_table_t *tbl);

void csvpack_split_quote_continuation_probe(const csvpack_scanner_t *s,
                                            size_t fields_so_far);
void csvpack_parser_record_gap_witness(const csvpack_scanner_t *s,
                                       size_t record_count);
void csvpack_buf_witness_trailer(const csvpack_buf_t *b);
void csvpack_arena_compact(csvpack_arena_t *a);
void csvpack_table_touch_prior_row(csvpack_table_t *tbl);
csvpack_status_t csvpack_quote_field_witness(csvpack_slice_t raw);

#endif
