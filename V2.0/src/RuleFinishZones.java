/// <project> SolveDoku 2 </project>
/// <author> F.R. van der Meulen </author>
/// <summary> Finish Zone Rule </summary>
/// <date> 2019-10-29 </date>

//- Imports
import java.util.ArrayList;

//- Class
public class RuleFinishZones extends Rule
{
    //=== Constructor
    public RuleFinishZones(Sudoku sudoku)
    {
        super(sudoku);
    }

    //=== Execute Method
    @Override
    public void execute()
    {
        // Execute rule for all zones in sudoku
        for (Zone zone : super.linkedPuzzle.getZoneManager().getAllZones())
        {
            this.finishZone(zone);
        }
    }

    //=== Private Methods
    private void finishZone(Zone target)
    {
        // Check if rule can be executed on target
        if (target.getContainedNumbers().size() != 8) return;

        // Fill empty cell with missing number
        findEmptyCell(target).fill( findMissingNum( target.getContainedNumbers() ) );
    }

    private int findMissingNum(ArrayList<Integer> numbers)
    {
        for (int i = 1; i < 10; i++)
        {
            if (!numbers.contains(i))
                return i;
        }

        return 0;
    }

    private Cell findEmptyCell(Zone target)
    {
        for (Cell cell : target.getCells())
        {
            if (cell.getStoredNumber() == 0)
                return cell;
        }

        return null;
    }
}