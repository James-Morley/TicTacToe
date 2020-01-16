#include "pch.h"
#include "Game.h"
#include "Board.h"
#include <iostream>

//==========INITIALISE STATIC MEMBERS==========

const std::string Game::X = "X";
const std::string Game::O = "O";

//==========CONSTRUCTORS==========
Game::Game() {}

Game::Game(const Board& _board) {
	player1 = true;
	gameover = false;
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

int& Game::getIndexToPlacembol() const {
	int index = -1;

	while (index < 0 || index >= board.getSize()) {
		std::cin >> index;
	}

	return index;
}

const std::string& Game::getPlayerSymbol() {
	return (player1 == true) ? Game::X : Game::O;
}

void Game::playGame() {
	
	while (!gameover) {

		if (player1) {
			std::cout << "PLAYER 1'S TURN" << std::endl;
		}
		else {
			std::cout << "PLAYER 2'S TURN" << std::endl;
		}

		std::string symbol = Game::getPlayerSymbol();

		int index = getIndexToPlacembol();

		board.addElem(symbol, index);

		if (board.checkDiagonal(symbol) || board.checkHorizontal(symbol) || board.checkVertical(symbol)) {
			std::cout << "GAMEOVER!" << std::endl;
			gameover = true;
		}
		
		std::cout << board << std::endl;

		changePlayer();
	}
}