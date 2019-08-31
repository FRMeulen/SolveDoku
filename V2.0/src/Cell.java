//  Project:    SolveDoku2.
//  Cell.java   --  Source file for the Cell class.
//  2019-08-14  --  F.R. van der Meulen --  Created.

//  Class.
public class Cell {
    //  Cell candidates.
    private int storedNumber = 0;   //  Default to 0 for 'empty' cell.
    private int index;
    private int candidateCount = 9;
    private boolean[] candidates = {
            true,   //  Could host 1.
            true,   //  Could host 2.
            true,   //  Could host 3.
            true,   //  Could host 4.
            true,   //  Could host 5.
            true,   //  Could host 6.
            true,   //  Could host 7.
            true,   //  Could host 8.
            true    //  Could host 9.
    };

    //  Location info.
    private SudokuBox box;
    private SudokuColumn column;
    private SudokuRow row;

    //  Constructor.
    public Cell(int index) {
        this.index = index;
    }

    //  Getters.
    public int getStoredNumber() { return this.storedNumber; }
    public int getIndex() { return this.index; }
    public int getCandidateCount() { return this.candidateCount; }
    public boolean[] getCandidates() { return this.candidates; }
    public SudokuBox getBox() { return this.box; }
    public SudokuColumn getColumn() { return this.column; }
    public SudokuRow getRow() { return this.row; }

    //  Setters.
    public void setStoredNumber(int number) { this.storedNumber = number; }
    public void setCandidateCount(int count) { this.candidateCount = count; }
    public void setBox(SudokuBox box) { this.box = box; }
    public void setColumn(SudokuColumn column) { this.column = column; }
    public void setRow(SudokuRow row) { this.row = row; }

    //  Methods.
    public boolean canBe(int candidate) {
        if (this.candidates[candidate - 1] == true)
            return true;

        return false;
    }

    private void checkCandidateArgument(int arg) throws IllegalArgumentException {
        if (arg < 1 || arg > 9)
            throw new IllegalArgumentException("Argument is not a valid candidate!");
    }

    public void strike(int candidate) {
        checkCandidateArgument(candidate);

        this.candidates[candidate - 1] = false;
    }

    public void strikeAllBut(int candidate) {
        checkCandidateArgument(candidate);

        for (int i = 0; i < 9; i++) {
            if (i != (candidate + 1))
                this.candidates[i] = false;
        }
    }

    public void enterNumber(int number) {
        checkCandidateArgument(number);

        this.strikeAllBut(number);
        this.setStoredNumber(number);
        this.getBox().update();
        this.getRow().update();
        this.getColumn().update();
    }

    //  Debug methods.
    public void print() {
        System.out.println("---Cell " + this.index + "---");
        if (this.storedNumber != 0)
            System.out.println("Hosts " + this.storedNumber + ".");

        else {
            for (int i = 0; i < 9; i++) {
                if (this.candidates[i] == true)
                    System.out.println("Could host " + (i + 1) + ".");
                else
                    System.out.println("Cannot host " + (i + 1) + ".");
            }
        }

        System.out.println();
    }

}
