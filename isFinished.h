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
* <file with helper function, to check if the game has finished>
*
*/

bool isFinished (int sudoku[9][9]) {
    int checkIfReady = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] != 0) checkIfReady++;
        }
    }
    if (checkIfReady == 81) {
        cout << "Congratulations! You did it!" << endl;
        return true;
    }

    return false;
}