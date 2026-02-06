#include <iostream>
#include <vector>

#include "Interpreter.h"
#include "CodeObject.h"

int main() {
    CodeObject code_object {{0,0, 1,0, 0,1, 1,0, 2,0, 1,0}, {10, 11}};

    Interpreter interpreter;
    interpreter.run_code(code_object);
}