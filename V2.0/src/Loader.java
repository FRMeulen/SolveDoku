/// <project> SolveDoku 2 </project>
/// <author> F.R. van der Meulen </author>
/// <summary> Loader Class </summary>
/// <date> 2019-10-20 </date>

//- Imports
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.stream.Stream;
import java.lang.StringBuilder;

//- Class
public class Loader
{
    //=== Properties
    private String loadedSudokuString;
    private int[] loadedNumbers = new int[81];

    //=== Constructor
    public Loader() {}
    
    //=== Methods
    public void loadSudoku(String source, Sudoku target)
    {
        this.loadedSudokuString = this.readSudokuFile(source);
        if (this.loadedSudokuString == null)
            return;

        this.scanForNumbers();
        this.fillSudoku(target);
        target.updateAll();
    }

    private String readSudokuFile(String source)
    {
        // Create string builder
        StringBuilder sb = new StringBuilder();

        // Try to read file
        try (Stream<String> stream = Files.lines( Paths.get(source), StandardCharsets.UTF_8))
        {
            stream.forEach(s -> sb.append(s).append("\n"));
        }

        catch (IOException e)
        {
            e.printStackTrace();
        }

        return sb.toString();
    }
    
    private void scanForNumbers()
    {   
        // Indexes of numbers in sudoku string
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

        for (int i = 0; i < numberIndexes.length; i++)
        {
            char checkChar = this.loadedSudokuString.charAt(numberIndexes[i]);
            if (checkChar != ' ')
            {
                this.loadedNumbers[i] = Character.getNumericValue(checkChar);
            }

            else
            {
                this.loadedNumbers[i] = 0;
            }
        }
    }

    private void fillSudoku(Sudoku target)
    {
        for (int i = 0; i < 81; i++)
            target.getCell(i).fill(this.loadedNumbers[i]);
    }

    //== Getters
    public String getLoadedSudokuString() { return this.loadedSudokuString; }
    public int[] getLoadedNumbers() { return this.loadedNumbers; }

    //=== Setters
}