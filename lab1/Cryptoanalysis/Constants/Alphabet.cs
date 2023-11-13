// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.

using System.Text;

namespace Cryptoanalysis.Constants;

public static class Alphabet
{
    public static readonly List<char> MESSAGE_ALPHABET_CHARS = new()
    {
        '\n', '\r', '.', ',', '!', '?', '\'', '"', '(', ')', '-',
        ':', ' ', ';', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };

    public static readonly List<char> KEY_ALPHABET_CHARS = new()
    {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
        'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
        'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D',
        'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
        'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
        'Y', 'Z', 'А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ё', 'Ж',
        'З', 'И', 'Й', 'К', 'Л', 'М', 'Н', 'О', 'П', 'Р',
        'С', 'Т', 'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ', 'Ъ',
        'Ы', 'Ь', 'Э', 'Ю', 'Я'
    };

    public static List<char> EncodeAlphabet(int codepage)
    {
        string keyAlphabetString = new(KEY_ALPHABET_CHARS.ToArray());
        Encoding codePageEncoding = Encoding.GetEncoding(codepage);
        byte[] keyAlphabetBytes = codePageEncoding.GetBytes(keyAlphabetString);

        List<char> result = new();
        result.AddRange(keyAlphabetBytes.Select(keyAlphabetByte => (char)keyAlphabetByte));
        return result;
    }
}
