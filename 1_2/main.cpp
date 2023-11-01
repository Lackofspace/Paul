#include <iostream>
#include "TextEncryptor.h"

int main() {
    std::string encryptionKey = "9";
    TextEncryptor encryptor(encryptionKey);

    std::string originalText = "Hello,\rMyname\n007";
    std::string encryptedText = encryptor.Encrypt(originalText);
    std::string decryptedText = encryptor.Decrypt(encryptedText);

    std::cout << "Original Text: " << originalText << std::endl;
    std::cout << "Encrypted Text: " << encryptedText << std::endl;
    std::cout << "Decrypted Text: " << decryptedText << std::endl;

    return 0;
}
