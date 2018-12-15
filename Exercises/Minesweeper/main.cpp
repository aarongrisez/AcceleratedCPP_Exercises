#include <iostream>
#include <vector>
#include "Board.h"
#include "BoardSpace.h"

using namespace std;

int main() {
	cout << "Welcome to Minesweeper" << endl;

	Board x;
	x.setUpBoard();
    cout << "Board Set up" << endl;
	x.displayBoard();
    int col;
    int row;

    while (!x.isGameComplete) {
        cout << "Choose row" << endl;
        cin >> row;
        cout << "Choose col" << endl;
        cin >> col;
        x.checkSpace(row, col, false);
        x.displayBoard();
    }

	return 0;
}
