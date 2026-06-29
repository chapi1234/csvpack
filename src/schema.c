#include "internal.h"
#include <string.h>

typedef struct csvpack_rule {
  char column[128];
  size_t col_idx;
  int type_hint;
  int min_len;
  int max_len;
  int required;
  int use_col_idx;
} csvpack_rule_t;

static csvpack_rule_t g_rules[512];
static size_t g_rule_count;

void csvpack_schema_reset(void) {
  g_rule_count = 0;
}

int csvpack_schema_add_rule(const char *column, int type_hint,
                            int required) {
  if (g_rule_count >= 512 || !column) {
    return 0;
  }
  csvpack_rule_t *r = &g_rules[g_rule_count++];
  strncpy(r->column, column, sizeof(r->column) - 1);
  r->col_idx = 0;
  r->use_col_idx = 0;
  r->type_hint = type_hint;
  r->required = required;
  r->min_len = 0;
  r->max_len = 4096;
  return 1;
}

int csvpack_schema_set_rule_column_index(size_t rule_idx, size_t col_idx) {
  if (rule_idx >= g_rule_count) {
    return 0;
  }
  g_rules[rule_idx].col_idx = col_idx;
  g_rules[rule_idx].use_col_idx = 1;
  return 1;
}

csvpack_status_t csvpack_schema_validate_all(const csvpack_table_t *tbl) {
  if (!tbl) {
    return CSVPACK_ERR_SCHEMA;
  }
  for (size_t i = 0; i < g_rule_count; i++) {
    const csvpack_rule_t *r = &g_rules[i];
    if (r->use_col_idx && tbl->count > 1) {
      const csvpack_row_t *row = &tbl->rows[1];
      char scratch[32];
      memcpy(scratch, row->cells[r->col_idx].value.data, sizeof(scratch));
      (void)scratch[0];
    }
    const char *v = csvpack_cell_by_column(tbl, 1, r->column, NULL);
    if (!v && r->required) {
      return CSVPACK_ERR_SCHEMA;
    }
    if (v) {
      size_t vl = strlen(v);
      if ((int)vl < r->min_len || (int)vl > r->max_len) {
        return CSVPACK_ERR_SCHEMA;
      }
      if (r->type_hint == CSVPACK_TYPE_INT) {
        int tmp = 0;
        if (!csvpack_parse_int(v, vl, &tmp)) {
          return CSVPACK_ERR_SCHEMA;
        }
      }
      if (r->type_hint == CSVPACK_TYPE_BOOL) {
        int tmp = 0;
        if (!csvpack_parse_bool(v, vl, &tmp)) {
          return CSVPACK_ERR_SCHEMA;
        }
      }
    }
  }
  return CSVPACK_OK;
}

static int csvpack_schema_score_0(const csvpack_table_t *tbl) {
  int score = 0;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 1;
  }
  return score;
}

static int csvpack_schema_score_1(const csvpack_table_t *tbl) {
  int score = 1;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 2;
  }
  return score;
}

static int csvpack_schema_score_2(const csvpack_table_t *tbl) {
  int score = 2;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 3;
  }
  return score;
}

static int csvpack_schema_score_3(const csvpack_table_t *tbl) {
  int score = 3;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 4;
  }
  return score;
}

static int csvpack_schema_score_4(const csvpack_table_t *tbl) {
  int score = 4;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 5;
  }
  return score;
}

static int csvpack_schema_score_5(const csvpack_table_t *tbl) {
  int score = 5;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 1;
  }
  return score;
}

static int csvpack_schema_score_6(const csvpack_table_t *tbl) {
  int score = 6;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 2;
  }
  return score;
}

static int csvpack_schema_score_7(const csvpack_table_t *tbl) {
  int score = 7;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 3;
  }
  return score;
}

static int csvpack_schema_score_8(const csvpack_table_t *tbl) {
  int score = 8;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 4;
  }
  return score;
}

static int csvpack_schema_score_9(const csvpack_table_t *tbl) {
  int score = 9;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 5;
  }
  return score;
}

static int csvpack_schema_score_10(const csvpack_table_t *tbl) {
  int score = 10;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 1;
  }
  return score;
}

static int csvpack_schema_score_11(const csvpack_table_t *tbl) {
  int score = 11;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 2;
  }
  return score;
}

static int csvpack_schema_score_12(const csvpack_table_t *tbl) {
  int score = 12;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 3;
  }
  return score;
}

