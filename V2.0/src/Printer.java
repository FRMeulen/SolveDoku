/// <project> SolveDoku 2 </project>
/// <author> F.R. van der Meulen </author>
/// <summary> Printer Class </summary>
/// <date> 2019-10-16 </date>

//- Imports
import java.lang.StringBuilder;

//- Class
public class Printer
{
    //=== Properties
    private Sudoku linkedPuzzle;
    private int[] filledNumbers = new int[81];

    //=== Constructor
    public Printer(Sudoku sudoku)
    {
        this.linkedPuzzle = sudoku;
    }

    //=== Methods
    public void printSudoku()
    {
        // Update before printing
        this.update();

        // Indexes of numbers in a sudoku char array
        int[] numberIndexes = {
            44,   48,  52,  58,  62,  66,  72,  76,  80,
            128, 132, 136, 142, 146, 150, 156, 160, 164,
            212, 216, 220, 226, 230, 234, 240, 244, 248,
            338, 342, 346, 352, 356, 360, 366, 370, 374,
            422, 426, 430, 436, 440, 444, 450, 454, 458,
            506, 510, 514, 520, 524, 528, 534, 538, 542,
            632, 636, 640, 646, 650, 654, 660, 664, 668,
            716, 720, 724, 730, 734, 738, 744, 748, 752,
            800, 804, 808, 814, 818, 822, 828, 832, 836
        };

        // Build sudoku string
        StringBuilder sb = new StringBuilder();
        sb.append("┌───┬───┬───┐ ┌───┬───┬───┐ ┌───┬───┬───┐\n")
          .append("│   │   │   │ │   │   │   │ │   │   │   │\n")
          .append("├───┼───┼───┤ ├───┼───┼───┤ ├───┼───┼───┤\n")
          .append("│   │   │   │ │   │   │   │ │   │   │   │\n")
          .append("├───┼───┼───┤ ├───┼───┼───┤ ├───┼───┼───┤\n")
          .append("│   │   │   │ │   │   │   │ │   │   │   │\n")
          .append("└───┴───┴───┘ └───┴───┴───┘ └───┴───┴───┘\n")
          .append("┌───┬───┬───┐ ┌───┬───┬───┐ ┌───┬───┬───┐\n")
          .append("│   │   │   │ │   │   │   │ │   │   │   │\n")
          .append("├───┼───┼───┤ ├───┼───┼───┤ ├───┼───┼───┤\n")
          .append("│   │   │   │ │   │   │   │ │   │   │   │\n")
          .append("├───┼───┼───┤ ├───┼───┼───┤ ├───┼───┼───┤\n")
          .append("│   │   │   │ │   │   │   │ │   │   │   │\n")
          .append("└───┴───┴───┘ └───┴───┴───┘ └───┴───┴───┘\n")
          .append("┌───┬───┬───┐ ┌───┬───┬───┐ ┌───┬───┬───┐\n")
          .append("│   │   │   │ │   │   │   │ │   │   │   │\n")
          .append("├───┼───┼───┤ ├───┼───┼───┤ ├───┼───┼───┤\n")
          .append("│   │   │   │ │   │   │   │ │   │   │   │\n")
          .append("├───┼───┼───┤ ├───┼───┼───┤ ├───┼───┼───┤\n")
          .append("│   │   │   │ │   │   │   │ │   │   │   │\n")
          .append("└───┴───┴───┘ └───┴───┴───┘ └───┴───┴───┘\n");

        // Fill sudoku with stored numbers
        for (int i = 0; i < 81; i++)
        {
            if (this.filledNumbers[i] != 0)
                sb.setCharAt(numberIndexes[i], Character.forDigit(this.filledNumbers[i], 10));
        }

        // Print sudoku
        System.out.println(sb.toString());
    }

    public void update()
    {
        for (int i = 0; i < 81; i++)
            this.filledNumbers[i] = this.linkedPuzzle.getCell(i).getStoredNumber();
    }
}