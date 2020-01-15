#include "pch.h"
#include "Board.h"

#ifndef BOARD
#define BOARD

Board::Board(const int& _rows, const int& _cols) {
	rows = _rows;
	cols = _cols;
	size = _rows * _cols;
	array = new int[rows * cols];
}

//==========DESTRUCTORS==========

Board::~Board() {
	delete[] array;
}

//==========GETTERS AND SETTERS==========

const int& Board::getRows() const {
	return rows;
}

const int& Board::getCols() const {
	return cols;
}

const int& Board::getSize() const {
	return size;
}

void Board::setCols(const int& _cols) {
	cols = _cols;
}

void Board::setRows(const int& _rows) {
	rows = _rows;
}

//==========OVERLOADED OPERATORS==========

int& Board::operator [] (const int& index)  {
	return array[index];
}

const int& Board::operator [] (const int& index) const {
	return array[index];
}

//==========FRIEND OPERATORS==========

std::ostream& operator << (std::ostream& os, const Board& board) {

	for (int i = 0; i < board.getSize(); ++i) {
		if (i % board.getRows() == 0) {
			os << "\n";
		} 
		else {
			int value = board[i];
			os << value  << " ";
		}
	}
	return os;
}

#endif // !BOARD
