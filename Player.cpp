//
//  Player.cpp
//

#include "Player.hpp"

//Player's assignment operator
Player& Player::operator=(const Player& p) {
	// TODO: implement this function properly
	if (this != &p) {
		die = p.die;
		position = p.position;
		playerName = p.playerName;
	}
	return *this;
}
// return player's new position after player rolls die
// If the new position is outside of the board, player stays put
// If not, player moves to the new square = player's postion + die's face value
//
int Player::rollDieAndMove() {
	die.roll();
	if ((position < 0) || (position >= BOARD_SIZE)) {		//checks if out of range on board
		throw range_error("index out of bounds");
	}

	else if ((die.getFaceValue() + position) > 100) {		//checks if position will go over board and returns original position before roll

		return position;
	}

	else {
		position += die.getFaceValue();
		return position;
	};
}
