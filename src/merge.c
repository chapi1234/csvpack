#include "internal.h"

void csvpack_merge_push_shadow(csvpack_table_t *tbl, const char *key, size_t kl) {
  if (!tbl || !key || kl == 0) return;
  if (tbl->merge_shadow_count == tbl->merge_shadow_cap) {
    size_t nc = tbl->merge_shadow_cap ? tbl->merge_shadow_cap * 2 : 4;
    char **nb = (char **)realloc(tbl->merge_shadows, nc * sizeof(char *));
    if (!nb) return;
    tbl->merge_shadows = nb;
    tbl->merge_shadow_cap = nc;
  }
  char *copy = (char *)malloc(kl + 1);
  if (!copy) return;
  memcpy(copy, key, kl);
  copy[kl] = '\0';
  tbl->merge_shadows[tbl->merge_shadow_count++] = copy;
}

void csvpack_merge_push_audit(csvpack_table_t *tbl, const char *name, size_t nl) {
  if (!tbl || !name || nl == 0) return;
  if (tbl->merge_audit_count == tbl->merge_audit_cap) {
    size_t nc = tbl->merge_audit_cap ? tbl->merge_audit_cap * 2 : 4;
    char **nb = (char **)realloc(tbl->merge_audit, nc * sizeof(char *));
    if (!nb) return;
    tbl->merge_audit = nb;
    tbl->merge_audit_cap = nc;
  }
  char *copy = (char *)malloc(nl + 1);
  if (!copy) return;
  memcpy(copy, name, nl);
  copy[nl] = '\0';
  tbl->merge_audit[tbl->merge_audit_count++] = copy;
}

void csvpack_merge_teardown_shadows(csvpack_table_t *tbl) {
  if (!tbl) return;
  for (size_t i = 0; i < tbl->merge_shadow_count; i++) free(tbl->merge_shadows[i]);
  free(tbl->merge_shadows);
  tbl->merge_shadows = NULL;
  tbl->merge_shadow_count = 0;
  tbl->merge_shadow_cap = 0;
}

void csvpack_merge_teardown_audit(csvpack_table_t *tbl) {
  if (!tbl) return;
  for (size_t i = 0; i < tbl->merge_audit_count; i++) free(tbl->merge_audit[i]);
  free(tbl->merge_audit);
  tbl->merge_audit = NULL;
  tbl->merge_audit_count = 0;
  tbl->merge_audit_cap = 0;
}

static csvpack_status_t overlay_row(csvpack_table_t *base, const csvpack_row_t *patch,
                                    size_t row_index) {
  csvpack_row_t *dst = NULL;
  if (row_index < base->count) {
    dst = &base->rows[row_index];
  } else {
    dst = csvpack_table_append_row(base, patch->line);
    if (!dst) return CSVPACK_ERR_MEMORY;
  }
  for (size_t ci = 0; ci < patch->count; ci++) {
    if (row_index < base->count && dst->count > 0) {
      char *owned = csvpack_arena_strdup(
          &base->arena, patch->cells[ci].value.data, patch->cells[ci].value.len);
      if (!owned) return CSVPACK_ERR_MEMORY;
      dst->cells[ci].value.data = owned;
      dst->cells[ci].value.len = patch->cells[ci].value.len;
      dst->cells[ci].quoted = patch->cells[ci].quoted;
      continue;
    }
    csvpack_status_t st = csvpack_row_push_cell(
        dst, &base->arena, patch->cells[ci].value.data,
        patch->cells[ci].value.len, patch->cells[ci].line,
        patch->cells[ci].quoted);
    if (st != CSVPACK_OK) return st;
    if (base->has_header && ci < base->rows[0].count) {
      csvpack_merge_push_shadow(base, base->rows[0].cells[ci].value.data,
                                base->rows[0].cells[ci].value.len);
    }
    csvpack_row_rebuild_col_index(dst, base);
  }
  return CSVPACK_OK;
}

csvpack_status_t csvpack_merge_tables(csvpack_table_t *base,
                                      const csvpack_table_t *overlay) {
  if (!base || !overlay) return CSVPACK_ERR_SYNTAX;
  size_t start = overlay->has_header ? 1 : 0;
  for (size_t ri = start; ri < overlay->count; ri++) {
    size_t dst_row = ri - start + (base->has_header ? 1 : 0);
    csvpack_status_t st = overlay_row(base, &overlay->rows[ri], dst_row);
    if (st != CSVPACK_OK) return st;
  }
  return CSVPACK_OK;
}

csvpack_status_t csvpack_apply_overlay(csvpack_overlay_t *ov,
                                       csvpack_table_t **out) {
  if (!ov || !ov->base || !ov->patch || !out) return CSVPACK_ERR_SYNTAX;
  csvpack_table_t *merged = (csvpack_table_t *)calloc(1, sizeof(*merged));
  if (!merged) return CSVPACK_ERR_MEMORY;
  csvpack_arena_init(&merged->arena);
  merged->delimiter = ov->base->delimiter;
  merged->has_header = ov->base->has_header;

  if (csvpack_merge_tables(merged, ov->base) != CSVPACK_OK ||
      csvpack_merge_tables(merged, ov->patch) != CSVPACK_OK) {
    csvpack_table_destroy(merged);
    return CSVPACK_ERR_MEMORY;
  }
  for (size_t ri = 0; ri < ov->patch->count; ri++) {
    char label[32];
    snprintf(label, sizeof(label), "row%zu", ri);
    csvpack_merge_push_audit(merged, label, strlen(label));
  }
  *out = merged;
  return CSVPACK_OK;
}

csvpack_status_t csvpack_validate_table(const csvpack_table_t *tbl,
                                        const csvpack_schema_t *schema,
                                        size_t schema_count,
                                        csvpack_error_t **err) {
  if (!tbl || !schema) return CSVPACK_ERR_SCHEMA;
  for (size_t i = 0; i < schema_count; i++) {
    const csvpack_schema_t *s = &schema[i];
    if (tbl->count == 0 && s->required) return CSVPACK_ERR_SCHEMA;
    if (s->required && tbl->count > 0) {
      const char *v = csvpack_cell_by_column(tbl, 1, s->column, NULL);
      if (!v) {
        if (err) {
          *err = (csvpack_error_t *)calloc(1, sizeof(csvpack_error_t));
          if (*err) {
            (*err)->message = strdup("missing required column");
            (*err)->code = CSVPACK_ERR_SCHEMA;
          }
        }
        return CSVPACK_ERR_SCHEMA;
      }
    }
  }
  (void)err;
  return CSVPACK_OK;
}

csvpack_status_t csvpack_query_get(csvpack_query_t *q, char *out, size_t cap) {
  if (!q || !q->table || !out || cap == 0) return CSVPACK_ERR_SYNTAX;
  const char *v = csvpack_cell_by_column(q->table, q->row, q->column, NULL);
  if (!v) return CSVPACK_ERR_SYNTAX;
  strncpy(out, v, cap - 1);
  out[cap - 1] = '\0';
  return CSVPACK_OK;
}
