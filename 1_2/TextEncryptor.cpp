#include "TextEncryptor.h"
#include "CharacterUtils.h"
#include <iostream>

TextEncryptor::TextEncryptor(const std::string& encryptionKey) {
    std::string customEncoding = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    try {
        if (!IsCharBelongsToKeyAlphabet(encryptionKey[0], customEncoding)) {
            throw std::runtime_error("Invalid key format. Key must belong to the custom encoding alphabet.");
        }

        m_key = GetKeyCharCode(encryptionKey[0], customEncoding);
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

std::string TextEncryptor::Encrypt(const std::string& text) const {
    std::string encryptedText;

    try {
        for (char c : text) {
            if (!IsCharBelongsToPlaintextAlphabet(static_cast<int>(c))) {
                throw std::runtime_error("Symbol `" + std::string(1, c) + "` does not belong to plaintext "
                                                                          "alphabet.\nEncryption failed!");
            }
            int encryptedChar = (static_cast<int>(c) + m_key) % 256;
            encryptedText += static_cast<char>(encryptedChar);
        }
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return encryptedText;
}


std::string TextEncryptor::Decrypt(const std::string& encryptedText) const {
    std::string decryptedText;
    for (char c : encryptedText) {
        int decryptedChar = (static_cast<int>(c) - m_key + 256) % 256;
        decryptedText += static_cast<char>(decryptedChar);
    }
    return decryptedText;
}
