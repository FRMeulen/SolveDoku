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
#include "SudokuParser.h"
#include <string>
#include <iostream>

int main() {
	std::cout << "Main started!" << std::endl;
	
	//	Create subject.
	SudokuSubject *puzzle = new SudokuSubject();
	
	//	Create parser and pre-fill sudoku.
	SudokuParser *parser = new SudokuParser(puzzle);
	parser->parseSudoku("res/medium.txt");

	//	Create rule observers.
	BoardObserver *board = new BoardObserver(puzzle);
	RowObserver *rows = new RowObserver(puzzle);
	ColumnObserver *columns = new ColumnObserver(puzzle);
	BoxObserver *boxes = new BoxObserver(puzzle);
	
	//	Create filler.
	FillObserver *filler = new FillObserver(puzzle);

	//	Start solving.
	puzzle->start();
	return 0;
}
