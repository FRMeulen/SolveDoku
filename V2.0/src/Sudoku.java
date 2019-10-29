/// <project> SolveDoku 2 </project>
/// <author> F.R. van der Meulen </author>
/// <summary> Sudoku Class </summary>
/// <date> 2019-10-16 </date>

//- Imports
import java.util.ArrayList;

//- Class
public class Sudoku
{
    //=== Properties
    private ArrayList<Cell> cells;
    private ZoneManager zoneManager;
    private Printer printer;
    private RuleManager ruleManager;

    //=== Constructor
    public Sudoku()
    {
        // Create lists
        this.cells = new ArrayList<Cell>();

        // Create cells
        for (int i = 0; i < 81; i++)
        {
            Cell cell = new Cell(this, i);
            this.cells.add(cell);
        }

        // Create child objects
        this.zoneManager = new ZoneManager(this);
        this.printer = new Printer(this);
        this.ruleManager = new RuleManager(this);

        // Create and add rules
        this.ruleManager.addRule(new RuleFinishZones(this));
    }

    //=== Methods
    public void debug(boolean thorough)
    {
        final String cellsMsg = this.cells.size() > 0
        ? "Sudoku has " + this.cells.size() + " assigned cells."
        : "Sudoku has no assigned cells.";

        System.out.println(cellsMsg);
        if (thorough)
        {
            for (Cell cell : this.cells)
            {
                System.out.println("  -Cell with index: " + cell.getIndex());
            }
        }

        this.zoneManager.debug(thorough);
        this.printer.printSudoku();
    }

    public void updateAll()
    {
        for (Zone zone : this.zoneManager.getAllZones())
            zone.update();
    }

    //=== Getters
    public ArrayList<Cell> getCells() { return this.cells; }
    public Cell getCell(int index) { return this.cells.get(index); }
    public ZoneManager getZoneManager() { return this.zoneManager; }
    public Printer getPrinter() { return this.printer; }
    public RuleManager getRuleManager() { return this.ruleManager; }
}