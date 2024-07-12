class Interpreter:
    def __init__(self):
        self.stack = []

    def LOAD_VALUE(self, number):
        self.stack.append(number);

    def PRINT_ANSWER(self):
        val = self.stack.pop()
        print(val)
    
    def ADD_TWO_NUMBERS(self):
        num1 = self.stack.pop()
        num2 = self.stack.pop()
        self.stack.append(num1 + num2)

    def run_code(self, what_to_execute):
        instructions = what_to_execute["instructions"]
        numbers = what_to_execute["numbers"]

        for step in instructions:
            instruction, argument = step

            if instruction == "LOAD_VALUE":
                self.LOAD_VALUE(numbers[argument])
            elif instruction == "ADD_TWO_NUMBERS":
                self.ADD_TWO_NUMBERS()
            elif instruction == "PRINT_ANSWER":
                self.PRINT_ANSWER()



if __name__ == "__main__":
    what_to_execute = {
        "instructions" : [
            ("LOAD_VALUE", 0),
            ("LOAD_VALUE", 1),
            ("ADD_TWO_NUMBERS", None),
            ("PRINT_ANSWER", None)
        ],
        "numbers" : [7,5]
    }

    interpreter = Interpreter()
    interpreter.run_code(what_to_execute)