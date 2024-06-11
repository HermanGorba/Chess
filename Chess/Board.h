#pragma once
class Piece;
#include <map>
#include <windows.h>
#include "Coordinates.h"
#include "Piece.h"

using namespace std;


class Board
{
private:
	map<Coordinates, Piece*> pieces;

public:
	Board();
	Board(const Board& board);
	~Board();


	
	void setPiece(const Coordinates& coordinates, Piece* piece);
	void setPieceByChar(const char ch, const Coordinates& coordinates);
	void removePiece(const Coordinates& coordinates);
	void movePiece(const Coordinates& start, const Coordinates& finish);

	Piece* getPiece(const Coordinates& coordinates) const;
	set<Piece*> getPiecesByColor(const Color& color) const;
	Piece* getKingByColor(const Color& color) const;



	void setDefaultPiecesPositions();
	void setFENPosition(const string& FEN);



	static const bool isSquareBlack(const Coordinates& coordinates);
	bool isSquareEmpty(const Coordinates& coordinates) const;
	bool isSquareAttackedByColor(const Coordinates& coordinates, const Color& color) const;
	bool isKingCheckedAfterMove(const Coordinates& start, const Coordinates& finish, const Color& color) const;


	set<Coordinates> getCoordinatesOnDiagonalBetween(const Coordinates& start, const Coordinates& finish) const;
	set<Coordinates> getCoordinatesOnHorizontalBetween(const Coordinates& start, const Coordinates& finish) const;
	set<Coordinates> getCoordinatesOnVerticalBetween(const Coordinates& start, const Coordinates& finish) const;
};
