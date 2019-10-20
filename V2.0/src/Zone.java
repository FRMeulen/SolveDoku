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
    public Zone(Sudoku sudoku, int index)
    {
        this.linkedPuzzle = sudoku;
        this.containedNumbers = new ArrayList<Integer>();
        determineZoneType(index);
        requestCells();
    }

    //=== Private Methods
    private void determineZoneType(int index)
    {
       if (index < 9)
       {
           this.zoneType = ZoneType.Row;
           this.zoneIndex = index;
       } 

       else if (index >= 9 && index < 18)
       {
           this.zoneType = ZoneType.Column;
           this.zoneIndex = index - 9;
       }

       else
       {
            this.zoneType = ZoneType.Box;
            this.zoneIndex = index - 18;
       }
    }

    private void requestCells()
    {
        // Check for NullPointer
        if (this.linkedPuzzle == null) return;

        //  Request cells based on type and index
        if (this.zoneType == ZoneType.Row)
        {
            this.zoneCells = this.linkedPuzzle.getZoneManager().getRowCells(zoneIndex);
        }

        else if (this.zoneType == ZoneType.Column)
        {
            this.zoneCells = this.linkedPuzzle.getZoneManager().getColumnCells(zoneIndex);
        }

        else if (this.zoneType == ZoneType.Box)
        {
            this.zoneCells = this.linkedPuzzle.getZoneManager().getBoxCells(zoneIndex);
        }

        // Set self as cell zone
        for (Cell cell : this.zoneCells) cell.setZone(this);
    }

    //=== Public Methods
    public void update()
    {
        for (Cell cell : this.zoneCells)
        {
            if (cell.getStoredNumber() != 0 && !this.containedNumbers.contains(cell.getStoredNumber()))
                this.containedNumbers.add(cell.getStoredNumber());
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

    //=== Setters
}