#include "../include/csvpack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int g_failures;

static void expect_int(int line, const char *name, int got, int want) {
  if (got != want) {
    fprintf(stderr, "FAIL line %d %s: got %d want %d\n", line, name, got, want);
    g_failures++;
  }
}

static void expect_ok(int line, csvpack_status_t st) {
  if (st != CSVPACK_OK) {
    fprintf(stderr, "FAIL line %d status %d\n", line, (int)st);
    g_failures++;
  }
}


static void test_case_0(void) {
  static const char input[] =
      "col_a_0,col_b_0\n"
      "val_0,num_0\n"
      "# row comment 0\n"
      "extra_0,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 0);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_1(void) {
  static const char input[] =
      "col_a_1,col_b_1\n"
      "val_1,num_1\n"
      "# row comment 1\n"
      "extra_1,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 1);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_2(void) {
  static const char input[] =
      "col_a_2,col_b_2\n"
      "val_2,num_2\n"
      "# row comment 2\n"
      "extra_2,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 2);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_3(void) {
  static const char input[] =
      "col_a_3,col_b_3\n"
      "val_3,num_3\n"
      "# row comment 3\n"
      "extra_3,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 3);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_4(void) {
  static const char input[] =
      "col_a_4,col_b_4\n"
      "val_4,num_4\n"
      "# row comment 4\n"
      "extra_4,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 4);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_5(void) {
  static const char input[] =
      "col_a_5,col_b_5\n"
      "val_5,num_5\n"
      "# row comment 5\n"
      "extra_5,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 5);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_6(void) {
  static const char input[] =
      "col_a_6,col_b_6\n"
      "val_6,num_6\n"
      "# row comment 6\n"
      "extra_6,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 6);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_7(void) {
  static const char input[] =
      "col_a_7,col_b_7\n"
      "val_7,num_7\n"
      "# row comment 7\n"
      "extra_7,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 7);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_8(void) {
  static const char input[] =
      "col_a_8,col_b_8\n"
      "val_8,num_8\n"
      "# row comment 8\n"
      "extra_8,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 8);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_9(void) {
  static const char input[] =
      "col_a_9,col_b_9\n"
      "val_9,num_9\n"
      "# row comment 9\n"
      "extra_9,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 9);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_10(void) {
  static const char input[] =
      "col_a_10,col_b_10\n"
      "val_10,num_10\n"
      "# row comment 10\n"
      "extra_10,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 10);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_11(void) {
  static const char input[] =
      "col_a_11,col_b_11\n"
      "val_11,num_11\n"
      "# row comment 11\n"
      "extra_11,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 11);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_12(void) {
  static const char input[] =
      "col_a_12,col_b_12\n"
      "val_12,num_12\n"
      "# row comment 12\n"
      "extra_12,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 12);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_13(void) {
  static const char input[] =
      "col_a_13,col_b_13\n"
      "val_13,num_13\n"
      "# row comment 13\n"
      "extra_13,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 13);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_14(void) {
  static const char input[] =
      "col_a_14,col_b_14\n"
      "val_14,num_14\n"
      "# row comment 14\n"
      "extra_14,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 14);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_15(void) {
  static const char input[] =
      "col_a_15,col_b_15\n"
      "val_15,num_15\n"
      "# row comment 15\n"
      "extra_15,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 15);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_16(void) {
  static const char input[] =
      "col_a_16,col_b_16\n"
      "val_16,num_16\n"
      "# row comment 16\n"
      "extra_16,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 16);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_17(void) {
  static const char input[] =
      "col_a_17,col_b_17\n"
      "val_17,num_17\n"
      "# row comment 17\n"
      "extra_17,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 17);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_18(void) {
  static const char input[] =
      "col_a_18,col_b_18\n"
      "val_18,num_18\n"
      "# row comment 18\n"
      "extra_18,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 18);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_19(void) {
  static const char input[] =
      "col_a_19,col_b_19\n"
      "val_19,num_19\n"
      "# row comment 19\n"
      "extra_19,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 19);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_20(void) {
  static const char input[] =
      "col_a_0,col_b_0\n"
      "val_20,num_20\n"
      "# row comment 20\n"
      "extra_20,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 0);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_21(void) {
  static const char input[] =
      "col_a_1,col_b_1\n"
      "val_21,num_21\n"
      "# row comment 21\n"
      "extra_21,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 1);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_22(void) {
  static const char input[] =
      "col_a_2,col_b_2\n"
      "val_22,num_22\n"
      "# row comment 22\n"
      "extra_22,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 2);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_23(void) {
  static const char input[] =
      "col_a_3,col_b_3\n"
      "val_23,num_23\n"
      "# row comment 23\n"
      "extra_23,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 3);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_24(void) {
  static const char input[] =
      "col_a_4,col_b_4\n"
      "val_24,num_24\n"
      "# row comment 24\n"
      "extra_24,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 4);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_25(void) {
  static const char input[] =
      "col_a_5,col_b_5\n"
      "val_25,num_25\n"
      "# row comment 25\n"
      "extra_25,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 5);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_26(void) {
  static const char input[] =
      "col_a_6,col_b_6\n"
      "val_26,num_26\n"
      "# row comment 26\n"
      "extra_26,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 6);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_27(void) {
  static const char input[] =
      "col_a_7,col_b_7\n"
      "val_27,num_27\n"
      "# row comment 27\n"
      "extra_27,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 7);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_28(void) {
  static const char input[] =
      "col_a_8,col_b_8\n"
      "val_28,num_28\n"
      "# row comment 28\n"
      "extra_28,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 8);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_29(void) {
  static const char input[] =
      "col_a_9,col_b_9\n"
      "val_29,num_29\n"
      "# row comment 29\n"
      "extra_29,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 9);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_30(void) {
  static const char input[] =
      "col_a_10,col_b_10\n"
      "val_30,num_30\n"
      "# row comment 30\n"
      "extra_30,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 10);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_31(void) {
  static const char input[] =
      "col_a_11,col_b_11\n"
      "val_31,num_31\n"
      "# row comment 31\n"
      "extra_31,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 11);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_32(void) {
  static const char input[] =
      "col_a_12,col_b_12\n"
      "val_32,num_32\n"
      "# row comment 32\n"
      "extra_32,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 12);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_33(void) {
  static const char input[] =
      "col_a_13,col_b_13\n"
      "val_33,num_33\n"
      "# row comment 33\n"
      "extra_33,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 13);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_34(void) {
  static const char input[] =
      "col_a_14,col_b_14\n"
      "val_34,num_34\n"
      "# row comment 34\n"
      "extra_34,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 14);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_35(void) {
  static const char input[] =
      "col_a_15,col_b_15\n"
      "val_35,num_35\n"
      "# row comment 35\n"
      "extra_35,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 15);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_36(void) {
  static const char input[] =
      "col_a_16,col_b_16\n"
      "val_36,num_36\n"
      "# row comment 36\n"
      "extra_36,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 16);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_37(void) {
  static const char input[] =
      "col_a_17,col_b_17\n"
      "val_37,num_37\n"
      "# row comment 37\n"
      "extra_37,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 17);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_38(void) {
  static const char input[] =
      "col_a_18,col_b_18\n"
      "val_38,num_38\n"
      "# row comment 38\n"
      "extra_38,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 18);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_39(void) {
  static const char input[] =
      "col_a_19,col_b_19\n"
      "val_39,num_39\n"
      "# row comment 39\n"
      "extra_39,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 19);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_40(void) {
  static const char input[] =
      "col_a_0,col_b_0\n"
      "val_40,num_40\n"
      "# row comment 40\n"
      "extra_40,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 0);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_41(void) {
  static const char input[] =
      "col_a_1,col_b_1\n"
      "val_41,num_41\n"
      "# row comment 41\n"
      "extra_41,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 1);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_42(void) {
  static const char input[] =
      "col_a_2,col_b_2\n"
      "val_42,num_42\n"
      "# row comment 42\n"
      "extra_42,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 2);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_43(void) {
  static const char input[] =
      "col_a_3,col_b_3\n"
      "val_43,num_43\n"
      "# row comment 43\n"
      "extra_43,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 3);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_44(void) {
  static const char input[] =
      "col_a_4,col_b_4\n"
      "val_44,num_44\n"
      "# row comment 44\n"
      "extra_44,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 4);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_45(void) {
  static const char input[] =
      "col_a_5,col_b_5\n"
      "val_45,num_45\n"
      "# row comment 45\n"
      "extra_45,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 5);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_46(void) {
  static const char input[] =
      "col_a_6,col_b_6\n"
      "val_46,num_46\n"
      "# row comment 46\n"
      "extra_46,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 6);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_47(void) {
  static const char input[] =
      "col_a_7,col_b_7\n"
      "val_47,num_47\n"
      "# row comment 47\n"
      "extra_47,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 7);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_48(void) {
  static const char input[] =
      "col_a_8,col_b_8\n"
      "val_48,num_48\n"
      "# row comment 48\n"
      "extra_48,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 8);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_49(void) {
  static const char input[] =
      "col_a_9,col_b_9\n"
      "val_49,num_49\n"
      "# row comment 49\n"
      "extra_49,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 9);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_50(void) {
  static const char input[] =
      "col_a_10,col_b_10\n"
      "val_50,num_50\n"
      "# row comment 50\n"
      "extra_50,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 10);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_51(void) {
  static const char input[] =
      "col_a_11,col_b_11\n"
      "val_51,num_51\n"
      "# row comment 51\n"
      "extra_51,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 11);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_52(void) {
  static const char input[] =
      "col_a_12,col_b_12\n"
      "val_52,num_52\n"
      "# row comment 52\n"
      "extra_52,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 12);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_53(void) {
  static const char input[] =
      "col_a_13,col_b_13\n"
      "val_53,num_53\n"
      "# row comment 53\n"
      "extra_53,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 13);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_54(void) {
  static const char input[] =
      "col_a_14,col_b_14\n"
      "val_54,num_54\n"
      "# row comment 54\n"
      "extra_54,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 14);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_55(void) {
  static const char input[] =
      "col_a_15,col_b_15\n"
      "val_55,num_55\n"
      "# row comment 55\n"
      "extra_55,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 15);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_56(void) {
  static const char input[] =
      "col_a_16,col_b_16\n"
      "val_56,num_56\n"
      "# row comment 56\n"
      "extra_56,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 16);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_57(void) {
  static const char input[] =
      "col_a_17,col_b_17\n"
      "val_57,num_57\n"
      "# row comment 57\n"
      "extra_57,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 17);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_58(void) {
  static const char input[] =
      "col_a_18,col_b_18\n"
      "val_58,num_58\n"
      "# row comment 58\n"
      "extra_58,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 18);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_59(void) {
  static const char input[] =
      "col_a_19,col_b_19\n"
      "val_59,num_59\n"
      "# row comment 59\n"
      "extra_59,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 19);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_60(void) {
  static const char input[] =
      "col_a_0,col_b_0\n"
      "val_60,num_60\n"
      "# row comment 60\n"
      "extra_60,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 0);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_61(void) {
  static const char input[] =
      "col_a_1,col_b_1\n"
      "val_61,num_61\n"
      "# row comment 61\n"
      "extra_61,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 1);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_62(void) {
  static const char input[] =
      "col_a_2,col_b_2\n"
      "val_62,num_62\n"
      "# row comment 62\n"
      "extra_62,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 2);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_63(void) {
  static const char input[] =
      "col_a_3,col_b_3\n"
      "val_63,num_63\n"
      "# row comment 63\n"
      "extra_63,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 3);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_64(void) {
  static const char input[] =
      "col_a_4,col_b_4\n"
      "val_64,num_64\n"
      "# row comment 64\n"
      "extra_64,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 4);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_65(void) {
  static const char input[] =
      "col_a_5,col_b_5\n"
      "val_65,num_65\n"
      "# row comment 65\n"
      "extra_65,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 5);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_66(void) {
  static const char input[] =
      "col_a_6,col_b_6\n"
      "val_66,num_66\n"
      "# row comment 66\n"
      "extra_66,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 6);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_67(void) {
  static const char input[] =
      "col_a_7,col_b_7\n"
      "val_67,num_67\n"
      "# row comment 67\n"
      "extra_67,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 7);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_68(void) {
  static const char input[] =
      "col_a_8,col_b_8\n"
      "val_68,num_68\n"
      "# row comment 68\n"
      "extra_68,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 8);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_69(void) {
  static const char input[] =
      "col_a_9,col_b_9\n"
      "val_69,num_69\n"
      "# row comment 69\n"
      "extra_69,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 9);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_70(void) {
  static const char input[] =
      "col_a_10,col_b_10\n"
      "val_70,num_70\n"
      "# row comment 70\n"
      "extra_70,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 10);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_71(void) {
  static const char input[] =
      "col_a_11,col_b_11\n"
      "val_71,num_71\n"
      "# row comment 71\n"
      "extra_71,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 11);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_72(void) {
  static const char input[] =
      "col_a_12,col_b_12\n"
      "val_72,num_72\n"
      "# row comment 72\n"
      "extra_72,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 12);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_73(void) {
  static const char input[] =
      "col_a_13,col_b_13\n"
      "val_73,num_73\n"
      "# row comment 73\n"
      "extra_73,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 13);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_74(void) {
  static const char input[] =
      "col_a_14,col_b_14\n"
      "val_74,num_74\n"
      "# row comment 74\n"
      "extra_74,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 14);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_75(void) {
  static const char input[] =
      "col_a_15,col_b_15\n"
      "val_75,num_75\n"
      "# row comment 75\n"
      "extra_75,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 15);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_76(void) {
  static const char input[] =
      "col_a_16,col_b_16\n"
      "val_76,num_76\n"
      "# row comment 76\n"
      "extra_76,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 16);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_77(void) {
  static const char input[] =
      "col_a_17,col_b_17\n"
      "val_77,num_77\n"
      "# row comment 77\n"
      "extra_77,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 17);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_78(void) {
  static const char input[] =
      "col_a_18,col_b_18\n"
      "val_78,num_78\n"
      "# row comment 78\n"
      "extra_78,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 18);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_79(void) {
  static const char input[] =
      "col_a_19,col_b_19\n"
      "val_79,num_79\n"
      "# row comment 79\n"
      "extra_79,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 19);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_80(void) {
  static const char input[] =
      "col_a_0,col_b_0\n"
      "val_80,num_80\n"
      "# row comment 80\n"
      "extra_80,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 0);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_81(void) {
  static const char input[] =
      "col_a_1,col_b_1\n"
      "val_81,num_81\n"
      "# row comment 81\n"
      "extra_81,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 1);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_82(void) {
  static const char input[] =
      "col_a_2,col_b_2\n"
      "val_82,num_82\n"
      "# row comment 82\n"
      "extra_82,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 2);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_83(void) {
  static const char input[] =
      "col_a_3,col_b_3\n"
      "val_83,num_83\n"
      "# row comment 83\n"
      "extra_83,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 3);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_84(void) {
  static const char input[] =
      "col_a_4,col_b_4\n"
      "val_84,num_84\n"
      "# row comment 84\n"
      "extra_84,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 4);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_85(void) {
  static const char input[] =
      "col_a_5,col_b_5\n"
      "val_85,num_85\n"
      "# row comment 85\n"
      "extra_85,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 5);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_86(void) {
  static const char input[] =
      "col_a_6,col_b_6\n"
      "val_86,num_86\n"
      "# row comment 86\n"
      "extra_86,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 6);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_87(void) {
  static const char input[] =
      "col_a_7,col_b_7\n"
      "val_87,num_87\n"
      "# row comment 87\n"
      "extra_87,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 7);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_88(void) {
  static const char input[] =
      "col_a_8,col_b_8\n"
      "val_88,num_88\n"
      "# row comment 88\n"
      "extra_88,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 8);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_89(void) {
  static const char input[] =
      "col_a_9,col_b_9\n"
      "val_89,num_89\n"
      "# row comment 89\n"
      "extra_89,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 9);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_90(void) {
  static const char input[] =
      "col_a_10,col_b_10\n"
      "val_90,num_90\n"
      "# row comment 90\n"
      "extra_90,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 10);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_91(void) {
  static const char input[] =
      "col_a_11,col_b_11\n"
      "val_91,num_91\n"
      "# row comment 91\n"
      "extra_91,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 11);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_92(void) {
  static const char input[] =
      "col_a_12,col_b_12\n"
      "val_92,num_92\n"
      "# row comment 92\n"
      "extra_92,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 12);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_93(void) {
  static const char input[] =
      "col_a_13,col_b_13\n"
      "val_93,num_93\n"
      "# row comment 93\n"
      "extra_93,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 13);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_94(void) {
  static const char input[] =
      "col_a_14,col_b_14\n"
      "val_94,num_94\n"
      "# row comment 94\n"
      "extra_94,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 14);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_95(void) {
  static const char input[] =
      "col_a_15,col_b_15\n"
      "val_95,num_95\n"
      "# row comment 95\n"
      "extra_95,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 15);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_96(void) {
  static const char input[] =
      "col_a_16,col_b_16\n"
      "val_96,num_96\n"
      "# row comment 96\n"
      "extra_96,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 16);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_97(void) {
  static const char input[] =
      "col_a_17,col_b_17\n"
      "val_97,num_97\n"
      "# row comment 97\n"
      "extra_97,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 17);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_98(void) {
  static const char input[] =
      "col_a_18,col_b_18\n"
      "val_98,num_98\n"
      "# row comment 98\n"
      "extra_98,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 18);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_99(void) {
  static const char input[] =
      "col_a_19,col_b_19\n"
      "val_99,num_99\n"
      "# row comment 99\n"
      "extra_99,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 19);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_100(void) {
  static const char input[] =
      "col_a_0,col_b_0\n"
      "val_100,num_100\n"
      "# row comment 100\n"
      "extra_100,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 0);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_101(void) {
  static const char input[] =
      "col_a_1,col_b_1\n"
      "val_101,num_101\n"
      "# row comment 101\n"
      "extra_101,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 1);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_102(void) {
  static const char input[] =
      "col_a_2,col_b_2\n"
      "val_102,num_102\n"
      "# row comment 102\n"
      "extra_102,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 2);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_103(void) {
  static const char input[] =
      "col_a_3,col_b_3\n"
      "val_103,num_103\n"
      "# row comment 103\n"
      "extra_103,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 3);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_104(void) {
  static const char input[] =
      "col_a_4,col_b_4\n"
      "val_104,num_104\n"
      "# row comment 104\n"
      "extra_104,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 4);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_105(void) {
  static const char input[] =
      "col_a_5,col_b_5\n"
      "val_105,num_105\n"
      "# row comment 105\n"
      "extra_105,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 5);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_106(void) {
  static const char input[] =
      "col_a_6,col_b_6\n"
      "val_106,num_106\n"
      "# row comment 106\n"
      "extra_106,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 6);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_107(void) {
  static const char input[] =
      "col_a_7,col_b_7\n"
      "val_107,num_107\n"
      "# row comment 107\n"
      "extra_107,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 7);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_108(void) {
  static const char input[] =
      "col_a_8,col_b_8\n"
      "val_108,num_108\n"
      "# row comment 108\n"
      "extra_108,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 8);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_109(void) {
  static const char input[] =
      "col_a_9,col_b_9\n"
      "val_109,num_109\n"
      "# row comment 109\n"
      "extra_109,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 9);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_110(void) {
  static const char input[] =
      "col_a_10,col_b_10\n"
      "val_110,num_110\n"
      "# row comment 110\n"
      "extra_110,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 10);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_111(void) {
  static const char input[] =
      "col_a_11,col_b_11\n"
      "val_111,num_111\n"
      "# row comment 111\n"
      "extra_111,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 11);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_112(void) {
  static const char input[] =
      "col_a_12,col_b_12\n"
      "val_112,num_112\n"
      "# row comment 112\n"
      "extra_112,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 12);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_113(void) {
  static const char input[] =
      "col_a_13,col_b_13\n"
      "val_113,num_113\n"
      "# row comment 113\n"
      "extra_113,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 13);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_114(void) {
  static const char input[] =
      "col_a_14,col_b_14\n"
      "val_114,num_114\n"
      "# row comment 114\n"
      "extra_114,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 14);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_115(void) {
  static const char input[] =
      "col_a_15,col_b_15\n"
      "val_115,num_115\n"
      "# row comment 115\n"
      "extra_115,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 15);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_116(void) {
  static const char input[] =
      "col_a_16,col_b_16\n"
      "val_116,num_116\n"
      "# row comment 116\n"
      "extra_116,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 16);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_117(void) {
  static const char input[] =
      "col_a_17,col_b_17\n"
      "val_117,num_117\n"
      "# row comment 117\n"
      "extra_117,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 17);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_118(void) {
  static const char input[] =
      "col_a_18,col_b_18\n"
      "val_118,num_118\n"
      "# row comment 118\n"
      "extra_118,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 18);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_119(void) {
  static const char input[] =
      "col_a_19,col_b_19\n"
      "val_119,num_119\n"
      "# row comment 119\n"
      "extra_119,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 19);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_120(void) {
  static const char input[] =
      "col_a_0,col_b_0\n"
      "val_120,num_120\n"
      "# row comment 120\n"
      "extra_120,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 0);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_121(void) {
  static const char input[] =
      "col_a_1,col_b_1\n"
      "val_121,num_121\n"
      "# row comment 121\n"
      "extra_121,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 1);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_122(void) {
  static const char input[] =
      "col_a_2,col_b_2\n"
      "val_122,num_122\n"
      "# row comment 122\n"
      "extra_122,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 2);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_123(void) {
  static const char input[] =
      "col_a_3,col_b_3\n"
      "val_123,num_123\n"
      "# row comment 123\n"
      "extra_123,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 3);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_124(void) {
  static const char input[] =
      "col_a_4,col_b_4\n"
      "val_124,num_124\n"
      "# row comment 124\n"
      "extra_124,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 4);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_125(void) {
  static const char input[] =
      "col_a_5,col_b_5\n"
      "val_125,num_125\n"
      "# row comment 125\n"
      "extra_125,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 5);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_126(void) {
  static const char input[] =
      "col_a_6,col_b_6\n"
      "val_126,num_126\n"
      "# row comment 126\n"
      "extra_126,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 6);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_127(void) {
  static const char input[] =
      "col_a_7,col_b_7\n"
      "val_127,num_127\n"
      "# row comment 127\n"
      "extra_127,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 7);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_128(void) {
  static const char input[] =
      "col_a_8,col_b_8\n"
      "val_128,num_128\n"
      "# row comment 128\n"
      "extra_128,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 8);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_129(void) {
  static const char input[] =
      "col_a_9,col_b_9\n"
      "val_129,num_129\n"
      "# row comment 129\n"
      "extra_129,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 9);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_130(void) {
  static const char input[] =
      "col_a_10,col_b_10\n"
      "val_130,num_130\n"
      "# row comment 130\n"
      "extra_130,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 10);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_131(void) {
  static const char input[] =
      "col_a_11,col_b_11\n"
      "val_131,num_131\n"
      "# row comment 131\n"
      "extra_131,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 11);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_132(void) {
  static const char input[] =
      "col_a_12,col_b_12\n"
      "val_132,num_132\n"
      "# row comment 132\n"
      "extra_132,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 12);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_133(void) {
  static const char input[] =
      "col_a_13,col_b_13\n"
      "val_133,num_133\n"
      "# row comment 133\n"
      "extra_133,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 13);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_134(void) {
  static const char input[] =
      "col_a_14,col_b_14\n"
      "val_134,num_134\n"
      "# row comment 134\n"
      "extra_134,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 14);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_135(void) {
  static const char input[] =
      "col_a_15,col_b_15\n"
      "val_135,num_135\n"
      "# row comment 135\n"
      "extra_135,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 15);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_136(void) {
  static const char input[] =
      "col_a_16,col_b_16\n"
      "val_136,num_136\n"
      "# row comment 136\n"
      "extra_136,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 16);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_137(void) {
  static const char input[] =
      "col_a_17,col_b_17\n"
      "val_137,num_137\n"
      "# row comment 137\n"
      "extra_137,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 17);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_138(void) {
  static const char input[] =
      "col_a_18,col_b_18\n"
      "val_138,num_138\n"
      "# row comment 138\n"
      "extra_138,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 18);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_139(void) {
  static const char input[] =
      "col_a_19,col_b_19\n"
      "val_139,num_139\n"
      "# row comment 139\n"
      "extra_139,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 19);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_140(void) {
  static const char input[] =
      "col_a_0,col_b_0\n"
      "val_140,num_140\n"
      "# row comment 140\n"
      "extra_140,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 0);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_141(void) {
  static const char input[] =
      "col_a_1,col_b_1\n"
      "val_141,num_141\n"
      "# row comment 141\n"
      "extra_141,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 1);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_142(void) {
  static const char input[] =
      "col_a_2,col_b_2\n"
      "val_142,num_142\n"
      "# row comment 142\n"
      "extra_142,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 2);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_143(void) {
  static const char input[] =
      "col_a_3,col_b_3\n"
      "val_143,num_143\n"
      "# row comment 143\n"
      "extra_143,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 3);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_144(void) {
  static const char input[] =
      "col_a_4,col_b_4\n"
      "val_144,num_144\n"
      "# row comment 144\n"
      "extra_144,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 4);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_145(void) {
  static const char input[] =
      "col_a_5,col_b_5\n"
      "val_145,num_145\n"
      "# row comment 145\n"
      "extra_145,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 5);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_146(void) {
  static const char input[] =
      "col_a_6,col_b_6\n"
      "val_146,num_146\n"
      "# row comment 146\n"
      "extra_146,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 6);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_147(void) {
  static const char input[] =
      "col_a_7,col_b_7\n"
      "val_147,num_147\n"
      "# row comment 147\n"
      "extra_147,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 7);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_148(void) {
  static const char input[] =
      "col_a_8,col_b_8\n"
      "val_148,num_148\n"
      "# row comment 148\n"
      "extra_148,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 8);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_149(void) {
  static const char input[] =
      "col_a_9,col_b_9\n"
      "val_149,num_149\n"
      "# row comment 149\n"
      "extra_149,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 9);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_150(void) {
  static const char input[] =
      "col_a_10,col_b_10\n"
      "val_150,num_150\n"
      "# row comment 150\n"
      "extra_150,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 10);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_151(void) {
  static const char input[] =
      "col_a_11,col_b_11\n"
      "val_151,num_151\n"
      "# row comment 151\n"
      "extra_151,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 11);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_152(void) {
  static const char input[] =
      "col_a_12,col_b_12\n"
      "val_152,num_152\n"
      "# row comment 152\n"
      "extra_152,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 12);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_153(void) {
  static const char input[] =
      "col_a_13,col_b_13\n"
      "val_153,num_153\n"
      "# row comment 153\n"
      "extra_153,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 13);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_154(void) {
  static const char input[] =
      "col_a_14,col_b_14\n"
      "val_154,num_154\n"
      "# row comment 154\n"
      "extra_154,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 14);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_155(void) {
  static const char input[] =
      "col_a_15,col_b_15\n"
      "val_155,num_155\n"
      "# row comment 155\n"
      "extra_155,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 15);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_156(void) {
  static const char input[] =
      "col_a_16,col_b_16\n"
      "val_156,num_156\n"
      "# row comment 156\n"
      "extra_156,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 16);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_157(void) {
  static const char input[] =
      "col_a_17,col_b_17\n"
      "val_157,num_157\n"
      "# row comment 157\n"
      "extra_157,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 17);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_158(void) {
  static const char input[] =
      "col_a_18,col_b_18\n"
      "val_158,num_158\n"
      "# row comment 158\n"
      "extra_158,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 18);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_159(void) {
  static const char input[] =
      "col_a_19,col_b_19\n"
      "val_159,num_159\n"
      "# row comment 159\n"
      "extra_159,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 19);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_160(void) {
  static const char input[] =
      "col_a_0,col_b_0\n"
      "val_160,num_160\n"
      "# row comment 160\n"
      "extra_160,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 0);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_161(void) {
  static const char input[] =
      "col_a_1,col_b_1\n"
      "val_161,num_161\n"
      "# row comment 161\n"
      "extra_161,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 1);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_162(void) {
  static const char input[] =
      "col_a_2,col_b_2\n"
      "val_162,num_162\n"
      "# row comment 162\n"
      "extra_162,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 2);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_163(void) {
  static const char input[] =
      "col_a_3,col_b_3\n"
      "val_163,num_163\n"
      "# row comment 163\n"
      "extra_163,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 3);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_164(void) {
  static const char input[] =
      "col_a_4,col_b_4\n"
      "val_164,num_164\n"
      "# row comment 164\n"
      "extra_164,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 4);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_165(void) {
  static const char input[] =
      "col_a_5,col_b_5\n"
      "val_165,num_165\n"
      "# row comment 165\n"
      "extra_165,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 5);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_166(void) {
  static const char input[] =
      "col_a_6,col_b_6\n"
      "val_166,num_166\n"
      "# row comment 166\n"
      "extra_166,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 6);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_167(void) {
  static const char input[] =
      "col_a_7,col_b_7\n"
      "val_167,num_167\n"
      "# row comment 167\n"
      "extra_167,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 7);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_168(void) {
  static const char input[] =
      "col_a_8,col_b_8\n"
      "val_168,num_168\n"
      "# row comment 168\n"
      "extra_168,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 8);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_169(void) {
  static const char input[] =
      "col_a_9,col_b_9\n"
      "val_169,num_169\n"
      "# row comment 169\n"
      "extra_169,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 9);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_170(void) {
  static const char input[] =
      "col_a_10,col_b_10\n"
      "val_170,num_170\n"
      "# row comment 170\n"
      "extra_170,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 10);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_171(void) {
  static const char input[] =
      "col_a_11,col_b_11\n"
      "val_171,num_171\n"
      "# row comment 171\n"
      "extra_171,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 11);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_172(void) {
  static const char input[] =
      "col_a_12,col_b_12\n"
      "val_172,num_172\n"
      "# row comment 172\n"
      "extra_172,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 12);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_173(void) {
  static const char input[] =
      "col_a_13,col_b_13\n"
      "val_173,num_173\n"
      "# row comment 173\n"
      "extra_173,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 13);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_174(void) {
  static const char input[] =
      "col_a_14,col_b_14\n"
      "val_174,num_174\n"
      "# row comment 174\n"
      "extra_174,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 14);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_175(void) {
  static const char input[] =
      "col_a_15,col_b_15\n"
      "val_175,num_175\n"
      "# row comment 175\n"
      "extra_175,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 15);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_176(void) {
  static const char input[] =
      "col_a_16,col_b_16\n"
      "val_176,num_176\n"
      "# row comment 176\n"
      "extra_176,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 16);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_177(void) {
  static const char input[] =
      "col_a_17,col_b_17\n"
      "val_177,num_177\n"
      "# row comment 177\n"
      "extra_177,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 17);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_178(void) {
  static const char input[] =
      "col_a_18,col_b_18\n"
      "val_178,num_178\n"
      "# row comment 178\n"
      "extra_178,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 18);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_179(void) {
  static const char input[] =
      "col_a_19,col_b_19\n"
      "val_179,num_179\n"
      "# row comment 179\n"
      "extra_179,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 19);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_180(void) {
  static const char input[] =
      "col_a_0,col_b_0\n"
      "val_180,num_180\n"
      "# row comment 180\n"
      "extra_180,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 0);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_181(void) {
  static const char input[] =
      "col_a_1,col_b_1\n"
      "val_181,num_181\n"
      "# row comment 181\n"
      "extra_181,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 1);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_182(void) {
  static const char input[] =
      "col_a_2,col_b_2\n"
      "val_182,num_182\n"
      "# row comment 182\n"
      "extra_182,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 2);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_183(void) {
  static const char input[] =
      "col_a_3,col_b_3\n"
      "val_183,num_183\n"
      "# row comment 183\n"
      "extra_183,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 3);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_184(void) {
  static const char input[] =
      "col_a_4,col_b_4\n"
      "val_184,num_184\n"
      "# row comment 184\n"
      "extra_184,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 4);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_185(void) {
  static const char input[] =
      "col_a_5,col_b_5\n"
      "val_185,num_185\n"
      "# row comment 185\n"
      "extra_185,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 5);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_186(void) {
  static const char input[] =
      "col_a_6,col_b_6\n"
      "val_186,num_186\n"
      "# row comment 186\n"
      "extra_186,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 6);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_187(void) {
  static const char input[] =
      "col_a_7,col_b_7\n"
      "val_187,num_187\n"
      "# row comment 187\n"
      "extra_187,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 7);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_188(void) {
  static const char input[] =
      "col_a_8,col_b_8\n"
      "val_188,num_188\n"
      "# row comment 188\n"
      "extra_188,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 8);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_189(void) {
  static const char input[] =
      "col_a_9,col_b_9\n"
      "val_189,num_189\n"
      "# row comment 189\n"
      "extra_189,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 9);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_190(void) {
  static const char input[] =
      "col_a_10,col_b_10\n"
      "val_190,num_190\n"
      "# row comment 190\n"
      "extra_190,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 10);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_191(void) {
  static const char input[] =
      "col_a_11,col_b_11\n"
      "val_191,num_191\n"
      "# row comment 191\n"
      "extra_191,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 11);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_192(void) {
  static const char input[] =
      "col_a_12,col_b_12\n"
      "val_192,num_192\n"
      "# row comment 192\n"
      "extra_192,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 12);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_193(void) {
  static const char input[] =
      "col_a_13,col_b_13\n"
      "val_193,num_193\n"
      "# row comment 193\n"
      "extra_193,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 13);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_194(void) {
  static const char input[] =
      "col_a_14,col_b_14\n"
      "val_194,num_194\n"
      "# row comment 194\n"
      "extra_194,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 14);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_195(void) {
  static const char input[] =
      "col_a_15,col_b_15\n"
      "val_195,num_195\n"
      "# row comment 195\n"
      "extra_195,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 15);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_196(void) {
  static const char input[] =
      "col_a_16,col_b_16\n"
      "val_196,num_196\n"
      "# row comment 196\n"
      "extra_196,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 16);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_197(void) {
  static const char input[] =
      "col_a_17,col_b_17\n"
      "val_197,num_197\n"
      "# row comment 197\n"
      "extra_197,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 17);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_198(void) {
  static const char input[] =
      "col_a_18,col_b_18\n"
      "val_198,num_198\n"
      "# row comment 198\n"
      "extra_198,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 18);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}

static void test_case_199(void) {
  static const char input[] =
      "col_a_19,col_b_19\n"
      "val_199,num_199\n"
      "# row comment 199\n"
      "extra_199,yes\n";
  csvpack_options_t opt;
  csvpack_options_init(&opt);
  csvpack_table_t *tbl = NULL;
  csvpack_error_t *err = NULL;
  expect_ok(__LINE__, csvpack_parse_memory((const uint8_t *)input, strlen(input),
                                           &opt, &tbl, &err));
  if (tbl) {
    char col[32];
    snprintf(col, sizeof(col), "col_a_%d", 19);
    const char *v = csvpack_cell_by_column(tbl, 1, col, NULL);
    if (v) {
      expect_int(__LINE__, "len", (int)strlen(v) > 0, 1);
    }
    uint8_t *out = NULL;
    size_t out_len = 0;
    expect_ok(__LINE__, csvpack_serialize_table(tbl, &out, &out_len));
    free(out);
    csvpack_table_destroy(tbl);
  }
  csvpack_error_free(err);
}
static void test_case_0(void);
static void test_case_1(void);
static void test_case_2(void);
static void test_case_3(void);
static void test_case_4(void);
static void test_case_5(void);
static void test_case_6(void);
static void test_case_7(void);
static void test_case_8(void);
static void test_case_9(void);
static void test_case_10(void);
static void test_case_11(void);
static void test_case_12(void);
static void test_case_13(void);
static void test_case_14(void);
static void test_case_15(void);
static void test_case_16(void);
static void test_case_17(void);
static void test_case_18(void);
static void test_case_19(void);
static void test_case_20(void);
static void test_case_21(void);
static void test_case_22(void);
static void test_case_23(void);
static void test_case_24(void);
static void test_case_25(void);
static void test_case_26(void);
static void test_case_27(void);
static void test_case_28(void);
static void test_case_29(void);
static void test_case_30(void);
static void test_case_31(void);
static void test_case_32(void);
static void test_case_33(void);
static void test_case_34(void);
static void test_case_35(void);
static void test_case_36(void);
static void test_case_37(void);
static void test_case_38(void);
static void test_case_39(void);
static void test_case_40(void);
static void test_case_41(void);
static void test_case_42(void);
static void test_case_43(void);
static void test_case_44(void);
static void test_case_45(void);
static void test_case_46(void);
static void test_case_47(void);
static void test_case_48(void);
static void test_case_49(void);
static void test_case_50(void);
static void test_case_51(void);
static void test_case_52(void);
static void test_case_53(void);
static void test_case_54(void);
static void test_case_55(void);
static void test_case_56(void);
static void test_case_57(void);
static void test_case_58(void);
static void test_case_59(void);
static void test_case_60(void);
static void test_case_61(void);
static void test_case_62(void);
static void test_case_63(void);
static void test_case_64(void);
static void test_case_65(void);
static void test_case_66(void);
static void test_case_67(void);
static void test_case_68(void);
static void test_case_69(void);
static void test_case_70(void);
static void test_case_71(void);
static void test_case_72(void);
static void test_case_73(void);
static void test_case_74(void);
static void test_case_75(void);
static void test_case_76(void);
static void test_case_77(void);
static void test_case_78(void);
static void test_case_79(void);
static void test_case_80(void);
static void test_case_81(void);
static void test_case_82(void);
static void test_case_83(void);
static void test_case_84(void);
static void test_case_85(void);
static void test_case_86(void);
static void test_case_87(void);
static void test_case_88(void);
static void test_case_89(void);
static void test_case_90(void);
static void test_case_91(void);
static void test_case_92(void);
static void test_case_93(void);
static void test_case_94(void);
static void test_case_95(void);
static void test_case_96(void);
static void test_case_97(void);
static void test_case_98(void);
static void test_case_99(void);
static void test_case_100(void);
static void test_case_101(void);
static void test_case_102(void);
static void test_case_103(void);
static void test_case_104(void);
static void test_case_105(void);
static void test_case_106(void);
static void test_case_107(void);
static void test_case_108(void);
static void test_case_109(void);
static void test_case_110(void);
static void test_case_111(void);
static void test_case_112(void);
static void test_case_113(void);
static void test_case_114(void);
static void test_case_115(void);
static void test_case_116(void);
static void test_case_117(void);
static void test_case_118(void);
static void test_case_119(void);
static void test_case_120(void);
static void test_case_121(void);
static void test_case_122(void);
static void test_case_123(void);
static void test_case_124(void);
static void test_case_125(void);
static void test_case_126(void);
static void test_case_127(void);
static void test_case_128(void);
static void test_case_129(void);
static void test_case_130(void);
static void test_case_131(void);
static void test_case_132(void);
static void test_case_133(void);
static void test_case_134(void);
static void test_case_135(void);
static void test_case_136(void);
static void test_case_137(void);
static void test_case_138(void);
static void test_case_139(void);
static void test_case_140(void);
static void test_case_141(void);
static void test_case_142(void);
static void test_case_143(void);
static void test_case_144(void);
static void test_case_145(void);
static void test_case_146(void);
static void test_case_147(void);
static void test_case_148(void);
static void test_case_149(void);
static void test_case_150(void);
static void test_case_151(void);
static void test_case_152(void);
static void test_case_153(void);
static void test_case_154(void);
static void test_case_155(void);
static void test_case_156(void);
static void test_case_157(void);
static void test_case_158(void);
static void test_case_159(void);
static void test_case_160(void);
static void test_case_161(void);
static void test_case_162(void);
static void test_case_163(void);
static void test_case_164(void);
static void test_case_165(void);
static void test_case_166(void);
static void test_case_167(void);
static void test_case_168(void);
static void test_case_169(void);
static void test_case_170(void);
static void test_case_171(void);
static void test_case_172(void);
static void test_case_173(void);
static void test_case_174(void);
static void test_case_175(void);
static void test_case_176(void);
static void test_case_177(void);
static void test_case_178(void);
static void test_case_179(void);
static void test_case_180(void);
static void test_case_181(void);
static void test_case_182(void);
static void test_case_183(void);
static void test_case_184(void);
static void test_case_185(void);
static void test_case_186(void);
static void test_case_187(void);
static void test_case_188(void);
static void test_case_189(void);
static void test_case_190(void);
static void test_case_191(void);
static void test_case_192(void);
static void test_case_193(void);
static void test_case_194(void);
static void test_case_195(void);
static void test_case_196(void);
static void test_case_197(void);
static void test_case_198(void);
static void test_case_199(void);

int main(void) {
  test_case_0();
  test_case_1();
  test_case_2();
  test_case_3();
  test_case_4();
  test_case_5();
  test_case_6();
  test_case_7();
  test_case_8();
  test_case_9();
  test_case_10();
  test_case_11();
  test_case_12();
  test_case_13();
  test_case_14();
  test_case_15();
  test_case_16();
  test_case_17();
  test_case_18();
  test_case_19();
  test_case_20();
  test_case_21();
  test_case_22();
  test_case_23();
  test_case_24();
  test_case_25();
  test_case_26();
  test_case_27();
  test_case_28();
  test_case_29();
  test_case_30();
  test_case_31();
  test_case_32();
  test_case_33();
  test_case_34();
  test_case_35();
  test_case_36();
  test_case_37();
  test_case_38();
  test_case_39();
  test_case_40();
  test_case_41();
  test_case_42();
  test_case_43();
  test_case_44();
  test_case_45();
  test_case_46();
  test_case_47();
  test_case_48();
  test_case_49();
  test_case_50();
  test_case_51();
  test_case_52();
  test_case_53();
  test_case_54();
  test_case_55();
  test_case_56();
  test_case_57();
  test_case_58();
  test_case_59();
  test_case_60();
  test_case_61();
  test_case_62();
  test_case_63();
  test_case_64();
  test_case_65();
  test_case_66();
  test_case_67();
  test_case_68();
  test_case_69();
  test_case_70();
  test_case_71();
  test_case_72();
  test_case_73();
  test_case_74();
  test_case_75();
  test_case_76();
  test_case_77();
  test_case_78();
  test_case_79();
  test_case_80();
  test_case_81();
  test_case_82();
  test_case_83();
  test_case_84();
  test_case_85();
  test_case_86();
  test_case_87();
  test_case_88();
  test_case_89();
  test_case_90();
  test_case_91();
  test_case_92();
  test_case_93();
  test_case_94();
  test_case_95();
  test_case_96();
  test_case_97();
  test_case_98();
  test_case_99();
  test_case_100();
  test_case_101();
  test_case_102();
  test_case_103();
  test_case_104();
  test_case_105();
  test_case_106();
  test_case_107();
  test_case_108();
  test_case_109();
  test_case_110();
  test_case_111();
  test_case_112();
  test_case_113();
  test_case_114();
  test_case_115();
  test_case_116();
  test_case_117();
  test_case_118();
  test_case_119();
  test_case_120();
  test_case_121();
  test_case_122();
  test_case_123();
  test_case_124();
  test_case_125();
  test_case_126();
  test_case_127();
  test_case_128();
  test_case_129();
  test_case_130();
  test_case_131();
  test_case_132();
  test_case_133();
  test_case_134();
  test_case_135();
  test_case_136();
  test_case_137();
  test_case_138();
  test_case_139();
  test_case_140();
  test_case_141();
  test_case_142();
  test_case_143();
  test_case_144();
  test_case_145();
  test_case_146();
  test_case_147();
  test_case_148();
  test_case_149();
  test_case_150();
  test_case_151();
  test_case_152();
  test_case_153();
  test_case_154();
  test_case_155();
  test_case_156();
  test_case_157();
  test_case_158();
  test_case_159();
  test_case_160();
  test_case_161();
  test_case_162();
  test_case_163();
  test_case_164();
  test_case_165();
  test_case_166();
  test_case_167();
  test_case_168();
  test_case_169();
  test_case_170();
  test_case_171();
  test_case_172();
  test_case_173();
  test_case_174();
  test_case_175();
  test_case_176();
  test_case_177();
  test_case_178();
  test_case_179();
  test_case_180();
  test_case_181();
  test_case_182();
  test_case_183();
  test_case_184();
  test_case_185();
  test_case_186();
  test_case_187();
  test_case_188();
  test_case_189();
  test_case_190();
  test_case_191();
  test_case_192();
  test_case_193();
  test_case_194();
  test_case_195();
  test_case_196();
  test_case_197();
  test_case_198();
  test_case_199();
  return g_failures ? 1 : 0;
}
