#include <iostream>
#include <string>
#include <random>

using namespace std;

string generateRandomKey(int length) {
    string key;
    random_device rd;  // Use a hardware entropy source for better randomness
    mt19937 gen(rd());
    uniform_int_distribution<int> dis('a', 'z');

    int keyLength = int(1 + gen() % length); // Random key length not greater than length

    for (int i = 0; i < keyLength; i++) {
        key += static_cast<char>(dis(gen));
    }

    // If key is shorter than the desired length, repeat it
    while (key.length() < length) {
        key += key;
    }

    // Trim the key to the desired length
    key = key.substr(0, length);

    return key;
}

string vigenereEncrypt(const string& plaintext, const string& key) {
    std::string ciphertext;
    size_t keyLength = key.length();

    for (int i = 0; i < plaintext.length(); i++) {
        char plainChar = plaintext[i];
        char keyChar = key[i % keyLength]; // Повторение ключа

        char encryptedChar = static_cast<char>('a' + (plainChar - 'a' + keyChar - 'a') % 26);
        ciphertext += encryptedChar;
    }

    return ciphertext;
}

string vigenereDecrypt(const string& ciphertext, const string& key) {
    string plaintext;
    std::string::size_type keyLength = key.length();

    for (int i = 0; i < ciphertext.length(); i++) {
        char encryptedChar = ciphertext[i];
        char keyChar = key[i % keyLength]; // Повторение ключа

        char decryptedChar = static_cast<char>('a' + (encryptedChar - keyChar + 26) % 26);
        plaintext += decryptedChar;
    }

    return plaintext;
}

int main() {
    string plaintext = "helloworld"; // Ваш текст для шифрования
    string key = generateRandomKey(static_cast<int>(plaintext.length())); // Генерация случайного ключа

    cout << "key: " << key << endl;

    string ciphertext = vigenereEncrypt(plaintext, key);
    cout << "ciphertext: " << ciphertext << endl;

    string decryptedText = vigenereDecrypt(ciphertext, key);
    cout << "plaintext: " << decryptedText << endl;

    return 0;
}
