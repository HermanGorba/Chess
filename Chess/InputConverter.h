#pragma once
#include <set>


enum class Color;
class Coordinates;
class Board;

class InputConverter
{
public:
	static Coordinates getInput();
	static Coordinates getInputPieceSelection(const Color& color, const Board& board);
	static Coordinates getInputAvailablePieceMove(const std::set<Coordinates>& availableSquaresForMovement);
};

