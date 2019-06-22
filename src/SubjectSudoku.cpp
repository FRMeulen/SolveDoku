//	Project:	SolveDoku.
//	SubjectSudoku.cpp	--	Implementation of the SudokuSubject class.
//	Revisions:
//	2019-06-07	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "SubjectSudoku.h"
#include <iostream>

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

//	defaultState	--	Sets cells to default state.
//	Parameters:	none.
//	Returns:	void.
void SudokuSubject::defaultState() {
	for (unsigned int i = 0; i < state.size(); i++) {
		state[i]->setStoredNumber(0);
	}
}

//	setByArray	--	Sets state by 81-length int array.
//	Parameters:
//		newState	--	Int array.
//	Returns:	void.
void SudokuSubject::setByArray(int *newState) {
	for (int i = 0; i < 81; i++) {
		if (newState[i] != 0)
			state[i]->setNumberAndStrike(newState[i]);
	}
}

//	start	--	Starts game.
//	Parameters:	none.
//	Returns:	void.
void SudokuSubject::start() {
	system("clear");
	std::cout << "*****GAME STARTED*****" << std::endl;
	std::cout << std::endl;

	notifyAll();
}

//	iterate	--	Starts next iteration.
//	Parameters:	none.
//	Returns:	void.
void SudokuSubject::iterate() {
	solveIterations++;
	notifyAll();
}

//	end	--	Ends game.
//	Parameters:	none.
//	Returns:	void.
void SudokuSubject::end() {
	gameAlive = false;
	std::cout << "*****GAME ENDED*****" << std::endl;
	std::cout << "Solved in " << solveIterations << " iterations." << std::endl;
}
