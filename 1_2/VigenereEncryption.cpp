#include "VigenereEncryption.h"

unsigned char *VigenereEncryption::Encrypt(const std::string &text) const {
    size_t keyLength = m_key.length();
    auto *ciphertext = new unsigned char[text.length()];

    for (int i = 0; i < text.length(); i++) {
        char plainChar = text[i];
        char keyChar = m_key[i % keyLength];

        auto encryptedChar = static_cast<unsigned char>((plainChar + keyChar) % 256);

        ciphertext[i] = encryptedChar;
    }

    return ciphertext;
}

unsigned char *VigenereEncryption::Decrypt(const std::string &cipherText) const {
    unsigned char *plaintext;
    std::string::size_type keyLength = m_key.length();

    for (int i = 0; i < cipherText.length(); i++) {
        char encryptedChar = cipherText[i];
        char keyChar = m_key[i % keyLength];

        char decryptedChar;

        decryptedChar = static_cast<char>((encryptedChar - keyChar + 256) % 256);

        plaintext += decryptedChar;
    }

    return plaintext;
}

VigenereEncryption::VigenereEncryption(const std::string &key) : m_key(key) {
}