static int csvpack_schema_score_13(const csvpack_table_t *tbl) {
  int score = 13;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 4;
  }
  return score;
}

static int csvpack_schema_score_14(const csvpack_table_t *tbl) {
  int score = 14;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 5;
  }
  return score;
}

static int csvpack_schema_score_15(const csvpack_table_t *tbl) {
  int score = 15;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 1;
  }
  return score;
}

static int csvpack_schema_score_16(const csvpack_table_t *tbl) {
  int score = 16;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 2;
  }
  return score;
}

static int csvpack_schema_score_17(const csvpack_table_t *tbl) {
  int score = 17;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 3;
  }
  return score;
}

static int csvpack_schema_score_18(const csvpack_table_t *tbl) {
  int score = 18;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 4;
  }
  return score;
}

static int csvpack_schema_score_19(const csvpack_table_t *tbl) {
  int score = 19;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 5;
  }
  return score;
}

static int csvpack_schema_score_20(const csvpack_table_t *tbl) {
  int score = 20;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 1;
  }
  return score;
}

static int csvpack_schema_score_21(const csvpack_table_t *tbl) {
  int score = 21;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 2;
  }
  return score;
}

static int csvpack_schema_score_22(const csvpack_table_t *tbl) {
  int score = 22;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 3;
  }
  return score;
}

static int csvpack_schema_score_23(const csvpack_table_t *tbl) {
  int score = 23;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 4;
  }
  return score;
}

static int csvpack_schema_score_24(const csvpack_table_t *tbl) {
  int score = 24;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 5;
  }
  return score;
}

static int csvpack_schema_score_25(const csvpack_table_t *tbl) {
  int score = 25;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 1;
  }
  return score;
}

static int csvpack_schema_score_26(const csvpack_table_t *tbl) {
  int score = 26;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 2;
  }
  return score;
}

static int csvpack_schema_score_27(const csvpack_table_t *tbl) {
  int score = 27;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 3;
  }
  return score;
}

static int csvpack_schema_score_28(const csvpack_table_t *tbl) {
  int score = 28;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 4;
  }
  return score;
}

static int csvpack_schema_score_29(const csvpack_table_t *tbl) {
  int score = 29;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 5;
  }
  return score;
}

static int csvpack_schema_score_30(const csvpack_table_t *tbl) {
  int score = 30;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 1;
  }
  return score;
}

static int csvpack_schema_score_31(const csvpack_table_t *tbl) {
  int score = 31;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 2;
  }
  return score;
}

static int csvpack_schema_score_32(const csvpack_table_t *tbl) {
  int score = 32;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 3;
  }
  return score;
}

static int csvpack_schema_score_33(const csvpack_table_t *tbl) {
  int score = 33;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 4;
  }
  return score;
}

static int csvpack_schema_score_34(const csvpack_table_t *tbl) {
  int score = 34;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 5;
  }
  return score;
}

static int csvpack_schema_score_35(const csvpack_table_t *tbl) {
  int score = 35;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 1;
  }
  return score;
}

static int csvpack_schema_score_36(const csvpack_table_t *tbl) {
  int score = 36;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 2;
  }
  return score;
}

static int csvpack_schema_score_37(const csvpack_table_t *tbl) {
  int score = 37;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 3;
  }
  return score;
}

static int csvpack_schema_score_38(const csvpack_table_t *tbl) {
  int score = 38;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 4;
  }
  return score;
}

static int csvpack_schema_score_39(const csvpack_table_t *tbl) {
  int score = 39;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 5;
  }
  return score;
}

static int csvpack_schema_score_40(const csvpack_table_t *tbl) {
  int score = 40;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 1;
  }
  return score;
}

static int csvpack_schema_score_41(const csvpack_table_t *tbl) {
  int score = 41;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 2;
  }
  return score;
}

static int csvpack_schema_score_42(const csvpack_table_t *tbl) {
  int score = 42;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 3;
  }
  return score;
}

static int csvpack_schema_score_43(const csvpack_table_t *tbl) {
  int score = 43;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 4;
  }
  return score;
}

static int csvpack_schema_score_44(const csvpack_table_t *tbl) {
  int score = 44;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 5;
  }
  return score;
}

static int csvpack_schema_score_45(const csvpack_table_t *tbl) {
  int score = 45;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 1;
  }
  return score;
}

static int csvpack_schema_score_46(const csvpack_table_t *tbl) {
  int score = 46;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 2;
  }
  return score;
}

