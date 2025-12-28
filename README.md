# Tic-Tac-Toe (C++ / SFML)

A simple Tic-Tac-Toe game written in C++ with a graphical interface using SFML.

Player 1 is the player who moves first (bc i havent done the player selection part yet).  
The winner is currently announced in the console. whoops

## Features
- GUI-based Tic-Tac-Toe using SFML
- Turn-based gameplay
- Win detection (console output)

## Limitations / To-Do
- No player prompts (Player 1 always starts)
- No winner pop-up window -> its in the console tho!!
- No restart button 

## Dependencies
- C++17
- SFML

## Build & Run

### Compile
```bash
g++ -std=c++17 main_gui.cpp Game.cpp Board.cpp Player.cpp -o gui_game \
-I/opt/homebrew/include -L/opt/homebrew/lib \
-lsfml-graphics -lsfml-window -lsfml-system \
-Wl,-rpath,/opt/homebrew/lib
