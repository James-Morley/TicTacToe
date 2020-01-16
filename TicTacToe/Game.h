#include "pch.h"
#include "Board.h"

#ifndef GAME
#define GAME

class Game {

	private:
		Board board;

		bool player1;

	public:
		
		//Constructors
		Game();
		Game(const Board& board);

		~Game();

		//Getters and setters
		const Board& getBoard() const;
		const bool& getPlayer() const;

		void changePlayer();

		void playGame();

};

#endif // !GAME