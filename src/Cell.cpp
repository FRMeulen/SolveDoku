//	Project:	SolveDoku.
//	Cell.cpp	--	Implementation of the Cell class.
//	Revisions:
//	2019-06-02	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "Cell.h"

//	Constructor.
//	Parameters:	none.
Cell::Cell() {
	//	No init value given, all numbers are candidates.
	for (unsigned int i = 0; i < sizeof(candidates); i++) {
		candidates[i] = true;
	}
}

//	Constructor.
//	Parameters:
//		initValue	--	Initial value of the Cell.
Cell::Cell(int initValue) {
	//	Init value given, all other candidates are false.
	storedNumber = initValue;
	for (unsigned int i = 0; i < sizeof(candidates); i++) {
		candidates[i] = false;
	}
	candidates[storedNumber - 1] = true;
}

//	Destructor.
//	Parameters:	none.
Cell::~Cell() {

}

//	getStoredNumber	--	Returns stored number..
//	Parameters:	none.
//	Returns:	int.
int Cell::getStoredNumber() {
	return storedNumber;
}

//	getCandidates	--	Returns bool list of cell candidates.
//	Parameters:	none.
//	Returns:	boolean pointer.
bool* Cell::getCandidates() {
	return candidates;
}

//	setStoredNumber	--	Overwrites stored number.
//	Parameters:
//		newStoredNumber	--	Int with new value.
//	Returns:	void.
void Cell::setStoredNumber(int newStoredNumber) {
	storedNumber = newStoredNumber;
}

//	strikeCandidate	--	Strikes a number as a cell candidate.
//	Parameters:
//		falseCandidate	--	Int the cell can not be.
//	Returns:	void.
void Cell::strikeCandidate(int falseCandidate) {
	candidates[falseCandidate - 1] = false;
}