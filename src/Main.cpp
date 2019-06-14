//	Project:	SolveDoku.
//	Main.cpp	--	Entry point for SolveDoku.
//	Revisions:
//	2019-06-02	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "SubjectSudoku.h"
#include "ObserverSudoku.h"
#include "ObserverBoard.h"
#include "ObserverRow.h"
#include "ObserverColumn.h"
#include "ObserverBox.h"
#include <iostream>

int main() {
	std::cout << "Main started!" << std::endl;
	
	//	Create subjects & Observers.
	SudokuSubject *puzzle = new SudokuSubject();

	//	Testing.
	puzzle->getCell(4, 7)->setNumberAndStrike(8);

	BoardObserver *board = new BoardObserver(puzzle);
	//RowObserver *rows = new RowObserver(puzzle);
	//ColumnObserver *columns = new ColumnObserver(puzzle);
	BoxObserver *boxes = new BoxObserver(puzzle);

	//	Testing.
	std::cout << "Row 5 column 7:" << std::endl;
	puzzle->getCell(5, 7)->printCandidates();
	std::cout << std::endl;
	std::cout << "Row 9 column 7:" << std::endl;
	puzzle->getCell(9, 7)->printCandidates();

	return 0;
}
