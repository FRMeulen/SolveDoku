//	Project:	SolveDoku.
//	Sudoku.cpp	--	Implementation of the Sudoku class.
//	Revisions:
//	2019-06-02	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "Sudoku.h"

//	Definitions.
#define maxCells 81
#define rowsOfBoxes 3
#define rowsPerBox 7
#define boxesPerRow 3
#define numbersPerBox 3
#define ruleCellCount 9

//	Constructor.
//	Parameters:	none.
Sudoku::Sudoku() {
	for (int i = 0; i < maxCells; i++) {
		Cell *cell = new Cell();
		cells.push_back(cell);
		cell->setStoredNumber(0);
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
	for (int i = 0; i < rowsOfBoxes; i++) {
		for (int j = 0; j < rowsPerBox; j++) {
			if (j == 0) {
				//	Print top row.
				std::cout << "┌───┬───┬───┐ ┌───┬───┬───┐ ┌───┬───┬───┐" << std::endl;
			}
			else if (j == 1 or j == 3 or j == 5) {
				//	Print number row.
				for (int k = 0; k < boxesPerRow; k++) {
					for (int m = 0; m < numbersPerBox; m++) {
						if (cells[cellNumber]->getStoredNumber() != 0) {
							std::cout << "│ " << cells[cellNumber]->getStoredNumber() << " ";
						} else {
							std::cout << "│   ";
						}
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

//	fillCell	--	Enters a number into a cell.
//	Parameters:
//		row 	--	int.
//		column	--	int.
//		number	--	int.
//	Returns:	void.
void Sudoku::fillCell(int row, int column, int number) {
	cells[((row - 1) * 9) + column - 1]->setNumberAndStrike(number);
}

//	checkRow	--	Checks a row and strikes off candidates.
//	Parameters:
//		row		--	int.
//	Returns:	void.
void Sudoku::checkRow(int row) {
	std::vector<int> used;
	//	Check every cell in row.
	for (int i = 0; i < ruleCellCount; i++) {
		//	Skip if empty.
		if (cells[((row - 1) * 9) + i]->getStoredNumber() <= 0)
			continue;

		//	Add to used numbers.
		used.push_back(cells[((row - 1) * 9) + i]->getStoredNumber());
	}

	//	Strike off all used numbers.
	for (unsigned int i = 0; i < sizeof(used); i++) {
		//	In all cells in the row.
		for (int j = 0; j < ruleCellCount; j++) {
			cells[((row - 1) * 9) + j]->strikeCandidate(used[i]);
		}
	}
}

//	checkColumn	--	Checks a column and strikes off candidates.
//	Parameters:
//		column	--	int.
//	Returns:	void.
void Sudoku::checkColumn(int column) {
	std::vector<int> used;
	//	Check every cell in column.
	for (int i = 0; i < ruleCellCount; i++) {
		//	Skip if empty.
		if (cells[(column - 1) + (i * 9)]->getStoredNumber() <= 0)
			continue;

		//	Add to used numbers.
		used.push_back(cells[(column - 1) + (i * 9)]->getStoredNumber());
	}

	//	Strike off all used numbers.
	for (unsigned int i = 0; i < sizeof(used); i++) {
		//	In all cells in the column.
		for (int j = 0; j < ruleCellCount; j++) {
			cells[(column - 1) + (i * 9)]->strikeCandidate(used[i]);
		}
	}
}

//	getCells	--	Returns pointer to cells.
//	Parameters:
//		row		--	int.
//		column	--	int.
//	Returns:	cell pointer.
Cell* Sudoku::getCell(int row, int column) {
	return cells[((row - 1) * 9) + column - 1];
}