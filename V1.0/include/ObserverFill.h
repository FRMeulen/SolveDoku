//	Project:	SolveDoku.
//	ObserverFill.h	--	Interface for the FillObserver class.
//	Revisions:
//	2019-06-15	--	F.R. van der Meulen	--	Created.

//	Pragma.
#pragma once

//	Include files.
#include "ObserverSudoku.h"
#include "SubjectSudoku.h"

//	Class.
class FillObserver : public SudokuObserver {
private:
	SudokuSubject *linkedSubject;

public:
	typedef SudokuObserver super;

	//	Constructors & Destructors.
	FillObserver(SudokuSubject *);
	virtual ~FillObserver();

	//	Methods.
	void update();
	void checkCells();
	void fillCell(int);
	bool checkDone();
};
