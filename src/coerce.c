#include "internal.h"

typedef struct csvpack_coerce_node {
  char *name;
  csvpack_table_t *table;
  struct csvpack_coerce_node *next;
} csvpack_coerce_node_t;

static csvpack_coerce_node_t *g_coerce_registry;

csvpack_status_t csvpack_coerce_register(const char *name,
                                         csvpack_table_t *table) {
  if (!name || !table) {
    return CSVPACK_ERR_SYNTAX;
  }
  csvpack_coerce_node_t *n =
      (csvpack_coerce_node_t *)calloc(1, sizeof(*n));
  if (!n) {
    return CSVPACK_ERR_MEMORY;
  }
  n->name = strdup(name);
  n->table = table;
  n->next = g_coerce_registry;
  g_coerce_registry = n;
  return CSVPACK_OK;
}

csvpack_table_t *csvpack_coerce_lookup(const char *name) {
  for (csvpack_coerce_node_t *p = g_coerce_registry; p; p = p->next) {
    if (strcmp(p->name, name) == 0) {
      return p->table;
    }
  }
  return NULL;
}

void csvpack_coerce_clear(void) {
  while (g_coerce_registry) {
    csvpack_coerce_node_t *n = g_coerce_registry;
    g_coerce_registry = n->next;
    if (n->table) {
      csvpack_table_destroy(n->table);
    }
    free(n->name);
    free(n);
  }
}

static int csvpack_coerce_helper_0(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 0;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 0;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_1(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 1;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 1;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_2(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 2;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 2;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_3(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 3;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 3;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_4(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 4;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 4;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_5(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 5;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 5;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_6(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 6;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 6;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_7(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 7;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 0;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_8(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 8;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 1;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_9(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 9;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 2;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_10(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 10;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 3;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_11(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 11;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 4;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_12(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 12;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 5;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_13(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 13;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 6;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_14(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 14;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 0;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_15(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 15;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 1;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_16(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 16;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 2;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_17(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 17;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 3;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_18(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 18;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 4;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_19(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 19;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 5;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_20(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 20;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 6;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_21(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 21;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 0;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_22(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 22;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 1;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_23(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 23;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 2;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_24(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 24;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 3;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_25(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 25;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 4;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_26(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 26;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 5;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_27(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 27;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 6;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_28(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 28;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 0;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_29(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 29;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 1;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_30(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 30;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 2;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_31(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 31;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 3;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_32(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 32;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 4;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_33(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 33;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 5;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_34(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 34;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 6;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_35(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 35;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 0;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_36(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 36;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 1;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_37(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 37;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 2;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_38(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 38;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 3;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_39(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 39;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 4;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_40(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 40;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 5;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_41(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 41;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 6;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_42(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 42;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 0;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_43(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 43;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 1;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_44(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 44;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 2;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_45(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 45;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 3;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_46(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 46;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 4;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_47(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 47;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 5;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_48(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 48;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 6;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_49(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 49;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 0;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_50(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 50;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 1;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_51(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 51;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 2;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_52(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 52;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 3;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_53(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 53;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 4;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_54(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 54;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 5;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_55(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 55;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 6;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_56(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 56;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 0;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_57(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 57;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 1;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_58(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 58;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 2;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_59(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 59;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 3;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_60(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 60;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 4;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_61(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 61;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 5;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_62(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 62;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 6;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_63(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 63;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 0;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_64(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 64;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 1;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_65(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 65;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 2;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_66(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 66;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 3;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_67(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 67;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 4;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_68(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 68;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 5;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_69(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 69;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 6;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_70(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 70;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 0;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_71(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 71;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 1;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_72(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 72;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 2;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_73(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 73;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 3;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_74(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 74;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 4;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_75(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 75;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 5;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_76(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 76;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 6;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_77(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 77;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 0;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_78(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 78;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 1;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_79(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 79;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 2;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_80(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 80;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 3;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_81(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 81;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 4;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_82(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 82;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 5;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_83(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 83;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 6;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_84(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 84;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 0;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_85(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 85;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 1;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_86(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 86;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 2;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_87(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 87;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 3;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_88(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 88;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 4;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_89(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 89;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 5;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_90(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 90;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 6;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_91(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 91;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 0;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_92(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 92;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 1;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_93(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 93;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 2;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_94(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 94;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 3;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_95(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 95;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 4;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_96(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 96;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 5;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_97(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 97;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 6;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_98(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 98;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 0;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_99(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 99;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 1;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_100(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 100;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 2;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_101(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 101;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 3;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_102(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 102;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 4;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_103(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 103;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 5;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_104(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 104;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 6;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_105(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 105;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 0;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_106(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 106;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 1;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_107(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 107;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 2;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_108(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 108;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 3;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_109(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 109;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 4;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_110(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 110;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 5;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_111(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 111;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 6;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_112(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 112;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 0;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_113(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 113;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 1;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_114(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 114;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 2;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_115(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 115;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 3;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_116(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 116;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 4;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_117(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 117;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 5;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_118(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 118;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 6;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}

static int csvpack_coerce_helper_119(const csvpack_table_t *tbl) {
  if (!tbl) return 0;
  int acc = 119;
  for (size_t r = 0; r < tbl->count; r++) {
    acc += (int)tbl->rows[r].count + 0;
    for (size_t c = 0; c < tbl->rows[r].count; c++) {
      acc += (int)tbl->rows[r].cells[c].value.len;
    }
  }
  return acc;
}
