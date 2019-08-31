//  Project:    SolveDoku2.
//  SudokuRow.java  --  Source file for the SudokuRow class.
//  2019-08-16  --  F.R. van der Meulen --  Created.

//  Class.
public class SudokuRow extends SudokuZone {
    //  Row number.
    private int rowNumber;

    public SudokuRow(int number, Cell[] cells) {
        //  Call super constructor.
        super(cells);

        System.out.println("Creating row...");

        System.out.println("Assigning cells...");
        for (Cell cell : super.getCells())
            cell.setRow(this);

        System.out.println("Assigning row number...");
        this.rowNumber = number;

        System.out.println("Row created!\n");
    }

    //  Getters.
    public int getRowNumber() { return this.rowNumber; }

    //  Setters.
    public void setRowNumber(int number) { this.rowNumber = number; }

    //  Debug methods.
    @Override
    public void print() {
        System.out.println("---SudokuRow " + this.rowNumber + "---");
        System.out.println("Currently holds " + this.getFilledCellCount() + "/9 numbers.");
        for (int i = 1; i < 10; i++) {
            if (this.contains(i))
                System.out.println("Row contains " + i + ".");
            else
                System.out.println("Row misses " + i + ".");
        }

        System.out.println();
    }
}
