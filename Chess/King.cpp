#include "King.h"
#include "Board.h"

King::King(const Color& color, const Coordinates& coordinates) : Piece(color, coordinates) {}


string King::getClassName() const
{
	return "King";
}


set<CoordinatesOffset> King::getPieceMoves() const
{
	set<CoordinatesOffset> kingMoves;

	for (int file = -1; file <= 1; file++)
	{
		for (int rank = -1; rank <= 1; rank++)
		{
			if (file == 0 && rank == 0) continue; // король не может остаться на месте
			kingMoves.insert(CoordinatesOffset(file, rank));
		}
	}

	return kingMoves;
}


bool King::isSquareAvailableForMovement(const Coordinates& coordinates, const Board& board) const
{
	if (Piece::isSquareAvailableForMovement(coordinates, board))
	{
		if (board.isSquareAttackedByColor(coordinates, getOposite(this->getColor())))
		{
			return false;
		}
		return true;
	}
	return false;
}