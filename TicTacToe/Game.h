#include "pch.h"
#include "Board.h"

#ifndef GAME
#define GAME

class Game {

	private:
		Board board;

		bool player1;

	public:
		

		Game(const Board& board);

		const bool& getPlayer() const;

		void changePlayer();

};

#endif // !GAME
