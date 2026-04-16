# Tic-Tac-Toe (C++ Console)

A simple Tic-Tac-Toe game written in C++ using console input/output.

## Features

- 2-player gameplay (X and O)
- Console-based board rendering
- Basic win detection (rows, columns, diagonals)

## Controls

Players choose a position by entering a number from **1 to 9**:

## How It Works

- The board is stored as a 2D array (`3x3`)
- Each move updates the board with the current player's marker
- The program checks for a winner after each move

## Current Limitations

- Game does not stop after a win
- No draw (tie) detection
- `current_player` variable is not fully implemented

## How to Compile

```bash
g++ tictactoe.cpp -o tictactoe