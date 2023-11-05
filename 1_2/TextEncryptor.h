#pragma once
#include <string>
#include "IEncryption.h"

class TextEncryptor {
public:
    explicit TextEncryptor(IEncryption* encryption);

    std::string Encrypt(const std::string& text) const;
    std::string Decrypt(const std::string& encryptedText) const;

private:
    IEncryption* m_encryption;
};
