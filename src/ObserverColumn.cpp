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

	//	Initial update.
	update();
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

	//	Check all columns.
	checkColumns();
}

//	checkColumns	--	Checks columns and stripes off candidates.
//	Parameters:	none.
//	Returns:	void.
void ColumnObserver::checkColumns() {
	//	Tracing.
	std::cout << "***Column Observer***" << std::endl;

	//	Check every column.
	for (int i = 0; i < 9; i++) {
		//	Check every cell.
		for (int j = 0; j < 9; j++) {
			//	Skip cells set to 0.
			int numberInCell = copiedCells[columns[j][i]]->getStoredNumber();
			if (numberInCell == 0)
				continue;

			//	Tracing.
			std::cout << "Number " << numberInCell << " found in column " << j + 1 << " row " << i + 1 << "." << std::endl;
			
			//	Strike off found number in all cells.
			for (int k = 0; k < 9; k++) {
				//	Skip cell with the number.
				if (k == i)
					continue;

				//	Strike off candidate.
				copiedCells[columns[j][k]]->strikeCandidate(numberInCell);
			}
		}
	}
}
