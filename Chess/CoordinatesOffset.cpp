#include "CoordinatesOffset.h"

CoordinatesOffset::CoordinatesOffset(const int& fileOffset, const int& rankOffset)
	: fileOffset{ fileOffset }, rankOffset{ rankOffset } {}



int CoordinatesOffset::getRankOffset() const
{
	return rankOffset;
}

int CoordinatesOffset::getFileOffset() const
{
	return fileOffset;
}


bool CoordinatesOffset::operator>(const CoordinatesOffset& coordinatesOffset) const
{
	if (fileOffset == coordinatesOffset.fileOffset)
		return rankOffset > coordinatesOffset.rankOffset;
	return fileOffset > coordinatesOffset.fileOffset;
}

bool CoordinatesOffset::operator<(const CoordinatesOffset& coordinatesOffset) const
{
	if (fileOffset == coordinatesOffset.fileOffset)
		return rankOffset < coordinatesOffset.rankOffset;
	return fileOffset < coordinatesOffset.fileOffset;
}

bool CoordinatesOffset::operator==(const CoordinatesOffset& coordinatesOffset) const
{
	return (fileOffset == coordinatesOffset.fileOffset && rankOffset == coordinatesOffset.rankOffset);
}