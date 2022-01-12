/**
*
* Solution to course project # 6
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Maria Ivanova
* @idnumber 9MI0600045
* @compiler GCC
*
* <file with helper function, to print the changed matrix>
*
*/

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