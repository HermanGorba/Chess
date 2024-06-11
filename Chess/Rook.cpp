#include "Rook.h"


Rook::Rook(const Color& color, const Coordinates& coordinates) : LinearPiece(color, coordinates) {}


string Rook::getClassName() const
{
    return "Rook";
}


set<CoordinatesOffset> Rook::getPieceMoves() const
{
    set<CoordinatesOffset> rookMoves;

    for (int i = -boardSize + 1; i < boardSize; i++)
    {
        if (i == 0) continue; // ладья не может остаться на месте
        rookMoves.insert(CoordinatesOffset(i, 0));
        rookMoves.insert(CoordinatesOffset(0, i));
    }

    return rookMoves;
}