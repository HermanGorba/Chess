#include "InputConverter.h"
#include "Color.h"
#include "Board.h"
#include <iostream>


Coordinates InputConverter::getInput()
{
	std::string coordinates;
	do
	{
		std::cin >> coordinates;

		if (coordinates.size() != 2)
		{
			std::wcout << "Invalid syntax" << std::endl;
			continue;
		}

		char fileChar = coordinates[0];
		if (fileChar < 'A' || (fileChar > 'H' && fileChar < 'a') || fileChar > 'h')
		{
			std::wcout << "File is not correct" << std::endl;
			continue;
		}

		char rankChar = coordinates[1];
		if (rankChar < '1' || rankChar > '8')
		{
			std::wcout << "Rank is not correct" << std::endl;
			continue;
		}

		return Coordinates(toFile(fileChar), std::atoi(&rankChar));

	} while (true);
}

Coordinates InputConverter::getInputPieceSelection(const Color& color, const Board& board)
{
	do
	{
		wcout << "Select piece: ";
		Coordinates coordinates = getInput();

		// если не пустая клетка
		if (board.isSquareEmpty(coordinates))
		{
			wcout << "Empty square" << endl;
			continue;
		}

		// если не фигура врага
		if(board.getPiece(coordinates)->getColor() != color)
		{
			wcout << "You can't select oponent's piece" << endl;
			continue;
		}

		// если у фигуры по координатам не ноль ходов
		if (board.getPiece(coordinates)->getAvailableSquaresForMovement(board).size() == 0)
		{
			wcout << "This piece has no moves" << endl;
			continue;
		}

		return coordinates;

	} while (true);
}

Coordinates InputConverter::getInputAvailablePieceMove(const set<Coordinates>& availableSquaresForMovement)
{
	do
	{
		wcout << "Select move: ";
		Coordinates finish = getInput();

		if (availableSquaresForMovement.count(finish) != 0)
		{
			return finish;
		}

	} while (true);
}





