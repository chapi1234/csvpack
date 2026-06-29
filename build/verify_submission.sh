#!/bin/bash
set -eu
cd "$(dirname "$0")/.."
FAIL=0

echo "=== fuzz harness crash matrix (all 4 targets) ==="
if ! bash build/test_all_fuzzers.sh; then
  FAIL=1
fi

echo ""
echo "=== reference patches close each crash (parse_fuzzer) ==="
OUT=/tmp/csvpack_verify
SRC="$PWD"
CC=${CC:-gcc}
MODULES="arena buffer scan quote split row table parse serialize merge alias chunk util coerce schema dialect filter transform stats encode pivot"

build_parse_fuzzer() {
  mkdir -p "$OUT"
  OBJECTS=()
  for src in $MODULES; do
    obj="${OUT}/${src}.o"
    ${CC} -O1 -g -std=c11 -Wall -fsanitize=address \
      -I"${SRC}/include" -I"${SRC}/src" \
      -c "${SRC}/src/${src}.c" -o "${obj}"
    OBJECTS+=("${obj}")
  done
  ${CC} -O1 -g -std=c11 -Wall -fsanitize=address \
    -I"${SRC}/include" -I"${SRC}/fuzz" \
    -c "${SRC}/fuzz/csvpack_fuzz_common.c" -o "${OUT}/fuzz_common.o"
  OBJECTS+=("${OUT}/fuzz_common.o")
  ${CC} -O1 -g -std=c11 -Wall -fsanitize=address \
    -I"${SRC}/include" -I"${SRC}/fuzz" \
    -c "${SRC}/fuzz/parse_fuzzer.c" -o "${OUT}/parse_fuzzer.o"
  cat > "${OUT}/fuzz_run.c" <<'EOF'
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
extern int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size);
int main(int argc, char **argv) {
  const char *path = argv[1];
  FILE *f = fopen(path, "rb");
  if (!f) return 1;
  fseek(f, 0, SEEK_END);
  long sz = ftell(f);
  fseek(f, 0, SEEK_SET);
  uint8_t *buf = malloc((size_t)sz > 0 ? (size_t)sz : 1);
  if (sz > 0) fread(buf, 1, (size_t)sz, f);
  fclose(f);
  LLVMFuzzerTestOneInput(buf, (size_t)sz);
  free(buf);
  return 0;
}
EOF
  ${CC} -O1 -g -std=c11 -Wall -fsanitize=address \
    "${OUT}/fuzz_run.c" "${OUT}/parse_fuzzer.o" "${OBJECTS[@]}" \
    -I"${SRC}/include" -o "${OUT}/parse_fuzzer"
}

crash_parse() {
  local poc="$1"
  set +e
  local out
  out=$(ASAN_OPTIONS=detect_leaks=0:abort_on_error=1 "${OUT}/parse_fuzzer" "$poc" 2>&1)
  set -e
  echo "$out" | grep -qE 'AddressSanitizer|heap-use-after-free|heap-buffer-overflow'
}

declare -A POCS=(
  [1]="poc/verified/quoted_continuation_row2.csv"
  [2]="poc/verified/multi_record_gap.csv"
  [3]="poc/verified/narrow_row_wide_header.csv"
  [4]="poc/verified/chunk_include_carry.csv"
  [5]="poc/verified/quote_witness_tail.csv"
  [6]="poc/verified/serialize_trailer.csv"
  [7]="poc/verified/query_long_value.csv"
  [8]="poc/verified/chunk_directive_tail.csv"
  [9]="poc/verified/wide_arena_rotate.csv"
  [10]="poc/verified/diff_many_rows.csv"
)

build_parse_fuzzer

for n in $(seq 1 10); do
  patch=$(ls poc/submit/bug${n}_*.patch)
  git apply --check "$patch"
  git apply "$patch"
  build_parse_fuzzer
  if crash_parse "${POCS[$n]}"; then
    echo "FAIL patched still crashes bug${n}"
    FAIL=1
  else
    echo "PASS patched clean bug${n}"
  fi
  git checkout HEAD -- src/
done

if command -v clang++ >/dev/null 2>&1; then
  export SRC="$PWD" OUT="$OUT" CC=clang CXX=clang++
  export LIB_FUZZING_ENGINE=-fsanitize=fuzzer
  export CFLAGS="-O1 -g -std=c11 -Wall -fsanitize=address"
  export CXXFLAGS="-O1 -g -std=c++17 -fsanitize=address"
  rm -f ./*.o
  bash .clusterfuzzlite/build.sh
  for f in parse_fuzzer chunk_fuzzer merge_fuzzer filter_fuzzer; do
    test -x "${OUT}/${f}"
  done
  echo "clusterfuzzlite build: OK"
else
  echo "SKIP clusterfuzz build: clang++ not installed"
fi

exit $FAIL
