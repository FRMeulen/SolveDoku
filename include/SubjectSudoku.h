//	Project:	SolveDoku.
//	SubjectSudoku.h	--	Interface for the SudokuSubject class.
//	Revisions:
//	2019-06-06	--	F.R. van der Meulen	--	Created.

//	Pragma.
#pragma once

//	Include files.
#include "SubjectBase.h"
#include <vector>
#include "Cell.h"

//	Definitions.
#define fieldCount 81

//	Class.
class SudokuSubject : public BaseSubject {
public:
	//	Constructors & Destructors.
	SudokuSubject();
	~SudokuSubject();

	//	Fields.
	std::vector<Cell *> state;
	bool gameAlive = true;

	//	Methods.
	std::vector<Cell *> getState();
	void setState(int, int);
	void defaultState();
	void start();
};
