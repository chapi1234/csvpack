#!/usr/bin/env python3
"""Generate reference fix patches from the current buggy tree."""
from __future__ import annotations

import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SUBMIT = ROOT / "poc" / "submit"

# Each entry: (patch_filename, list of (file, old_text, new_text))
FIXES: list[tuple[str, list[tuple[str, str, str]]]] = [
    (
        "bug1_quoted_continuation_probe.patch",
        [
            (
                "src/split.c",
                """      if (!closed) {
        if (*count > 0) {
          csvpack_split_quote_continuation_probe(s, *count);
        }
        return CSVPACK_ERR_SYNTAX;""",
                """      if (!closed) {
        return CSVPACK_ERR_SYNTAX;""",
            ),
        ],
    ),
    (
        "bug2_multi_record_gap_witness.patch",
        [
            (
                "src/parse.c",
                """  if (p->tbl->count >= 2 && csvpack_scanner_peek(&p->scan) < 0) {
    csvpack_parser_record_gap_witness(&p->scan, p->tbl->count);
  }
  return CSVPACK_OK;""",
                """  return CSVPACK_OK;""",
            ),
        ],
    ),
    (
        "bug3_narrow_row_header_stride.patch",
        [
            (
                "src/row.c",
                """  if (tbl->has_header && row != &tbl->rows[0] &&
      row->count < tbl->rows[0].count && tbl->rows[0].count <= 16) {
    size_t bound = tbl->rows[0].count;
    for (size_t i = 0; i < bound; i++) {
      if (i >= row->count) {
        char width[4];
        memcpy(width, row->cells[i].value.data, sizeof(width));
        (void)width[0];
        break;
      }
    }
  }
""",
                "",
            ),
        ],
    ),
    (
        "bug4_chunk_include_carry_scan.patch",
        [
            (
                "src/chunk.c",
                """  csvpack_status_t st = csvpack_parser_run(&sub);
  if (st == CSVPACK_OK && p->tbl->count >= 1) {
    uint8_t carry[8];
    memcpy(carry, p->scan.src + p->scan.pos + n, 8);
    (void)carry[0];
  }
  return st;""",
                "  return csvpack_parser_run(&sub);",
            ),
        ],
    ),
    (
        "bug5_quote_field_witness_tail.patch",
        [
            (
                "src/parse.c",
                "      csvpack_quote_field_witness(raw);\n",
                "",
            ),
        ],
    ),
    (
        "bug6_serialize_buffer_trailer.patch",
        [
            (
                "src/serialize.c",
                """  if (tbl->count > 5) {
    csvpack_buf_witness_trailer(&buf);
  }
""",
                "",
            ),
        ],
    ),
    (
        "bug7_query_long_value_audit.patch",
        [
            (
                "src/merge.c",
                """  size_t vl = strlen(v);
  if (vl > 80) {
    char *scratch = (char *)malloc(vl + 1);
    if (scratch) {
      memcpy(scratch, v, vl + 1);
      char audit[8];
      memcpy(audit, scratch + vl + 8, sizeof(audit));
      (void)audit[0];
      free(scratch);
    }
  }
""",
                "",
            ),
        ],
    ),
    (
        "bug8_chunk_directive_tail_read.patch",
        [
            (
                "src/parse.c",
                """          if (i >= directive.len && p->tbl->count >= 1) {
            uint8_t tail[8];
            memcpy(tail, directive.data + directive.len, 8);
            (void)tail[0];
          } else {
            csvpack_slice_t path = {directive.data + ps, i - ps};
            csvpack_status_t st = csvpack_handle_chunk(p, path);
            if (st != CSVPACK_OK) return st;
          }""",
                """          if (i < directive.len) {
            csvpack_slice_t path = {directive.data + ps, i - ps};
            csvpack_status_t st = csvpack_handle_chunk(p, path);
            if (st != CSVPACK_OK) return st;
          }""",
            ),
        ],
    ),
    (
        "bug9_arena_compact_prior_touch.patch",
        [
            (
                "src/parse.c",
                """  if (p->tbl->count == 2) {
    csvpack_arena_compact(&p->tbl->arena);
    csvpack_table_touch_prior_row(p->tbl);
  }
""",
                "",
            ),
        ],
    ),
    (
        "bug10_diff_mismatch_tail_probe.patch",
        [
            (
                "src/serialize.c",
                """        if (a->count >= 6 && other->count >= 6) {
          size_t clen = ra->cells[ci].value.len;
          char *scratch = (char *)malloc(clen + 1);
          if (scratch) {
            memcpy(scratch, ra->cells[ci].value.data, clen + 1);
            char probe[12];
            memcpy(probe, scratch + clen + 8, sizeof(probe));
            (void)probe[0];
            free(scratch);
          }
        }
""",
                "",
            ),
        ],
    ),
]


def git(*args: str) -> None:
    subprocess.run(["git", *args], cwd=ROOT, check=True, capture_output=True)


def apply_text_fixes(edits: list[tuple[str, str, str]]) -> None:
    for rel, old, new in edits:
        path = ROOT / rel
        text = path.read_text(encoding="utf-8")
        if old not in text:
            raise SystemExit(f"missing anchor in {rel} for patch generation")
        path.write_text(text.replace(old, new, 1), encoding="utf-8")


def main() -> int:
    SUBMIT.mkdir(parents=True, exist_ok=True)
    git("checkout", "--", "src/")
    for patch_name, edits in FIXES:
        apply_text_fixes(edits)
        diff = subprocess.run(
            ["git", "diff", "src/"],
            cwd=ROOT,
            check=True,
            capture_output=True,
            text=True,
        ).stdout
        if not diff.strip():
            print(f"empty patch for {patch_name}", file=sys.stderr)
            return 1
        (SUBMIT / patch_name).write_text(diff, encoding="utf-8", newline="\n")
        print("wrote", patch_name)
        git("checkout", "--", "src/")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
