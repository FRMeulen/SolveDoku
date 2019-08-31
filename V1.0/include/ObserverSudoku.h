//	Project:	SolveDoku.
//	ObserverSudoku.h	--	Interface for the SudokuObserver class.
//	Revisions:
//	2019-06-06	--	F.R. van der Meulen	--	Created.

//	Pragma.
#pragma once

//	Include files.
#include "ObserverBase.h"
#include "Cell.h"
#include <vector>

//	Class dependencies.
class SudokuSubject;

//	Class.
class SudokuObserver : public BaseObserver {
public:
	//	Constructors & Destructors.
	SudokuObserver(BaseSubject*);
	virtual ~SudokuObserver();

	//	Fields.
	std::vector<Cell*> copiedCells;
	int gameDone = -1;
	SudokuSubject *linkedSubject;

	//	Methods.
	void update(SudokuSubject*);
	void copyState(std::vector<Cell*>);
};

//	Late includes.
#include "SubjectSudoku.h"
