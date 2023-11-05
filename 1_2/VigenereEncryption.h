#pragma once

#include <string>
#include "IEncryption.h"

class VigenereEncryption : public IEncryption {
public:
    std::string Encrypt(const std::string& text) const override;
    std::string Decrypt(const std::string& cipherText) const override;

private:
    std::string m_key;
};