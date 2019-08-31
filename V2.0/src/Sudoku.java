//	Project:	SolveDoku2.
//	Sudoku.java	--	Source file for the Sudoku class.
//	2019-08-29	--	F.R. van der Meulen	--	Created.

//	Class.
public class Sudoku {
	//	Cells & cell sets.
	private Cell[] cells = new Cell[81];
	private SudokuBox[] boxes = new SudokuBox[9];
	private SudokuColumn[] columns = new SudokuColumn[9];
	private SudokuRow[] rows = new SudokuRow[9];

	//	Progress information.
	private int filledCellCount = 0;
	private double difficultyRating = 0;

	//	Constructor.
	public Sudoku() {
		//	Tracing.
		System.out.println("-------------------------");
		System.out.println("-----Creating sudoku-----");
		System.out.println("-------------------------\n");

		//	Sudoku index layout.
		/*
				00	01	02		03	04	05		06	07	08
				09	10	11		12	13	14		15	16	17
				18	19	20		21	22	23		24	25	26

				27	28	29		30	31	32		33	34	35
				36	37	38		39	40	41		42	43	44
				45	46	47		48	49	50		51	52	53

				54	55	56		57	58	59		60	61	62
				63	64	65		66	67	68		69	70	71
				72	73	74		75	76	77		78	79	80

		 */

		//	Create cells.
		System.out.println("---Assigning cells---");
		for (int i = 0; i < 81; i++) {
			int cellNumber = i + 1;
			System.out.println("Creating cell " + cellNumber + "/81...");
			cells[i] = new Cell(i);
		}

		System.out.println("---Cells assigned!---\n");

		//	Create Boxes.
		System.out.println("---Assigning boxes---");
		System.out.println("Assigning box 1/9...");
		boxes[0] = new SudokuBox(1, new Cell[] { cells[0],	cells[1],	cells[2],	cells[9],	cells[10],	cells[11],	cells[18],	cells[19],	cells[20] });
		System.out.println("Assigning box 2/9...");
		boxes[1] = new SudokuBox(2, new Cell[] { cells[3],	cells[4],	cells[5],	cells[12],	cells[13],	cells[14],	cells[21],	cells[22],	cells[23] });
		System.out.println("Assigning box 3/9...");
		boxes[2] = new SudokuBox(3, new Cell[] { cells[6],	cells[7],	cells[8],	cells[15],	cells[16],	cells[17],	cells[24],	cells[25],	cells[26] });
		System.out.println("Assigning box 4/9...");
		boxes[3] = new SudokuBox(4, new Cell[] { cells[27],	cells[28],	cells[29],	cells[36],	cells[37],	cells[38],	cells[45],	cells[46],	cells[47] });
		System.out.println("Assigning box 5/9...");
		boxes[4] = new SudokuBox(5, new Cell[] { cells[30],	cells[31],	cells[32],	cells[39],	cells[40],	cells[41],	cells[48],	cells[49],	cells[50] });
		System.out.println("Assigning box 6/9...");
		boxes[5] = new SudokuBox(6, new Cell[] { cells[33],	cells[34],	cells[35],	cells[42],	cells[43],	cells[44],	cells[51],	cells[52],	cells[53] });
		System.out.println("Assigning box 7/9...");
		boxes[6] = new SudokuBox(7, new Cell[] { cells[54],	cells[55],	cells[56],	cells[63],	cells[64],	cells[65],	cells[72],	cells[73],	cells[74] });
		System.out.println("Assigning box 8/9...");
		boxes[7] = new SudokuBox(8, new Cell[] { cells[57],	cells[58],	cells[59],	cells[66],	cells[67],	cells[68],	cells[75],	cells[76],	cells[77] });
		System.out.println("Assigning box 9/9...");
		boxes[8] = new SudokuBox(9, new Cell[] { cells[60],	cells[61],	cells[62],	cells[69],	cells[70],	cells[71],	cells[78],	cells[79],	cells[80] });
		System.out.println("---Boxes assigned!---\n");

		//	Create Columns.
		System.out.println("---Assigning columns---");
		System.out.println("Assigning column 1/9...");
		columns[0] = new SudokuColumn(1, new Cell[] { cells[0],	cells[9],	cells[18],	cells[27],	cells[36],	cells[45],	cells[54],	cells[63],	cells[72] });
		System.out.println("Assigning column 2/9...");
		columns[1] = new SudokuColumn(2, new Cell[] { cells[1],	cells[10],	cells[19],	cells[28],	cells[37],	cells[46],	cells[55],	cells[64],	cells[73] });
		System.out.println("Assigning column 3/9...");
		columns[2] = new SudokuColumn(3, new Cell[] { cells[2],	cells[11],	cells[20],	cells[29],	cells[38],	cells[47],	cells[56],	cells[65],	cells[74] });
		System.out.println("Assigning column 4/9...");
		columns[3] = new SudokuColumn(4, new Cell[] { cells[3],	cells[12],	cells[21],	cells[30],	cells[39],	cells[48],	cells[57],	cells[66],	cells[75] });
		System.out.println("Assigning column 5/9...");
		columns[4] = new SudokuColumn(5, new Cell[] { cells[4],	cells[13],	cells[22],	cells[31],	cells[40],	cells[49],	cells[58],	cells[67],	cells[76] });
		System.out.println("Assigning column 6/9...");
		columns[5] = new SudokuColumn(6, new Cell[] { cells[5],	cells[14],	cells[23],	cells[32],	cells[41],	cells[50],	cells[59],	cells[68],	cells[77] });
		System.out.println("Assigning column 7/9...");
		columns[6] = new SudokuColumn(7, new Cell[] { cells[6],	cells[15],	cells[24],	cells[33],	cells[42],	cells[51],	cells[60],	cells[69],	cells[78] });
		System.out.println("Assigning column 8/9...");
		columns[7] = new SudokuColumn(8, new Cell[] { cells[7],	cells[16],	cells[25],	cells[34],	cells[43],	cells[52],	cells[61],	cells[70],	cells[79] });
		System.out.println("Assigning column 9/9...");
		columns[8] = new SudokuColumn(9, new Cell[] { cells[8],	cells[17],	cells[26],	cells[35],	cells[44],	cells[53],	cells[62],	cells[71],	cells[80] });
		System.out.println("---Columns assigned!---\n");

		//	Create Rows.
		System.out.println("---Assigning rows---");
		System.out.println("Assigning row 1/9...");
		rows[0] = new SudokuRow(1, new Cell[] { cells[0],	cells[1],	cells[2],	cells[3],	cells[4],	cells[5],	cells[6],	cells[7],	cells[8] });
		System.out.println("Assigning row 2/9...");
		rows[1] = new SudokuRow(2, new Cell[] { cells[9],	cells[10],	cells[11],	cells[12],	cells[13],	cells[14],	cells[15],	cells[16],	cells[17] });
		System.out.println("Assigning row 3/9...");
		rows[2] = new SudokuRow(3, new Cell[] { cells[18],	cells[19],	cells[20],	cells[21],	cells[22],	cells[23],	cells[24],	cells[25],	cells[26] });
		System.out.println("Assigning row 4/9...");
		rows[3] = new SudokuRow(4, new Cell[] { cells[27],	cells[28],	cells[29],	cells[30],	cells[31],	cells[32],	cells[33],	cells[34],	cells[35] });
		System.out.println("Assigning row 5/9...");
		rows[4] = new SudokuRow(5, new Cell[] { cells[36],	cells[37],	cells[38],	cells[39],	cells[40],	cells[41],	cells[42],	cells[43],	cells[44] });
		System.out.println("Assigning row 6/9...");
		rows[5] = new SudokuRow(6, new Cell[] { cells[45],	cells[46],	cells[47],	cells[48],	cells[49],	cells[50],	cells[51],	cells[52],	cells[53] });
		System.out.println("Assigning row 7/9...");
		rows[6] = new SudokuRow(7, new Cell[] { cells[54],	cells[55],	cells[56],	cells[57],	cells[58],	cells[59],	cells[60],	cells[61],	cells[62] });
		System.out.println("Assigning row 8/9...");
		rows[7] = new SudokuRow(8, new Cell[] { cells[63],	cells[64],	cells[65],	cells[66],	cells[67],	cells[68],	cells[69],	cells[70],	cells[71] });
		System.out.println("Assigning row 9/9...");
		rows[8] = new SudokuRow(9, new Cell[] { cells[72],	cells[73],	cells[74],	cells[75],	cells[76],	cells[77],	cells[78],	cells[79],	cells[80] });
		System.out.println("---Rows assigned!---\n");

		//	Tracing.
		System.out.println("-------------------------");
		System.out.println("-----Sudoku created!-----");
		System.out.println("-------------------------\n");
	};

	//	Getters.
	public Cell[] getCells() { return cells; }
	public SudokuBox[] getBoxes() { return boxes; }
	public SudokuColumn[] getColumns() { return columns; }
	public SudokuRow[] getRows() { return rows; }
	public int getFilledCellCount() { return filledCellCount; }
	public double getDifficultyRating() { return difficultyRating; }

	//	Specific getters.
	public Cell getSpecificCell(int index) {
		if (index < 0 || index > 80) throw new IllegalArgumentException("Argument is not a valid cell index!");
		else return cells[index];
	}

	public SudokuBox getSpecificBox(int index) {
		if (index < 0 || index > 8) throw new IllegalArgumentException("Argument is not a box number!");
		else return boxes[index];
	}

	public SudokuColumn getSpecificColumn(int index) {
		if (index < 0 || index > 8) throw new IllegalArgumentException("Argument is not a column number!");
		else return columns[index];
	}

	public SudokuRow getSpecificRow(int index) {
		if (index < 0 || index > 8) throw new IllegalArgumentException("Argument is not a row number!");
		else return rows[index];
	}

	//	Setters.
	public void setFilledCellCount(int count) { this.filledCellCount = count; }
	public void setDifficultyRating(double rating) { this.difficultyRating = rating; }

}
