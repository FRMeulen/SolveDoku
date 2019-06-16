//	Project:	SolveDoku.
//	ObserverBox.cpp	--	Implementation of the BoxObserver class.
//	Revisions:
//	2019-06-15	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "ObserverBox.h"
#include <iostream>

//	Constructor.
BoxObserver::BoxObserver(SudokuSubject *sub) : SudokuObserver(sub) {
	this->linkedSubject = sub;

	//	Initial update.
	update();
}

//	Destructor.
BoxObserver::~BoxObserver() {

}

//	update	--	Updates observer with new information.
//	Parameters:	none.
//	Returns:	void.
void BoxObserver::update() {
	//	Update observer.
	super::update(linkedSubject);

	//	Check all rows.
	checkBoxes();
}

//	checkBoxes	--	Checks boxes and stripes off candidates.
//	Parameters:	none.
//	Returns:	void.
void BoxObserver::checkBoxes() {
	//	Tracing.
	std::cout << "***Box Observer***" << std::endl;
	
	//	Check  every Box.
	for (int i = 0; i < 9; i++) {
		//	Check every cell.
		for (int j = 0; j < 9; j++) {
			//	Skip cells set to 0.
			int numberInCell = copiedCells[boxes[j][i]]->getStoredNumber();
			if (numberInCell == 0)
				continue;

			//	Strike off found number in all cells.
			for (int k = 0; k < 9; k++) {
				//	Skip cell with the number.
				if (k == i)
					continue;

				//	Strike off candidate.
				copiedCells[boxes[j][k]]->strikeCandidate(numberInCell);
			}
		}
	}
	
	std::cout << "Done scanning boxes." << std::endl;
	std::cout << std::endl;
}
