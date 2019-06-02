//	Project:	SolveDoku.
//	SolveDoku.cpp	--	Entry point for SolveDoku.
//	Revisions:
//	2019-06-02	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "Sudoku.h"
#include <iostream>

int main() {
	Sudoku *puzzle = new Sudoku();
	puzzle->printSudoku();

	return 0;
}