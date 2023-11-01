#ifndef TEXTENCRYPTOR_H
#define TEXTENCRYPTOR_H

#include <string>

class TextEncryptor {
private:
    int m_key;

public:
    explicit TextEncryptor(const std::string& encryptionKey);

    std::string Encrypt(const std::string& text) const;
    std::string Decrypt(const std::string& encryptedText) const;
};

#endif
