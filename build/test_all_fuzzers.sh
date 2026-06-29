#!/bin/bash
set -eu
cd "$(dirname "$0")/.."
OUT=/tmp/csvpack_fuzz_test
SRC="$PWD"
CC=${CC:-gcc}
mkdir -p "$OUT"

MODULES="arena buffer scan quote split row table parse serialize merge alias chunk util coerce schema dialect filter transform stats encode pivot"

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

OBJECTS=()
for src in $MODULES; do
  obj="${OUT}/${src}.o"
  ${CC} -O1 -g -std=c11 -Wall -fsanitize=address \
    -I"${SRC}/include" -I"${SRC}/src" \
    -c "${SRC}/src/${src}.c" -o "${obj}" 2>/dev/null
  OBJECTS+=("${obj}")
done
${CC} -O1 -g -std=c11 -Wall -fsanitize=address \
  -I"${SRC}/include" -I"${SRC}/fuzz" \
  -c "${SRC}/fuzz/csvpack_fuzz_common.c" -o "${OUT}/fuzz_common.o"
OBJECTS+=("${OUT}/fuzz_common.o")

HARNESS=(parse_fuzzer chunk_fuzzer merge_fuzzer filter_fuzzer)
for h in "${HARNESS[@]}"; do
  ${CC} -O1 -g -std=c11 -Wall -fsanitize=address \
    -I"${SRC}/include" -I"${SRC}/fuzz" \
    -c "${SRC}/fuzz/${h}.c" -o "${OUT}/${h}.o"
  ${CC} -O1 -g -std=c11 -Wall -fsanitize=address \
    "${OUT}/fuzz_run.c" "${OUT}/${h}.o" "${OBJECTS[@]}" \
    -I"${SRC}/include" -o "${OUT}/${h}"
done

run_poc() {
  local harness="$1"
  local poc="$2"
  set +e
  local out
  out=$(ASAN_OPTIONS=detect_leaks=0:abort_on_error=1 "${OUT}/${harness}" "$poc" 2>&1)
  set -e
  if echo "$out" | grep -qE 'AddressSanitizer|heap-use-after-free|heap-buffer-overflow|SUMMARY: AddressSanitizer'; then
    echo "CRASH"
  else
    echo "OK"
  fi
}

POCS=(
  "1:poc/verified/quoted_continuation_row2.csv"
  "2:poc/verified/multi_record_gap.csv"
  "3:poc/verified/narrow_row_wide_header.csv"
  "4:poc/verified/chunk_include_carry.csv"
  "5:poc/verified/quote_witness_tail.csv"
  "6:poc/verified/serialize_trailer.csv"
  "7:poc/verified/query_long_value.csv"
  "8:poc/verified/chunk_directive_tail.csv"
  "9:poc/verified/wide_arena_rotate.csv"
  "10:poc/verified/diff_many_rows.csv"
)

FAIL=0
printf "%-6s" "bug"
for h in "${HARNESS[@]}"; do printf " %-14s" "$h"; done
echo

for entry in "${POCS[@]}"; do
  n="${entry%%:*}"
  poc="${entry#*:}"
  crashed=0
  printf "bug%-3s" "$n"
  for h in "${HARNESS[@]}"; do
    result=$(run_poc "$h" "$poc")
    printf " %-14s" "$result"
    if [ "$result" = "CRASH" ]; then
      crashed=1
    fi
  done
  echo
  if [ "$crashed" -eq 0 ]; then
    echo "FAIL bug${n}: no fuzz harness crashed"
    FAIL=1
  fi
done

exit $FAIL
