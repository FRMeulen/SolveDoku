/// <project> SolveDoku 2 </project>
/// <author> F.R. van der Meulen </author>
/// <summary> Cell Class </summary>
/// <date> 2019-10-16 </date>

//- Imports
import java.util.ArrayList;
import java.lang.Integer;

//- Class
public class Cell
{
    //=== Properties
    private Sudoku linkedPuzzle;
    private Zone linkedRow;
    private Zone linkedColumn;
    private Zone linkedBox;
    private int index;
    private int storedNumber;
    private ArrayList<Integer> candidates;

    //=== Constructor
    public Cell(Sudoku sudoku, int index)
    {
        this.linkedPuzzle = sudoku;
        this.index = index;
        
        // Set candidates
        candidates = new ArrayList<Integer>();
        for (int i = 1; i < 10; i++) candidates.add(i);
    }

    //=== Methods
    public void strikeCandidate(int candidate)
    {
        for (int i = 0; i < this.candidates.size(); i++)
            if (this.candidates.get(i) == candidate) this.candidates.remove(i);
    }

    public void fill(int number)
    {
        // Strike candidates
        for (int i = 0; i < this.candidates.size(); i++)
        {
            if (this.candidates.get(i) != number)
                strikeCandidate(this.candidates.get(i));
        }

        // Set stored number
        this.setStoredNumber(number);

        // Update linked zones
        this.linkedRow.update();
        this.linkedColumn.update();
        this.linkedBox.update();
    }

    //=== Getters
    public int getIndex() { return this.index; }
    public int getStoredNumber() { return this.storedNumber; }
    public Zone getRow() { return this.linkedRow; }
    public Zone getColumn() { return this.linkedColumn; }
    public Zone getBox() { return this.linkedBox; }
    public ArrayList<Integer> getCandidates() { return this.candidates; }

    //=== Setters
    public void setStoredNumber(int number) { this.storedNumber = number; }
    public void setRow(Zone row) { this.linkedRow = row; }
    public void setColumn(Zone column) { this.linkedColumn = column; }
    public void setBox(Zone box) { this.linkedBox = box; }
}