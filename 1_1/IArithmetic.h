#pragma once

class IArithmetic {
public:
    virtual ~IArithmetic() = default;

    virtual long long Add(long long a, long long b) const = 0;
    virtual long long Subtract(long long a, long long b) const = 0;
    virtual long long Multiply(long long a, long long b) const = 0;
    virtual long long Divide(long long a, long long b) const = 0;
};
