/// <project> SolveDoku 2 </project>
/// <author> F.R. van der Meulen </author>
/// <summary> Single Candidate Rule </summary>
/// <date> 2019-10-29 </date>

//- Imports
import java.util.ArrayList;

//- Class
class RuleSingleCandidate extends Rule
{
    //=== Constructor
    public RuleSingleCandidate(Sudoku sudoku)
    {
        super(sudoku);
    }

    //=== Execute Method
    @Override
    public void execute()
    {
        for (Cell cell : super.linkedPuzzle.getCells())
        {
            this.checkCell(cell);
        }
    }

    //=== Private Methods
    private void checkCell(Cell target)
    {
        // Check if rule can be applied
        if (target.getCandidates().size() != 1) return;

        // Fill cell with last candidate
        target.fill(target.getCandidates().get(0));
    }
}