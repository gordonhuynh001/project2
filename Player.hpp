#pragma once
#include <stdio.h>
#include <string>

#include "Die.hpp"
#include "GameBoard.hpp"

using namespace std;

class Player {
public:
	// default constructor with no name
	Player() : playerName("no name"), position(0), die() {}

	// parametrized constructor with name
	// player's initial position is at the figurative square 0
	Player(string name) : playerName(name), position(0), die() {}

	// copy constructor
	// Player should make player's own copy of the die
	Player(const Player &p) : playerName(p.playerName), position(p.position) {}

	// assignment constructor
	// Player should make player's own copy of the die
	Player& Player::operator=(const Player& p);

	// destructor
	~Player() { }

	// getters and setters
	void setName(string name) { playerName = name; }
	void setPostion(int location) { position = location; }
	string getName() const { return playerName; }
	int getPostion() const { return position; }
	Die getDie() { return die; }

	// return player's new position after player rolls die
	// If the new position is outside of the board, player stays put
	// If not, player moves to the new square = player's postion + die's face value
	
	int rollDieAndMove();   // implemented in .cpp file

private:
	string playerName;
	int position;
	Die die;
};
