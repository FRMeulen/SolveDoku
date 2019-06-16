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
	puzzle->getCell(1, 1)->setNumberAndStrike(8);
	puzzle->getCell(1, 2)->setNumberAndStrike(7);
	puzzle->getCell(1, 3)->setNumberAndStrike(6);
	puzzle->getCell(1, 4)->setNumberAndStrike(9);
	puzzle->getCell(2, 2)->setNumberAndStrike(1);
	puzzle->getCell(2, 6)->setNumberAndStrike(6);
	puzzle->getCell(3, 2)->setNumberAndStrike(4);
	puzzle->getCell(3, 4)->setNumberAndStrike(3);
	puzzle->getCell(3, 6)->setNumberAndStrike(5);
	puzzle->getCell(3, 7)->setNumberAndStrike(8);
	puzzle->getCell(4, 1)->setNumberAndStrike(4);
	puzzle->getCell(4, 7)->setNumberAndStrike(2);
	puzzle->getCell(4, 8)->setNumberAndStrike(1);
	puzzle->getCell(5, 2)->setNumberAndStrike(9);
	puzzle->getCell(5, 4)->setNumberAndStrike(5);
	puzzle->getCell(6, 2)->setNumberAndStrike(5);
	puzzle->getCell(6, 5)->setNumberAndStrike(4);
	puzzle->getCell(6, 7)->setNumberAndStrike(3);
	puzzle->getCell(6, 9)->setNumberAndStrike(6);
	puzzle->getCell(7, 2)->setNumberAndStrike(2);
	puzzle->getCell(7, 3)->setNumberAndStrike(9);
	puzzle->getCell(7, 9)->setNumberAndStrike(8);
	puzzle->getCell(8, 3)->setNumberAndStrike(4);
	puzzle->getCell(8, 4)->setNumberAndStrike(6);
	puzzle->getCell(8, 5)->setNumberAndStrike(9);
	puzzle->getCell(8, 7)->setNumberAndStrike(1);
	puzzle->getCell(8, 8)->setNumberAndStrike(7);
	puzzle->getCell(8, 9)->setNumberAndStrike(3);
	puzzle->getCell(9, 6)->setNumberAndStrike(1);
	puzzle->getCell(9, 9)->setNumberAndStrike(4);
	

	//	Create observers.
	BoardObserver *board = new BoardObserver(puzzle);
	RowObserver *rows = new RowObserver(puzzle);
	ColumnObserver *columns = new ColumnObserver(puzzle);
	BoxObserver *boxes = new BoxObserver(puzzle);
	FillObserver *filler = new FillObserver(puzzle);

	puzzle->start();
	return 0;
}
