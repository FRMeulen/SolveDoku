//	Project:	SolveDoku.
//	ObserverBoard.h	--	Interface of the BoardObserver class.
//	Revisions:
//	2019-06-11	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "ObserverSudoku.h"
#include "SubjectSudoku.h"

//	Class.
class BoardObserver : public SudokuObserver {
private:
	SudokuSubject *linkedSubject;

public:
	typedef SudokuObserver super;
	
	//	Constructors & Destructors.
	BoardObserver(SudokuSubject *);
	virtual ~BoardObserver();

	void update();
	void printBoard();
	void printNumbersLine(int);
	bool checkDone();
};
