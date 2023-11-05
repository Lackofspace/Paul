#include <iostream>
#include "IArithmetic.h"
#include "ModularArithmetic.h"

int main(int argc, char **argv) {
    std::cout
            << "Please provide 3 (three) params in the next order separated by spaces: 1) left operand, 2) right operand and 3) module\n";

    if (argc < 3) {
        std::cout << "Unable to get required params";

        return EXIT_FAILURE;
    }

    try {
        long long leftOperand = std::atoll(argv[1]);
        long long rightOperand = std::atoll(argv[2]);
        long long module = std::atoll(argv[3]);


        IArithmetic *ma = new ModularArithmetic(module);

        long long resultAdd = ma->Add(leftOperand, rightOperand);
        long long resultSubtract = ma->Subtract(leftOperand, rightOperand);
        long long resultMultiply = ma->Multiply(leftOperand, rightOperand);
        long long resultDivide = ma->Divide(leftOperand, rightOperand);

        std::cout << leftOperand << " + " << rightOperand << " = " << resultAdd << " mod " << module << std::endl;
        std::cout << leftOperand << " - " << rightOperand << " = " << resultSubtract << " mod " << module << std::endl;
        std::cout << leftOperand << " * " << rightOperand << " = " << resultMultiply << " mod " << module << std::endl;
        std::cout << leftOperand << " / " << rightOperand << " = " << resultDivide << " mod " << module << std::endl;
    }
    catch (std::runtime_error e) {
        std::cout << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
