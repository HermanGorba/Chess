#include "BoardVisualizer.h"
#include "Board.h"
#include <iostream>

void BoardVisualizer::visualize(const Board& board)
{
	visualize(board, nullptr);
}

void BoardVisualizer::visualize(const Board& board, Piece* moving)
{
	system("cls");

	set<Coordinates> availableSquaresForMovement;
	if (moving != nullptr)
	{
		availableSquaresForMovement = moving->getAvailableSquaresForMovement(board);
	}

	for (int rank = boardSize; rank > 0; rank--)
	{
		wcout << " " <<  rank << " ";

		for (File file : allFiles)
		{
			Coordinates coordinates(file, rank);

			bool isAttacked = availableSquaresForMovement.count(coordinates) == 0 ? false : true;

			if (board.isSquareEmpty(coordinates))
			{
				printToConsoleColoredSprite
				(
					getEmptySprite(), getColorForSquare(coordinates, isAttacked)
				);
			}
			else
			{
				printToConsoleColoredSprite(getPieceSprite
				(
					board.getPiece(coordinates)), getColorForPiece(board.getPiece(coordinates), isAttacked)
				);
			}
		}
		wcout << endl;
	}

	
	wcout << "   ";
	for (const File& file : allFiles)
	{
		wcout << " " << toString(file) << " ";
	}
	wcout << endl;
}

void BoardVisualizer::printToConsoleColoredSprite(const wstring& sprite, int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	wcout << sprite;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DefaultColor);
}



int BoardVisualizer::getColorForPiece(Piece* piece, bool isAttacked)
{
	if (piece->getColor() == Color::Black)
	{
		if (isAttacked)
		{
			return BlackPieceOnAttakedBackground;
		}
		else if (Board::isSquareBlack(piece->getCoordinates()))
		{
			return BlackPieceOnBlackBackground;
		}
		else
		{
			return BlackPieceOnWhiteBackground;
		}
	}
	else
	{
		return getColorForSquare(piece->getCoordinates(), isAttacked);
	}
}

int BoardVisualizer::getColorForSquare(const Coordinates& coordinates, bool isAttacked)
{
	if (isAttacked)
	{
		return WhitePieceOnAttakedBackground;
	}
	else if (Board::isSquareBlack(coordinates))
	{
		return WhitePieceOnBlackBackground;
	}
	else
	{
		return WhitePieceOnWhiteBackground;
	}
}



wstring BoardVisualizer::getEmptySprite()
{
	return L"   ";
}

wstring BoardVisualizer::getPieceSprite(Piece* piece)
{
	string className = piece->getClassName();

	if (className == "Pawn")
	{
		return L" \u2659 ";
	}
	else if (className == "Bishop")
	{
		return L" \u2657 ";
	}
	else if (className == "Knight")
	{
		return L" \u2658 ";
	}
	else if (className == "Rook")
	{
		return L" \u2656 ";
	}
	else if (className == "Queen")
	{
		return L" \u2655 ";
	}
	else if (className == "King")
	{
		return L" \u2654 ";
	}
	else 
	{
		return L"???";
	}
}