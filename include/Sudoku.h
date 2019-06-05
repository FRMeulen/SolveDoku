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
	void fillCell(int row, int column, int number);

	//	Checking rules.
	void checkRow(int row);
	void checkColumn(int column);
	void checkBox(int box);

	//	Getters.
	Cell* getCell(int row, int column);
};