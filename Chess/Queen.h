#pragma once
#include "LinearPiece.h"



class Queen final : public LinearPiece
{
public:
	Queen(const Color& color, const Coordinates& coordinates);

	virtual string getClassName() const override final;

	virtual set<CoordinatesOffset> getPieceMoves() const override final;

};