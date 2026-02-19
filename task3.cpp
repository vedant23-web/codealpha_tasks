#include <iostream>

#define SIZE 9

// Function to print Sudoku board nicely
void printBoard(int board[SIZE][SIZE]) {

    std::cout << "\nSolved Sudoku:\n";
    std::cout << "-------------------------\n";

    for (int i = 0; i < SIZE; i++) {

        for (int j = 0; j < SIZE; j++) {

            if (j % 3 == 0)
                std::cout << "| ";

            std::cout << board[i][j] << " ";
        }

        std::cout << "|\n";

        if ((i + 1) % 3 == 0)
            std::cout << "-------------------------\n";
    }
}

// Check if number can be placed safely
bool isSafe(int board[SIZE][SIZE], int row, int col, int num) {

    // Check row
    for (int x = 0; x < SIZE; x++)
        if (board[row][x] == num)
            return false;

    // Check column
    for (int x = 0; x < SIZE; x++)
        if (board[x][col] == num)
            return false;

    // Check 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Backtracking algorithm
bool solveSudoku(int board[SIZE][SIZE]) {

    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {

            if (board[row][col] == 0) {

                for (int num = 1; num <= 9; num++) {

                    if (isSafe(board, row, col, num)) {

                        board[row][col] = num;

                        if (solveSudoku(board))
                            return true;

                        board[row][col] = 0; // Backtrack
                    }
                }

                return false; // No number fits
            }
        }
    }

    return true; // Solved
}

int main() {

    int board[SIZE][SIZE];

    std::cout << "Enter Sudoku 9x9 grid (use 0 for empty cells),(space between every number):\n";

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            std::cin >> board[i][j];

    if (solveSudoku(board))
        printBoard(board);
    else
        std::cout << "\nNo solution exists.\n";

    return 0;
}
