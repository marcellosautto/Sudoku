#include "sudoku.h"

int main()
{
	sudoku* solveSudoku = new sudoku(); //create pointer to sudoku class
	while (solveSudoku->run()) //while mainLoop returns true, create a new instance of the sudoku class
		solveSudoku = new sudoku();
}

