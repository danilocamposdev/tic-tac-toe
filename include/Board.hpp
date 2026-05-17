#ifndef BOARD_HPP
#define BOARD_HPP

#include "Player.hpp"
#include <iostream>
#include <string>

using namespace std;

class Board {
  private:
	const static int boardSize = 3;
	inline const static string boardTemplate = "   0   1   2 \n"
											   "0  % │ % │ % \n"
											   "  ───┼───┼───\n"
											   "1  % │ % │ % \n"
											   "  ───┼───┼───\n"
											   "2  % │ % │ % \n";
	char boardValues[boardSize][boardSize];

  public:
	Board() {
		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {
				boardValues[i][j] = ' ';
			}
		}
	}

	void print() {
		string boardVisual = boardTemplate;
		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {
				int pos = boardVisual.find("%");
				if (pos != string::npos) {
					string value;
					value.push_back(boardValues[i][j]);
					boardVisual.replace(pos, 1, value);
				}
			}
		}
		cout << boardVisual << endl;
	}

	int getBoardSize() { return boardSize; }

	bool setValue(Player *player, int line, int column) {
		if (line >= boardSize || column >= boardSize) {
			return false;
		}
		char *value = &boardValues[line][column];
		if (*value == ' ') {
			*value = player->getCharacter();
			return true;
		}
		return false;
	}

	char getValue(int i, int j) { return boardValues[i][j]; }

	bool isFull() {
		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {
				if (boardValues[i][j] == ' ')
					return false;
			}
		}
		return true;
	}
};

#endif
