#include "pch.h"
#include "Board.h"
#include <iostream>

int main()
{
	
	int mod = 0 % 3;

	std::cout << "MOD: " << mod << std::endl;

	Board board(3, 3);

	std::cout << board.getCols() << std::endl;
	std::cout << board.getRows() << std::endl;
	std::cout << board.getSize() << std::endl;



	std::cout << board << std::endl;

}
