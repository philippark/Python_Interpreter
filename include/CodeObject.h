#ifndef CODEOBJECT_H
#define CODEOBJECT_H

#include <vector>
#include <cstdint>

struct CodeObject {
    std::vector<uint8_t> co_code; // bytecode instructions
    std::vector<int> co_consts; // constants
};

#endif