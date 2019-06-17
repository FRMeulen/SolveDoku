//	Project:	SolveDoku.
//	ObserverRow.cpp	--	Implementation of the RowObserver class.
//	Revisions:
//	2019-06-14	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "ObserverRow.h"
#include <iostream>

//	Constructor.
RowObserver::RowObserver(SudokuSubject *sub) : SudokuObserver(sub) {
	this->linkedSubject = sub;
}

//	Destructor.
RowObserver::~RowObserver() {

}

//	update	--	Updates observer with new information.
//	Parameters:	none.
//	Returns:	void.
void RowObserver::update() {
	//	Update observer.
	super::update(linkedSubject);

	//	Check all rows.
	checkRows();
}

//	checkRows	--	Checks rows and stripes off candidates.
//	Parameters:	none.
//	Returns:	void.
void RowObserver::checkRows() {
	//	Tracing.
	std::cout << "***Row Observer***" << std::endl;
	
	//	Check  every row.
	for (int i = 0; i < 9; i++) {
		//	Check every cell.
		for (int j = 0; j < 9; j++) {
			//	Skip cells set to 0.
			int numberInCell = copiedCells[rows[j][i]]->getStoredNumber();
			if (numberInCell == 0)
				continue;
			
			//	Strike off found number in all cells.
			for (int k = 0; k < 9; k++) {
				//	Skip cell with the number.
				if (k == i)
					continue;

				//	Strike off candidate.
				copiedCells[rows[j][k]]->strikeCandidate(numberInCell);
			}
		}
	}
	
	std::cout << "Done scanning rows." << std::endl;
	std::cout << std::endl;
}
