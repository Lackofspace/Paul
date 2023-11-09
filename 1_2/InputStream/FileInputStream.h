#pragma once
#include <fstream>
#include "IInputStream.h"

#include <ios>

class FileInputStream : public IInputStream
{
public:
    explicit FileInputStream(const std::string& fileName);

    bool IsEOF() const override;

    uint8_t ReadByte() override;

    std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) override;

    // Считываем аналогично методу ReadFile без указания размера size: его считаем равным всему размеру файла
    std::streamsize ReadFile(void* dstBuffer);

    std::streamsize GetStreamSize();

private:
    std::ifstream m_inputFile;
};