#include "VigenereEncryption.h"


std::string VigenereEncryption::Encrypt(const std::string &text) const {
    std::string ciphertext;
    size_t keyLength = m_key.length();

    for (int i = 0; i < text.length(); i++) {
        char plainChar = text[i];
        char keyChar = m_key[i % keyLength];

        char encryptedChar = plainChar;
        if (std::islower(plainChar)) {
            encryptedChar = static_cast<char>('a' + (plainChar - 'a' + keyChar - 'a') % 26);
        }
        if (std::isupper(plainChar))
        {
            encryptedChar = static_cast<char>('A' + (plainChar - 'A' + keyChar - 'A') % 26);
        }

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

        char decryptedChar = encryptedChar;
        if (std::islower(encryptedChar)) {
            decryptedChar = static_cast<char>('a' + (encryptedChar - keyChar + 26) % 26);
        }
        if (std::isupper(encryptedChar))
        {
            decryptedChar = static_cast<char>('A' + (encryptedChar - keyChar + 26) % 26);
        }

        plaintext += decryptedChar;
    }

    return plaintext;
}

VigenereEncryption::VigenereEncryption(const std::string& key): m_key(key) {
}
