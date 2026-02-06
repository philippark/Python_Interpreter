#ifndef OPCODE_H
#define OPCODE_h

#include <cstdint>

enum class OpCode : uint8_t {
    LOAD_VALUE, // Adds arg to stack
    PRINT_ANSWER, // Prints top of stack
    ADD_TWO_VALUES // Adds top two values
};

#endif