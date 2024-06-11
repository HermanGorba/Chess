#pragma once
#include "Piece.h"



class LinearPiece : public Piece
{
protected:
    LinearPiece(const Color& color, const Coordinates& coordinates);

    virtual bool isSquareAvailableForMovement(const Coordinates& coords, const Board& board) const override final;
    virtual bool isSquareAvailableForAttack(const Coordinates& coords, const Board& board) const override final;
};

