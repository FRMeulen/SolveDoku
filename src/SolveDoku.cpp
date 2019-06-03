//	Project:	SolveDoku.
//	SolveDoku.cpp	--	Entry point for SolveDoku.
//	Revisions:
//	2019-06-02	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "Sudoku.h"
#include "Cell.h"
#include <iostream>

int main() {
	Sudoku *puzzle = new Sudoku();
	puzzle->fillCell(2, 4, 9);
	puzzle->fillCell(5, 9, 1);
	puzzle->fillCell(8, 2, 4);
	puzzle->printSudoku();

	puzzle->checkColumn(4);
	puzzle->getCell(1, 4)->printCandidates();

	return 0;
}