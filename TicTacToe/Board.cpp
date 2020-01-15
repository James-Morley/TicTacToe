#include "pch.h"
#include "Board.h"

#ifndef BOARD
#define BOARD

Board::Board(const unsigned int& _rows, const unsigned int& _cols) {
	rows = _rows;
	cols = _cols;
	array = new int[rows * cols];
}

#endif // !BOARD
