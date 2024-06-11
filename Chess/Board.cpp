#include "Board.h"
#include <sstream>
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"

Board::Board() {}

Board::Board(const Board& board)
{
	for (const auto& element : board.pieces)
	{
		string className = element.second->getClassName();
		Color color = element.second->getColor();


		if (className == "Pawn")
		{
			setPiece(element.first, new Pawn(color, element.first));
		}
		else if (className == "Bishop")
		{
			setPiece(element.first, new Bishop(color, element.first));
		}
		else if (className == "Knight")
		{
			setPiece(element.first, new Knight(color, element.first));
		}
		else if (className == "Rook")
		{
			setPiece(element.first, new Rook(color, element.first));
		}
		else if (className == "Queen")
		{
			setPiece(element.first, new Queen(color, element.first));
		}
		else if (className == "King")
		{
			setPiece(element.first, new King(color, element.first));
		}
		else
		{
			cout << "Board copy ctor error" << endl;
		}
	}
}

Board::~Board()
{
	for (const auto& element : pieces)
	{
		delete element.second;
	}
}




void Board::setPiece(const Coordinates& coordinates, Piece* piece)
{
	piece->setCoordinates(coordinates);
	pieces.insert(make_pair(coordinates, piece));
}

void Board::setPieceByChar(const char ch, const Coordinates& coordinates)
{
	Color color;

	if (ch <= 'R' && ch >= 'B')
	{
		color = Color::White;

		switch (ch)
		{
		case 'P':
			setPiece(coordinates, new Pawn(color, coordinates));
			break;

		case'N':
			setPiece(coordinates, new Knight(color, coordinates));
			break;

		case 'B':
			setPiece(coordinates, new Bishop(color, coordinates));
			break;

		case 'R':
			setPiece(coordinates, new Rook(color, coordinates));
			break;

		case 'Q':
			setPiece(coordinates, new Queen(color, coordinates));
			break;

		case 'K':
			setPiece(coordinates, new King(color, coordinates));
			break;

		default:
			throw invalid_argument("Invalid FEN syntax");
			break;
		}
	}
	else if (ch <= 'r' && ch >= 'b')
	{
		color = Color::Black;

		switch (ch)
		{
		case 'p':
			setPiece(coordinates, new Pawn(color, coordinates));
			break;

		case 'n':
			setPiece(coordinates, new Knight(color, coordinates));
			break;

		case 'b':
			setPiece(coordinates, new Bishop(color, coordinates));
			break;

		case 'r':
			setPiece(coordinates, new Rook(color, coordinates));
			break;

		case 'q':
			setPiece(coordinates, new Queen(color, coordinates));
			break;

		case 'k':
			setPiece(coordinates, new King(color, coordinates));
			break;

		default:
			throw invalid_argument("Invalid FEN syntax");
			break;
		}
	}
	else
	{
		throw invalid_argument("Invalid FEN syntax");
	}
}

void Board::removePiece(const Coordinates& coordinates)
{
	pieces.erase(coordinates);
}

void Board::movePiece(const Coordinates& start, const Coordinates& finish)
{
	Piece* piece = getPiece(start);
	if (!isSquareEmpty(finish))
	{
		removePiece(finish);
	}
	removePiece(start);
	setPiece(finish, piece);
}


Piece* Board::getPiece(const Coordinates& coordinates) const
{
	return pieces.at(coordinates);
}

set<Piece*> Board::getPiecesByColor(const Color& color) const
{
	set<Piece*> enemyPieces;

	for (const auto& piece : pieces)
	{
		if (piece.second->getColor() == color)
		{
			enemyPieces.insert(piece.second);
		}
	}

	return enemyPieces;
}

Piece* Board::getKingByColor(const Color& color) const
{
	for (Piece* piece : getPiecesByColor(color))
	{
		if (piece->getClassName() == "King")
		{
			return piece;
		}
	}
	return nullptr;
}


