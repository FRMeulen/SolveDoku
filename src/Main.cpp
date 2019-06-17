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
#include "ObserverFill.h"
#include <iostream>

int main() {
	std::cout << "Main started!" << std::endl;
	
	//	Create subjects & Observers.
	SudokuSubject *puzzle = new SudokuSubject();

	//	Pre-fill sudoku.
	int startState[81] = {
		6,	0,	0,	0,	2,	0,	8,	0,	3,
		0,	3,	0,	0,	9,	4,	0,	0,	0,
		0,	0,	0,	0,	0,	0,	0,	9,	0,
		0,	0,	0,	0,	0,	0,	0,	0,	5,
		0,	0,	8,	0,	0,	0,	0,	6,	9,
		7,	5,	0,	0,	0,	0,	2,	4,	0,
		0,	0,	2,	0,	3,	0,	0,	0,	1,
		0,	0,	4,	6,	5,	0,	0,	8,	0,
		1,	8,	5,	2,	4,	0,	0,	3,	6
	};
	puzzle->setByArray(startState);

	//	Create observers.
	BoardObserver *board = new BoardObserver(puzzle);
	RowObserver *rows = new RowObserver(puzzle);
	ColumnObserver *columns = new ColumnObserver(puzzle);
	BoxObserver *boxes = new BoxObserver(puzzle);
	FillObserver *filler = new FillObserver(puzzle);

	puzzle->start();
	return 0;
}
