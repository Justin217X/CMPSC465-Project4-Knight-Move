# Traveling Knight Problem Solver

## Overview
This is a C++ program that solves the "Traveling Knight" problem on a standard 8×8 chessboard. Given two squares (e.g., "a1" and "h8"), the program determines the minimum number of knight moves required to travel from the starting square to the destination square using a breadth-first search (BFS) algorithm.

## Project Information
- **Course**: CMPSC 465 Fall 2025
- **Author**: Justin Hued (jjh6734)
- **Due Date**: October 12, 2025
- **Language**: C++ (C++17)

## Project Structure
- `proj4.cpp` - Main program implementing the knight move solver
- `input.txt` - Input file containing pairs of chess squares
- `proj4` - Compiled executable (generated, excluded from git)

## How It Works
The program:
1. Reads pairs of chess squares from `input.txt`
2. Converts chess notation (a1-h8) to coordinates
3. Uses BFS to find the shortest path between squares
4. Outputs the minimum number of knight moves required

## Running the Program
The workflow automatically compiles and runs the program:
```bash
clang++ -std=c++17 -o proj4 proj4.cpp && ./proj4
```

## Input Format
The `input.txt` file contains pairs of chess squares, one pair per line:
```
e2 e4
a1 b2
b2 c3
a1 h8
```

## Example Output
```
To get from e2 to e4 takes 2 knight moves.
To get from a1 to b2 takes 4 knight moves.
To get from b2 to c3 takes 2 knight moves.
To get from a1 to h8 takes 6 knight moves.
```

## Recent Changes
- **October 7, 2025**: Imported project to Replit
  - Set up C++ compilation environment
  - Created workflow for automatic compilation and execution
  - Added proper .gitignore for C++ artifacts
  - Program successfully tested and running

## Development Setup
- **Compiler**: Clang 14 (C++17 standard)
- **Build System**: Direct compilation via clang++
- **Output**: Console-based application
