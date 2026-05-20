Hybrid Sudoku Engine: Generator & Solver in C++

A robust, lightweight Command Line Interface (CLI) application written in modern C++ (C++17) that can both generate 100% valid, randomized Sudoku puzzles from scratch and solve any given Sudoku board using a hybrid algorithmic approach.

**Build via CMake**
mkdir build
cd build
cmake ..
cmake --build .

After a successful compilation, you will find two separate executables inside your build directory: sudoku and sudokuSolve.

How to Use
1. Generating a Sudoku Board

To generate a completely random and solved Sudoku board, run the generator executable:

    Linux/macOS: ./sudoku
    Windows: sudoku.exe

2. Solving a Custom Sudoku Board

To input a puzzle you want the engine to solve, run the solver executable:

    Linux/macOS: ./sudokuSolve
    Windows: sudokuSolve.exe
    
The engine will then process the puzzle and instantaneously print out the final validated ***Solution*** block on your screen.
