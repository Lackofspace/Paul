// ModularOperand.cpp

#include "ModularOperand.h"

ModularOperand::ModularOperand(int value, const IArithmetic& ma) : m_operand(value) {} // , m_arithmetic(ma)

int ModularOperand::GetValue() const {
    return m_operand;
}
