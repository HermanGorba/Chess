#include "File.h"
File operator++(File& file, int)
{
    File old = file;
    file = static_cast<File>(static_cast<int>(file) + 1);
    return old;
}

File operator--(File& file, int)
{
    File old = file;
    file = static_cast<File>(static_cast<int>(file) - 1);
    return old;
}


int toNumber(const File& file)
{
    return static_cast<int>(file);
}

std::wstring toString(const File& file)
{
    switch(toNumber(file))
    {
    case 0:
        return L"A";
        break;

    case 1:
        return L"B";
        break;

    case 2:
        return L"C";
        break;

    case 3:
        return L"D";
        break;

    case 4:
        return L"E";
        break;

    case 5:
        return L"F";
        break;

    case 6:
        return L"G";
        break;

    case 7:
        return L"H";
        break;

    default:
        return L"?";
        break;
    }
}

File toFile(const char ch)
{
    for (const auto& file : allFiles)
    {
        if (ch <= 'H')
        {            
            if (toNumber(file) == ch - 'A')
            {
                return file;
            }
        }
        else
        {
            if (toNumber(file) == ch - 'a')
            {
                return file;
            }
        }
    }
}

File toFile(int number)
{
    if (number > boardSize)
    {
        number = number % boardSize;
    }
    for (const auto& file : allFiles)
    {
        if (toNumber(file) == number)
        {
            return file;
        }
    }
    return File::A;
}

