FROM gcr.io/oss-fuzz-base/base-builder:v1

# Copy project into the container
COPY . $SRC/oss_fuzz_test
WORKDIR $SRC/oss_fuzz_test

# ClusterFuzzLite/OSS-Fuzz expect build.sh to live under $SRC
COPY .clusterfuzzlite/build.sh $SRC/