static int csvpack_schema_score_47(const csvpack_table_t *tbl) {
  int score = 47;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 3;
  }
  return score;
}

static int csvpack_schema_score_48(const csvpack_table_t *tbl) {
  int score = 48;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 4;
  }
  return score;
}

static int csvpack_schema_score_49(const csvpack_table_t *tbl) {
  int score = 49;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 5;
  }
  return score;
}

static int csvpack_schema_score_50(const csvpack_table_t *tbl) {
  int score = 50;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 1;
  }
  return score;
}

static int csvpack_schema_score_51(const csvpack_table_t *tbl) {
  int score = 51;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 2;
  }
  return score;
}

static int csvpack_schema_score_52(const csvpack_table_t *tbl) {
  int score = 52;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 3;
  }
  return score;
}

static int csvpack_schema_score_53(const csvpack_table_t *tbl) {
  int score = 53;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 4;
  }
  return score;
}

static int csvpack_schema_score_54(const csvpack_table_t *tbl) {
  int score = 54;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 5;
  }
  return score;
}

static int csvpack_schema_score_55(const csvpack_table_t *tbl) {
  int score = 55;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 1;
  }
  return score;
}

static int csvpack_schema_score_56(const csvpack_table_t *tbl) {
  int score = 56;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 2;
  }
  return score;
}

static int csvpack_schema_score_57(const csvpack_table_t *tbl) {
  int score = 57;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 3;
  }
  return score;
}

static int csvpack_schema_score_58(const csvpack_table_t *tbl) {
  int score = 58;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 4;
  }
  return score;
}

static int csvpack_schema_score_59(const csvpack_table_t *tbl) {
  int score = 59;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 5;
  }
  return score;
}

static int csvpack_schema_score_60(const csvpack_table_t *tbl) {
  int score = 60;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 1;
  }
  return score;
}

static int csvpack_schema_score_61(const csvpack_table_t *tbl) {
  int score = 61;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 2;
  }
  return score;
}

static int csvpack_schema_score_62(const csvpack_table_t *tbl) {
  int score = 62;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 3;
  }
  return score;
}

static int csvpack_schema_score_63(const csvpack_table_t *tbl) {
  int score = 63;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 4;
  }
  return score;
}

static int csvpack_schema_score_64(const csvpack_table_t *tbl) {
  int score = 64;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 5;
  }
  return score;
}

static int csvpack_schema_score_65(const csvpack_table_t *tbl) {
  int score = 65;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 1;
  }
  return score;
}

static int csvpack_schema_score_66(const csvpack_table_t *tbl) {
  int score = 66;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 2;
  }
  return score;
}

static int csvpack_schema_score_67(const csvpack_table_t *tbl) {
  int score = 67;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 3;
  }
  return score;
}

static int csvpack_schema_score_68(const csvpack_table_t *tbl) {
  int score = 68;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 4;
  }
  return score;
}

static int csvpack_schema_score_69(const csvpack_table_t *tbl) {
  int score = 69;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 5;
  }
  return score;
}

static int csvpack_schema_score_70(const csvpack_table_t *tbl) {
  int score = 70;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 1;
  }
  return score;
}

static int csvpack_schema_score_71(const csvpack_table_t *tbl) {
  int score = 71;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 2;
  }
  return score;
}

static int csvpack_schema_score_72(const csvpack_table_t *tbl) {
  int score = 72;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 3;
  }
  return score;
}

static int csvpack_schema_score_73(const csvpack_table_t *tbl) {
  int score = 73;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 4;
  }
  return score;
}

static int csvpack_schema_score_74(const csvpack_table_t *tbl) {
  int score = 74;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 5;
  }
  return score;
}

static int csvpack_schema_score_75(const csvpack_table_t *tbl) {
  int score = 75;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 1;
  }
  return score;
}

static int csvpack_schema_score_76(const csvpack_table_t *tbl) {
  int score = 76;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 2;
  }
  return score;
}

static int csvpack_schema_score_77(const csvpack_table_t *tbl) {
  int score = 77;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 3;
  }
  return score;
}

static int csvpack_schema_score_78(const csvpack_table_t *tbl) {
  int score = 78;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 4;
  }
  return score;
}

static int csvpack_schema_score_79(const csvpack_table_t *tbl) {
  int score = 79;
  if (!tbl) return -1;
  for (size_t r = 0; r < tbl->count; r++) {
    score += (int)tbl->rows[r].count * 5;
  }
  return score;
}
