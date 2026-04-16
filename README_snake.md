# Snake Game (C++ Console)

A simple Snake game implemented in C++ using the Windows console. The project demonstrates basic game loop structure, real-time input handling, and simple rendering in a terminal environment.

## Features

- Classic Snake gameplay
- Real-time keyboard input (`W`, `A`, `S`, `D`)
- Score tracking
- Growing tail mechanics
- Screen refresh without flickering (cursor repositioning)
- Wrap-around movement (snake appears on the opposite side)

## Controls

| Key | Action        |
|-----|--------------|
| W   | Move up       |
| S   | Move down     |
| A   | Move left     |
| D   | Move right    |
| X   | Exit game     |

## How It Works

The game is built around a simple loop:

1. **Input** – checks for user keystrokes without pausing the program  
2. **Game Logic** – updates snake position, handles collisions and fruit collection  
3. **Rendering** – redraws the board in the console  

The snake's tail follows the head using a shifting array mechanism, where each segment takes the position of the previous one.

## Requirements

- Windows OS (uses `windows.h` and `conio.h`)
- C++ compiler (e.g. MinGW, MSVC)

## How to Compile

Using g++ (MinGW):

```bash
g++ snake.cpp -o snake