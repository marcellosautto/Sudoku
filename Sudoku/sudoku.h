#include <iostream>
#include <conio.h>
using namespace std;
class sudoku
{
public:
    sudoku();
    //default constructor
    //Postcondition: grid is initialized to 0
    bool run();

private:
    int grid[9][9];
  
    void initializeSudokuGrid();
    //Function to promt the user to specify the numbers of the
    //partially filled grid.
    //Postcondition: grid is initialized to the numbers 
    //    specified by the user.

    bool printSudokuGrid();
    //Function to print the sudoku grid.

    bool solveSudoku(int row, int col, int num);
    //Funtion to solve the sudoku problem.
    //Postcondition: If a solution exits, it returns true,
    //    otherwise it returns false.

    bool findEmptyGridSlot(int row, int col);
    //Function to determine if the grid slot specified by 
    //row and col is empty.
    //Postcondition: Returns true if grid[row][col] = 0;

    bool canPlaceNum(int row, int col, int num);
    //Function to determine if num can be placed in 
    //grid[row][col]
    //Postcondition: Returns true if num can be placed in
    //    grid[row][col], otherwise it returns false.

    bool numAlreadyInRow(int row, int num);
    //Function to determine if num is in grid[row][]
    //Postcondition: Returns true if num is in grid[row][],
    //    otherwise it returns false.

    bool numAlreadyInCol(int col, int num);
    //Function to determine if num is in grid[row][]
    //Postcondition: Returns true if num is in grid[row][],
    //    otherwise it returns false.

    bool numAlreadyInBox(int smallGridRow, int smallGridCol, int num);
    //Function to determine if num is in the small grid
    //Postcondition: Returns true if num is in small grid,
    //    otherwise it returns false.

    //bool findNum(int row, int col, int num); //finds a number to place in an empty grid spot

    //bool findReplacement(int row, int col, int num); //finds a number to replace a value when backtracking

    bool noSolution(); //prints "no solution" if solution does not exist

};

