#pragma once
#include "IArithmetic.h"

class ModularArithmetic: public IArithmetic
{
public:
    explicit ModularArithmetic(long long module);

    long long Add(long long leftOp, long long rightOp) const override;
    long long Subtract(long long leftOp, long long rightOp) const override;
    long long Multiply(long long leftOp, long long rightOp) const override;
    long long Divide(long long leftOp, long long rightOp) const override;
private:
    long long BinaryPower(long long base, long long p) const;
    long long InverseElement(long long x) const;

    long long m_module;
};
