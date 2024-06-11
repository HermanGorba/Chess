#include "Queen.h"


Queen::Queen(const Color& color, const Coordinates& coordinates) : LinearPiece(color, coordinates) {}


string Queen::getClassName() const
{
	return "Queen";
}


set<CoordinatesOffset> Queen::getPieceMoves() const
{
    set<CoordinatesOffset> queenMoves;

    for (int i = -boardSize + 1; i < boardSize; i++)
    {
        if (i == 0) continue; // ферзь не может остаться на месте
        queenMoves.insert(CoordinatesOffset(i, i));
        queenMoves.insert(CoordinatesOffset(i, -i));
        queenMoves.insert(CoordinatesOffset(i, 0));
        queenMoves.insert(CoordinatesOffset(0, i));
    }

    return queenMoves;
}