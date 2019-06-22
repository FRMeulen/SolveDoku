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

//	Destructor.
//	Parameters:	none.
Cell::~Cell() {

}

//	printCandidates	--	Prints all candidate values.
//	Parameters:	none.
//	Returns:	void.
void Cell::printCandidates() {
	for (unsigned int i = 0; i < sizeof(candidates); i++) {
		std::cout << "Possibility of " << i + 1 << ": " << candidates[i] << std::endl;
	}
}

//	strikeCandidate	--	Strikes a number as a cell candidate.
//	Parameters:
//		falseCandidate	--	int.
//	Returns:	void.
void Cell::strikeCandidate(int falseCandidate) {
	candidates[falseCandidate - 1] = false;
}

//	strikeAllExcept	--	Strikes all numbers as cell candidates except for one.
//	Parameters:
//		trueCandidate	--	int.
//	Returns:	void.
void Cell::strikeAllExcept(int trueCandidate) {
	for (int i = 0; i < 9; i++) {
		if (i != (trueCandidate - 1)) {
			candidates[i] = false;
		}
	}
}

//	setNumberAndStrike	--	Sets cell number and strikes all other candidates.
//	Parameters:
//		newNumber	--	int.
//	Returns:	void.
void Cell::setNumberAndStrike(int newNumber) {
	//	First set all numbers to false.
	for (unsigned int i = 0; i < possibleNumbers; i++) {
		candidates[i] = false;
	}
	
	//	Set filled number as only candidate with corrected index.
	candidates[newNumber - 1] = true;

	//	Set new number.
	setStoredNumber(newNumber);

}

//	canBe	--	Checks if the cell can be a certain number.
//	Parameters:
//		number	--	int.
//	Returns:	bool.
bool Cell::canBe(int number) {
	int index = number - 1;
	if (candidates[index]) {
		return true;
	}

	else {
		return false;
	}
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

//	getCandidateCount	--	Returns number of possible candidates.
//	Parameters:	none.
//	Returns:	int.
int Cell::getCandidateCount() {
	int possibleCandidates = 0;
	
	for (unsigned int i = 0; i < sizeof(candidates); i++) {
		if (candidates[i] == true)
			possibleCandidates++;
	}

	return possibleCandidates;
}

//	setStoredNumber	--	Overwrites stored number.
//	Parameters:
//		newStoredNumber	--	int.
//	Returns:	void.
void Cell::setStoredNumber(int newStoredNumber) {
	storedNumber = newStoredNumber;
}
