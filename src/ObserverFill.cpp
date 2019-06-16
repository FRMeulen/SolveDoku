//	Project:	SolveDoku.
//	ObserverFill.cpp	--	Implementation of the FillObserver class.
//	Revisions:
//	2019-06-15	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "ObserverFill.h"
#include <unistd.h>
#include <iostream>

//	Constructor.
FillObserver::FillObserver(SudokuSubject *sub) : SudokuObserver(sub) {
	this->linkedSubject = sub;

	//	Initial update.
	update();
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
		//	Only fill cells that are not filled, and have one possible candidate.
		if (copiedCells[i]->getStoredNumber() == 0 && copiedCells[i]->getCandidateCount() == 1) {
			fillCell(i);
			totalFilled++;
		}
	}

	//	Tracing.
	std::cout << "Iteration finished. Filled " << totalFilled << " cells." << std::endl;
	std::cout << std::endl;

	usleep(1000);
	
	//	If new information present, notify observers.
	if (totalFilled != 0)
		linkedSubject->notifyAll();

	else std::cout << "No new moves found! Dead end!" << std::endl;
}

//	fillCell	--	Gets a cell's possible candidates, and fills it if possible.
//	Parameters:
//		index	--	int.
//	Returns:	void.
void FillObserver::fillCell(int index) {
	bool *possibilities = copiedCells[index]->getCandidates();
	for (unsigned int i = 0; i < sizeof(possibilities); i++) {
		if (possibilities[i] == true) {
			std::cout << "Filling cell at row " << (int) (index / 9) + 1 << " column " << (index % 9) + 1 << " with number " << i + 1 << "." << std::endl;
			copiedCells[index]->setStoredNumber(i + 1);
		}
	}

	std::cout << std::endl;
}
