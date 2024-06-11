#pragma once
class Board;
#include "Coordinates.h"
#include "Color.h"
#include <string>
#include <set>
#include <iostream>

using namespace std;

class Piece
{
protected:
	const Color color;
	Coordinates coordinates;

	Piece(const Color& color, const Coordinates& coordinates);

public:

	void setCoordinates(const Coordinates& newCoordinates);
	Coordinates	getCoordinates() const;
	Color getColor() const;

	virtual string getClassName() const = 0;



	set<Coordinates> getAvailableSquaresForMovement(const Board& board) const;
	set<Coordinates> getAvailableSquaresForAttack(const Board& board) const;



	virtual set<CoordinatesOffset> getPieceMoves() const = 0;
	virtual set<CoordinatesOffset> getPieceAttacks() const;



	virtual bool isSquareAvailableForMovement(const Coordinates& coords, const Board& board) const;
	virtual bool isSquareAvailableForAttack(const Coordinates& coords, const Board& board) const;
};