//	Project:	SolveDoku.
//	ObserverBoard.cpp	--	Implementation of the BoardObserver class.
//	Revisions:
//	2019-06-11	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "ObserverBoard.h"
#include <iostream>

//	Constructor.
BoardObserver::BoardObserver(SudokuSubject *sub) : SudokuObserver(sub) {
	this->linkedSubject = sub;
		
	//	Initial update to print board.
	update();
}

//	Destructor.
BoardObserver::~BoardObserver() {

}

//	update	--	Updates observer with new information.
//	Parameters:	none.
//	Returns:	void.
void BoardObserver::update() {
	//	Update observer.
	super::update(linkedSubject);

	//	Print board.
	printBoard();
}

//	printBoard	--	Prints the board to the screen.
//	Parameters:	none.
//	Returns:	void.
void BoardObserver::printBoard() {
	std::cout << "***Board Observer***" << std::endl;
	
	//	Prints out the board to the screen.
	//	Lines containing the numbers are printed using the printNumbersLine method.
	//	Starting index for printNumbersLine increases with 9 after each call.

	//	Top row of boxes.
	std::cout << "┌───┬───┬───┐ ┌───┬───┬───┐ ┌───┬───┬───┐" << std::endl;
	printNumbersLine(0);
	std::cout << "├───┼───┼───┤ ├───┼───┼───┤ ├───┼───┼───┤" << std::endl;
	printNumbersLine(9);
	std::cout << "├───┼───┼───┤ ├───┼───┼───┤ ├───┼───┼───┤" << std::endl;
	printNumbersLine(18);
	std::cout << "└───┴───┴───┘ └───┴───┴───┘ └───┴───┴───┘" << std::endl;
	
	//	Middle row of boxes.
	std::cout << "┌───┬───┬───┐ ┌───┬───┬───┐ ┌───┬───┬───┐" << std::endl;
	printNumbersLine(27);
	std::cout << "├───┼───┼───┤ ├───┼───┼───┤ ├───┼───┼───┤" << std::endl;
	printNumbersLine(36);
	std::cout << "├───┼───┼───┤ ├───┼───┼───┤ ├───┼───┼───┤" << std::endl;
	printNumbersLine(45);
	std::cout << "└───┴───┴───┘ └───┴───┴───┘ └───┴───┴───┘" << std::endl;
	
	//	Bottom row of boxes.
	std::cout << "┌───┬───┬───┐ ┌───┬───┬───┐ ┌───┬───┬───┐" << std::endl;
	printNumbersLine(54);
	std::cout << "├───┼───┼───┤ ├───┼───┼───┤ ├───┼───┼───┤" << std::endl;
	printNumbersLine(63);
	std::cout << "├───┼───┼───┤ ├───┼───┼───┤ ├───┼───┼───┤" << std::endl;
	printNumbersLine(72);
	std::cout << "└───┴───┴───┘ └───┴───┴───┘ └───┴───┴───┘" << std::endl;
	std::cout << std::endl;	
}

//	printNumbersLine	--	Prints a sudoku line with the numbers.
//	Parameters:
//		startNumber	--	int.
//	Returns:	void.
void BoardObserver::printNumbersLine(int startNumber) {
	int cellNumber = startNumber;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (copiedCells[cellNumber]->getStoredNumber() != 0) {
				std::cout << "│ " << copiedCells[cellNumber]->getStoredNumber() << " ";
			}

			else {
				std::cout << "│   ";
			}

			cellNumber++;
		}

		if (i != 2) {
			std::cout << "│ ";
		}

		else {
			std::cout << "│" << std::endl;
		}
	}
}
