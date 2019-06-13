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

	//	Check if game is done.
	if (checkDone() == 1) {
		std::cout << "Sudoku solved!" << std::endl;

		linkedSubject->gameAlive = false;
	}
}

//	printBoard	--	Prints the board to the screen.
//	Parameters:	none.
//	Returns:	void.
void BoardObserver::printBoard() {
	std::cout << "***Board Observer***" << std::endl;
	
	int cellNumber = 0;
	int lineIterator = 0;

	switch (lineIterator) {
		//	Top row.
		case 0: 
			std::cout << "┌───┬───┬───┐ ┌───┬───┬───┐ ┌───┬───┬───┐" << std::endl;
		
		//	First number line.
		case 1: 
			printNumbersLine(cellNumber);
			cellNumber += 9;
		
		//	Intersection line.
		case 2:
			std::cout << "├───┼───┼───│ │───┼───┼───│ │───┼───┼───┤" << std::endl;
		
		//	Second number line.
		case 3:
			printNumbersLine(cellNumber);
			cellNumber += 9;
		
		//	Intersection line.
		case 4:
			std::cout << "├───┼───┼───│ │───┼───┼───│ │───┼───┼───┤" << std::endl;
		
		//	Third number line.
		case 5:
			printNumbersLine(cellNumber);
			cellNumber += 9;
		
		//	Bottom line.
		case 6:
			std::cout << "└───┴───┴───┘ └───┴───┴───┘ └───┴───┴───┘" << std::endl;
		
		//	Top row.
		case 7:
			std::cout << "┌───┬───┬───┐ ┌───┬───┬───┐ ┌───┬───┬───┐" << std::endl;
		
		//	Fourth number line.
		case 8:
			printNumbersLine(cellNumber);
			cellNumber += 9;
		
		//	Intersection line.
		case 9:
			std::cout << "├───┼───┼───│ │───┼───┼───│ │───┼───┼───┤" << std::endl;
		
		//	Fifth number line.
		case 10:
			printNumbersLine(cellNumber);
			cellNumber += 9;
		
		//	Intersection line.
		case 11:
			std::cout << "├───┼───┼───│ │───┼───┼───│ │───┼───┼───┤" << std::endl;
		
		//	Sixth number line.
		case 12:
			printNumbersLine(cellNumber);
			cellNumber += 9;
		
		//	Bottom line.
		case 13:
			std::cout << "└───┴───┴───┘ └───┴───┴───┘ └───┴───┴───┘" << std::endl;
		
		//	Top row.
		case 14:
			std::cout << "┌───┬───┬───┐ ┌───┬───┬───┐ ┌───┬───┬───┐" << std::endl;
		
		//	Seventh number line.
		case 15:
			printNumbersLine(cellNumber);
			cellNumber += 9;
		
		//	Intersection line.
		case 16:
			std::cout << "├───┼───┼───│ │───┼───┼───│ │───┼───┼───┤" << std::endl;
		
		//	Eighth number line.
		case 17:
			printNumbersLine(cellNumber);
			cellNumber += 9;
		
		//	Intersection line.
		case 18:
			std::cout << "├───┼───┼───│ │───┼───┼───│ │───┼───┼───┤" << std::endl;
		
		//	Ninth number line.
		case 19:
			printNumbersLine(cellNumber);
			cellNumber += 9;
		
		//	Bottom line.
		case 20:
			std::cout << "└───┴───┴───┘ └───┴───┴───┘ └───┴───┴───┘" << std::endl;
	}		
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

//	checkDone	--	Checks if the game is done.
//	Parameters:	none.
//	Returns:	bool.
bool BoardObserver::checkDone() {
	for (unsigned int i = 0; i < copiedCells.size(); i++) {
		if (copiedCells[i]->getStoredNumber() == 0) {
			return false;
		}
	}
	
	return true;	
}
