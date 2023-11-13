#pragma once

#include <string>

namespace Lab1 {
    class IEncryption {
    public:
        virtual unsigned char* Encrypt(const std::string &text) const = 0;

        virtual unsigned char* Decrypt(const std::string &text) const = 0;
    };
}