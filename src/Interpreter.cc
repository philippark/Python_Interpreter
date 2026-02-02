#include "Interpreter.h"
#include <iostream>

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