#include <iostream>

using namespace std;

void choseMatrix (int level, int sudoku[9][9]) {
    int easy[9][9] = {
            {0, 0, 0, -2, -6, 0, -7, 0, -1},
            {-6, -8, 0, 0, -7, 0, 0, -9, 0},
            {-1, -9, 0, 0, 0, -4, -5, 0, 0},
            {-8, -2, 0, -1, 0, 0, 0, -4, 0},
            {0, 0, -4, -6, 0, -2, -9, 0, 0},
            {0, -5, 0, 0, 0, -3, 0, -2, -8},
            {0, 0, -9, -3, 0, 0, 0, -7, -4},
            {0, -4, 0, 0, -5, 0, 0, -3, -6},
            {-7, 0, -3, 0, -1, -8, 0, 0 ,0}
    };

    int medium[9][9] = {
            {0, -2, 0, -6, 0, -8, 0, 0, 0},
            {-5, -8, 0, 0, 0, -9, -7, 0, 0},
            {0, 0, 0, 0, -4, 0, 0, 0, 0},
            {-3, -7, 0, 0, 0, 0, -5, 0, 0},
            {-6, 0, 0, 0, 0, 0, 0, 0, -4},
            {0, 0, -8, 0, 0, 0, 0, -1, -3},
            {0, 0, 0, 0, -2, 0, 0, 0, 0},
            {0, 0, -9, -8, 0, 0, 0, -3, -6},
            {0, 0, 0, -3, 0, -6, 0, -9, 0}
    };

    int hard[9][9] = {
            {0, 0, 0, -6, 0, 0, -4, 0, 0},
            {-7, 0, 0, 0, 0, -3, -6, 0, 0},
            {0, 0, 0, 0, -9, -1, 0, -8, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, -5, 0, -1, -8, 0, 0, 0, -3},
            {0, 0, 0, -3, 0, -6, 0, -4, -5},
            {0, -4, 0, -2, 0, 0, 0, -6, 0},
            {-9, 0, -3, 0 ,0, 0, 0, 0, 0},
            {0, -2, 0, 0, 0, 0, -1, 0, 0}
    };

    if (level == 1) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                sudoku[i][j] = easy[i][j];
            }
        }
    }

    else if (level == 2) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                sudoku[i][j] = medium[i][j];
            }
        }
    }

    else if (level == 3) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                sudoku[i][j] = hard[i][j];
            }
        }
    }
}

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

void print(int sudoku[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if(sudoku[i][j] == 0) {
                cout << "_ ";
                continue;
            }

            if(sudoku[i][j] < 0) {
                cout << sudoku[i][j] * -1 << " ";
                continue;
            }

            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int level;
    cout << "Choose difficulty to play: 1 = easy, 2 = medium, 3 = hard" << endl;
    cin >> level;

    int sudoku[9][9];
    cout << "Here's your sudoku:" << endl;
    choseMatrix (level, sudoku);

    while (true) {
        print(sudoku);
        int row, column, number;
        cin >> row >> column >> number;

        // not changing the primitive numbers
        if (sudoku[row][column] < 0) {
            cout << "This position can't be changed. Try again:" << endl;
            continue;
        }

        //erase with 0
        if (number == 0) {
            sudoku[row][column] = 0;
            continue;
        }

        if (checkNumber(sudoku, row, column, number)) {
            sudoku[row][column] = number;
            continue;
        }

        if (!checkNumber(sudoku, row, column, number)) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        int checkIfReady = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (sudoku[i][j] != 0) checkIfReady++;
            }
        }
        if (checkIfReady == 81) {
            cout << "Congratulations! You did it!" << endl;
            return false;
        }

        break;
    }

    return 0;
}
