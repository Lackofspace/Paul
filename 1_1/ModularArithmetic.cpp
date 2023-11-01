#include <tuple>
#include <iostream>
#include "ModularArithmetic.h"

// Отсутствие наибольшего общего делителя greatest common divisor
constexpr int NO_GCD = -1;

int ModularArithmetic::Add(int leftOp, int rightOp) const {
    return (leftOp + rightOp) % m_module;
}


ModularArithmetic::ModularArithmetic(int module) : m_module(module) {
}

int ModularArithmetic::Subtract(int leftOp, int rightOp) const {
    int result = (leftOp - rightOp) % m_module;
    if (result < 0) {
        result += m_module;
    }
    return result;
}

int ModularArithmetic::Multiply(int a, int b) const {
    return (a * b) % m_module;
}

std::tuple<int, int, int> CalculateAdvancedEuclidAlgorithm(int number, int module);

int ModularArithmetic::Divide(int a, int b) const {
    std::tuple<int, int, int> result = CalculateAdvancedEuclidAlgorithm(b, m_module);

    int div = std::get<0>(result);

    try {
        if (div != 1) {
            throw std::runtime_error("The divisor and the modulus are not mutually simple\n"
                                     "The result will be -1 instead");
        }
    } catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return NO_GCD;
    }

    int x = std::get<1>(result) + m_module;

    return Multiply(a, x);
}

/*
 * Расширенный алгоритм Евклида для нахождения НОДа и коэффициентов Безу
 * 1-ый параметр: текущий НОД
 * 2-ой параметр: обратное значение для наибольшего числа (коэффициент Безу)
 * 3-ий параметр: обратное значение для
 */
std::tuple<int, int, int> CalculateAdvancedEuclidAlgorithm(int number, int module) {
    if (number == 0) {
        return std::make_tuple(module, 0, 1);
    } else {
        int div, x, y;
        std::tie(div, x, y) = CalculateAdvancedEuclidAlgorithm(module % number, number);
        return std::make_tuple(div, y - (module / number) * x, x);
    }
}
