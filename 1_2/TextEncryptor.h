#pragma once
#include <string>
#include "IEncryption.h"

class TextEncryptor {
public:
    explicit TextEncryptor(IEncryption* encryption);

    std::string Encrypt(char* text) const;
    std::string Decrypt(char* encryptedText) const;

private:
    IEncryption* m_encryption;
};
