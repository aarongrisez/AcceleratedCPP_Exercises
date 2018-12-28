// Board.h
//

#ifndef BOARD_H
#define BOARD_H
#include "Player.h"
#include <vector>

using namespace std;

class Player;

class Board {

    vector<vector<char> > spaces;

    public:
        Board();
        void displayBoard();
        void setSpaces();
        vector<pair<int, int> > getTokenLocations(Player& player); // Returns vector of tuples, all locations where player has a token
        bool isSpaceFree(int row, int col);
        bool isSpaceFree(pair<int, int> coord);

};

#endif
