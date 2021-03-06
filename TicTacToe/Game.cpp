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

//==========DESTRUCTOR==========

Game::~Game() {}

//==========GETTERS AND SETTERS==========

const Board& Game::getBoard() const {
	return board;
}

const bool& Game::getPlayer() const {
	return player1;
}

//==========MISCELANEOUS FUNCIONS==========

bool Game::isDraw() {
	int cnt = 0;
	for (int i = 0; i < board.getSize(); i++) {
		if (board[i] == X || board[i] == O) {
			cnt++;
		}
	}
	return cnt == board.getSize() - 1;
}

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

		if (isDraw()) {
			std::cout << "THE GAME HAS ENDED IN A DRAW!" << std::endl;
			gameover = !gameover;
		}

		if (player1) {
			std::cout << "PLAYER 1'S TURN" << std::endl;
		}
		else {
			std::cout << "PLAYER 2'S TURN" << std::endl;
		}

		std::cout << board << std::endl;

		std::string symbol = Game::getPlayerSymbol();

		std::cout << "PLEASE ENTER THE POSITION WHERE YOU WOULD LIKE TO ADD THE POSITION: ";
		int index = getIndexToPlacembol();
		std::cout << std::endl;


		while (index < 0 || index >= board.getSize() || board[index] == Game::X || board[index] == Game::O) {

			std::cout << "THE POSITION IS EITHER INVALID OR HAS ANOTHER SYMBOL IN IT: ";
			index = getIndexToPlacembol();
			std::cout << std::endl;
		}

		board.addElem(symbol, index);

		if (board.checkDiagonal(symbol) || board.checkHorizontal(symbol) || board.checkVertical(symbol)) {

			std::cout << "GAMEOVER!";

			std::string winner = (player1) ? " PLAYER 1 HAS WON" : " PLAYER 1 HAS WON";

			std::cout << winner << std::endl;

			gameover = true;
		}
		 
		changePlayer();
	}
}