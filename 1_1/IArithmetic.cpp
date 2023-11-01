#include <iostream>
#include <tuple>
#include "IArithmetic.h"

#define EXIT_ERROR -1;


std::tuple<int, int, int> GcdExtended(int number, int module) {
    if (number == 0) {
        return std::make_tuple(module, 0, 1);
    } else {
        int div, x, y;
        std::tie(div, x, y) = GcdExtended(module % number, number);
        return std::make_tuple(div, y - (module / number) * x, x);
    }
}


IArithmetic::IArithmetic(int mod) : modulo(mod) {}

int IArithmetic::Add(int a, int b) const {
    return (a + b) % modulo;
}

int IArithmetic::Subtract(int a, int b) const {
    int result = (a - b) % modulo;
    if (result < 0) {
        result += modulo;
    }
    return result;
}

int IArithmetic::Multiply(int a, int b) const {
    return (a * b) % modulo;
}

int IArithmetic::Divide(int a, int b) const {

    std::tuple<int, int, int> result = GcdExtended(b, modulo);

    int div = std::get<0>(result);

    try {
        if (div != 1) {
            throw std::runtime_error("The divisor and the modulus are not mutually simple\n"
                                     "The result will be -1 instead");
        }
    } catch (const std::runtime_error& e) {

        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_ERROR;
    }

        int x = std::get<1>(result) + modulo;

        return IArithmetic::Multiply(a, x);
}