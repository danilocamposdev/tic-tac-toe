#include "Game.hpp"

int main() {
	char option;

	do {
		Game game;
		game.start();

		do {
			cout << "\nRestart? (y/n): ";
			cin >> option;
			option = tolower(option);
		} while (option != 'y' && option != 'n');

	} while (option == 'y');
	cout << "Thanks for playing!" << endl;
	return 0;
}
