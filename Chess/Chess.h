#pragma once
#include "BoardVisualizer.h"
#include "Status.h"

class Chess
{
private:
	Board board;

	Status defineStatus(const Board& board, const Color& color);

public:
	Chess(const Board& board);
	void play();
};

