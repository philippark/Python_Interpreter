#include <stack>

class Interpreter {
public:
    Interpreter() {stack = {};};
    void LOAD_VALUE(int number);
    void PRINT_ANSWER();
    void ADD_TWO_VALUES();

private:
    std::stack<int> stack;
};