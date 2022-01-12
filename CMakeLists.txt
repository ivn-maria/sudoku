cmake_minimum_required(VERSION 3.20)
project(sudoku)

set(CMAKE_CXX_STANDARD 14)

add_executable(sudoku main.cpp chooseMatrix.h printMatrix.h checkNumber.h isFinished.h)
