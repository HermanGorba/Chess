#pragma once
#include "Board.h"

class BoardVisualizer
{
private:
	static const int WhitePieceOnWhiteBackground = 127;
	static const int WhitePieceOnBlackBackground = 143;

	static const int BlackPieceOnBlackBackground = 128;
	static const int BlackPieceOnWhiteBackground = 112;

	static const int WhitePieceOnAttakedBackground = 207;
	static const int BlackPieceOnAttakedBackground = 192;

	static const int DefaultColor = 7;

public:


	static void visualize(const Board& board);
	static void visualize(const Board& board, Piece* moving);

private:
	static void printToConsoleColoredSprite(const wstring& sprite, int color);



	static int getColorForPiece(Piece* piece, bool isAttacked);
	static int getColorForSquare(const Coordinates& coordinates, bool isAttacked);



	static wstring getEmptySprite();
	static wstring getPieceSprite(Piece* piece);
};

