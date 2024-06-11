#include "Piece.h"
#include "Board.h"

Piece::Piece(const Color& color, const Coordinates& coordinates)
	: color{ color }, coordinates{ coordinates }
{}



void Piece::setCoordinates(const Coordinates& newCoordinates)
{
	coordinates = newCoordinates;
}

Coordinates Piece::getCoordinates() const
{
	return coordinates;
}

Color Piece::getColor() const
{
	return color;
}



set<Coordinates> Piece::getAvailableSquaresForMovement(const Board& board) const
{
	set<Coordinates> availableSquaresForMovement;

	for (const CoordinatesOffset& coordinatesOffset : getPieceMoves())
	{
		if (coordinates.canOffset(coordinatesOffset))
		{
			Coordinates newCoordinates = coordinates.offset(coordinatesOffset);

			if (isSquareAvailableForMovement(newCoordinates, board))
			{				
				availableSquaresForMovement.insert(newCoordinates);
			}
		}
	}

	return availableSquaresForMovement;
}

set<Coordinates> Piece::getAvailableSquaresForAttack(const Board& board) const
{
	set<Coordinates> availableSquaresForAttack;

	for (const auto& pieceAttack : getPieceAttacks())
	{
		if (coordinates.canOffset(pieceAttack))
		{
			Coordinates newCoordinates = coordinates.offset(pieceAttack);

			if (isSquareAvailableForAttack(newCoordinates, board))
			{
				availableSquaresForAttack.insert(newCoordinates);
			}
		}
	}

	return availableSquaresForAttack;
}



set<CoordinatesOffset> Piece::getPieceAttacks() const
{
	return getPieceMoves();
}




bool Piece::isSquareAvailableForMovement(const Coordinates& coords, const Board& board) const
{
	return board.isSquareEmpty(coords) || board.getPiece(coords)->getColor() != color;
}

bool Piece::isSquareAvailableForAttack(const Coordinates& coords, const Board& board) const
{
	return true;
}
