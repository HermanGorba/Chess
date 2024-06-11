#pragma once
#include "Piece.h"



class Knight final : public Piece
{
public:
	Knight(const Color& color, const Coordinates& coordinates);

	virtual string getClassName() const override final;

	virtual set<CoordinatesOffset> getPieceMoves() const override final;

};