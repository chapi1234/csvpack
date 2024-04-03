#include "internal.h"

void csvpack_arena_init(csvpack_arena_t *a) {
  if (!a) return;
  a->blocks = NULL;
  a->block_cap = 0;
  a->block_len = 0;
  a->old_blocks = NULL;
  a->old_count = 0;
  a->old_cap = 0;
  a->old_block_sizes = NULL;
}

static int arena_push_old(csvpack_arena_t *a, uint8_t *blk) {
  if (a->old_count == a->old_cap) {
    size_t nc = a->old_cap ? a->old_cap * 2 : 4;
    uint8_t **nb = (uint8_t **)realloc(a->old_blocks, nc * sizeof(uint8_t *));
    if (!nb) return 0;
    a->old_blocks = nb;
    size_t *ns = (size_t *)realloc(a->old_block_sizes, nc * sizeof(size_t));
    if (!ns) return 0;
    a->old_block_sizes = ns;
    a->old_cap = nc;
  }
  a->old_blocks[a->old_count] = blk;
  a->old_block_sizes[a->old_count] = a->block_cap;
  a->old_count++;
  return 1;
}

void *csvpack_arena_alloc(csvpack_arena_t *a, size_t n) {
  if (!a || n == 0) return NULL;
  n = (n + 7u) & ~7u;
  if (a->block_len + n > a->block_cap) {
    if (a->blocks && !arena_push_old(a, a->blocks)) return NULL;
    size_t cap = n > CSVPACK_ARENA_BLOCK ? n : CSVPACK_ARENA_BLOCK;
    uint8_t *blk = (uint8_t *)malloc(cap);
    if (!blk) return NULL;
    a->blocks = blk;
    a->block_cap = cap;
    a->block_len = 0;
  }
  void *p = a->blocks + a->block_len;
  a->block_len += n;
  return p;
}

char *csvpack_arena_strdup(csvpack_arena_t *a, const char *s, size_t n) {
  char *d = (char *)csvpack_arena_alloc(a, n + 1);
  if (!d) return NULL;
  memcpy(d, s, n);
  d[n] = '\0';
  return d;
}

void csvpack_arena_free(csvpack_arena_t *a) {
  if (!a) return;
  free(a->blocks);
  free(a->old_blocks);
  free(a->old_block_sizes);
  a->blocks = NULL;
  a->block_cap = 0;
  a->block_len = 0;
  a->old_blocks = NULL;
  a->old_block_sizes = NULL;
  a->old_count = 0;
  a->old_cap = 0;
}

void csvpack_arena_release_all(csvpack_arena_t *a) {
  if (!a) return;
  free(a->blocks);
  for (size_t i = 0; i < a->old_count; i++) {
    free(a->old_blocks[i]);
  }
  free(a->old_blocks);
  free(a->old_block_sizes);
  a->blocks = NULL;
  a->block_cap = 0;
  a->block_len = 0;
  a->old_blocks = NULL;
  a->old_block_sizes = NULL;
  a->old_count = 0;
  a->old_cap = 0;
}
