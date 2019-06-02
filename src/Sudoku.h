//	Project:	Solvedoku.
//	Sudoku.h	--	Interface for the Sudoku class.
//	Revisions:
//	2019-06-02	--	F.R. van der Meulen	--	Created.

//	Pragma.
#pragma once

//	Include files.
#include "Cell.h"
#include <iostream>

//	Class.
class Sudoku {
protected:
	Cell cells[81];

public:
	//	Constructors & Destructors.
	Sudoku();
	~Sudoku();

	//	Methods.
	void printSudoku();

	//	Getters.
	Cell* getCells();
};