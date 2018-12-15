#ifndef BOARDSPACE_H
#define BOARDSPACE_H

class BoardSpace {

		private:
				bool isMine;
				bool isSearched;
				char displayChar;
				int numAdjacentMines;
		public:
				BoardSpace();
				BoardSpace(bool isMine);
                void setMine();
				void setNumAdjacentMines(int mines);
                char getDisplayChar();
                void setDisplayChar(char c);
                bool checkIfMine();

};

#endif
