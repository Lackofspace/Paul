#include <iostream>
#include "IArithmetic.h"
#include "ModularOperand.h"

int main() {
    int modulo = 26;
    IArithmetic ma(modulo);

    ModularOperand a(11, ma);
    ModularOperand b(13, ma);

    int resultAdd = ma.Add(a.GetValue(), b.GetValue());
    int resultSubtract = ma.Subtract(a.GetValue(), b.GetValue());
    int resultMultiply = ma.Multiply(a.GetValue(), b.GetValue());
    int resultDivide = ma.Divide(a.GetValue(), b.GetValue());

    std::cout << a.GetValue() << " + " << b.GetValue() << " = " << resultAdd << " mod " << modulo << std::endl;
    std::cout << a.GetValue() << " - " << b.GetValue() << " = " << resultSubtract << " mod " << modulo << std::endl;
    std::cout << a.GetValue() << " * " << b.GetValue() << " = " << resultMultiply << " mod " << modulo << std::endl;
    std::cout << a.GetValue() << " / " << b.GetValue() << " = " << resultDivide << " mod " << modulo << std::endl;

    return 0;
}
