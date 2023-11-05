#pragma once

#include <string>

class IEncryption {
public:
    virtual std::string Encrypt(const std::string& text) const = 0;
    virtual std::string Decrypt(const std::string& text) const = 0;
};
