//	Project:	SolveDoku.
//	ObserverColumn.cpp	--	Implementation of the ColumnObserver class.
//	Revisions:
//	2019-06-14	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "ObserverColumn.h"
#include <iostream>

//	Constructor.
ColumnObserver::ColumnObserver(SudokuSubject *sub) : SudokuObserver(sub) {
	this->linkedSubject = sub;
}

//	Destructor.
ColumnObserver::~ColumnObserver() {

}

//	update	--	Updates observer with new information.
//	Parameters:	none.
//	Returns:	void.
void ColumnObserver::update() {
	//	Update observer.
	super::update(linkedSubject);

	std::cout << "***Column Observer Start***" << std::endl;

	//	Check all columns.
	checkColumns();
	
	std::cout << "***Column Observer End***" << std::endl << std::endl;
}

//	checkColumns	--	Checks columns and stripes off candidates.
//	Parameters:	none.
//	Returns:	void.
void ColumnObserver::checkColumns() {
	//	Check every column.
	for (int i = 0; i < 9; i++) {
		//	Check every cell.
		for (int j = 0; j < 9; j++) {
			//	Skip cells set to 0.
			int numberInCell = copiedCells[columns[i][j]]->getStoredNumber();
			if (numberInCell == 0)
				continue;
			
			//	Strike off found number in all cells.
			for (int k = 0; k < 9; k++) {
				//	Skip cell with the number.
				if (k == j)
					continue;

				//	Strike off candidate.
				copiedCells[columns[i][k]]->strikeCandidate(numberInCell);
			}
		}
	}

	std::cout << "--Done scanning columns.--" << std::endl;
}
