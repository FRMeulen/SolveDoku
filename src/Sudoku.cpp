//	Project:	SolveDoku.
//	Sudoku.cpp	--	Implementation of the Sudoku class.
//	Revisions:
//	2019-06-02	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "Sudoku.h"

//	Definitions.
#define boxRows 3
#define boxRowLines 7
#define lineCharLength 41

//	Constructor.
//	Parameters:	none.
Sudoku::Sudoku() {
	for (unsigned int i = 0; i < sizeof(cells); i++) {
		cells[i].setStoredNumber(0);
	}
}

//	Destructor.
//	Parameters:	none.
Sudoku::~Sudoku() {

}

//	printSudoku	--	Prints sudoku contents on screen.
//	Parameters:	none.
//	Returns:	void.
void Sudoku::printSudoku() {
	int cellNumber = 0;
	for (int i = 0; i < boxRows; i++) {
		for (int j = 0; j < boxRowLines; j++) {
			if (j == 0) {
				//	Print top row.
				std::cout << "┌───┬───┬───┐ ┌───┬───┬───┐ ┌───┬───┬───┐" << std::endl;
			}
			else if (j == 1 or j == 3 or j == 5) {
				//	Print number row.
				for (int k = 0; k < 3; k++) {
					for (int m = 0; m < 3; m++) {
						std::cout << "│ " << cells[cellNumber].getStoredNumber() << " ";
						cellNumber++;	
					}
					if (k != 2) {
						std::cout << "│ ";
					} else {
						std::cout << "│" << std::endl;
					}
				}
			}
			else if (j == 2 or j == 4) {
				//	Print intersection row.
				std::cout << "├───┼───┼───│ │───┼───┼───│ │───┼───┼───┤" << std::endl;
			}
			else {
				//	Print bottom row.
				std::cout << "└───┴───┴───┘ └───┴───┴───┘ └───┴───┴───┘" << std::endl;
			}
		}
	}
}

//	getCells	--	Returns pointer to cells.
//	Parameters:	none.
//	Returns:	pointer to first cell.
Cell* Sudoku::getCells() {
	return cells;
}