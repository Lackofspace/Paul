cmake_minimum_required(VERSION 3.23)
project(1_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(1_2 main.cpp IEncryption.h TextEncryptor.h TextEncryptor.cpp VigenereEncryption.h VigenereEncryption.cpp)
