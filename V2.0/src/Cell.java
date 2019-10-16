/// <project> SolveDoku 2 </project>
/// <author> F.R. van der Meulen </author>
/// <summary> Cell Class </summary>
/// <date> 2019-10-16 </date>

//- Class
public class Cell
{
    //=== Properties
    private Sudoku linkedPuzzle;
    private int index;
    private int storedNumber;

    //=== Constructor
    public Cell(Sudoku sudoku, int index)
    {
        this.linkedPuzzle = sudoku;
        this.index = index;
    }

    //=== Methods


    //=== Getters
    public int getIndex() { return this.index; }
    public int getStoredNumber() { return this.storedNumber;}

    //=== Setters
    public void setStoredNumber(int number) { this.storedNumber = number; }
}