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

	std::cout << "***Box Observer Start***" << std::endl;
	
	//	Check all rows.
	checkBoxes();

	std::cout << "***Box Observer End***" << std::endl << std::endl;
}

//	checkBoxes	--	Checks boxes and stripes off candidates.
//	Parameters:	none.
//	Returns:	void.
void BoxObserver::checkBoxes() {
	//	Check  every Box.
	for (int i = 0; i < 9; i++) {
		//	Check every cell.
		for (int j = 0; j < 9; j++) {
			//	Skip cells set to 0.
			int numberInCell = copiedCells[boxes[i][j]]->getStoredNumber();
			if (numberInCell == 0)
				continue;
			
			//	Strike off found number in all cells.
			for (int k = 0; k < 9; k++) {
				//	Skip cell with the number.
				if (k == j)
					continue;

				//	Strike off candidate.
				copiedCells[boxes[i][k]]->strikeCandidate(numberInCell);
			}
		}
	}

	std::cout << "--Done scanning rows.--" << std::endl;
}
