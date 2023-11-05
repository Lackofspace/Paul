#include "VigenereEncryption.h"


std::string VigenereEncryption::Encrypt(const std::string &text) const {
    std::string ciphertext;
    size_t keyLength = m_key.length();

    for (int i = 0; i < text.length(); i++) {
        char plainChar = text[i];
        char keyChar = m_key[i % keyLength];

        char encryptedChar = static_cast<char>('a' + (plainChar - 'a' + keyChar - 'a') % 26);
        ciphertext += encryptedChar;
    }

    return ciphertext;
}

std::string VigenereEncryption::Decrypt(const std::string &cipherText) const {
    std::string plaintext;
    std::string::size_type keyLength = m_key.length();

    for (int i = 0; i < cipherText.length(); i++) {
        char encryptedChar = cipherText[i];
        char keyChar = m_key[i % keyLength];

        char decryptedChar = static_cast<char>('a' + (encryptedChar - keyChar + 26) % 26);
        plaintext += decryptedChar;
    }

    return plaintext;
}
