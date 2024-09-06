#!/bin/bash
        set -eu
        cd "$(dirname "$0")/.."
        export SRC="$PWD"
        export OUT=/tmp/csvpack_out
        mkdir -p "$OUT"
        rm -f ./*.o

        CC=${CC:-gcc}
        CXX=${CXX:-g++}

        OBJECTS=()
        for src in arena buffer scan quote split row table parse serialize merge alias chunk util coerce schema dialect filter transform stats encode pivot; do
          obj="${src}.o"
          ${CC} -O1 -g -std=c11 -Wall -fsanitize=address \
            -I"${SRC}/include" -I"${SRC}/src" \
            -c "${SRC}/src/${src}.c" -o "${obj}"
          OBJECTS+=("${obj}")
        done

        ${CC} -O1 -g -std=c11 -Wall -fsanitize=address \
          "${SRC}/tests/test_runner.c" "${OBJECTS[@]}" \
          -I"${SRC}/include" \
          -o "${OUT}/test_runner"

        ${CC} -O1 -g -std=c11 -Wall -fsanitize=address \
          "${SRC}/examples/simple_parse.c" "${OBJECTS[@]}" \
          -I"${SRC}/include" \
          -o "${OUT}/simple_parse"

        if command -v clang++ >/dev/null 2>&1; then
          export CC=clang
          export CXX=clang++
          export LIB_FUZZING_ENGINE=-fsanitize=fuzzer
          export CFLAGS="-O1 -g -std=c11 -Wall -fsanitize=address"
          export CXXFLAGS="-O1 -g -std=c++17 -fsanitize=address"
          rm -f ./*.o
          bash .clusterfuzzlite/build.sh
        fi

        ls -la "$OUT"
        echo "Build OK"
