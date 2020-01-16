#include "pch.h"
#include "Board.h"

#ifndef GAME
#define GAME

class Game {

	//Initialise static members
	static const std::string X;
	static const std::string O;

	private:
		Board board;

		bool player1;
		bool gameover;

	public:
		
		//Constructors
		Game();
		Game(const Board& board);

		~Game();

		//Getters and setters
		const Board& getBoard() const;
		const bool& getPlayer() const;

		//Miscelaneous functions

		void changePlayer();

		int& getIndexToPlacembol() const;

		const std::string& getPlayerSymbol();

		void playGame();

};

#endif // !GAME