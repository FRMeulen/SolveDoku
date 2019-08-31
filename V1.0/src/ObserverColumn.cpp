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
	//	Strike off existing numbers as candidates.
	strikeNumbers();

	//	Check for singles.
	checkSingles();

	std::cout << "--Done scanning columns.--" << std::endl;
}

//	strikeNumbers	--	Checks columns and strikes off found numbers.
//	Parameters:	none.
//	Returns:	void.
void ColumnObserver::strikeNumbers() {
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
}

//	checkSingles	--	Check if a number can appear in only one cell.
//	Parameters:	none.
//	Returns:	void.
void ColumnObserver::checkSingles() {
	int occurances;

	//	Check every column.
	for (int i = 0; i < 9; i++) {
		occurances = 0;
		//Check every possible number.
		for (int j = 0; j < 9; j++) {
			//	Check every cell.
			for (int k = 0; k < 9; k++) {
				if(copiedCells[columns[i][k]]->canBe(j)) {
					occurances++;
				}
			}

			//	If only one cell can host j.
			if (occurances == 1) {
				//	Find and fill cell.
				for (int k = 0; k < 9; k++) {
					if (copiedCells[columns[i][k]]->canBe(j)) {
						copiedCells[columns[i][k]]->strikeAllExcept(j);
					}
				}
			}
		}
	}	
}