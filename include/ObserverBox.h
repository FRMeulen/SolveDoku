//	Project:	SolveDoku.
//	ObserverBox.h	--	Interface for the BoxObserver class.
//	Revisions:
//	2019-06-15	--	F.R. van der Meulen	--	Created.

//	Pragma.
#pragma once

//	Include files.
#include "ObserverSudoku.h"
#include "SubjectSudoku.h"

//	Class.
class BoxObserver : public SudokuObserver {
private:
	SudokuSubject *linkedSubject;

public:
	typedef SudokuObserver super;

	//	Constructors & Destructors.
	BoxObserver(SudokuSubject *);
	virtual ~BoxObserver();

	//	Row indexes.
	int boxes[9][9] = {
		{0,	1,	2,	9,	10,	11,	18,	19,	20},
		{3,	4,	5,	12,	13,	14,	21,	22,	23},
		{6,	7,	8,	15,	16,	17,	24,	25,	26},
		{27,	28,	29,	36,	37,	38,	45,	46,	47},
		{30,	31,	32,	39,	40,	41,	48,	49,	50},
		{33,	34,	35,	42,	43,	44,	51,	52,	53},
		{54,	55,	56,	63,	64,	65,	72,	73,	74},
		{57,	58,	59,	66,	67,	68,	75,	76,	77},
		{60,	61,	62,	69,	70,	71,	78,	79,	80}
	};

	//	Methods.
	void update();
	void checkBoxes();
};
