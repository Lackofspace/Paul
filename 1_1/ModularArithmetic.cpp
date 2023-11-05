#include <tuple>
#include "ModularArithmetic.h"

std::tuple<int, int, int> CalculateAdvancedEuclidAlgorithm(int number, int module);

ModularArithmetic::ModularArithmetic(long long module) : m_module(module) {
}

long long ModularArithmetic::Add(long long leftOp, long long rightOp) const {
    return (leftOp + rightOp) % m_module;
}

long long ModularArithmetic::Subtract(long long leftOp, long long rightOp) const {
    long long result = (leftOp - rightOp) % m_module;
    if (result < 0) {
        result += m_module;
    }
    return result;
}

long long ModularArithmetic::Multiply(long long leftOp, long long rightOp) const {
    return (leftOp * rightOp) % m_module;
}

long long ModularArithmetic::Divide(long long leftOp, long long rightOp) const {
    std::tuple<int, int, int> result = CalculateAdvancedEuclidAlgorithm(rightOp, m_module);
    int div = std::get<0>(result);
    if (div != 1) {
        throw std::runtime_error("The divisor and the modulus are not mutually simple\n");
    }

    return (leftOp * InverseElement(rightOp)) % m_module;
}

//base ^ p
long long ModularArithmetic::BinaryPower(long long base, long long p) const {
    if (p == 1) {
        return base;
    }

    if (p % 2 == 0) {
        long long t = BinaryPower(base, p / 2);
        return t * t % m_module;
    } else {
        return BinaryPower(base, p - 1) * base % m_module;
    }
}

long long ModularArithmetic::InverseElement(long long x) const {
    return BinaryPower(x, m_module - 2);
}

/*
 * Расширенный алгоритм Евклида для нахождения НОДа и коэффициентов Безу
 * 1-ый параметр: текущий НОД
 * 2-ой параметр: обратное значение для number (первый коэффициент Безу)
 * 3-ий параметр: обратное значение для module (второй коэффициент Безу)
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
