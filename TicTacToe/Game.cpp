#include "pch.h"
#include "Game.h"
#include "Board.h"
#include <iostream>

Game::Game() {
	std::cout << "IN DEFAULT CONSTRUCTOR" << std::endl;
}

Game::Game(const Board& _board) {
	player1 = true;
	gameover = true;
	board = _board;
}

Game::~Game() {
}

//==========GETTERS AND SETTERS==========

const Board& Game::getBoard() const {
	return board;
}

const bool& Game::getPlayer() const {
	return player1;
}


//==========MISCELANEOUS FUNCIONS==========

void Game::changePlayer() {
	player1 = !player1;
}

void Game::playGame() {
	if (player1) {
		std::cout << "PLAYER 1'S TURN" << std::endl;
	}
	else {
		std::cout << "PLAYER 2'S TURN" << std::endl;
	}

}