#include "pch.h"
#include "Game.h"
#include "Board.h"

Game::Game(const Board& _board) {
	player1 = true;
	board = _board;
}


//==========GETTERS AND SETTERS==========

const bool& Game::getPlayer() const {
	return player1;
}

void Game::changePlayer() {
	player1 = !player1;
}