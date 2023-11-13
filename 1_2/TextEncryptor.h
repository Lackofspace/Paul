#pragma once

#include <string>
#include "IEncryption.h"

class TextEncryptor {
public:
    explicit TextEncryptor(Lab1::IEncryption *encryption);

    void SetEncryption(Lab1::IEncryption* encryption);

    unsigned char *Encrypt(const char *text) const;

    unsigned char *Decrypt(const char *encryptedText) const;

private:
    Lab1::IEncryption *m_encryption;
};