#!/bin/bash
set -eu
cd "$(dirname "$0")/.."
OUT=/tmp/csvpack_out
SRC="$PWD"
CC=${CC:-gcc}
FAIL=0

MODULES="arena buffer scan quote split row table parse serialize merge alias chunk util coerce schema dialect filter transform stats encode pivot"

build_replay() {
  OBJECTS=()
  for src in $MODULES; do
    obj="${src}.o"
    ${CC} -O1 -g -std=c11 -Wall -fsanitize=address \
      -I"${SRC}/include" -I"${SRC}/src" \
      -c "${SRC}/src/${src}.c" -o "${obj}"
    OBJECTS+=("${obj}")
  done
  ${CC} -O1 -g -std=c11 -Wall -fsanitize=address \
    "${SRC}/tools/chunk_replay_driver.c" "${OBJECTS[@]}" \
    -I"${SRC}/include" \
    -o "${OUT}/chunk_replay_driver"
  rm -f ./*.o
}

crash_replay() {
  local poc="$1"
  set +e
  local out
  out=$(ASAN_OPTIONS=detect_leaks=0 "${OUT}/chunk_replay_driver" "$poc" 2>&1)
  set -e
  echo "$out" | grep -qE 'AddressSanitizer|heap-use-after-free|heap-buffer-overflow'
}

build_clusterfuzz() {
  if ! command -v clang++ >/dev/null 2>&1; then
    echo "SKIP clusterfuzz build: clang++ not installed"
    return 0
  fi
  export SRC="$PWD"
  export OUT="$OUT"
  export CC=clang
  export CXX=clang++
  export LIB_FUZZING_ENGINE=-fsanitize=fuzzer
  export CFLAGS="-O1 -g -std=c11 -Wall -fsanitize=address"
  export CXXFLAGS="-O1 -g -std=c++17 -fsanitize=address"
  rm -f ./*.o
  bash .clusterfuzzlite/build.sh
  test -x "${OUT}/chunk_fuzzer"
  echo "clusterfuzzlite build: OK"
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

mkdir -p "$OUT"
echo "=== chunk_replay driver (matches chunk_fuzzer paths) ==="
build_replay

for n in $(seq 1 10); do
  poc="${POCS[$n]}"
  if crash_replay "$poc"; then
    echo "PASS unpatched crash bug${n}"
  else
    echo "FAIL unpatched crash bug${n}"
    FAIL=1
  fi
done

echo ""
echo "=== reference patches close each crash ==="
for n in $(seq 1 10); do
  poc="${POCS[$n]}"
  patch=$(ls poc/submit/bug${n}_*.patch)
  git apply --check "$patch"
  git apply "$patch"
  build_replay
  if crash_replay "$poc"; then
    echo "FAIL patched still crashes bug${n}"
    FAIL=1
  else
    echo "PASS patched clean bug${n}"
  fi
  git checkout HEAD -- src/
done

echo ""
build_clusterfuzz

exit $FAIL
