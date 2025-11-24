#include <cstddef>
#include <cstdint>
#include <string>

namespace demo {

// Silly function with a deliberate bug: it crashes when it sees "CRSH".
void process_input(const uint8_t* data, size_t size) {
    if (size < 4) return;

    std::string s(reinterpret_cast<const char*>(data), size);
    if (s.find("CRSH") != std::string::npos) {
        // Intentional bug for the demo.
        int* p = nullptr;
        *p = 42;  // Boom: null dereference
    }
}

}
