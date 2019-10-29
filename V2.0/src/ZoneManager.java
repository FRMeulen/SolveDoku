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
    private ArrayList<Zone> rows;
    private ArrayList<Zone> columns;
    private ArrayList<Zone> boxes;
    private ArrayList<Zone> allZones;

    //=== Constructor
    public ZoneManager(Sudoku sudoku)
    {
        this.linkedPuzzle = sudoku;

        // Create lists
        this.rows = new ArrayList<Zone>();
        this.columns = new ArrayList<Zone>();
        this.boxes = new ArrayList<Zone>();
        this.allZones = new ArrayList<Zone>();

        // Form lists
        this.formRowLists();
        this.formColumnLists();
        this.formBoxLists();

        // Update cells
        this.updateCells();
    }

    //=== Public Methods
    public void debug(boolean thorough)
    {
        final String rowListsMsg = this.rows.size() > 0
        ? "ZoneManager formed " + this.rows.size() + " rows."
        : "ZoneManager failed to form rows.";

        final String columnListsMsg = this.columns.size() > 0
        ? "ZoneManager formed " + this.columns.size() + " columns."
        : "ZoneManager failed to form columns.";

        final String boxListsMsg = this.boxes.size() > 0
        ? "ZoneManager formed " + this.boxes.size() + " boxes."
        : "ZoneManager failed to form boxes.";

        System.out.println(rowListsMsg);
        if (thorough)
        {
            for (Zone row : this.rows)
            {
                System.out.println("  -Row found:");
                for (Cell cell : row.getCells())
                {
                    System.out.println("    -Contains cell with index: " + cell.getIndex());
                }
                System.out.println();
            }
        }

        System.out.println(columnListsMsg);
        if (thorough)
        {
            for (Zone column : this.columns)
            {
                System.out.println("  -Column found:");
                for (Cell cell : column.getCells())
                {
                    System.out.println("    -Contains cell with index: " + cell.getIndex());
                }
                System.out.println();
            }
        }
        
        System.out.println(boxListsMsg);
        if (thorough)
        {
            for (Zone box : this.boxes)
            {
                System.out.println("  -Box found:");
                for (Cell cell : box.getCells())
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
        int rowIndex = 0;
        for (int i = 0; i < 81; i+=9)
        {
            ArrayList<Cell> tempList = new ArrayList<Cell>();
            for (int j = 0; j < 9; j++)
            {
                tempList.add(linkedPuzzle.getCell( i + j ));
            }
            
            Zone row = new Zone(this.linkedPuzzle, ZoneType.Row, rowIndex, tempList);
            this.rows.add(row);
            this.allZones.add(row);
            rowIndex++;
        }
    }

    private void formColumnLists()
    {
        int columnIndex = 0;
        for (int i = 0; i < 9; i++)
        {
            ArrayList<Cell> tempList = new ArrayList<Cell>();
            for (int j = 0; j < 81; j+=9)
            {
                tempList.add(linkedPuzzle.getCell( i + j ));
            }

            Zone column = new Zone(this.linkedPuzzle, ZoneType.Column, columnIndex, tempList);
            this.columns.add(column);
            this.allZones.add(column);
            columnIndex++;
        }
    }

    private void formBoxLists()
    {
        int boxIndex = 0;
        int[] topLeftIndexes = {0, 3, 6, 27, 30, 33, 54, 57, 60};
        for (int topLeft : topLeftIndexes)
        {
            ArrayList<Cell> tempList = new ArrayList<Cell>();
            int[] boxCellIndexes = {
                topLeft, topLeft + 1, topLeft + 2, 
                topLeft + 9, topLeft + 10, topLeft + 11,
                topLeft + 18, topLeft + 19, topLeft + 20
            };

            for (int index : boxCellIndexes)
            {
                tempList.add(linkedPuzzle.getCell(index));
            }

            Zone box = new Zone(this.linkedPuzzle, ZoneType.Box, boxIndex, tempList);
            this.boxes.add(box);
            this.allZones.add(box);
            boxIndex++;
        }
    }

    private void updateCells()
    {
        // Update cells with row info
        for (Zone row : this.rows)
        {
            for (Cell cell : row.getCells())
            {
                cell.setRow(row);
            }
        }

        // Update cells with column info
        for (Zone column : this.columns)
        {
            for (Cell cell : column.getCells())
            {
                cell.setColumn(column);
            }
        }

        // Update cells with box info
        for (Zone box : this.boxes)
        {
            for (Cell cell : box.getCells())
            {
                cell.setBox(box);
            }
        }
    }

    //=== Getters
    public ArrayList<Zone> getAllZones() { return this.allZones; }
    public ArrayList<Zone> getRows() { return this.rows; }
    public ArrayList<Zone> getColumns() { return this.columns; }
    public ArrayList<Zone> getBoxes() { return this.boxes; }
    public Zone getRow(int index) { return this.rows.get(index); }
    public Zone getColumn(int index) { return this.columns.get(index); }
    public Zone getBox(int index) { return this.boxes.get(index); }

    //=== Setters
}