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

//CREATE AN AI CLASS TO SIMULATE A PLAYER IT WOULD HAVE TO BE ABLE TO ADD SYMBOLS TO THE GRID
//NEED TO CREATE A GAME TREE CLASS WHICH COULD CONTAIN THE AI LOGIC 