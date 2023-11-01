#pragma once
#include "IArithmetic.h"

class ModularArithmetic: public IArithmetic
{
public:
    explicit ModularArithmetic(int module);

    int Add(int leftOp, int rightOp) const override;
    int Subtract(int leftOp, int rightOp) const override;
    int Multiply(int a, int b) const override;
    int Divide(int a, int b) const override;
private:
    int m_module;
};
