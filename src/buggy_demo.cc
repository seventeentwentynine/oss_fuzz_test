#include "buggy_demo.h"
#include <string>

namespace demo {

void process_input(const uint8_t* data, size_t size) {
    if (size < 4) return;

    std::string s(reinterpret_cast<const char*>(data), size);
    if (s.find("CRSH") != std::string::npos) {
        int* p = nullptr;
        *p = 42;  // Intentional crash
    }
}

}  // namespace demo
