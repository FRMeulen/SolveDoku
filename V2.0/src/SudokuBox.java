//  Project:    SolveDoku2.
//  SudokuBox.java  --  Source file for the SudokuBox class.
//  2019-08-16  --  F.R. van der Meulen --  Created.

//  Class.
public class SudokuBox extends SudokuZone {
    //  Box number.
    private int boxNumber;

    public SudokuBox(int number, Cell[] cells) {
        //  Call super constructor.
        super(cells);

        System.out.println("Creating box...");

        System.out.println("Assigning cells...");
        for (Cell cell : super.getCells())
            cell.setBox(this);

        System.out.println("Assigning box number...");
        this.boxNumber = number;

        System.out.println("Box created!\n");
    }

    //  Getters.
    public int getBoxNumber() { return this.boxNumber; }

    //  Setters.
    public void setBoxNumber(int number) { this.boxNumber = number; }

    //  Debug methods.
    @Override
    public void print() {
        System.out.println("---SudokuBox " + this.boxNumber + "---");
        System.out.println("Currently holds " + this.getFilledCellCount() + "/9 numbers.");
        for (int i = 1; i < 10; i++) {
            if (this.contains(i))
                System.out.println("Box contains " + i + ".");
            else
                System.out.println("Box misses " + i + ".");
        }

        System.out.println();
    }
}
