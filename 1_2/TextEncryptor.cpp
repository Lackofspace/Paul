#include "TextEncryptor.h"

TextEncryptor::TextEncryptor(IEncryption* encryption): m_encryption(encryption)
{
}

std::string TextEncryptor::Encrypt(const std::string& text) const
{
    return m_encryption->Encrypt(text);
}


std::string TextEncryptor::Decrypt(const std::string& encryptedText) const {
    return m_encryption->Decrypt(encryptedText);
}
