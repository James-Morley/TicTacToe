#include "pch.h"
#include "Board.h"
#include "Game.h"
#include <iostream>

int main()
{
	
	Board board(3, 3);

	Game game(board);

	game.playGame();

}
