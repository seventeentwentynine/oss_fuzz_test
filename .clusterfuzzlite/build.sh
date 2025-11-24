#!/bin/bash -eu

PROJECT_DIR="$SRC/oss_fuzz_test"
cd "$PROJECT_DIR"

# Build the fuzz target using ClusterFuzzLite's compiler flags.
# $CC / $CXX / $CFLAGS / $CXXFLAGS / $LIB_FUZZING_ENGINE / $OUT
# are provided by the OSS-Fuzz toolchain and must be used.:contentReference[oaicite:10]{index=10}
$CXX $CXXFLAGS -std=c++17 -Isrc \
    src/buggy_demo.cc \
    fuzz/fuzz_buggy_demo.cc \
    -o "$OUT/fuzz_buggy_demo" \
    $LIB_FUZZING_ENGINE
