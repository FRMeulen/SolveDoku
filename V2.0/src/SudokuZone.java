//  Project:    SolveDoku2.
//  SudokuZone.java --  Source file for the SudokuZone abstract class.
//  2019-08-14  --  F.R. van der Meulen --  Created.

//  Class.
public abstract class SudokuZone {
    //  Contained cells.
    private Cell[] cells;
    private int filledCellCount = 0;
    private boolean[] containedNumbers = {
            false,  //  No 1 yet.
            false,  //  No 2 yet.
            false,  //  No 3 yet.
            false,  //  No 4 yet.
            false,  //  No 5 yet.
            false,  //  No 6 yet.
            false,  //  No 7 yet.
            false,  //  No 8 yet.
            false   //  No 9 yet.
    };

    //  Constructor.
    public SudokuZone(Cell[] cells) {
        if (cells.length != 9)
            throw new IllegalArgumentException("Cell array of invalid size! Must contain exactly 9 cells!");

        this.cells = cells;
    }

    //  Getters.
    public Cell[] getCells() { return this.cells; }
    public Cell getSpecificCell(int index) { return this.cells[index - 1]; }
    public int getFilledCellCount() { return this.filledCellCount; }

    //  Setters.
    public void setFilledCellCount(int count) { this.filledCellCount = count; }

    //  Methods.
    private void checkCandidateArgument(int arg) throws IllegalArgumentException {
        if (arg < 1 || arg > 9)
            throw new IllegalArgumentException("Argument is not a valid candidate!");
    }

    public boolean contains(int number) {
        checkCandidateArgument(number);

        if (this.containedNumbers[number - 1] == true)
            return true;

        return false;
    }

    public void addContainedNumber(int number) {
        checkCandidateArgument(number);

        this.containedNumbers[number - 1] = true;
    }

    public void update() {
        for (int i = 0; i < 9; i++) {
            if (this.cells[i].getStoredNumber() != 0) {
                this.containedNumbers[this.cells[i].getStoredNumber() - 1] = true;
                this.filledCellCount++;
            }
        }
    }

    //  Debug methods.
    public void print() {
        //  Method to override in derived classes.
    }
}
