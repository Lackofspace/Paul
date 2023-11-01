#pragma once

class IArithmetic {
public:
    explicit IArithmetic(int mod);
    int Add(int a, int b) const;
    int Subtract(int a, int b) const;
    int Multiply(int a, int b) const;
    int Divide(int a, int b) const;

private:
    int modulo;
};
