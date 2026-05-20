# Hybrid Sudoku Engine: Generator & Solver in C++

A robust, lightweight Command Line Interface (CLI) application written in modern C++  that can both **generate 100% valid, randomized Sudoku puzzles** from scratch and **solve any given Sudoku board** using a hybrid algorithmic approach.

---

## 🚀 Features

* **100% Valid Puzzle Generation:** Automatically creates complete, completely randomized, and mathematically flawless Sudoku boards every single time.
* **Dual Input Methods for Solving:**
  1. **Sequential Mode:** Fill the entire board cell-by-cell dynamically.
  2. **Index-Based Mode (Recommended):** Enter numbers directly by targeting specific row and column indices (`1-9`), making it incredibly easy to clone a real-world puzzle into the engine.
* **Cross-Platform UI Visuals:** Uses ANSI escape codes (`\033[2J`) to clear the terminal screen cleanly for a smooth visual experience during user input and result displaying.
* **CMake Build System:** Organized cleanly with standard `CMakeLists.txt` producing two separate executable targets.

---

## 🧠 The Algorithm Behind the Engine

Unlike traditional, rigid deterministic solvers, this project implements a **Randomized Brute-Force with Backtracking & Local Row-Reset** approach:

* **Generation (`main.cpp`):** Fills cells sequentially with valid random numbers (`1-9`). If it hits a dead-end where a cell cannot legally accept any number (due to row, column, or 3x3 block conflicts) after 150 attempts, it safely resets the entire board state and restarts. This guarantees a uniquely shuffled board layout on every run.
* **Solving (`solveAlgorithm.cpp`):** Employs a similar heuristic. It populates empty cells (`0`) with valid random guesses. If a cell reaches a dead-end (exceeding 250 attempts), the algorithm backtracks by wiping the current row and stepping back to the previous row. If local backtracking cycles too many times (`MAX_ROW_RESETS = 5000`), it triggers a global reset (`goto restart_puzzle`) to break out of complex algorithmic traps.

---

## 🛠️ Compilation and Installation

This project uses **CMake** for easy building. Ensure you have a C++17 compatible compiler (like GCC or Clang) and CMake installed.

### 1. Clone the Repository

```bash
git clone (https://github.com/Wexis39/SudokuAlgorithm.git)
cd SudokuAlgorithm
```

2. Build via CMake

Create a build directory, generate the build files, and compile the executables:
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

After a successful compilation, you will find two separate executables inside your build directory: sudoku and sudokuSolve.

🎮 How to Use

🎲 1. Generating a Sudoku Board

To generate a completely random and solved Sudoku board, run the generator executable:

    Linux/macOS: ./sudoku

    Windows: sudoku.exe

🔍 2. Solving a Custom Sudoku Board

To input a puzzle you want the engine to solve, run the solver executable:

    Linux/macOS: ./sudokuSolve

    Windows: sudokuSolve.exe

📋 How to Input Data in Solver Mode

Upon running, you'll be greeted with a menu:

    Option 1 (Sequential): The program asks for numbers for every single cell starting from (0,0) to (8,8). Enter 0 for blank/unknown cells. Type -1 anytime to stop early.

    Option 2 (Index-Based - Recommended): Type the Row (1-9), Column (1-9), and the Number. The board will update live on the screen. Once you have populated your starting hints, type -1 during the coordinate entry phase to start the solving engine.

The engine will then process the puzzle and instantaneously print out the final validated ***Solution*** block on your screen.


## Author

- [@Metehan Atalay](https://www.linkedin.com/in/metehan-atalay-bb2b76300/)
