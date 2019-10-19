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
    private Zone linkedZone;
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

    //=== Getters
    public int getIndex() { return this.index; }
    public int getStoredNumber() { return this.storedNumber; }
    public Zone getZone() { return this.linkedZone; }

    //=== Setters
    public void setStoredNumber(int number) { this.storedNumber = number; }
    public void setZone(Zone zone) { this.linkedZone = zone; }
}