#pragma once
#include <windows.h>
#include <iostream>
#include <string>

class ConsoleFontChanger
{
private:
    std::wstring fontName;
    SHORT sizeX;
    SHORT sizeY;

public:
    ConsoleFontChanger(const std::wstring& fontName, SHORT sizeX, SHORT sizeY)
        : fontName(fontName), sizeX(sizeX), sizeY(sizeY) {}

    void Apply() const;
};

