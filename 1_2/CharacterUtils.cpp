#include <iostream>
#include "CharacterUtils.h"

bool IsCharBelongsToPlaintextAlphabet(int charCode) {
    unsigned int charCodeFlags = 0;

    if (charCode == 10 || charCode == 13) {
        charCodeFlags |= (1 << 0);
    }

    if (charCode >= 33 && charCode <= 34) {
        charCodeFlags |= (1 << 1);
    }

    if (charCode >= 40 && charCode <= 41) {
        charCodeFlags |= (1 << 2);
    }

    if (charCode >= 44 && charCode <= 46) {
        charCodeFlags |= (1 << 3);
    }

    if (charCode >= 58 && charCode <= 59) {
        charCodeFlags |= (1 << 4);
    }

    if (charCode == 63) {
        charCodeFlags |= (1 << 5);
    }

    if (charCode >= 48 && charCode <= 57) {
        charCodeFlags |= (1 << 6);
    }

    if (charCode >= 65 && charCode <= 90) {
        charCodeFlags |= (1 << 7);
    }

    if (charCode >= 97 && charCode <= 122) {
        charCodeFlags |= (1 << 8);
    }

    return charCodeFlags != 0;
}

bool IsCharBelongsToKeyAlphabet(char c, const std::string& customEncoding) {
    return customEncoding.find(c) != std::string::npos;
}

int GetKeyCharCode(char c, const std::string& customEncoding) {
    return static_cast<int>(customEncoding.find(c));
}
