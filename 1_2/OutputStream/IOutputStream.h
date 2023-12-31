#pragma once

#include <cstdint>
#include <ios>
#include <memory>

class IOutputStream
{
public:
    // Записывает в поток данных байт
    // Выбрасывает исключение std::ios_base::failure в случае ошибки
    virtual void WriteByte(uint8_t data) = 0;

    // Записывает в поток блок данных размером size байт,
    // располагающийся по адресу srcData,
    // В случае ошибки выбрасывает исключение std::ios_base::failure
    virtual void WriteBlock(const void* srcData, std::streamsize size) = 0;

    virtual ~IOutputStream() = default;
};

typedef std::unique_ptr<IOutputStream> IOutputStreamPtr;