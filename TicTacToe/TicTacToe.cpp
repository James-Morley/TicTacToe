#include "pch.h"
#include "Board.h"
#include "Game.h"
#include <iostream>
#include <vector>
#include <map>
#include <functional>

int main()
{
	
	Board board(3, 3);

	Game game(board);

	game.playGame();

}