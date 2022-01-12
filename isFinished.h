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