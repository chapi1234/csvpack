#include "internal.h"

static int push_chunk_frame(csvpack_table_t *tbl, const char *path, size_t n,
                            const char *parent) {
  if (!tbl || !path || n == 0) return 0;
  if (tbl->chunk_frame_count == tbl->chunk_frame_cap) {
    size_t nc = tbl->chunk_frame_cap ? tbl->chunk_frame_cap * 2 : 4;
    csvpack_chunk_frame_t *nb =
        (csvpack_chunk_frame_t *)realloc(tbl->chunk_frames, nc * sizeof(*nb));
    if (!nb) return 0;
    tbl->chunk_frames = nb;
    tbl->chunk_frame_cap = nc;
  }
  csvpack_chunk_frame_t *fr = &tbl->chunk_frames[tbl->chunk_frame_count++];
  fr->path = (char *)malloc(n + 1);
  if (!fr->path) {
    tbl->chunk_frame_count--;
    return 0;
  }
  memcpy(fr->path, path, n);
  fr->path[n] = '\0';
  fr->parent_row = parent ? strdup(parent) : strdup("");
  if (!fr->parent_row) {
    free(fr->path);
    fr->path = NULL;
    tbl->chunk_frame_count--;
    return 0;
  }
  return 1;
}

void csvpack_chunk_teardown(csvpack_table_t *tbl) {
  if (!tbl) return;
  for (size_t i = 0; i < tbl->chunk_frame_count; i++) {
    free(tbl->chunk_frames[i].path);
    free(tbl->chunk_frames[i].parent_row);
  }
  free(tbl->chunk_frames);
  tbl->chunk_frames = NULL;
  tbl->chunk_frame_count = 0;
  tbl->chunk_frame_cap = 0;
}

csvpack_status_t csvpack_handle_chunk(csvpack_parser_t *p, csvpack_slice_t path) {
  if (!p || !p->read_fn) return CSVPACK_ERR_CHUNK;
  if (p->depth >= p->opt.max_chunk_depth) return CSVPACK_ERR_DEPTH;
  char pathbuf[512];
  if (path.len >= sizeof(pathbuf)) return CSVPACK_ERR_CHUNK;
  memcpy(pathbuf, path.data, path.len);
  pathbuf[path.len] = '\0';
  const char *parent = (p->tbl->count > 0) ? "root" : "";
  if (!push_chunk_frame(p->tbl, pathbuf, path.len, parent)) return CSVPACK_ERR_MEMORY;

  uint8_t ibuf[65536];
  size_t n = p->read_fn(p->read_ctx, pathbuf, ibuf, sizeof(ibuf));
  if (n == 0) return CSVPACK_ERR_CHUNK;

  csvpack_parser_t sub;
  memset(&sub, 0, sizeof(sub));
  csvpack_scanner_init(&sub.scan, ibuf, n);
  sub.opt = p->opt;
  sub.tbl = p->tbl;
  sub.read_fn = p->read_fn;
  sub.read_ctx = p->read_ctx;
  sub.depth = p->depth + 1;
  return csvpack_parser_run(&sub);
}
