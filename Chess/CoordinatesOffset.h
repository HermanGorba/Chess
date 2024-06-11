#pragma once
class CoordinatesOffset
{
private:
	int fileOffset;
	int rankOffset;

public:
	CoordinatesOffset(const int& fileOffset, const int& rankOffset);

	// �������

	int getFileOffset() const;
	int getRankOffset() const;

	// ��������� ���������

	bool operator>(const CoordinatesOffset& coordinatesOffset) const;
	bool operator<(const CoordinatesOffset& coordinatesOffset) const;
	bool operator==(const CoordinatesOffset& coordinatesOffset) const;
};

