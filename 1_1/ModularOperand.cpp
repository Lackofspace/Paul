#include "ModularOperand.h"

ModularOperand::ModularOperand(int value, const IArithmetic& ma) : m_operand(value) {}

int ModularOperand::GetValue() const {
    return m_operand;
}
