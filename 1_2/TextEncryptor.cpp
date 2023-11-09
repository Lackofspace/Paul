#include "TextEncryptor.h"

TextEncryptor::TextEncryptor(IEncryption* encryption): m_encryption(encryption)
{
}

std::string TextEncryptor::Encrypt(char* text) const
{
    return m_encryption->Encrypt(text);
}


std::string TextEncryptor::Decrypt(char* encryptedText) const {
    return m_encryption->Decrypt(encryptedText);
}
