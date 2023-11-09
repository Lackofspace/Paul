#include <iostream>
#include "TextEncryptor.h"
#include "VigenereEncryption.h"
#include "InputStream/FIleInputStream.h"

int main(int argc, char** argv) {
    std::cout << "Enter file path and encryption key\n";
    if (argc < 2)
    {
        std::cout << "Missing file path in program arguments\n";

        return EXIT_FAILURE;
    }

    std::string filePath = argv[1];
    std::string encryptionKey = argv[2];

    auto* vigenereEncryption = new VigenereEncryption(encryptionKey);
    TextEncryptor encryptor(vigenereEncryption);
    std::string originalText;

    FileInputStream fileInputStream(filePath);
    char* buffer = new char[fileInputStream.GetStreamSize()];
    fileInputStream.ReadFile(buffer);
    std::string encryptedText = encryptor.Encrypt(buffer);
    std::string decryptedText = encryptor.Decrypt(const_cast<char *>(encryptedText.c_str()));

    std::cout << "Original Text: " << buffer << std::endl;
    std::cout << "Encrypted Text: " << encryptedText << std::endl;
    std::cout << "Decrypted Text: " << decryptedText << std::endl;

    return EXIT_SUCCESS;
}
