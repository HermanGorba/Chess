#include "ConsoleFontChanger.h"

void ConsoleFontChanger::Apply() const
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (hConsole == INVALID_HANDLE_VALUE) {
        std::cerr << "Error getting console handle" << std::endl;
        return;
    }

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    cfi.nFont = 0;
    cfi.dwFontSize.X = sizeX;
    cfi.dwFontSize.Y = sizeY;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, fontName.c_str());

    if (!SetCurrentConsoleFontEx(hConsole, FALSE, &cfi)) {
        std::cerr << "Error setting console font" << std::endl;
    }
}
