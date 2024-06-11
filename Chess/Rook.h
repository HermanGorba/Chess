#pragma once
#include "LinearPiece.h"



class Rook final : public LinearPiece
{
public:
	Rook(const Color& color, const Coordinates& coordinates);

	virtual string getClassName() const override final;

	virtual set<CoordinatesOffset> getPieceMoves() const override final;

};