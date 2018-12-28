#include "Board.h"
#include <iostream>

using namespace std;

int main() {

    Board board;
    board.setSpaces();
    board.displayBoard();
    Player p1('B');
    Player p2('R');
    //board.getTokenLocations(p1);
    auto x = p1.getLegalMoves(board);
    for (int i = 0; i < x.size(); ++i) {
        cout << x[i].first.first << " " << x[i].first.second << " : ";
        cout << x[i].second.first << " " << x[i].second.second << endl;
    }

    return 0;
}
