#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include <iostream>
using namespace std;

class Game {
  private:
	Board board;
	Player players[2] = {Player('X'), Player('O')};
	Player *currentPlayer = &players[0];

	char checkHorizontally() {
		for (int i = 0; i < board.getBoardSize(); i++) {
			char firstValue = board.getValue(i, 0);
			if (firstValue == ' ')
				continue;
			bool isEqual = true;
			for (int j = 1; j < board.getBoardSize(); j++) {
				if (board.getValue(i, j) != firstValue)
					isEqual = false;
			}
			if (isEqual)
				return firstValue;
		}
		return -1;
	}
	char checkVertically() {
		for (int j = 0; j < board.getBoardSize(); j++) {
			char firstValue = board.getValue(0, j);
			if (firstValue == ' ')
				continue;
			bool isEqual = true;
			for (int i = 1; i < board.getBoardSize(); i++) {
				if (board.getValue(i, j) != firstValue)
					isEqual = false;
			}
			if (isEqual)
				return firstValue;
		}
		return -1;
	}
	char checkDiagonally() {
		char firstValue = board.getValue(0, 0);
		bool isEqual = true;

		if (firstValue != ' ') {
			for (int ij = 0; ij < board.getBoardSize(); ij++) {
				if (board.getValue(ij, ij) != firstValue)
					isEqual = false;
			}

			if (isEqual)
				return firstValue;
		}

		int i = board.getBoardSize() - 1;
		int j = 0;
		firstValue = board.getValue(i, j);
		isEqual = true;

		if (firstValue == ' ')
			return -1;

		while (i >= 0 && j < board.getBoardSize()) {
			if (board.getValue(i, j) != firstValue) {
				isEqual = false;
				break;
			}
			i--;
			j++;
		}
		if (isEqual)
			return firstValue;
		return -1;
	}
	Player *checkWinner() {
		char character = -1;
		if (checkHorizontally() != -1)
			character = checkHorizontally();
		else if (checkVertically() != -1)
			character = checkVertically();
		else if (checkDiagonally() != -1)
			character = checkDiagonally();

		if (character == -1)
			return nullptr;

		for (Player &player : players) {
			if (player.getCharacter() == character)
				return &player;
		}
		return nullptr;
	}

  public:
	void start() {
		while (1) {

			cout << "--------------------- Player "
				 << currentPlayer->getCharacter()
				 << " turn --------------------" << endl
				 << endl;
			board.print();

			Player *winnerPlayer = checkWinner();
			if (checkWinner() != nullptr) {
				cout << "Player " << winnerPlayer->getCharacter() << " won!"
					 << endl;
				break;
			}

			if (board.isFull()) {
				cout << "Game Over" << endl;
				break;
			}

			int line;
			int column;
			cout << "Choose a line:" << endl;
			cout << "Player " << currentPlayer->getCharacter() << " ➝ ";
			cin >> line;
			cout << "Choose a column" << endl;
			cout << "Player " << currentPlayer->getCharacter() << " ➝ ";
			cin >> column;

			if (!board.setValue(currentPlayer, line, column)) {
				cout << endl << "Invalid Position!" << endl << endl;
				continue;
			}

			if (currentPlayer == &players[0])
				currentPlayer = &players[1];
			else
				currentPlayer = &players[0];
		}
	}
};

#endif
