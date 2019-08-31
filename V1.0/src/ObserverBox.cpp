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
	//	Strike off existing numbers as candidates.
	strikeNumbers();

	//	Check for singles.
	checkSingles();

	std::cout << "--Done scanning rows.--" << std::endl;
}

//	strikeNumbers	--	Checks boxes and strikes off found numbers.
//	Parameters:	none.
//	Returns:	void.
void BoxObserver::strikeNumbers() {
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
}

//	checkSingles	--	Check if a number can appear in only one cell.
//	Parameters:	none.
//	Returns:	void.
void BoxObserver::checkSingles() {
	int occurances;

	//	Check every box.
	for (int i = 0; i < 9; i++) {
		occurances = 0;
		//Check every possible number.
		for (int j = 0; j < 9; j++) {
			//	Check every cell.
			for (int k = 0; k < 9; k++) {
				if(copiedCells[boxes[i][k]]->canBe(j)) {
					occurances++;
				}
			}

			//	If only one cell can host j.
			if (occurances == 1) {
				//	Find and fill cell.
				for (int k = 0; k < 9; k++) {
					if (copiedCells[boxes[i][k]]->canBe(j)) {
						copiedCells[boxes[i][k]]->strikeAllExcept(j);
					}
				}
			}
		}
	}
}
