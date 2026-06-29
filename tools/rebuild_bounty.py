#!/usr/bin/env python3
"""Regenerate CSV fixtures and fuzz corpus seeds."""
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
VER = ROOT / "poc" / "verified"
CORPUS = ROOT / "fuzz" / "corpus"
FUZZERS = ("parse_fuzzer", "chunk_fuzzer", "merge_fuzzer", "filter_fuzzer")

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
    "quote_witness_tail.csv": 'id,text\n1,"trail\\\\"\n',
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
        ",".join(f"h{i}" for i in range(256))
        + "\n"
        + ",".join("xxxxxxx" for _ in range(256))
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


def write_corpus() -> None:
    for fuzzer in FUZZERS:
        dest = CORPUS / fuzzer
        dest.mkdir(parents=True, exist_ok=True)
        for stale in dest.iterdir():
            if stale.is_file() and stale.name.startswith("seed_"):
                stale.unlink()
        for name, content in POCS.items():
            path = dest / f"seed_{name}"
            if isinstance(content, bytes):
                path.write_bytes(content)
            else:
                path.write_text(content, encoding="utf-8", newline="\n")


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
    write_corpus()
    print("wrote", len(POCS), "PoCs to", VER)
    print("wrote corpus seeds under", CORPUS)


if __name__ == "__main__":
    main()
