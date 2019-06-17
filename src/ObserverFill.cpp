//	Project:	SolveDoku.
//	ObserverFill.cpp	--	Implementation of the FillObserver class.
//	Revisions:
//	2019-06-15	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "ObserverFill.h"
#include <iostream>

//	Constructor.
FillObserver::FillObserver(SudokuSubject *sub) : SudokuObserver(sub) {	
	this->linkedSubject = sub;
}

//	Destructor.
FillObserver::~FillObserver() {

}

//	update	--	Updates observer with new information.
//	Parameters:	none.
//	Returns:	void.
void FillObserver::update() {
	//	Update observer.
	super::update(linkedSubject);

	//	Check all rows.
	checkCells();
}

//	checkCells	--	Checks cells and fills them if possible.
//	Parameters:	none.
//	Returns:	void.
void FillObserver::checkCells() {
	//	Tracing.
	std::cout << "***Fill Observer***" << std::endl;
	int totalFilled = 0;

	//	Check every cell.
	for (int i = 0; i < 81; i++) {
		//	Only fill cells that are not filled.
		if (copiedCells[i]->getStoredNumber() == 0) {
			//	Only fill cells that have one candidate.
			if (copiedCells[i]->getCandidateCount() == 1) {
				totalFilled++;
				fillCell(i);
			}
		}
	}

	//	Tracing.
	std::cout << "Iteration finished. Filled " << totalFilled << " cells." << std::endl;
	std::cout << std::endl;

	//	Notify observers if new information is available.
	if (totalFilled != 0) {
		linkedSubject->iterate();
	}

	else {
		if (checkDone()) {
			linkedSubject->end();
		}

		else {
			std::cout << "No cells solvable! Additional rule-observers needed!" << std::endl;
		}
	}
}

//	fillCell	--	Gets a cell's possible candidates, and fills it if possible.
//	Parameters:
//		index	--	int.
//	Returns:	void.
void FillObserver::fillCell(int index) {
	bool *possibilities = copiedCells[index]->getCandidates();
	for (unsigned int i = 0; i < sizeof(possibilities) + 1; i++) {
		if (possibilities[i] == true) {
			std::cout << "Filling cell at row " << (int) (index / 9) + 1 << " column " << (index % 9) + 1 << " with number " << i + 1 << "." << std::endl;
			copiedCells[index]->setStoredNumber(i + 1);
		}
	}
}

//	checkDone	--	Checks whether the game is done or not.
//	Parameters:	none.
//	Returns:	int.
bool FillObserver::checkDone() {
	for (int i = 0; i < 81; i++) {
		if (copiedCells[i]->getStoredNumber() == 0) {
			return false;
		}
	}
	return true;
}
