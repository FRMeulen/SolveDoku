//	Project:	SolveDoku.
//	Cell.h	--	Interface for the Cell class.
//	Revisions:
//	2019-06-02	--	F.R. van der Meulen	--	Created.

//	Pragma.
#pragma once

//	Include files.
#include <iostream>

//	Definitions.
#define possibleNumbers 9

//	Class interface.
class Cell {
protected:
	int storedNumber;
	bool candidates[possibleNumbers];

public:
	//	Constructors & Destructors.
	Cell();
	~Cell();

	//	Methods.
	void printCandidates();
	void strikeCandidate(int);
	void strikeAllExcept(int);
	void setNumberAndStrike(int);
	bool canBe(int);

	//	Getters.
	int getStoredNumber();
	bool* getCandidates();
	int getCandidateCount();

	//	Setters.
	void setStoredNumber(int);
};
