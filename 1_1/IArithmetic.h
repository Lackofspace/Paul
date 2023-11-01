#pragma once

class IArithmetic {
public:
    explicit IArithmetic(int mod);
    virtual int Add(int a, int b) const = 0;
    virtual int Subtract(int a, int b) const = 0;
    virtual int Multiply(int a, int b) const = 0;
    virtual int Divide(int a, int b) const = 0;

private:
    int modulo;
};
