//	Project:	SolveDoku.
//	SubjectSudoku.cpp	--	Implementation of the SudokuSubject class.
//	Revisions:
//	2019-06-07	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "SubjectSudoku.h"

//	Constructor.
SudokuSubject::SudokuSubject() {
	for (int i = 0; i < 81; i++) {
		Cell *newCell = new Cell();
		state.push_back(newCell);
	}

	defaultState();
}

//	Destructor.
SudokuSubject::~SudokuSubject() {

}

//	getState	--	Returns state cells.
//	Parameters:	none.
//	Returns:	void.
std::vector<Cell *> SudokuSubject::getState() {
	return state;
}

//	getCell	--	Fetches cell in given position.
//	Parameters:
//		row	--	int.
//		column	--	int.
//	Returns:	Cell pointer.
Cell* SudokuSubject::getCell(int row, int column) {
	int rowIndex = row - 1;
	int columnIndex = column - 1;
	int pos = (rowIndex * 9) + columnIndex;
	
	return state[pos];
}

//	setState	--	Sets a number in a cell.
//	Parameters:
//		pos	--	int.
//		number	--	int.
//	Returns:	void.
void SudokuSubject::setState(int pos, int number) {
	state[pos]->setStoredNumber(number);
}

//	defaultState	--	Sets cells to default state.
//	Parameters:	none.
//	Returns:	void.
void SudokuSubject::defaultState() {
	for (unsigned int i = 0; i < state.size(); i++) {
		state[i]->setStoredNumber(0);
	}
}

//	start	--	Starts game.
//	Parameters:	none.
//	Returns:	void.
void SudokuSubject::start() {
	std::cout << "*****GAME STARTED*****" << std::endl;
	std::cout << std::endl;

	notifyAll();
}
