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

	std::cout << "***Row Observer Start***" << std::endl;

	//	Check all rows.
	checkRows();

	std::cout << "***Row Observer End***" << std::endl << std::endl;
}

//	checkRows	--	Checks rows and stripes off candidates.
//	Parameters:	none.
//	Returns:	void.
void RowObserver::checkRows() {
	//	Strike off existing numbers as candidates.
	strikeNumbers();

	//	Check for singles.
	checkSingles();

	//	Check for pairs.
	checkPairs();

	std::cout << "--Done scanning rows.--" << std::endl;
}

//	strikeNumbers	--	Checks columns and strikes off found numbers.
//	Parameters:	none.
//	Returns:	void.
void RowObserver::strikeNumbers() {
	//	Check  every row.
	for (int i = 0; i < 9; i++) {
		//	Check every cell.
		for (int j = 0; j < 9; j++) {
			//	Skip cells set to 0.
			int numberInCell = copiedCells[rows[i][j]]->getStoredNumber();
			if (numberInCell == 0)
				continue;
			
			//	Strike off found number in all cells.
			for (int k = 0; k < 9; k++) {
				//	Skip cell with the number.
				if (k == j)
					continue;

				//	Strike off candidate.
				copiedCells[rows[i][k]]->strikeCandidate(numberInCell);
			}
		}
	}
}

//	checkSingles	--	Check if a number can appear in only one cell.
//	Parameters:	none.
//	Returns:	void.
void RowObserver::checkSingles() {
	int occurances;

	//	Check every row.
	for (int i = 0; i < 9; i++) {
		occurances = 0;
		//Check every possible number.
		for (int j = 1; j < 10; j++) {
			//	Check every cell.
			for (int k = 0; k < 9; k++) {
				if(copiedCells[rows[i][k]]->canBe(j)) {
					occurances++;
				}
			}

			//	If only one cell can host j.
			if (occurances == 1) {
				//	Find and fill cell.
				for (int k = 0; k < 9; k++) {
					if (copiedCells[rows[i][k]]->canBe(j)) {
						copiedCells[rows[i][k]]->strikeAllExcept(j);
					}
				}
			}
		}
	}
}

//	checkPairs	--	Check if two numbers pair up in two cells.
//	Parameters:	none.
//	Returns:	void.
void RowObserver::checkPairs() {
	int occurances;
	bool pairEligibles[9] = {
		false,	//	1.
		false,	//	2.
		false,	//	3.
		false,	//	4.
		false,	//	5.
		false,	//	6.
		false,	//	7.
		false,	//	8.
		false	//	9.
	};

	//	Check every row.
	for (int i = 0; i < 9; i++) {
		occurances = 0;
		//	Check every possible number.
		for (int j = 1; j < 10; j++) {
			//	Check every cell.
			for (int k = 0; k < 9; k++) {
				if (copiedCells[rows[i][k]]->canBe(j)) {
					occurances++;
				}
			}

			//	If j can appear in two cells.
			if (occurances == 2) {
				//	Note number as pair-eligible.
				pairEligibles[j - 1] = true;
			}
		}
	}
}
