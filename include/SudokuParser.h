//	Project:	SolveDoku.
//	SudokuParser.h	--	Interface for the SudokuParser class.
//	Revisions:
//	2019-06-18	--	F.R. van der Meulen	--	Created.

//	Pragma.
#pragma once

//	Include files.
#include "SubjectSudoku.h"
#include <fstream>
#include <iostream>
#include <string>

class SudokuParser {
private:
	SudokuSubject *linkedSubject;

public:
	//	Constructors & Destructors.
	SudokuParser(SudokuSubject*);
	virtual ~SudokuParser();

	//	Fields.
	int sudokuDigits[81];

	//	Methods.
	void parseSudoku(std::string);
};
