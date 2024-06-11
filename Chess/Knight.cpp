#include "Knight.h"


Knight::Knight(const Color& color, const Coordinates& coordinates) : Piece(color, coordinates) {}


string Knight::getClassName() const
{
    return "Knight";
}


set<CoordinatesOffset> Knight::getPieceMoves() const
{
    set<CoordinatesOffset> knightMoves;

    knightMoves.insert(CoordinatesOffset(1, 2));
    knightMoves.insert(CoordinatesOffset(2, 1));

    knightMoves.insert(CoordinatesOffset(2, -1));
    knightMoves.insert(CoordinatesOffset(1, -2));

    knightMoves.insert(CoordinatesOffset(-1, -2));
    knightMoves.insert(CoordinatesOffset(-2, -1));

    knightMoves.insert(CoordinatesOffset(-2, 1));
    knightMoves.insert(CoordinatesOffset(-1, 2));

    return knightMoves;
}