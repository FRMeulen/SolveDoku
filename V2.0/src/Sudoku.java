/// <project> SolveDoku 2 </project>
/// <author> F.R. van der Meulen </author>
/// <summary> Sudoku Class </summary>
/// <date> 2019-10-16 </date>

//- Imports
import java.util.*;

//- Class
public class Sudoku
{
    //=== Properties
    private ArrayList<Cell> cells;
    private ZoneManager zoneManager;
    private ArrayList<Zone> zones;
    private Checker checker;

    //=== Constructor
    public Sudoku()
    {
        // Create lists
        this.cells = new ArrayList<Cell>();
        this.zones = new ArrayList<Zone>();

        // Create cells
        for (int i = 0; i < 81; i++)
        {
            Cell cell = new Cell(this, i);
            this.cells.add(cell);
        }

        // Create zone manager
        this.zoneManager = new ZoneManager(this);

        // Create zones
        for (int i = 0; i < 27; i++)
        {
            Zone zone = new Zone(this, i);
            this.zones.add(zone);
        }

        // Create checker
        this.checker = new Checker(this);
    }

    //=== Methods
    public void debug(boolean thorough)
    {
        final String cellsMsg = this.cells.size() > 0
        ? "Sudoku has " + this.cells.size() + " assigned cells."
        : "Sudoku has no assigned cells.";

        System.out.println();
        final String zonesMsg = this.zones.size() > 0
        ? "Sudoku has " + this.zones.size() + " assigned zones."
        : "sudoku has no assigned zones.";

        final String checkerMsg = this.checker != null
        ? "Sudoku has an assigned checker.\n"
        : "Sudoku has no assigned checker.\n";

        System.out.println(cellsMsg);
        if (thorough)
        {
            for (Cell cell : this.cells)
            {
                System.out.println("  -Cell with index: " + cell.getIndex());
            }
        }

        System.out.println(zonesMsg);
        if (thorough)
        {
            for (Zone zone : this.zones)
            {
                System.out.println("  -Zone of type: " + zone.getZoneType() + " and index: " + zone.getZoneIndex());
            }
        }

        System.out.println(checkerMsg);

        this.zoneManager.debug(thorough);
    }

    //=== Getters
    public Cell getCell(int index) { return this.cells.get(index); }
    public ZoneManager getZoneManager() { return this.zoneManager; }

    //=== Setters
}