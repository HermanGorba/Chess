#include "Coordinates.h"

Coordinates::Coordinates(const File& file, const int& rank) : file{ file }, rank{ rank } {}


bool Coordinates::operator>(const Coordinates& coordinates) const
{
    if (file == coordinates.file)
        return rank > coordinates.rank;
    return file > coordinates.file;
}

bool Coordinates::operator<(const Coordinates& coordinates) const
{
    if (file == coordinates.file)
        return rank < coordinates.rank;
    return file < coordinates.file;
}

bool Coordinates::operator==(const Coordinates& coordinates) const
{
    return file == coordinates.file && rank == coordinates.rank;
}

File Coordinates::getFile() const
{
    return file;
}

int Coordinates::getRank()const
{
    return rank;
}

Coordinates Coordinates::offset(const CoordinatesOffset& coordinatesOffset) const
{
    return Coordinates
    (
        File(int(file) + coordinatesOffset.getFileOffset()), rank + coordinatesOffset.getRankOffset()
    );
}

bool Coordinates::canOffset(const CoordinatesOffset& coordinatesOffset) const
{
    int newFile = toNumber(file) + coordinatesOffset.getFileOffset();
    int newRank = rank + coordinatesOffset.getRankOffset();

    return !(newFile > boardSize - 1 || newFile < 0 || newRank > boardSize || newRank < 1);

}
