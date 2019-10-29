/// <project> SolveDoku 2 </project>
/// <author> F.R. van der Meulen </author>
/// <summary> Abstract Rule Class </summary>
/// <date> 2019-10-29 </date>

//- Class
public abstract class Rule
{
    //=== Properties
    Sudoku linkedPuzzle;

    //=== Constructor
    public Rule(Sudoku sudoku)
    {
        this.linkedPuzzle = sudoku;
    }

    //=== Methods
    public void execute()
    {

    }
}