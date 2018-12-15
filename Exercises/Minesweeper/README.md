# Minesweeper

A C++ implementation of the game Minesweeper


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
	3 inputs: board length, board width, and number of mines

MainLoop:
- Display Board
- Prompt for Input
- Update Board
	1. Check if current space is mine
		If it is, game over
		If it isn't, flood fill to check nearby spaces
