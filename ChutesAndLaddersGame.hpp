#pragma once

#include <stdio.h>
#include <string>

#include "ArrayQueue.h"
#include "Player.hpp"
#include "GameBoard.hpp"

using namespace std;

const int MIN_NUMBER_OF_PLAYERS = 2;

class ChutesAndLaddersGame {
public:
	// constructor with the default value of 2 minimum players
	ChutesAndLaddersGame(int nPlayers = MIN_NUMBER_OF_PLAYERS);

	// destructor
	~ChutesAndLaddersGame();	//all functions implemented in .cpp file

	// accessors
	long getNumberOfPlayers() {
		return nPlayers;
	}

	string getWinner() {
		return winner;
	}

	// reset the game - (1) this will reset the position of each player to zero
	void resetGame();

	// play the Chutes and Ladders game
	void playGame();


private:
	const int WINNING_POSITION = 100;

	string winner;       // the winner
	GameBoard gameBoard; // the game board
	int nPlayers;
	ArrayQueue<Player> store;
};
