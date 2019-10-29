/// <project> SolveDoku 2 </project>
/// <author> F.R. van der Meulen </author>
/// <summary> RuleManager Class </summary>
/// <date> 2019-10-29 </date>

//- Imports
import java.util.ArrayList;

//- Class
public class RuleManager
{
    //=== Properties
    Sudoku linkedPuzzle;
    ArrayList<Rule> rules;

    //=== Constructor
    public RuleManager(Sudoku sudoku)
    {
        this.linkedPuzzle = sudoku;
        this.rules = new ArrayList<Rule>();
    }

    //=== Methods
    public void addRule(Rule rule)
    {
        this.rules.add(rule);
    }

    public void executeAll()
    {
        for (Rule rule : this.rules)
            rule.execute();
    }
}