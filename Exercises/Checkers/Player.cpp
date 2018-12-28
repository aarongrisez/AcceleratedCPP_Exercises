// Player.cpp
//

#include "Player.h"
#include "Board.h"
#include <iostream>
#include <vector>

using namespace std;

typedef vector<pair<pair<int, int> , pair<int, int> > > COORD_PAIR;

Player::Player() {
    this->token = 'T';
}

Player::Player(char token) {
    this->token = token;
}

char Player::getToken() {
    return this->token;
}

vector<pair<int, int> > Player::getNeighbors(pair<int, int> space) {
    pair<int, int> ur = make_pair(space.first + 1, space.second + 1);
    pair<int, int> ul = make_pair(space.first - 1, space.second + 1);
    pair<int, int> lr = make_pair(space.first + 1, space.second - 1);
    pair<int, int> ll = make_pair(space.first - 1, space.second - 1);
    vector<pair<int, int> > neighbors {ur, ul, lr, ll};
    return neighbors;
}

COORD_PAIR Player::getLegalMoves(Board& board) {
    vector<pair<int, int> > tokenLocs = board.getTokenLocations(*this);
    COORD_PAIR legalMoves;
    for (auto it = tokenLocs.begin(); it != tokenLocs.end(); ++it) {
        vector<pair<int, int> > neighbors = this->getNeighbors(*it); 
        for (auto jt = neighbors.begin(); jt != neighbors.end(); ++jt) {
            if (board.isSpaceFree(*jt)) {
                legalMoves.push_back(make_pair(*it, *jt));
            }
       }
    }
    return legalMoves;
}
