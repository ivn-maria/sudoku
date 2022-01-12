bool checkNumber (int sudoku[9][9], int row, int column, int number) {

    // Row Check
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == number || sudoku[row][i] == number * (-1)) {
            return false;
        }
    }

    // Column Check
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][column] == number || sudoku[i][column] == number * (-1)) {
            return false;
        }
    }

    // Small Square check
    int startRow = row - row % 3;
    int startColumn = column - column % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[i + startRow][j + startColumn] == number)
                return false;
            if (sudoku[i + startRow][j + startColumn] == number * (-1))
                return false;
        }
    }

    return true;
}
