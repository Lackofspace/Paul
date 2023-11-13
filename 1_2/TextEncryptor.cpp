#include "TextEncryptor.h"

TextEncryptor::TextEncryptor(Lab1::IEncryption *encryption) {
    SetEncryption(encryption);
}

unsigned char *TextEncryptor::Encrypt(const char *text) const {
    return m_encryption->Encrypt(text);
}


unsigned char * TextEncryptor::Decrypt(const char *encryptedText) const {
    return m_encryption->Decrypt(encryptedText);
}

void TextEncryptor::SetEncryption(Lab1::IEncryption *encryption) {
    if (encryption != nullptr) {
        m_encryption = encryption;
    }
}
