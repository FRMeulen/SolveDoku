/// <project> SolveDoku 2 </project>
/// <author> F.R. van der Meulen </author>
/// <summary> Zone Class </summary>
/// <date> 2019-10-16 </date>

//- Imports
import java.util.*;

//- Class
public class Zone
{
    //=== Properties
    private Sudoku linkedPuzzle;
    private ZoneType zoneType;
    private int zoneIndex;
    private ArrayList<Cell> zoneCells;

    //=== Constructor
    public Zone(Sudoku sudoku, int index)
    {
        this.linkedPuzzle = sudoku;
        determineZoneType(index);
        requestCells();
    }

    //=== Methods
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
    }

    //=== Getters
    public ZoneType getZoneType() { return this.zoneType; }
    public int getZoneIndex() { return this.zoneIndex; }

    //=== Setters
}