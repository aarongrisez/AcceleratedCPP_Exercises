// Board.cpp
//

#include <iostream>
#include <string>
#include <vector>
#include "Board.h"
#define DIM 8
typedef vector<vector<char> >::iterator ROW_IT;
typedef vector<char>::iterator COL_IT;

using namespace std;

Board::Board() {
    vector<char> emptyRow(DIM, ' ');
    vector<vector<char> > temp;
    for (int i = 0; i < DIM; i++) {
        temp.push_back(emptyRow);
    }
    this->spaces = temp;
}

void Board::setSpaces() {
    for (int r = 0; r < DIM; r++) {
        for (int c = 0; c < DIM; c++) {
            if ((r + c) % 2 == 0) {
                // Black spaces occur when x and y coords add to an even integer
                this->spaces[r][c] = '#';
            } 
            if ((r + c) % 2 == 1 && r < DIM / 4) {
                this->spaces[r][c] = 'R';
            } 
            if ((r + c) % 2 == 1 && r >  3 * DIM / 4  - 1) {
                this->spaces[r][c] = 'B';
            } 
        }
    }
}

void Board::displayBoard() {
    string horizontalLine(DIM * 4 + 1, '-');
    cout << horizontalLine << endl;
    for (int r = 0; r < DIM; ++r) {
        cout << "| ";
        for (int c = 0; c < DIM; ++c) {
            cout << this->spaces[r][c] << " | ";
        }
        cout << endl << horizontalLine << endl;
    }
}

vector<pair<int, int> > Board::getTokenLocations(Player& player) {
    char tokenChar = player.getToken();
    vector<pair<int, int> > locs;
    for (int r = 0; r < DIM; ++r) {
        for (int c = 0; c < DIM; ++c) {
            if (this->spaces[r][c] == tokenChar) {
                locs.push_back(make_pair(r, c)); 
            } 
        }
    }
    return locs;
}

bool Board::isSpaceFree(pair<int, int> coord) {
    // BOUNDS CHECK!!!
    if (coord.first >= 0 && coord.first < this->spaces.size() && coord.second >= 0 && coord.second < this->spaces[0].size()) {
        if (this->spaces[coord.first][coord.second] != ' ') {
            return false;
        }
        else {
            return true;
        }
    }
    else { return false; }
}
