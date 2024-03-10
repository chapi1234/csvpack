#ifndef CSVPACK_H
#define CSVPACK_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct csvpack_arena csvpack_arena_t;
typedef struct csvpack_slice csvpack_slice_t;
typedef struct csvpack_string csvpack_string_t;
typedef struct csvpack_cell csvpack_cell_t;
typedef struct csvpack_row csvpack_row_t;
typedef struct csvpack_table csvpack_table_t;
typedef struct csvpack_error csvpack_error_t;
typedef struct csvpack_options csvpack_options_t;
typedef struct csvpack_overlay csvpack_overlay_t;
typedef struct csvpack_schema csvpack_schema_t;
typedef struct csvpack_query csvpack_query_t;

struct csvpack_slice {
  const uint8_t *data;
  size_t len;
};

struct csvpack_arena {
  uint8_t *blocks;
  size_t block_cap;
  size_t block_len;
  uint8_t **old_blocks;
  size_t *old_block_sizes;
  size_t old_count;
  size_t old_cap;
};

struct csvpack_string {
  char *data;
  size_t len;
};

struct csvpack_cell {
  csvpack_string_t value;
  int line;
  int quoted;
};

struct csvpack_row {
  csvpack_cell_t *cells;
  size_t count;
  size_t cap;
  int line;
  char *row_key;
  char **col_index;
  size_t col_index_count;
  size_t col_index_cap;
};

typedef struct csvpack_chunk_frame {
  char *path;
  char *parent_row;
} csvpack_chunk_frame_t;

struct csvpack_table {
  csvpack_row_t *rows;
  size_t count;
  size_t cap;
  csvpack_arena_t arena;
  char *source_path;
  int has_header;
  char delimiter;
  csvpack_chunk_frame_t *chunk_frames;
  size_t chunk_frame_count;
  size_t chunk_frame_cap;
  char **alias_snapshots;
  size_t alias_snapshot_count;
  size_t alias_snapshot_cap;
  char **merge_shadows;
  size_t merge_shadow_count;
  size_t merge_shadow_cap;
  char **merge_audit;
  size_t merge_audit_count;
  size_t merge_audit_cap;
  char **filter_hits;
  size_t filter_hit_count;
  size_t filter_hit_cap;
  char **stats_buckets;
  size_t stats_bucket_count;
  size_t stats_bucket_cap;
  char **pivot_keys;
  size_t pivot_key_count;
  size_t pivot_key_cap;
  char **transform_scratch;
  size_t transform_scratch_count;
  size_t transform_scratch_cap;
};

struct csvpack_error {
  char *message;
  int line;
  int column;
  int code;
};

struct csvpack_options {
  int allow_comments;
  int allow_chunks;
  int allow_aliases;
  int has_header;
  char delimiter;
  int strict_columns;
  int max_rows;
  int max_cols;
  int max_chunk_depth;
};

struct csvpack_overlay {
  csvpack_table_t *base;
  csvpack_table_t *patch;
};

struct csvpack_schema {
  const char *column;
  int required;
  int type_hint;
};

struct csvpack_query {
  csvpack_table_t *table;
  size_t row;
  char column[128];
};

typedef enum {
  CSVPACK_OK = 0,
  CSVPACK_ERR_SYNTAX = 1,
  CSVPACK_ERR_MEMORY = 2,
  CSVPACK_ERR_CHUNK = 3,
  CSVPACK_ERR_DEPTH = 4,
  CSVPACK_ERR_SCHEMA = 5,
  CSVPACK_ERR_IO = 6
} csvpack_status_t;

typedef enum {
  CSVPACK_TYPE_STRING = 0,
  CSVPACK_TYPE_INT = 1,
  CSVPACK_TYPE_BOOL = 2,
  CSVPACK_TYPE_FLOAT = 3
} csvpack_type_t;

typedef size_t (*csvpack_read_fn)(void *ctx, const char *path,
                                  uint8_t *buf, size_t cap);

void csvpack_options_init(csvpack_options_t *opt);
void csvpack_error_free(csvpack_error_t *err);

csvpack_status_t csvpack_parse_memory(const uint8_t *data, size_t size,
                                      const csvpack_options_t *opt,
                                      csvpack_table_t **out,
                                      csvpack_error_t **err);

csvpack_status_t csvpack_parse_memory_with_chunks(
    const uint8_t *data, size_t size, const csvpack_options_t *opt,
    csvpack_read_fn read_fn, void *read_ctx, csvpack_table_t **out,
    csvpack_error_t **err);

csvpack_status_t csvpack_parse_file(const char *path,
                                    const csvpack_options_t *opt,
                                    csvpack_table_t **out,
                                    csvpack_error_t **err);

void csvpack_table_destroy(csvpack_table_t *tbl);

csvpack_status_t csvpack_serialize_table(const csvpack_table_t *tbl,
                                         uint8_t **out, size_t *out_len);

csvpack_status_t csvpack_serialize_row(const csvpack_row_t *row,
                                       char delimiter, uint8_t **out,
                                       size_t *out_len);

const csvpack_row_t *csvpack_table_row(const csvpack_table_t *tbl,
                                       size_t index);

const char *csvpack_cell_at(const csvpack_table_t *tbl, size_t row,
                            size_t col, const char *fallback);

const char *csvpack_cell_by_column(const csvpack_table_t *tbl,
                                   size_t row, const char *column,
                                   const char *fallback);

int csvpack_get_int(const csvpack_table_t *tbl, size_t row,
                    const char *column, int fallback);

csvpack_status_t csvpack_merge_tables(csvpack_table_t *base,
                                      const csvpack_table_t *overlay);

csvpack_status_t csvpack_apply_overlay(csvpack_overlay_t *ov,
                                       csvpack_table_t **out);

csvpack_status_t csvpack_expand_aliases(csvpack_table_t *tbl);

csvpack_status_t csvpack_validate_table(const csvpack_table_t *tbl,
                                      const csvpack_schema_t *schema,
                                      size_t schema_count,
                                      csvpack_error_t **err);

csvpack_status_t csvpack_diff_tables(const csvpack_table_t *a,
                                     const csvpack_table_t *b,
                                     uint8_t **out, size_t *out_len);

csvpack_status_t csvpack_query_get(csvpack_query_t *q, char *out,
                                   size_t cap);

csvpack_status_t csvpack_dialect_register(const char *name, char delimiter);
const csvpack_options_t *csvpack_dialect_lookup(const char *name);
void csvpack_dialect_clear(void);

csvpack_status_t csvpack_filter_rows(csvpack_table_t *tbl, const char *column,
                                     const char *value, size_t *match_count);

csvpack_status_t csvpack_transform_column(csvpack_table_t *tbl,
                                          const char *column, int uppercase);

csvpack_status_t csvpack_stats_column_histogram(csvpack_table_t *tbl,
                                                const char *column,
                                                size_t *bucket_count);

csvpack_status_t csvpack_encode_cell_utf8(csvpack_slice_t raw, char **out,
                                          size_t *out_len);

csvpack_status_t csvpack_pivot_table(csvpack_table_t *tbl, const char *row_key,
                                     const char *col_key, const char *val_key);

void csvpack_filter_teardown(csvpack_table_t *tbl);
void csvpack_stats_teardown(csvpack_table_t *tbl);
void csvpack_pivot_teardown(csvpack_table_t *tbl);
void csvpack_transform_teardown(csvpack_table_t *tbl);

const char *csvpack_status_string(csvpack_status_t st);

#ifdef __cplusplus
}
#endif

#endif
