/// <project> SolveDoku 2 </project>
/// <author> F.R. van der Meulen </author>
/// <summary> ZoneManager Class </summary>
/// <date> 2019-10-16 </date>

//- Imports
import java.util.*;

//- Class
public class ZoneManager
{
    //=== Properties
    private Sudoku linkedPuzzle;
    private ArrayList<ArrayList<Cell>> rowZoneCells;
    private ArrayList<ArrayList<Cell>> columnZoneCells;
    private ArrayList<ArrayList<Cell>> boxZoneCells;

    //=== Constructor
    public ZoneManager(Sudoku sudoku)
    {
        this.linkedPuzzle = sudoku;

        // Create lists
        this.rowZoneCells = new ArrayList<ArrayList<Cell>>();
        this.columnZoneCells = new ArrayList<ArrayList<Cell>>();
        this.boxZoneCells = new ArrayList<ArrayList<Cell>>();

        // Form lists
        this.formRowLists();
        this.formColumnLists();
        this.formBoxLists();
    }

    //=== Public Methods
    public void debug(boolean thorough)
    {
        final String rowListsMsg = this.rowZoneCells.size() > 0
        ? "ZoneManager formed " + this.rowZoneCells.size() + " rows."
        : "ZoneManager failed to form rows.";

        final String columnListsMsg = this.columnZoneCells.size() > 0
        ? "ZoneManager formed " + this.columnZoneCells.size() + " columns."
        : "ZoneManager failed to form columns.";

        final String boxListsMsg = this.boxZoneCells.size() > 0
        ? "ZoneManager formed " + this.boxZoneCells.size() + " boxes."
        : "ZoneManager failed to form boxes.";

        System.out.println(rowListsMsg);
        if (thorough)
        {
            for (ArrayList<Cell> rowZone : this.rowZoneCells)
            {
                System.out.println("  -Row found:");
                for (Cell cell : rowZone)
                {
                    System.out.println("    -Contains cell with index: " + cell.getIndex());
                }
                System.out.println();
            }
        }

        System.out.println(columnListsMsg);
        if (thorough)
        {
            for (ArrayList<Cell> columnZone : this.columnZoneCells)
            {
                System.out.println("  -Column found:");
                for (Cell cell : columnZone)
                {
                    System.out.println("    -Contains cell with index: " + cell.getIndex());
                }
                System.out.println();
            }
        }
        
        System.out.println(boxListsMsg);
        if (thorough)
        {
            for (ArrayList<Cell> boxZone : this.boxZoneCells)
            {
                System.out.println("  -Box found:");
                for (Cell cell : boxZone)
                {
                    System.out.println("    -Contains cell with index: " + cell.getIndex());
                }
                System.out.println();
            }
        }
    }

    //=== Private Methods
    private void formRowLists()
    {
        for (int i = 0; i < 81; i+=9)
        {
            ArrayList<Cell> tempList = new ArrayList<Cell>();
            for (int j = 0; j < 9; j++)
            {
                tempList.add(linkedPuzzle.getCell( i + j ));
            }
            
            rowZoneCells.add(tempList);
        }
    }

    private void formColumnLists()
    {
        for (int i = 0; i < 9; i++)
        {
            ArrayList<Cell> tempList = new ArrayList<Cell>();
            for (int j = 0; j < 81; j+=9)
            {
                tempList.add(linkedPuzzle.getCell( i + j ));
            }

            columnZoneCells.add(tempList);
        }
    }

    private void formBoxLists()
    {
        
        int[] topRightIndexes = {0, 3, 6, 27, 30, 33, 54, 57, 60};
        for (int topRight : topRightIndexes)
        {
            ArrayList<Cell> tempList = new ArrayList<Cell>();
            int[] boxCellIndexes = {
                topRight, topRight + 1, topRight + 2, 
                topRight + 9, topRight + 10, topRight + 11,
                topRight + 18, topRight + 19, topRight + 20
            };

            for (int index : boxCellIndexes)
            {
                tempList.add(linkedPuzzle.getCell(index));
            }

            boxZoneCells.add(tempList);
        }
    }

    //=== Getters
    public ArrayList<Cell> getRowCells(int index) { return rowZoneCells.get(index); }
    public ArrayList<Cell> getColumnCells(int index) { return columnZoneCells.get(index); }
    public ArrayList<Cell> getBoxCells(int index) { return boxZoneCells.get(index); }

    //=== Setters
}