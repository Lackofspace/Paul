#pragma once
#include "IArithmetic.h"

class ModularOperand {
public:
    ModularOperand(int value, const IArithmetic& ma);
    int GetValue() const;

private:
    int m_operand;
};
