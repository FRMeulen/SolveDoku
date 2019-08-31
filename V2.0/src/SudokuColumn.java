//  Project:    SolveDoku2.
//  SudokuColumn.java  --  Source file for the SudokuColumn class.
//  2019-08-16  --  F.R. van der Meulen --  Created.

//  Class.
public class SudokuColumn extends SudokuZone {
    //  Column number.
    private int columnNumber;

    public SudokuColumn(int number, Cell[] cells) {
        //  Call super constructor.
        super(cells);

        System.out.println("Creating column...");

        System.out.println("Assigning cells...");
        for (Cell cell : super.getCells())
            cell.setColumn(this);

        System.out.println("Assigning column number...");
        this.columnNumber = number;

        System.out.println("Column created!\n");
    }

    //  Getters.
    public int getColumnNumber() { return this.columnNumber; }

    //  Setters.
    public void setColumnNumber(int number) { this.columnNumber = number; }

    //  Debug methods.
    @Override
    public void print() {
        System.out.println("---SudokuColumn " + this.columnNumber + "---");
        System.out.println("Currently holds " + this.getFilledCellCount() + "/9 numbers.");
        for (int i = 1; i < 10; i++) {
            if (this.contains(i))
                System.out.println("Column contains " + i + ".");
            else
                System.out.println("Column misses " + i + ".");
        }

        System.out.println();
    }
}