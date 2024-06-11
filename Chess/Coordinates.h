#pragma once
#include "File.h"
#include "CoordinatesOffset.h"

class Coordinates
{
private:
	File file;
	int rank;

public:
	Coordinates(const File& file, const int& rank);

    bool operator>(const Coordinates& coordinates) const;
    bool operator<(const Coordinates& coordinates) const;
	bool operator==(const Coordinates& coordinates) const;

	File getFile() const;
	int getRank() const;

	Coordinates offset(const CoordinatesOffset& coordinatesOffset) const;
	bool canOffset(const CoordinatesOffset& coordinatesOffset) const;
};

