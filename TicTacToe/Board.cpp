#include "pch.h"
#include "Board.h"
#include <string>

//==========CONSTRUCTORS==========

Board::Board() {
	rows = 0;
	cols = 0;
	size = 0;
}

Board::Board(const int& _rows, const int& _cols) {

	rows = _rows;
	cols = _cols;
	size = _rows * _cols;
	array = new std::string[rows * cols];

	for (int i = 0; i < size; i++) { array[i] = std::to_string(i); }
}

//==========DESTRUCTORS==========

Board::~Board() {
	delete[] array;
	array = nullptr;
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

//==========RAII==========

//COPY CONSTRUCTOR
Board::Board(const Board& board) {

	rows = board.getRows();
	cols = board.getCols();
	size = board.getSize();

	array = new std::string[size];

	for (int i = 0; i < board.getSize(); i++) {
		array[i] = board[i];
	}
}

//COPY ASSIGNMENT CONSTRUCTOR
Board& Board::operator=(const Board& other) {

	if (this != &other) {

		delete[] array;
		array = nullptr;

		rows = other.getRows();
		cols = other.getCols();
		size = other.getSize();
		
		array = new std::string[size];

		for (int i = 0; i < size; i++) {
			array[i] = other[i];
		}

	}
	return *this;
}

//==========CHECK POSITION==========

bool Board::checkPositionIsEmpty(const int& i) const { //Returns true if the array at the given index is empty
	return !(array[i] == "X" || array[i] == "O");
}

//==========ADD AN ELEMENT==========

void Board::addElem(const std::string& symbol, const int& index) {

	bool valid = false;

	while (!valid) {

		if (index < 0) {

			std::cout << "INDEX VALUE CAN'T BE NEGATIVE" << std::endl;

		}
		else if (index >= size ) {

			std::cout << "INDEX VALUE CAN'T BE GRETER THAN ARRAY SIZE" << std::endl;

		}
		else if (array[index] == "X" || array[index] == "O") {

			std::cout << "CAN'T ADD SYMBOL TO A CELL THAT ALREADY HAS A SYMBOL" << std::endl;
			break;

		}
		else {

			array[index] = symbol;
			valid = true;
		}
	}
}

//==========BOARD VALIDATION==========

bool Board::checkHorizontal(const std::string& symbol) const {

	bool top = array[0] == symbol && array[1] == symbol && array[2] == symbol;

	bool middle = array[3] == symbol && array[4] == symbol && array[5] == symbol;

	bool bottom = array[6] == symbol && array[7] == symbol && array[8] == symbol;

	return top || middle || bottom;
}

bool Board::checkVertical(const std::string& symbol) const {

	bool left = array[0] == symbol && array[3] == symbol && array[6] == symbol;

	bool middle = array[1] == symbol && array[4] == symbol && array[7] == symbol;

	bool right = array[2] == symbol && array[5] == symbol && array[8] == symbol;

	return left || middle || right;
}

bool Board::checkDiagonal(const std::string& symbol) const {

	bool topLeftToBotRight = array[0] == symbol && array[4] == symbol && array[8] == symbol;

	bool topRightToBotLeft = array[2] == symbol && array[4] == symbol && array[6] == symbol;

	return topLeftToBotRight || topRightToBotLeft;
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

	std::string line = "-----------";

	os << line << "\n";

	for (int i = 0; i < board.getSize(); i++) {

		std::string temp = (board.array[i] == "X" || board.array[i] == "O") ? board.array[i] : std::to_string(i);

		std::string bar = " " + temp + " |";
		std::string end = " " + temp + " ";

		switch (i) {
			case 0: os << bar;
				break;
			case 1: os << bar;
				break;
			case 2: os << end << "\n" << line << "\n"; 
				break;
			case 3: os << bar;
				break;
			case 4: os << bar;
				break;
			case 5: os << end << "\n" << line << "\n";
				break;
			case 6: os << bar;
				break;
			case 7: os << bar;
				break;
			case 8: os << end << "\n" << line << "\n";
				break;
		}
	}
	os << std::endl;
	return os;
}


//==========HASHING OPERATOR==========

std::size_t Board::operator () (const Board& board) const {
	return 13;
}