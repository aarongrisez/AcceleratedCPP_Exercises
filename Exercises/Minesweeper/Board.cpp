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

Board::Board(int& rows, int& cols, int& mines) {
	this->rows = rows;
	this->cols = cols;
	this->numSpaces = this->rows * this->cols;
	this->numMines = mines;
    this->isGameComplete = false;
    BoardSpace blank = BoardSpace();
	vector<BoardSpace> spacesVec(this->rows * this->cols, blank);
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
    int coord;
	
	for (int r = 0; r < this->rows; r++) {
		// Set Up Row
		for (int c = 0; c < this->cols; c++) {
			// Set Up Column
            coord = this->convertCoords(r, c);
            isCurrentSpaceMine = mines[coord];
            if (isCurrentSpaceMine) {
			    this->spaces[coord].setMine();
            }
		}
	}
    char displayChar;
    for (int r = 0; r < this->rows; r++) {
        for (int c = 0; c < this->cols; c++) {
            coord = this->convertCoords(r, c);
            displayChar = (char)this->countAdjacentMines(r,c);
            this->spaces[coord].setDisplayChar(displayChar);
        }
    }
}

void Board::displayBoard() {
    int coord;
	for (int r = 0; r < this->rows; r++) {
        std::cout << " ";
		for (int c = 0; c < this->cols; c++) {
                coord = this->convertCoords(r, c);
				std::cout << this->spaces[coord].getDisplayChar() << " ";
		}
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
    // Converted Coord
    // Takes Pair and converts from tuple to row major
    // If -1, out of bounds
    int coord = this->convertCoords(row, col);

    // Access space
    if (coord == -1) {
        cout << "Oops! You selected a spot that is out of bounds; please try again." << endl;
        return 0;
    }
    else {

        char thisChar = this->spaces[coord].getDisplayChar();

        // Check space
        if (this->spaces[coord].checkIfMine() && not safe) {
            std::cout << "Game Over" << endl;
            this->displayAllMines();
            this->isGameComplete = true;
            return 0;
        }
        else if (this->spaces[coord].checkIfMine() && safe) {
            return 1; 
        }
        else if (not this->spaces[coord].checkIfMine() && safe) {
            return 0;
        }
        else if (thisChar != 'O') {
            return 0;
        }
        // Random probability that flood fill fails
        else if (safe && randNum < 40000) {
            this->spaces[coord].updateDisplayChar();
            return 0;
        }
        else {
            this->spaces[coord].updateDisplayChar();
            // Check All Neighbors
            this->checkSpace(row, col + 1, true);
            this->checkSpace(row, col - 1, true);
            this->checkSpace(row + 1, col, true);
            this->checkSpace(row - 1, col, true);
        }
        return 0;

    }
}

int Board::countAdjacentMines(int row, int col) {
    int count = 0;
    int coord = this->convertCoords(row, col);
    if (coord != -1) {
        count += this->checkSpace(row, col + 1, true);
        count += this->checkSpace(row + 1, col + 1, true);
        count += this->checkSpace(row, col - 1, true);
        count += this->checkSpace(row + 1, col - 1, true);
        count += this->checkSpace(row + 1, col, true);
        count += this->checkSpace(row + 1, col + 1, true);
        count += this->checkSpace(row - 1, col, true);
        count += this->checkSpace(row - 1, col + 1, true);
    }
    return count;
}

int Board::convertCoords(int row, int col) {
    bool outOfBounds = (col > this->cols || col < 0 || row > this->rows || row < 0); 
    if (not outOfBounds) {
        return row * this->cols + col;
    }
    else {
        return -1;
    }
}
