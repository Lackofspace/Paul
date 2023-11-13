#include <iostream>
#include "TextEncryptor.h"
#include "VigenereEncryption.h"
#include "InputStream/FIleInputStream.h"
#include "OutputStream/FileOutputStream.h"

using namespace Lab1;

int main(int argc, char **argv) {
    setlocale(LC_ALL, "");
    std::cout
            << "Enter file path, encryption key and mode (-d | -e): -d stands for decryption and -e stands for encryption\n";
    if (argc < 3) {
        std::cout << "Missing file path in program arguments\n";

        return EXIT_FAILURE;
    }

    std::string filePath = argv[1];
    std::string encryptionKey = argv[2];
    std::string mode = argv[3];

    auto *vigenereEncryption = new VigenereEncryption(encryptionKey);
    TextEncryptor encryptor(vigenereEncryption);
    std::string originalText;

    FileInputStream fileInputStream(filePath);
    std::streamsize fileSize = fileInputStream.GetStreamSize();
    char *buffer = new char[fileSize];
    fileInputStream.ReadFile(buffer);

    unsigned char* result;
    if (mode == "-e") {
        result = encryptor.Encrypt(buffer);
    } else if (mode == "-d") {
        result = encryptor.Decrypt(buffer);
    }

    FileOutputStream fileOutputStream("output.res");
    fileOutputStream.WriteBlock(result, fileSize);

    return EXIT_SUCCESS;
}
