#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <time.h>
#include <stdio.h>
#include "Board.h"
#include "BoardSpace.h"

#define DEFAULT_ROWS 15;
#define DEFAULT_COLS 19;
#define DEFAULT_MINES 40;

using namespace std;

Board::Board() {
	this->rows = DEFAULT_ROWS;
	this->cols = DEFAULT_COLS;
	this->numSpaces = this->rows * this->cols;
	this->numMines = DEFAULT_MINES;
    this->isGameComplete = false;
    BoardSpace blank = BoardSpace();
	vector<BoardSpace> spacesVec(this->rows * this->cols, blank);
	this->spaces = spacesVec;
}

Board::Board(int rows, int cols, int mines) {
	this->rows = rows;
	this->cols = cols;
	this->numMines = mines;
	this->numSpaces = this->rows * this->cols;
    this->isGameComplete = false;
	vector<BoardSpace> spacesVec;
	this->spaces = spacesVec;
}

vector<bool> Board::setMines() {
	srand(time(NULL));
	int randLoc = 0;

	vector<bool> mineLocs(this->numSpaces, false);
	for (int i = 0; i < this->numMines; i++) {
		randLoc = rand() % this->numSpaces;
        if (mineLocs[randLoc]) {
            --i;
        }
        else {
		    mineLocs[randLoc] = true;
        }
	}

    return mineLocs;
}

void Board::setUpBoard() {
	vector<bool> mines = this->setMines();
	bool isCurrentSpaceMine = false;
	
	for (int r = 0; r < this->rows; r++) {
		// Set Up Row
		for (int c = 0; c < this->cols; c++) {
			// Set Up Column
            isCurrentSpaceMine = mines[r * this->cols + c];
            if (isCurrentSpaceMine) {
			    this->spaces[r * this->cols + c].setMine();
            }
		}
	}
}

void Board::displayBoard() {
	for (int r = 0; r < this->rows; r++) {
        std::cout << " ";
		for (int c = 0; c < this->cols; c++) {
				std::cout << this->spaces[r * this->cols + c].getDisplayChar() << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
}

void Board::displayAllMines() {
    for (int i = 0; i < this->spaces.size(); i++) {
        if (this->spaces[i].checkIfMine()) {
            this->spaces[i].setDisplayChar('*');
        }
    }
}

int Board::checkSpace(int row, int col, bool safe) {
	int randNum = rand() % 100000;
    bool outOfBounds = (col > this->cols || col < 0 || row > this->rows || row < 0); 
    char thisChar = this->spaces[row * this->cols + col].getDisplayChar();
    if (this->spaces[row * this->cols + col].checkIfMine() && not safe) {
        std::cout << "Game Over" << endl;
        this->displayAllMines();
        this->isGameComplete = true;
        return 0;
    }
    else if (this->spaces[row * this->cols + col].checkIfMine() && safe) {
        return 0; 
    }
    else if (thisChar == '.') {
        return 0;
    }
    else if (outOfBounds) {
        return 0;
    }
    // Random probability that flood fill succeeds
    else if (safe && randNum < 38000) {
        return 0;
    }
    else {
        this->spaces[row * this->cols + col].setDisplayChar('.');
        // Check All Neighbors
        this->checkSpace(row, col + 1, true);
        this->checkSpace(row, col - 1, true);
        this->checkSpace(row + 1, col, true);
        this->checkSpace(row - 1, col, true);
    }
    return 0;
}
