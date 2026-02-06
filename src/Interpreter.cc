#include <iostream>
#include <vector>
#include <cstdint>

#include "Interpreter.h"
#include "OpCode.h"

void Interpreter::LOAD_VALUE(int number) {
    stack.push(number);
}

void Interpreter::PRINT_ANSWER() {
    int answer = stack.top();
    stack.pop();
    std::cout << answer << "\n";
}

void Interpreter::ADD_TWO_VALUES() {
    int first_num = stack.top();
    stack.pop();
    int second_num = stack.top();
    stack.pop();
    int total = first_num + second_num;
    stack.push(total);
}

void Interpreter::run_code(CodeObject code_object) {
    std::vector<uint8_t> co_code = code_object.co_code;
    
    for (size_t i = 0; i < co_code.size(); i += 2) {
        OpCode opcode = static_cast<OpCode>(co_code[i]);
        uint8_t arg = co_code[i+1];
        
        switch (opcode) {
            case OpCode::LOAD_VALUE:
                LOAD_VALUE(arg);
                break;
            case OpCode::PRINT_ANSWER:
                PRINT_ANSWER();
                break;
            case OpCode::ADD_TWO_VALUES:
                ADD_TWO_VALUES();
                break;
        }
        
    }
}