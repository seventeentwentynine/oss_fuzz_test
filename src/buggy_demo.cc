#include "buggy_demo.h"
#include <string>

namespace demo {

void process_input(const uint8_t* data, size_t size) {
    // --- New bug: out-of-bounds write on stack array ---
    // If size == 0, we can't even read data[0], so just bail.
    if (size == 0) {
        return;
    }

    int small[8] = {0};

    // Take the first byte as an index.
    uint8_t index = data[0];

    // BUG: No bounds check. If index >= 8, this writes past the end of `small`.
    // With random fuzzing, most values of data[0] will be >= 8, so ASan will
    // very quickly report a stack buffer overflow here.
    small[index] = 1;

    // --- Existing bug: null deref when "CRSH" is present ---
    if (size < 4) {
        return;
    }

    std::string s(reinterpret_cast<const char*>(data), size);
    if (s.find("CRSH") != std::string::npos) {
        int* p = nullptr;
        *p = 42;  // Intentional crash
    }
}

}  // namespace demo
