//	Project:	SolveDoku.
//	SudokuParser.cpp	--	Implementation of the SudokuParser class.
//	Revisions:
//	2019-06-18	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "SudokuParser.h"

//	Constructor.
SudokuParser::SudokuParser(SudokuSubject *sub) {
	this->linkedSubject = sub;
}

//	Destructor.
SudokuParser::~SudokuParser() {

}

//	parseSudoku	--	Parses sudoku from text.
//	Parameters:
//		path	--	char pointer.
//	Returns:	--	void.
void SudokuParser::parseSudoku(std::string path) {
	std::ifstream inputFile;
	inputFile.open(path);

	if (!inputFile) {
		std::cout << "Error opening file!" << std::endl;
		return;
	}

	std::string rawText;
	char x;
	while (inputFile >> x) {
		rawText += x;
	}

	inputFile.close();
	
	int currentDigit = 0;
	int currentChar = 0;
	while (currentDigit < 81) {
		char c = rawText[currentChar];
		if (c == '0') {
			sudokuDigits[currentDigit] = 0;
			currentDigit++;
		}

		else if (c == '1') {
			sudokuDigits[currentDigit] = 1;
			currentDigit++;
		}

		else if (c == '2') {
			sudokuDigits[currentDigit] = 2;
			currentDigit++;
		}

		else if (c == '3') {
			sudokuDigits[currentDigit] = 3;
			currentDigit++;
		}
		
		else if (c == '4') {
			sudokuDigits[currentDigit] = 4;
			currentDigit++;
		}

		else if (c == '5') {
			sudokuDigits[currentDigit] = 5;
			currentDigit++;
		}

		else if (c == '6') {
			sudokuDigits[currentDigit] = 6;
			currentDigit++;
		}

		else if (c == '7') {
			sudokuDigits[currentDigit] = 7;
			currentDigit++;
		}

		else if (c == '8') {
			sudokuDigits[currentDigit] = 8;
			currentDigit++;
		}

		else if (c == '9') {
			sudokuDigits[currentDigit] = 9;
			currentDigit++;
		}

		currentChar++;
	}

	linkedSubject->setByArray(sudokuDigits);
}
