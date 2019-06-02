//	Project:	SolveDoku.
//	Cell.h	--	Interface for the Cell class.
//	Revisions:
//	2019-06-02	--	F.R. van der Meulen	--	Created.

//	Pragma.
#pragma once

//	Class interface.
class Cell {
protected:
	int storedNumber;
	bool candidates[9];

public:
	//	Constructors & Destructors.
	Cell();
	Cell(int initValue);
	~Cell();

	//	Getters.
	int getStoredNumber();
	bool* getCandidates();

	//	Setters.
	void setStoredNumber(int newNumber);
	void strikeCandidate(int falseCandidate);
};