#include <vector>
#include <cstdint>

class CodeObject {
public:

private:
    std::vector<uint8_t> co_code; // bytecode instructions
    std::vector<int> co_consts; // constants
};