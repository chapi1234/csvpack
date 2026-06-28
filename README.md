# csvpack

csvpack is a C11 library for parsing, transforming, and serializing tabular data
stored in comma-separated value (CSV) form. It targets applications that ingest
spreadsheet exports, log-derived tables, or ETL pipelines where rows and named
columns must be read reliably, validated, merged, and written back out without
pulling in a heavy database or scripting runtime.

The parser follows RFC 4180 conventions: newline-delimited records, configurable
field delimiters, double-quoted fields with doubled-quote escaping, and optional
comment lines. Quoted fields additionally support backslash escapes for common
control characters, hexadecimal bytes, Unicode code points, and octal bytes.
Large documents are handled through an arena allocator and growable row/column
storage so repeated parsing stays predictable in memory use.

Beyond plain parsing, csvpack exposes higher-level table operations. Tables can
embed other CSV documents through `@chunk` references resolved via a caller-supplied
read callback, similar to a tiny virtual file system. Cell values may reference
other columns using `${column}` alias interpolation. Multiple tables can be
combined with patch-style overlays, diffed for change tracking, checked against
simple schemas, and round-tripped through a serializer.

Utility modules round out the toolkit: a dialect registry for named delimiter
profiles, row filtering by column value, in-place column transforms, numeric
histogram buckets per column, UTF-8 validation for raw cell bytes, and pivot
helpers that index rows by composite axis keys. The public API lives in
`include/csvpack.h`; implementation modules sit under `src/`.

## Building and testing

```bash
make          # build libcsvpack.a, test_runner, simple_parse
make test     # run the unit test harness
```

For sanitizer-enabled builds (recommended when fuzzing or debugging):

```bash
bash build/wsl_build.sh
```

## Fuzzing

ClusterFuzzLite harnesses under `fuzz/` exercise the parser (`parse_fuzzer`),
chunk resolution (`chunk_fuzzer`), table merge overlays (`merge_fuzzer`), and
row filtering (`filter_fuzzer`). Seed corpora are provided in `fuzz/corpus/`.

## Layout

| Path | Description |
|------|-------------|
| `include/csvpack.h` | Public types and function declarations |
| `src/` | Parser, serializer, merge, alias, chunk, and helper modules |
| `tests/test_runner.c` | Regression tests |
| `examples/simple_parse.c` | Minimal parse-and-print example |
| `docs/api.md` | API overview |
| `.clusterfuzzlite/` | OSS-Fuzz / ClusterFuzzLite build scripts |

## License

See `LICENSE` in the repository root.
