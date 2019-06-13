//	Project:	Solvedoku.
//	Sudoku.h	--	Interface for the Sudoku class.
//	Revisions:
//	2019-06-02	--	F.R. van der Meulen	--	Created.

//	Pragma.
#pragma once

//	Include files.
#include "Cell.h"
#include <iostream>
#include <vector>

//	Class.
class Sudoku {
protected:
	std::vector<Cell*> cells;

public:
	//	Constructors & Destructors.
	Sudoku();
	~Sudoku();

	//	Methods.
	void printSudoku();
	void fillCell(int, int, int);

	//	Checking rules.
	void checkRow(int);
	void checkColumn(int);
	void checkBox(int);

	//	Getters.
	Cell* getCell(int, int);
};
