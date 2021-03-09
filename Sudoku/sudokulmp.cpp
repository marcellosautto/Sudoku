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
	system("cls");
	if (solveSudoku(0, 0, false)) //if a solution is found, print sudoku grid, if not, print no solution
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

	for (int k = 0; k < 9; k++)
	{
		for (int l = 0; l < 9; l++)
			gridCopy[k][l] = grid[k][l];
	}
}

bool sudoku::solveSudoku(int row, int col, bool isDeadEnd)
{
	if (row == 9) //we found a solution
		return true;
	else if (row == -1) //there is no solution
		return false;
	
	if (col > 8) //go to the next row
	{
		col = 0;
		row++;
	}

	else if (col < 0) //go to the prev row
	{
		col = 8;
		row--;
	}

	if (findEmptyGridSlot(row, col) && !findNum(row, col, 1)) //if there's an empty grid slot and there isn't a number which can be placed there, we've reached a dead end
	{
		isDeadEnd = true;
		solveSudoku(row, col - 1, isDeadEnd);
	}

	else if (isDeadEnd == true) //if we reached a dead end, check if the grid slot we backtracked to is still a dead end, if not, increment it by 1 and continue solving
	{
		if (grid[row][col] != gridCopy[row][col] && findReplacement(row, col, grid[row][col] + 1)) //if the current grid slot is not a part of the original grid and there's another value that can be placed there, place it and proceed
		{
			isDeadEnd = false;
			solveSudoku(row, col + 1, isDeadEnd);
		}

		else //no replacement found, go back another space
			solveSudoku(row, col - 1, isDeadEnd);
	}

	else //keep looking
		solveSudoku(row, col + 1, isDeadEnd);
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
	if (!numAlreadyInRow(row, num) && !numAlreadyInCol(col, num) && !numAlreadyInBox(row - row % 3, col - col % 3, num) && num != 10)
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

bool sudoku::findNum(int row, int col, int num)
{
	if (canPlaceNum(row, col, num)) //if the number being looked at is not in the same row, column or 3x3 space, assign that value to the grid spot and continue through the grid
	{
		grid[row][col] = num;
		return true;
	}

	else if (num < 9) //go to the next number
		return findNum(row, col, num + 1);

	else
		return false;
}

bool sudoku::findReplacement(int row, int col, int num)
{

	if (canPlaceNum(row, col, num)) //if the number being looked at is not in the same row, column or 3x3 space, assign that value to the grid spot and continue through the grid
	{
		grid[row][col] = num;
		return true;
	}

	else if (num < 9) //start from the current value and go up
		return findReplacement(row, col, num + 1);

	else //no value found, set grid space to 0
	{
		grid[row][col] = 0;
		return false;
	}

}

bool sudoku::printSudokuGrid() //prints solution
{
	cout << "Original Sudoku Grid:" << endl << endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << gridCopy[i][j] << " ";
		cout << endl;
	}

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


