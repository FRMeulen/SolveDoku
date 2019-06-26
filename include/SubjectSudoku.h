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
	int solveIterations = 0;
	int solvedCells = 0;

	//	Getters.
	std::vector<Cell *> getState();
	Cell* getCell(int, int);
	
	//	Setters.
	void defaultState();
	void setByArray(int*);
	
	//	Game methods.
	void start();
	void increaseSolvedCellCount(int);
	void iterate();
	void end();
};
