# Minesweeper

A C++ implementation of the game Minesweeper

## Installation

This code has been tested and run with `g++` on Ubuntu 18.04.1. The following `g++` command will compile the application:

```bash
g++ Board.cpp BoardSpace.cpp main.cpp
```

Classes:
- Board
	A 2Dimensional container that has members representing each position on the board
- BoardSpace
	A single space, can have multiple states
		isMine
		isSearched
		displayChar

Setup: (runs once)
- Create Board

MainLoop:
- Display Board
- Prompt for Input
- Update Board
	1. Check if current space is mine
		If it is, game over
		If it isn't, flood fill to check nearby spaces
