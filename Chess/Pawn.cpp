#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(const Color& color, const Coordinates& coordinates) : Piece(color, coordinates) {}

string Pawn::getClassName() const
{
    return "Pawn";
}

set<CoordinatesOffset> Pawn::getPieceMoves() const
{
    set<CoordinatesOffset> pawnMoves;

    if (this->color == Color::White)
    {
        pawnMoves.insert(CoordinatesOffset(0, 1));

        if (this->coordinates.getRank() == 2) // если белые пешки на начальной позиции
        {
            pawnMoves.insert(CoordinatesOffset(0, 2));
        }
    }
    else 
    {
        pawnMoves.insert(CoordinatesOffset(0, -1));

        if (this->coordinates.getRank() == 7) // если черные пешки на начальной позиции
        {
            pawnMoves.insert(CoordinatesOffset(0, -2));
        }
    }

    set<CoordinatesOffset> pawnAttacks = getPieceAttacks();
    pawnMoves.insert(pawnAttacks.begin(), pawnAttacks.end());

    return pawnMoves;
}

set<CoordinatesOffset> Pawn::getPieceAttacks() const
{
    set<CoordinatesOffset> pawnAttacks;

    if (this->color == Color::White)
    {
        pawnAttacks.insert(CoordinatesOffset(1, 1));
        pawnAttacks.insert(CoordinatesOffset(-1, 1));
    }
    else
    {
        pawnAttacks.insert(CoordinatesOffset(1, -1));
        pawnAttacks.insert(CoordinatesOffset(-1, -1));
    }

    return pawnAttacks;
}

bool Pawn::isSquareAvailableForMovement(const Coordinates& coords, const Board& board) const
{

    if (coordinates.getFile() == coords.getFile()) // если клетка перед ней пуста, то может двигаться
    {
        Color color = this->getColor();
        int offset = color == Color::White ? 1 : -1;
        if (
            board.isSquareEmpty(Coordinates(coordinates.getFile(), coordinates.getRank() + offset))
           )
        {
            return board.isSquareEmpty(coords);
        }
        return false;
    }
    else // удар по диагонали
    {
        if (!board.isSquareEmpty(coords))
        {
            return board.getPiece(coords)->getColor() != color;
        }
        return false;
    }
}
