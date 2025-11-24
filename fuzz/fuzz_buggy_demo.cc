#include <cstddef>
#include <cstdint>
#include "buggy_demo.cc"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
    demo::process_input(data, size);
    return 0;
}
