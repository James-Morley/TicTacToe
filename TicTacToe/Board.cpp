#include "pch.h"
#include "Board.h"
#include <string>

#ifndef BOARD
#define BOARD

//==========CONSTRUCTORS==========

Board::Board(const int& _rows, const int& _cols) {
	rows = _rows;
	cols = _cols;
	size = _rows * _cols;
	array = new std::string[rows * cols];

	for (int i = 0; i < size; i++) { array[i] = "HELLO "; }

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


//==========ADD AN ELEMENT==========

void Board::addElem(const std::string& symbol, const int& index) {
	if (index >= 0 && index <= size - 1) {
		array[index] = symbol;
	}
	else {
		std::cout << "CAN'T ADD SYMBOL: " << symbol << " AT INDEX: " << index << std::endl;
	}
}

//==========OVERLOADED OPERATORS==========

std::string& Board::operator [] (const int& index)  {
	return array[index];
}

const std::string& Board::operator [] (const int& index) const {
	return array[index];
}

//==========FRIEND OPERATORS==========

std::ostream& operator << (std::ostream& os, const Board& board) {
	for (int i = 0; i < board.getRows(); i++) {
		for (int j = 0; j < board.getCols(); j++) {
			int index = i * 3 + j;
			os << board[index] << " ";
		}
		os << "\n";
	}
	return os;
}

#endif // !BOARD