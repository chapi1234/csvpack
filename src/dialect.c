#define _GNU_SOURCE
#include "internal.h"
#include <stdio.h>
#include <string.h>

typedef struct csvpack_dialect_node {
  char *name;
  csvpack_options_t opt;
  struct csvpack_dialect_node *next;
} csvpack_dialect_node_t;

static csvpack_dialect_node_t *g_dialects = NULL;

csvpack_status_t csvpack_dialect_register(const char *name, char delimiter) {
  if (!name || !name[0]) return CSVPACK_ERR_SYNTAX;
  csvpack_dialect_node_t *node =
      (csvpack_dialect_node_t *)malloc(sizeof(csvpack_dialect_node_t));
  if (!node) return CSVPACK_ERR_MEMORY;
  node->name = strdup(name);
  if (!node->name) {
    free(node);
    return CSVPACK_ERR_MEMORY;
  }
  csvpack_options_init(&node->opt);
  node->opt.delimiter = delimiter;
  node->next = g_dialects;
  g_dialects = node;
  return CSVPACK_OK;
}

const csvpack_options_t *csvpack_dialect_lookup(const char *name) {
  for (csvpack_dialect_node_t *n = g_dialects; n; n = n->next) {
    if (strcmp(n->name, name) == 0) return &n->opt;
  }
  return NULL;
}

void csvpack_dialect_clear(void) {
  while (g_dialects) {
    csvpack_dialect_node_t *n = g_dialects;
    g_dialects = n->next;
    free(n->name);
    free(n);
  }
}
