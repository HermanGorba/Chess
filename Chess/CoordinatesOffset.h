#pragma once
class CoordinatesOffset
{
private:
	int fileOffset;
	int rankOffset;

public:
	CoordinatesOffset(const int& fileOffset, const int& rankOffset);

	// геттеры

	int getFileOffset() const;
	int getRankOffset() const;

	// операторы сравнения

	bool operator>(const CoordinatesOffset& coordinatesOffset) const;
	bool operator<(const CoordinatesOffset& coordinatesOffset) const;
	bool operator==(const CoordinatesOffset& coordinatesOffset) const;
};