void Board::setDefaultPiecesPositions()
{
	setFENPosition("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
}


// Forsyth–Edwards Notation
void Board::setFENPosition(const string& FEN)
{
	stringstream notation(FEN);
	// rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1

	string piecesPositionInFEN;
	notation >> piecesPositionInFEN;
	//rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR

	stringstream piecesPosition(piecesPositionInFEN);
	string allRanks[boardSize];
	string rankString;


	int iterator = 0;
	while (getline(piecesPosition, rankString, '/'))
	{
		allRanks[iterator++] = rankString;
	}

	int rank;
	for (int i = 0; i < boardSize; i++)
	{
		rank = boardSize - i;
		rankString = allRanks[i];

		int fileIndex = 0;
		for (int j = 0; j < rankString.size(); j++)
		{
			char ch = rankString[j];

			if (ch >= '1' && ch <= '8')
			{
				fileIndex += atoi(&ch);
			}
			else
			{
				File file = toFile(fileIndex++);
				Coordinates coordinates(file, rank);

				try
				{
					setPieceByChar(ch, coordinates);
				}
				catch (const invalid_argument& ex)
				{
					cout << ex.what();
					system("pause");
				}
				catch (...)
				{
					cout << "Something went wrong.." << endl;
					system("pause");
				}
			}
		}
	}


}




const bool Board::isSquareBlack(const Coordinates& coordinates)
{
	return (toNumber(coordinates.getFile()) + 1 + coordinates.getRank()) % 2 == 0;
}

bool Board::isSquareEmpty(const Coordinates& coordinates) const
{
	return pieces.count(coordinates) == 0;
}

bool Board::isSquareAttackedByColor(const Coordinates& coordinates, const Color& color) const
{
	for (const auto& piece : getPiecesByColor(color))
	{
		set<Coordinates> availableSquaresForAttack = piece->getAvailableSquaresForAttack(*this);

		if (availableSquaresForAttack.count(coordinates) > 0)
		{
			return true;
		}
	}

	return false;
}

bool Board::isKingCheckedAfterMove(const Coordinates& start, const Coordinates& finish, const Color& color) const
{
	Board newBoard = *this;
	Piece* king = newBoard.getKingByColor(color);
	newBoard.movePiece(start, finish);
	Coordinates kingCoordinates = king->getCoordinates();

	return newBoard.isSquareAttackedByColor(kingCoordinates, getOposite(color));
}


set<Coordinates> Board::getCoordinatesOnDiagonalBetween(const Coordinates& start, const Coordinates& finish) const
{
	set<Coordinates> coordinatesBetween;


	int fileOffset = start.getFile() < finish.getFile() ? 1 : -1;
	int rankOffset = start.getRank() < finish.getRank() ? 1 : -1;

	for
		(
			int file = toNumber(start.getFile()) + fileOffset,
			rank = start.getRank() + rankOffset;

			file != toNumber(finish.getFile()) && rank != finish.getRank();

			file += fileOffset, rank += rankOffset
			)
	{
		coordinatesBetween.insert(Coordinates(toFile(file), rank));
	}
	return coordinatesBetween;
}

set<Coordinates> Board::getCoordinatesOnHorizontalBetween(const Coordinates& start, const Coordinates& finish) const
{
	set<Coordinates> coordinatesBetween;
	int fileOffset = start.getFile() < finish.getFile() ? 1 : -1;

	for
		(
			int file = toNumber(start.getFile()) + fileOffset;
			file != toNumber(finish.getFile());
			file += fileOffset
			)
	{
		coordinatesBetween.insert(Coordinates(toFile(file), start.getRank()));
	}
	return coordinatesBetween;
}

set<Coordinates> Board::getCoordinatesOnVerticalBetween(const Coordinates& start, const Coordinates& finish) const
{
	set<Coordinates> coordinatesBetween;
	int rankOffset = start.getRank() < finish.getRank() ? 1 : -1;

	for
		(
			int rank = start.getRank() + rankOffset;
			rank != finish.getRank();
			rank += rankOffset
			)
	{
		coordinatesBetween.insert(Coordinates(start.getFile(), rank));
	}
	return coordinatesBetween;
}