#!/usr/bin/env python3
"""Regenerate PoC files and local drivers list for the 10-bug csvpack bounty."""
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
VER = ROOT / "poc" / "verified"

POCS = {
    "quoted_continuation_row2.csv": (
        "sku,label\n"
        "A,ok\n"
        'B,"unclosed\n'
    ),
    "multi_record_gap.csv": "a,b\n1,2\n3,4",
    "narrow_row_wide_header.csv": "c1,c2,c3,c4,c5,c6,c7,c8\nonly\n",
    "chunk_include_carry.csv": (
        "id,name\n"
        "1,alpha\n"
        '@chunk "child.csv"\n'
    ),
    "quote_witness_tail.csv": 'id,text\n1,"value\\"\n',
    "serialize_trailer.csv": (
        "k,v\n"
        + "\n".join(f"{i},{i}" for i in range(8))
        + "\n"
    ),
    "query_long_value.csv": (
        "key,value\n"
        "note," + ("Q" * 96) + "\n"
    ),
    "chunk_directive_tail.csv": (
        "id\n"
        "1\n"
        '@chunk "open\n'
    ),
    "wide_arena_rotate.csv": (
        ",".join(f"h{i}" for i in range(520))
        + "\n"
        + ",".join("x" for _ in range(520))
        + "\n"
    ),
    "diff_many_rows.csv": (
        "id,val\n"
        + "\n".join(f"{i},{i}" for i in range(6))
        + "\n---DIFF---\n"
        "id,val\n"
        + "\n".join(f"{i},{i + 1}" for i in range(6))
        + "\n"
    ),
}

DRIVERS = [
    ("split_poc", "quoted_continuation_row2.csv", "crash"),
    ("parse_poc", "multi_record_gap.csv", "crash"),
    ("row_poc", "narrow_row_wide_header.csv", "crash"),
    ("chunk_poc", "chunk_include_carry.csv", "crash"),
    ("quote_poc", "quote_witness_tail.csv", "crash"),
    ("serialize_poc", "serialize_trailer.csv", "crash"),
    ("query_poc", "query_long_value.csv", "crash"),
    ("chunk_directive_poc", "chunk_directive_tail.csv", "crash"),
    ("arena_poc", "wide_arena_rotate.csv", "crash"),
    ("diff_poc", "diff_many_rows.csv", "crash"),
]


def main() -> None:
    VER.mkdir(parents=True, exist_ok=True)
    for name, content in POCS.items():
        path = VER / name
        if name.endswith(".bin"):
            path.write_bytes(content if isinstance(content, bytes) else content.encode())
        else:
            path.write_text(content, encoding="utf-8", newline="\n")
    for stale in VER.iterdir():
        if stale.is_file() and stale.name not in POCS:
            stale.unlink()
    print("wrote", len(POCS), "PoCs to", VER)


if __name__ == "__main__":
    main()
