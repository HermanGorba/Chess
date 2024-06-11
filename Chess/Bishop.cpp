#include "Bishop.h"


Bishop::Bishop(const Color& color, const Coordinates& coordinates) : LinearPiece(color, coordinates) {}


string Bishop::getClassName() const
{
    return "Bishop";
}


set<CoordinatesOffset> Bishop::getPieceMoves() const
{
    set<CoordinatesOffset> bishopMoves;

    for (int i = -boardSize + 1; i < boardSize; i++)
    {
        if (i == 0) continue; // ���� �� ����� �������� �� �����
        bishopMoves.insert(CoordinatesOffset(i, i));
        bishopMoves.insert(CoordinatesOffset(i, -i));
    }

    return bishopMoves;
}