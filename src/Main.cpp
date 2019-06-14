//	Project:	SolveDoku.
//	Main.cpp	--	Entry point for SolveDoku.
//	Revisions:
//	2019-06-02	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "SubjectSudoku.h"
#include "ObserverSudoku.h"
#include "ObserverBoard.h"
#include "ObserverRow.h"
#include <iostream>

int main() {
	std::cout << "Main started!" << std::endl;
	
	//	Create subjects & Observers.
	SudokuSubject *puzzle = new SudokuSubject();

	//	Testing.
	puzzle->getCell(4, 7)->setStoredNumber(8);

	BoardObserver *board = new BoardObserver(puzzle);
	RowObserver *rows = new RowObserver(puzzle);

	//	Testing.
	puzzle->getCell(4, 1)->printCandidates();

	return 0;
}