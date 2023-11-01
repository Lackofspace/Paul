#pragma once

class IArithmetic {
public:
    virtual ~IArithmetic() = default;

    virtual int Add(int a, int b) const = 0;
    virtual int Subtract(int a, int b) const = 0;
    virtual int Multiply(int a, int b) const = 0;
    virtual int Divide(int a, int b) const = 0;
};
