#!/bin/bash -eu

OBJECTS=()
for src in arena buffer scan quote split row table parse serialize merge alias \
           chunk util coerce schema dialect filter transform stats encode pivot; do
  obj="${src}.o"
  ${CC:-clang} ${CFLAGS} \
    -I"${SRC:-.}/include" -I"${SRC:-.}/src" \
    -c "${SRC:-.}/src/${src}.c" -o "${obj}"
  OBJECTS+=("${obj}")
done

build_fuzzer() {
  local harness="$1"
  local out_name="$2"
  local harness_obj="${out_name}_harness.o"
  ${CC:-clang} ${CFLAGS} \
    -I"${SRC:-.}/include" \
    -c "${SRC:-.}/fuzz/${harness}" -o "${harness_obj}"
  ${CXX:-clang++} ${CXXFLAGS} ${LIB_FUZZING_ENGINE} \
    "${harness_obj}" "${OBJECTS[@]}" \
    -o "${OUT}/${out_name}"
}

build_fuzzer parse_fuzzer.c parse_fuzzer
build_fuzzer chunk_fuzzer.c chunk_fuzzer
build_fuzzer merge_fuzzer.c merge_fuzzer
build_fuzzer filter_fuzzer.c filter_fuzzer
