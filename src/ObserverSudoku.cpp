//	Project:	SolveDoku.
//	ObserverSudoku.h	--	Interface for the SudokuObserver class.
//	Revisions:
//	2019-06-06	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "ObserverSudoku.h"
#include "SubjectBase.h"
#include "ObserverBase.h"
#include <iostream>

//	Constructor.
SudokuObserver::SudokuObserver(BaseSubject *subject) : BaseObserver(subject) {
	//	Fill vector with NULL pointers.
	for (int i = 0; i < 81; i++) {
		Cell *newCell = NULL;
		copiedCells.push_back(newCell);
	}
}

//	Destructor.
SudokuObserver::~SudokuObserver() {

}

//	update	--	Updates copied game state with subject's game state.
//	Parameters:
//		targetSubject	--	SudokuSubject pointer.
//	Returns:	void.
void SudokuObserver::update(SudokuSubject *targetSubject) {
	copyState(targetSubject->getState());
}

//	copyState	--	Copies game state from subject.
//	Parameters:
//		originalState	--	State from game subject.
//	Returns:	void.
void SudokuObserver::copyState(std::vector<Cell *> originalState) {	
	for (unsigned int i = 0; i < originalState.size(); i++) {
		copiedCells[i] = originalState[i];
	}
}
