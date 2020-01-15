#include "iostream"

class Board {

	private:
		int rows;
		int cols;
		int size;
		int* array;

	public:
		//Constructors
		Board(const int& rows, const int& cols);

		//Destructors
		~Board();

		//Getters and Setters
		const int& getCols() const;
		const int& getRows() const;
		const int& getSize() const;


		//Overloaded operators
		int& operator[] (const int& index);

		const int& operator [] (const int& index) const ;

		//friend operators
		friend std::ostream& operator << (std::ostream& os, const Board& board);



};