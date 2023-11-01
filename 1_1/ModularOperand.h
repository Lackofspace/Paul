// ModularOperand.h

#pragma once
#include "ModularArithmetic.h"

class ModularOperand {
public:
    ModularOperand(int value, const IArithmetic& ma);
    int GetValue() const;

private:
    int m_operand;
//    const IArithmetic m_arithmetic;
};
