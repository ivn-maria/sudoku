#include <iostream>
using namespace std;

bool checkSquare (int sudoku[9][9], int row, int column, int number) {

    // isNumber Check
    if (sudoku[row][column] != 0 && number != 0)
        return false;

    // Row & Column Check
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == number || sudoku[i][column] == number)
            return false;
    }

    int startRow = row - row % 3;
    int startColumn = column - column % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            if (sudoku[i + startRow][j + startColumn] == number)
                return false;
    }

    return true;
}

int main() {
    int sudoku[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
        }
    }

    cout << checkSquare(sudoku, 1, 1, 2);

    return 0;
}
