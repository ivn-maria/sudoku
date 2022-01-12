using namespace std;

void printMatrix (int sudoku[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] == 0) {
                cout << "_ ";
                continue;
            }

            if (sudoku[i][j] < 0) {
                cout << sudoku[i][j] * -1 << " ";
                continue;
            }

            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}