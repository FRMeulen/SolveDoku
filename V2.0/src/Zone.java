/// <project> SolveDoku 2 </project>
/// <author> F.R. van der Meulen </author>
/// <summary> Zone Class </summary>
/// <date> 2019-10-16 </date>

//- Imports
import java.util.ArrayList;
import java.lang.Integer;

//- Class
public class Zone
{
    //=== Properties
    private Sudoku linkedPuzzle;
    private ZoneType zoneType;
    private int zoneIndex;
    private ArrayList<Cell> zoneCells;
    private ArrayList<Integer> containedNumbers;

    //=== Constructor
    public Zone(Sudoku sudoku, ZoneType type, int index, ArrayList<Cell> cells)
    {
        this.linkedPuzzle = sudoku;
        this.zoneType = type;
        this.containedNumbers = new ArrayList<Integer>();
        this.zoneIndex = index;
        this.zoneCells = cells;
    }

    //=== Public Methods
    public void update()
    {
        // Scan for contained numbers
        for (Cell cell : this.zoneCells)
        {
            if (cell.getStoredNumber() != 0 && !this.containedNumbers.contains(cell.getStoredNumber()))
                this.containedNumbers.add(cell.getStoredNumber());
        }

        // Strike candidates from all cells
        for (Cell cell : this.zoneCells)
        {
            for (int i : this.containedNumbers)
                cell.strikeCandidate(i);
        }
    }

    public void printProgress()
    {
        if (this.zoneType == ZoneType.Row) System.out.print("Row " + this.zoneIndex);
        else if (this.zoneType == ZoneType.Column) System.out.print("Column " + this.zoneIndex);
        else System.out.print("Box " + this.zoneIndex);
        
        System.out.print(" contains: ");
        for (int number : this.containedNumbers)
            System.out.print(number + " ");
        
        System.out.println();
    }

    //=== Getters
    public ZoneType getZoneType() { return this.zoneType; }
    public int getZoneIndex() { return this.zoneIndex; }
    public ArrayList<Integer> getContainedNumbers() { return this.containedNumbers; }
    public ArrayList<Cell> getCells() { return this.zoneCells; }
}