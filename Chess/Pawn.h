#pragma once
#include "Piece.h"



class Pawn final: public Piece
{
public:
	Pawn(const Color& color, const Coordinates& coordinates);

	virtual string getClassName() const override final;

	virtual set<CoordinatesOffset> getPieceMoves() const override final;
	virtual set<CoordinatesOffset> getPieceAttacks() const override final;

	virtual bool isSquareAvailableForMovement(const Coordinates& coords, const Board& board) const override final;
};

