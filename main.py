class Interpreter:
    def __init__(self):
        self.stack = []
        self.environment = {}

    def STORE_NAME(self, name):
        val = self.stack.pop()
        self.environment[name] = val

    def LOAD_NAME(self, name):
        val = self.environment[name]
        self.stack.append(val);

    def parse_argument(self, instruction, argument, what_to_execute):
        numbers = ["LOAD_VALUE"]
        names = ["LOAD_NAME", "STORE_NAME"]

        if instruction in numbers:
            argument = what_to_execute["numbers"][argument]
        elif instruction in names:
            argument = what_to_execute["names"][argument]
        
        return argument

    def execute(self, what_to_execute):
        instructions = what_to_execute["instructions"]
        for step in instructions:
            instruction, argument = self.parse_argument(instruction, argument, what_to_execute)
            bytecode_method = getattr(self, instruction)
            if argument:
                bytecode_method(argument)
            else:
                bytecode_method()

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