#include "iostream"
#include <string>

#ifndef BOARD
#define BOARD

class Board {

	private:

		static const std::string X;
		static const std::string O;

		int rows;
		int cols;
		int size;
		std::string* array;

	public:
		//Constructors
		Board();
		Board(const int& rows, const int& cols);

		//Destructors
		~Board();

		//Getters and Setters
		const int& getCols() const;
		const int& getRows() const;
		const int& getSize() const;

		void setCols(const int& cols);
		void setRows(const int& rows);

		//RAII
		Board(const Board& board); //COPY CONSTRUCTOR
		Board& operator = (const Board& other); //COPY ASSIGNMENT CONSTRUCTOR

		//Add element
		void addElem(const std::string& symbol, const int& index);
		
		//Board validation
		bool checkHorizontal(const std::string& symbol) const;
		bool checkVertical(const std::string& symbol) const;
		bool checkDiagonal(const std::string& symbol) const;

		//Overloaded operators
		std::string& operator[] (const int& index);

		const std::string& operator [] (const int& index) const ;

		//friend operators
		friend std::ostream& operator << (std::ostream& os, const Board& board);

};

#endif // !BOARD