#!/bin/bash -eu

if [ -z "${OUT:-}" ]; then
  echo "OUT must be set" >&2
  exit 1
fi

mkdir -p "${OUT}"

OBJECTS=()
for src in arena buffer scan quote split row table parse serialize merge alias \
           chunk util coerce schema dialect filter transform stats encode pivot; do
  obj="${src}.o"
  ${CC:-clang} ${CFLAGS:--O1 -g -std=c11 -Wall -fsanitize=address} \
    -I"${SRC:-.}/include" -I"${SRC:-.}/src" \
    -c "${SRC:-.}/src/${src}.c" -o "${obj}" || exit 1
  OBJECTS+=("${obj}")
done

fuzz_common_obj="fuzz_common.o"
${CC:-clang} ${CFLAGS:--O1 -g -std=c11 -Wall -fsanitize=address} \
  -I"${SRC:-.}/include" -I"${SRC:-.}/fuzz" \
  -c "${SRC:-.}/fuzz/csvpack_fuzz_common.c" -o "${fuzz_common_obj}" || exit 1
OBJECTS+=("${fuzz_common_obj}")

build_fuzzer() {
  local harness="$1"
  local out_name="$2"
  local harness_obj="${out_name}_harness.o"
  ${CC:-clang} ${CFLAGS:--O1 -g -std=c11 -Wall -fsanitize=address} \
    -I"${SRC:-.}/include" -I"${SRC:-.}/fuzz" \
    -c "${SRC:-.}/fuzz/${harness}" -o "${harness_obj}" || exit 1
  ${CXX:-clang++} ${CXXFLAGS:--O1 -g -std=c++17 -fsanitize=address} \
    ${LIB_FUZZING_ENGINE:--fsanitize=fuzzer} \
    "${harness_obj}" "${OBJECTS[@]}" \
    -o "${OUT}/${out_name}" || exit 1
}

build_fuzzer parse_fuzzer.c parse_fuzzer
build_fuzzer chunk_fuzzer.c chunk_fuzzer
build_fuzzer merge_fuzzer.c merge_fuzzer
build_fuzzer filter_fuzzer.c filter_fuzzer

test -x "${OUT}/chunk_fuzzer"
test -x "${OUT}/parse_fuzzer"
test -x "${OUT}/merge_fuzzer"
test -x "${OUT}/filter_fuzzer"

echo "Built fuzz targets in ${OUT}"
