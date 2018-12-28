#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "BoardSpace.h"

class Board {
		public:
				Board();
				Board(int& rows, int& cols, int& mines);
				void setUpBoard();
                bool isGameComplete;
				void updateBoard(int row, int col);
				int checkSpace(int row, int col, bool safe);
				void displayBoard();
                void displayAllMines();

		private:
				char* cstring;
				Board(const char* s, std::size_t n);
				std::vector<BoardSpace> spaces;
                int countAdjacentMines(int row, int col);
				int rows;
				int cols;
				int numMines;
				int numSpaces;
                int convertCoords(int row, int col);
				std::vector<bool> setMines(); // true => isMine
};

#endif
