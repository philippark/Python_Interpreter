#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stack>

#include "CodeObject.h"

class Interpreter {
public:
    Interpreter() {stack = {};};

    // Load constant from co_consts[arg]
    void LOAD_VALUE(int);

    // Prints top of the stack
    void PRINT_ANSWER();

    // Pop two values, push their sum
    void ADD_TWO_VALUES();

    // Run the bytecode instructions
    void run_code(CodeObject);

private:
    std::stack<int> stack;
};

#endif