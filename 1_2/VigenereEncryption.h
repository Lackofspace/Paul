#pragma once

#include <string>
#include "IEncryption.h"
#include <ostream>

class VigenereEncryption : public Lab1::IEncryption {
public:
    explicit VigenereEncryption(const std::string &key);

    unsigned char* Encrypt(const std::string &text) const override;

    unsigned char* Decrypt(const std::string &cipherText) const override;

private:
    std::string m_key;
};