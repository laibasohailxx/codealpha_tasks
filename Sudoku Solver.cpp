//Sudoku Solver

#include <iostream>
using namespace std;

const int SIZE = 9;

// Function to print Sudoku grid
void printGrid(int grid[SIZE][SIZE]) {

    cout << "\nSolved Sudoku Puzzle:\n\n";

    for (int row = 0; row < SIZE; row++) {

        for (int col = 0; col < SIZE; col++) {
            cout << grid[row][col] << " ";
        }

        cout << endl;
    }
}

// Check if number exists in row
bool isRowSafe(int grid[SIZE][SIZE], int row, int num) {

    for (int col = 0; col < SIZE; col++) {

        if (grid[row][col] == num)
            return false;
    }

    return true;
}

// Check if number exists in column
bool isColSafe(int grid[SIZE][SIZE], int col, int num) {

    for (int row = 0; row < SIZE; row++) {

        if (grid[row][col] == num)
            return false;
    }

    return true;
}

// Check 3x3 subgrid
bool isBoxSafe(int grid[SIZE][SIZE], int startRow, int startCol, int num) {

    for (int row = 0; row < 3; row++) {

        for (int col = 0; col < 3; col++) {

            if (grid[row + startRow][col + startCol] == num)
                return false;
        }
    }

    return true;
}

// Check if placing number is valid
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num) {

    return isRowSafe(grid, row, num) &&
           isColSafe(grid, col, num) &&
           isBoxSafe(grid, row - row % 3, col - col % 3, num);
}

// Find empty cell
bool findEmptyCell(int grid[SIZE][SIZE], int &row, int &col) {

    for (row = 0; row < SIZE; row++) {

        for (col = 0; col < SIZE; col++) {

            if (grid[row][col] == 0)
                return true;
        }
    }

    return false;
}

// Backtracking Sudoku Solver
bool solveSudoku(int grid[SIZE][SIZE]) {

    int row, col;

    // If no empty cell exists, puzzle solved
    if (!findEmptyCell(grid, row, col))
        return true;

    // Try numbers 1 to 9
    for (int num = 1; num <= 9; num++) {

        if (isSafe(grid, row, col, num)) {

            // Place number
            grid[row][col] = num;

            // Recursive call
            if (solveSudoku(grid))
                return true;

            // Backtrack
            grid[row][col] = 0;
        }
    }

    return false;
}

int main() {

    int grid[SIZE][SIZE] = {

        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},

        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},

        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Original Sudoku Puzzle:\n\n";

    for (int row = 0; row < SIZE; row++) {

        for (int col = 0; col < SIZE; col++) {
            cout << grid[row][col] << " ";
        }

        cout << endl;
    }

    // Solve Sudoku
    if (solveSudoku(grid)) {
        printGrid(grid);
    }
    else {
        cout << "\nNo Solution Exists.\n";
    }

    return 0;
}
