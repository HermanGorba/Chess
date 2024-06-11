#pragma once
#include <string>

enum class File
{
	A, B, C, D, E, F, G, H
};

File operator++(File& file, int);
File operator--(File& file, int);


static const File allFiles[] = { File::A, File::B, File::C, File::D, File::E, File::F, File::G, File::H };

int toNumber(const File& file);
std::wstring toString(const File& file);
File toFile(const char ch);
File toFile(int number);

static const int boardSize = 8;