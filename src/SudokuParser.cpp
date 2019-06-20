//	Project:	SolveDoku.
//	SudokuParser.cpp	--	Implementation of the SudokuParser class.
//	Revisions:
//	2019-06-18	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "SudokuParser.h"
#include <limits>

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

//	formSudoku	--	Forms sudoku from user input.
//	Parameters:	none.
//	Returns:	void.
void SudokuParser::formSudoku() {
	//	Read sudoku template.
	std::string sudokuTemplate;
	std::string lineContent;
	std::ifstream input;
	input.open("res/template.txt");
	if (input.is_open()) {
		while (getline(input, lineContent)) {
			sudokuTemplate += lineContent;
			sudokuTemplate += "\n";
		}
	}
	input.close();

	std::string userSudoku = sudokuTemplate;

	//	Hardcoded indexes of the numbers in the template.	
	int numberIndexes[81] = {
		124,	130,	136,	146,	152,	158,	168,	174,	180,
		310,	316,	322,	332,	338,	344,	354,	360,	366,
		496,	502,	508,	518,	524,	530,	540,	546,	552,
		802,	808,	814,	824,	830,	836,	846,	852,	858,
		988,	994,	1000,	1010,	1016,	1022,	1032,	1038,	1044,
		1174,	1180,	1186,	1196,	1202,	1208,	1218,	1224,	1230,
		1480,	1486,	1492,	1502,	1508,	1514,	1524,	1530,	1536,
		1666,	1672,	1678,	1688,	1694,	1700,	1710,	1716,	1722,
		1852,	1858,	1864,	1874,	1880,	1886,	1896,	1902,	1908
	};

	//	Debugging pause.
	std::string userInput;
	char inputDigitChar;

	//	Ask user to fill cells.
	while (true) {
		//	Utility fields.
		int row;
		int column;
		int userNumber;

		//	Print board as-is.
		std::string yesOrNo;
		std::cout << userSudoku << std::endl;
		std::cout << "Do you wish to enter a number?" << std::endl;
		std::cout << "y/n: ";
		std::cin >> yesOrNo;

		//	Clear input buffer.
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		//	Process input.
		if (yesOrNo.compare("y") == 0 || yesOrNo.compare("Y") == 0) {
			//	Clear screen.
			system("clear");

			//	Determine row.
			std::cout << "Please enter the row of your number: ";
			if (!std::cin >> row && row >= 1 && row <= 9) {
				std::cout << "Not a valid number, ignored..." << std::endl;
				continue;
			}
			std::cout << std::endl;

			//	Clear input buffer.
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
			//	Determine column.
			std::cout << "Please enter the column of your number: ";
			if (!std::cin >> column && column >= 1 && column <= 9) {
				std::cout << "Not a valid number, ignored..." << std::endl;
				continue;
			}
			int indexesPos = (9 * row) + column;
			std::cout << std::endl;

			//	Clear input buffer.
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			
			//	Determine number.
			std::cout << "Which number should go there? 0 means empty." << std::endl;
			std::cout << "Number: ";
			if (!std::cin >> userNumber && userNumber >= 0 && userNumber <= 9) {
				std::cout << "Not a valid number, ignored..." << std::endl;
				continue;
			}

			//	Clear input buffer.
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			//	Fill number in sudoku.
			userSudoku[numberIndexes[indexesPos]] = userNumber;
		}

		else if (yesOrNo.compare("n") == 0 || yesOrNo.compare("N") == 0) {
			break;
		}

		else {
			std::cout << "Invalid answer! Try again!" << std::endl;
		}
	}

	std::cout << "Testing formSudoku..." << std::endl;
	std::cout << userSudoku << std::endl;
	
	//	Debug pause.
	std::string wait;
	std::cin >> wait;
}
