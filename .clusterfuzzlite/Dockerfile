FROM gcr.io/oss-fuzz-base/base-builder:v1

COPY . $SRC/oss_fuzz_test
WORKDIR $SRC/oss_fuzz_test

COPY .clusterfuzzlite/build.sh $SRC/
