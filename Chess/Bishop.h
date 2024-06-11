#pragma once
#include "LinearPiece.h"



class Bishop final : public LinearPiece
{
public:
	Bishop(const Color& color, const Coordinates& coordinates);

	virtual string getClassName() const override final;

	virtual set<CoordinatesOffset> getPieceMoves() const override final;

};