#include "Chess.h"
#include "ConsoleFontChanger.h"

int main()
{
	ConsoleFontChanger fontChanger(L"MS Gothic", 20, 32);
	fontChanger.Apply();

	Board board;
	board.setDefaultPiecesPositions();

	Chess chess(board);
	chess.play();
}

