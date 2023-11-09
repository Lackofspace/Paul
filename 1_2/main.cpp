#include <iostream>
#include <fstream>
#include <sstream>
#include "TextEncryptor.h"
#include "VigenereEncryption.h"

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

    std::ifstream inputFile(filePath, std::ios::binary);
    if (!inputFile.is_open())
    {
        std::cout << "Unable to open specified file\n";

        return EXIT_FAILURE;
    }
    std::string originalText;
    std::stringstream stringstream;
    std::copy(std::istreambuf_iterator<char>(inputFile), std::istreambuf_iterator<char>(), std::ostreambuf_iterator<char>(stringstream));
    std::string encryptedText = encryptor.Encrypt(stringstream.str());
    std::string decryptedText = encryptor.Decrypt(encryptedText);

    std::cout << "Original Text: " << originalText << std::endl;
    std::cout << "Encrypted Text: " << encryptedText << std::endl;
    std::cout << "Decrypted Text: " << decryptedText << std::endl;

    return EXIT_SUCCESS;
}
