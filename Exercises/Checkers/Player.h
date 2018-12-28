// Player.h
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include <iostream>
#include <vector>


using namespace std;

typedef vector<pair<pair<int, int> , pair<int, int> > > COORD_PAIR;

class Board;

class Player {

    char token;
    vector<pair<int, int> > getNeighbors(pair<int, int> space);

    public:
        Player();
        Player(char token);
        char getToken();
        COORD_PAIR getLegalMoves(Board& board);
};

#endif
