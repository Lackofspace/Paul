// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.

using System.Text;
using Cryptoanalysis.Constants;
using Cryptoanalysis.Util;

namespace Cryptoanalysis;

public class Cryptoanalyzer
{
    private byte[] _fileContent = Array.Empty<byte>();
    private byte[] _key = Array.Empty<byte>();
    private static readonly int MODULE = 256;
    private static int n;
    private static int _codePage;
    public void Init(string interceptedFilename, int codePage)
    {
        _fileContent = File.ReadAllBytes(interceptedFilename);
        _codePage = codePage;
        n = GetBytesCount();
    }

    public int GetBytesCount()
    {
        return _fileContent.Length;
    }

    public bool Decode(int keyLength)
    {
        bool isSuccessDecode = true;
        List<List<byte>> chipperCharsByKeyIndex = ListExtensions.CreateList<List<byte>>(keyLength);
        chipperCharsByKeyIndex = chipperCharsByKeyIndex.Select(x => new List<byte>()).ToList();

        // считываем содержимое перехваченного сообщения и разбиваем по позициям ключам
        for (int i = 0; i < keyLength; i++)
        {
            for (int j = i; j < n; j += keyLength)
            {
                chipperCharsByKeyIndex[i].Add(_fileContent[(j) % n]);
            }
        }

        List<HashSet<byte>> result = new();
        List<byte> keyAlphabetWithCodePage = Alphabet.EncodeAlphabet(_codePage).Select(letter => (byte)letter).ToList();
        foreach (List<byte> chipperCharsByKey in chipperCharsByKeyIndex)
        {
            // вычисляем значения символа ключа на i позиции ключа
            List<List<byte>> xLists = ListExtensions.CreateList<List<byte>>(chipperCharsByKey.Count);
            xLists = xLists.Select(x => new List<byte>()).ToList();
            for (int i = 0; i < chipperCharsByKey.Count; i++)
            {
                foreach (char messageChar in Alphabet.MESSAGE_ALPHABET_CHARS)
                {
                    xLists[i].Add(MathExtensions.Mod((byte)(chipperCharsByKey[i] - messageChar), MODULE));
                }
            }

            // пересекаем полученное множество
            HashSet<byte> intersection = xLists
                .Skip(1)
                .Aggregate(
                    new HashSet<byte>(xLists.First()),
                    (h, e) => { h.IntersectWith(e); return h; }
                );
            intersection.IntersectWith(keyAlphabetWithCodePage);
            result.Add(intersection);

            // узнаем, нашли ли мы однозначный элемент на i позицию ключа
            isSuccessDecode = intersection.Count == 1;
        }

        if (isSuccessDecode)
        {
            // сохраняем ключ
            _key = result.Select(keySet => keySet.First()).ToArray();
        }

        return isSuccessDecode;
    }

    public void PrintKey()
    {
        Encoding cp866 = Encoding.GetEncoding(_codePage);
        Console.WriteLine(cp866.GetString(_key));
    }
}
