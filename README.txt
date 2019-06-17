------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------README---------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------
SolveDoku is a (quote-on-quote) 'simple', iterative Sudoku solver, written in C++.
It implements the Observer pattern to allow for (relatively) easy expansion.

All code written thus far is written by F.R. van der Meulen (Github: FRMeulen), SolveDoku however is free to download and use/expand.
I'd love to see expansions or improvements happen! :)

Current list of classes (both .h and .cpp):
Subjects:
	- BaseSubject		(abstract!)
	- SudokuSubject

Observers:
	- BaseObserver		(abstract!)
	- SudokuObserver	(abstract!)
	- BoxObserver
	- ColumnObserver
	- RowObserver
	- BoardObserver
	- FillObserver

Misc:
	- Cell

------------------------------------------------------------------------------------------------------------------------------------------------------------
Cell class:
	- Holds a number.
	- Remembers candidates.

SudokuSubject:
	- Holds Cell objects.

BoxObserver:
	- Strikes numbers in box off as candidates.

ColumnObserver:
	- Strikes numbers in column off as candidates.

RowObserver:
	- Strikes numbers in row off as candidates.

BoardObserver:
	- Prints the current state of the board every iteration.

FillObserver:
	- Checks every cell.
	- Fills cells with only one possible candidate.
	- Notifies observers.
