//	Project:	SolveDoku.
//	Main.cpp	--	Entry point for SolveDoku.
//	Revisions:
//	2019-06-02	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "SubjectSudoku.h"
#include "ObserverSudoku.h"
#include "ObserverBoard.h"
#include "ObserverRow.h"
#include "ObserverColumn.h"
#include "ObserverBox.h"
#include "ObserverFill.h"
#include "SudokuParser.h"
#include <string>
#include <iostream>

//	getDifficulty	--	Asks user for difficulty.
//	Parameters:
//		parser	--	SudokuParser pointer.
//	Returns:	void.
void getDifficulty(SudokuParser *parser) {
	//	Request difficulty.
	std::string difficulty;
	while (true) {
		std::cout << "Please enter the requested difficulty." << std::endl;
		std::cout << "Options include: easy, medium, hard, expert, custom" << std::endl;
		std::cout << "Difficulty: ";
		std::cin >> difficulty;

		if (difficulty.compare("easy") == 0 || difficulty.compare("Easy") == 0) {
			std::cout << "Loading easy-level sudoku..." << std::endl;
			parser->parseSudoku("res/easy.txt");
			break;
		}

		else if (difficulty.compare("medium") == 0 || difficulty.compare("Medium") == 0) {
			std::cout << "Loading medium-level sudoku..." << std::endl;
			parser->parseSudoku("res/medium.txt");
			break;
		}

		else if (difficulty.compare("hard") == 0 || difficulty.compare("Hard") == 0) {
			std::cout << "Loading hard-level sudoku..." << std::endl;
			parser->parseSudoku("res/hard.txt");
			break;
		}

		else if (difficulty.compare("expert") == 0 || difficulty.compare("Expert") == 0) {
			std::cout << "Loading expert-level sudoku..." << std::endl;
			parser->parseSudoku("res/expert.txt");
			break;
		
		}

		else if (difficulty.compare("custom") == 0 || difficulty.compare("Custom") == 0) {
			std::cout << "Loading sudoku input wizard..." << std::endl;
			parser->formSudoku();
			break;
		}

		else {
			std::cout << "Difficulty does not exist! Please try again!" << std::endl;
		}
	}	
}

//	main	--	Entry point for SolveDoku.
//	Parameters:	none.
//	Returns:	int.
int main() {	
	//	Create subject.
	SudokuSubject *puzzle = new SudokuSubject();
	
	//	Create parser.
	SudokuParser *parser = new SudokuParser(puzzle);
	
	//	Get difficulty.
	getDifficulty(parser);

	//	Create rule observers.
	BoardObserver *board = new BoardObserver(puzzle);
	RowObserver *rows = new RowObserver(puzzle);
	ColumnObserver *columns = new ColumnObserver(puzzle);
	BoxObserver *boxes = new BoxObserver(puzzle);
	
	//	Create filler.
	FillObserver *filler = new FillObserver(puzzle);

	//	Start solving.
	puzzle->start();
	return 0;
}