#include "LinearPiece.h"
#include "Board.h"

LinearPiece::LinearPiece(const Color& color, const Coordinates& coordinates) : Piece(color, coordinates) {}


bool LinearPiece::isSquareAvailableForMovement(const Coordinates& coords, const Board& board) const
{
    if (Piece::isSquareAvailableForMovement(coords, board))
    {
        return isSquareAvailableForAttack(coords, board);
    }
    else
    {
        return false;
    }
}

bool LinearPiece::isSquareAvailableForAttack(const Coordinates& coords, const Board& board) const
{
    set<Coordinates> coordinatesBetween;

    if (coordinates.getFile() == coords.getFile())
    {
        coordinatesBetween = board.getCoordinatesOnVerticalBetween(coordinates, coords);
    }
    else if (coordinates.getRank() == coords.getRank())
    {
        coordinatesBetween = board.getCoordinatesOnHorizontalBetween(coordinates, coords);
    }
    else
    {
        coordinatesBetween = board.getCoordinatesOnDiagonalBetween(coordinates, coords);
    }

    for (const Coordinates& coordBetween : coordinatesBetween)
    {
        // если клетка между фигурой и целевыми координатами не пуста, то она не подходит
        if (!board.isSquareEmpty(coordBetween))
        {
            return false;
        }
    }
    return true;
}
