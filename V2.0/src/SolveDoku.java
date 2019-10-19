/// <project> SolveDoku 2 </project>
/// <author> F.R. van der Meulen </author>
/// <summary> Main Java File </summary>
/// <date> 2019-10-16 </date>

//- Class
public class SolveDoku
{
    public static void main(String[] args)
    {
        Sudoku puzzle = new Sudoku();
        String easySudokuPath = "./res/easy.txt";
        Loader loader = new Loader();
        loader.loadSudoku(easySudokuPath, puzzle);
        puzzle.getPrinter().printSudoku();
    }
}