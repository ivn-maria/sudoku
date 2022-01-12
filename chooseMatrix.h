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
* <file with helper function, to pick easy/ medium/ hard matrix, depending on the user choice>
*
*/

void choseMatrix (int level, int sudoku[9][9]) {

    // with negative numbers, so we can check if there is changing of the initial numbers
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