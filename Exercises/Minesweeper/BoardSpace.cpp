#include <iostream>
#include "BoardSpace.h"

using namespace std;

BoardSpace::BoardSpace() {
	this->isMine = false;
	this->isSearched = false;	
	this->displayChar = 'O';
	this->numAdjacentMines = 0;
}

BoardSpace::BoardSpace(bool isMine) {
	this->isMine = isMine;
	this->isSearched = false;
	if (isMine) {
		this->displayChar = '.';
	}
	else {
		this->displayChar = 'O';
	}
	this->numAdjacentMines = 0;
}

void BoardSpace::setMine() {
    this->isMine = true;
    //this->displayChar = '*'; // For debugging, uncomment this line
}

void BoardSpace::setNumAdjacentMines(int mines) {
	this->numAdjacentMines = mines;
}

char BoardSpace::getDisplayChar() {
    return this->displayChar;
}

void BoardSpace::setDisplayChar(char c) {
    this->displayChar = c;
}

bool BoardSpace::checkIfMine() {
    return this->isMine;
}

void BoardSpace::updateDisplayChar() {
    if (this->numAdjacentMines == 0) {
        this->setDisplayChar('.');
    }
    else {
        char newChar = this->numAdjacentMines + '0';
        this->setDisplayChar(newChar);
    }
}
