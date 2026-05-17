#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {
  private:
	char character;

  public:
	Player(char character) { this->character = character; }
	char getCharacter() { return character; }
};

#endif
