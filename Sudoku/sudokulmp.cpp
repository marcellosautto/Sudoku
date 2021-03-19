#include "sudoku.h"

////////////////////////////////////////////
// IMPORTANT: MUST RUN PROGRAM IN RELEASE //
////////////////////////////////////////////

sudoku::sudoku()
{
	for (int row = 0; row < 9; row++)
		for (int col = 0; col < 9; col++)
			grid[row][col] = 0;
}

bool sudoku::run()
{
	initializeSudokuGrid();
	if (solveSudoku(0, 0, 1)) //if a solution is found, print sudoku grid, if not, print no solution
		return printSudokuGrid();
	else
		return noSolution();
}

void sudoku::initializeSudokuGrid() //initializes the sudoku grid
{
	int rowNum = 1;
	cout << "INSTRUCTIONS: " << endl;
	cout << "(1) Type All 9 Numbers In Row Before Pressing ENTER" << endl;
	cout << "(2) Include a Space Between Each Number (Ex. 0 8 0 1 7 0 0 0 3)" << endl;
	cout << "(3) You Can Also Copy/Paste A Grid Directly Into Console" << endl << endl;

	for (int i = 0; i < 9; i++)
	{
		cout << "Please enter 9 values (0-9) for row #" << rowNum << ": " << endl;
		for (int j = 0; j < 9; j++)
		{
			cin >> grid[i][j];
		}
		cout << endl;
		rowNum++;
	}

	system("cls");
	cout << "Original Sudoku Grid:" << endl << endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << grid[i][j] << " ";
		cout << endl;
	}
}

bool sudoku::solveSudoku(int row, int col, int num)
{
	for (int r = 0; r < 9; r++)
		for (int c = 0; c < 9; c++)
		{
			if (findEmptyGridSlot(r, c))
			{
				num = grid[r][c];
				for (int n = num + 1; n <= 9; n++)
				{
					if (canPlaceNum(r, c, n))
					{
						grid[r][c] = n;
						if (solveSudoku(r, c, n))
							return true;
					}
				}
				grid[row][col] = 0;
				return false;
			}
		}
}

bool sudoku::findEmptyGridSlot(int row, int col) //if the grid slot is empty, return true
{
	if (grid[row][col] == 0)
		return true;
	else
		return false;
}

bool sudoku::canPlaceNum(int row, int col, int num) //if the number is not in the same row, column, or 3x3 grid, it can be placed
{
	if (!numAlreadyInRow(row, num) && !numAlreadyInCol(col, num) && !numAlreadyInBox(row - row % 3, col - col % 3, num))
		return true;
	else
		return false;

}

bool sudoku::numAlreadyInRow(int row, int num) //check if the number is in the same row
{
	for (int i = 0; i < 9; i++)
		if (grid[row][i] == num)
			return true;
	return false;
}

bool sudoku::numAlreadyInCol(int col, int num) //check if the number is in the same column
{
	for (int i = 0; i < 9; i++)
		if (grid[i][col] == num)
			return true;
	return false;
}

bool sudoku::numAlreadyInBox(int smallGridRow, int smallGridCol, int num) //check if the number is in the 3x3 grid
{
	for (int sGR = 0; sGR < 3; sGR++)
		for (int sGC = 0; sGC < 3; sGC++)
			if (grid[smallGridRow + sGR][smallGridCol + sGC] == num)
				return true;
	return false;

}

bool sudoku::printSudokuGrid() //prints solution
{
	cout << endl << endl << "Solution:" << endl << endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << grid[i][j] << " ";
		cout << endl;
	}

	char repeat;
	cout << endl << "Would you like to enter another sudoku grid? (Y/N)" << endl;
	cin >> repeat;
	if (repeat == 'Y' || repeat == 'y')
	{
		system("cls");
		return true;
	}

	else if (repeat == 'N' || repeat == 'n')
	{
		cout << "Thank you!";
		return false;
	}
}

bool sudoku::noSolution() //prints no solution
{
	cout << "No Solution Exists For This Sudoku Grid :(" << endl << endl;

	char repeat;
	cout << "Would you like to enter another sudoku grid? (Y/N)" << endl;
	cin >> repeat;
	if (repeat == 'Y' || repeat == 'y')
	{
		system("cls");
		return true;
	}

	else if (repeat == 'N' || repeat == 'n')
	{
		cout << "Thank you!";
		return false;
	}
}


