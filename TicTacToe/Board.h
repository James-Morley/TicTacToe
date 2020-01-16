#include "iostream"
#include <string>

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

		void addElem(const std::string& symbol, const int& index);


		//Overloaded operators
		std::string& operator[] (const int& index);

		const std::string& operator [] (const int& index) const ;

		//friend operators
		friend std::ostream& operator << (std::ostream& os, const Board& board);

};