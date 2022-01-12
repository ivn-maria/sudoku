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
* <file with the main function>
*
*/

#include <iostream>
#include "chooseMatrix.h"
#include "printMatrix.h"
#include "checkNumber.h"
#include "isFinished.h"

using namespace std;

int main() {
    int level;
    cout << "Choose difficulty to play: 1 = easy, 2 = medium, 3 = hard" << endl;
    cin >> level;

    int sudoku[9][9];
    cout << "Here's your sudoku:" << endl;
    choseMatrix (level, sudoku);

    while (true) {
        printMatrix(sudoku);
        if (isFinished(sudoku))
            break;

        int row, column, number;
        cin >> row >> column >> number;

        // not changing the initial numbers
        if (sudoku[row][column] < 0) {
            cout << "This position can't be changed. Try again:" << endl;
            continue;
        }

        // erase with 0
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
    }

    return 0;
}
