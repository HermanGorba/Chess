#include "Chess.h"
#include "InputConverter.h"
#include <io.h>
#include <fcntl.h>

Chess::Chess(const Board& board) : board{ board } {}

void Chess::play()
{
	int mode = _setmode(_fileno(stdout), _O_WTEXT);

	Color toMove = Color::White;

	Status status = defineStatus(board, toMove);

	while(status == Status::GameOn)
	{
		system("cls");

		BoardVisualizer::visualize(board);


		Coordinates start = InputConverter::getInputPieceSelection(toMove, board);

		BoardVisualizer::visualize(board, board.getPiece(start));

		Coordinates finish = InputConverter::getInputAvailablePieceMove
		(
			board.getPiece(start)->getAvailableSquaresForMovement(board)
		);

		if (board.isKingCheckedAfterMove(start, finish, toMove))
		{
			wcout << "Your king is checked" << endl;
			system("pause");
			continue;
		}
		else
		{
			board.movePiece(start, finish);

			toMove = getOposite(toMove);

			status = defineStatus(board, toMove);
		}
	}

	BoardVisualizer::visualize(board);

	if (status == Status::CheckMateToBlack)
	{
		wcout << "Checkmate to black";
	}
	else if (status == Status::CheckmateToWhite)
	{
		wcout << "Checkmate to white";
	}
	else
	{
		wcout << "Stalemate";
	}
	wcout << endl;

	system("pause");
}


Status Chess::defineStatus(const Board& board, const Color& color)
{
	Piece* king = board.getKingByColor(color);

	if (board.isSquareAttackedByColor(king->getCoordinates(), getOposite(color)))
	{
		set<Piece*> ourPieces = board.getPiecesByColor(color);

		for (Piece* piece : ourPieces)
		{
			set<Coordinates> availableSquaresForMovement = piece->getAvailableSquaresForMovement(board);

			for (const auto& coordinates : availableSquaresForMovement)
			{
				Board newBoard = board;
				Piece* newKing = newBoard.getKingByColor(color);

				newBoard.movePiece(piece->getCoordinates(), coordinates);

				if (!newBoard.isSquareAttackedByColor(newKing->getCoordinates(), getOposite(color)))
				{
					return Status::GameOn;
				}
			}
		}

		return color == Color::White ? Status::CheckmateToWhite : Status::CheckMateToBlack;
	}
	else
	{
		for (const auto& piece : board.getPiecesByColor(color))
		{
			if (piece->getAvailableSquaresForMovement(board).size() > 0)
			{
				return Status::GameOn;
			}
		}

		return Status::Stalemate;
	}
}
