#pragma once
//
//  GameBoard.hpp
//

#pragma once

#include <stdexcept>

#include "ExtendableVector.h"

const int OUTSIDE_BOARD = -1;
const int BOARD_SIZE = 101;

class GameBoard {
public:
	enum Ladders { ONE = 1, FOUR = 4, NINE = 9, TWENTY_ONE = 21, TWENTY_EIGHT = 28, THIRTY_SIX = 36, FIFTY_ONE = 51, SEVENTY_ONE = 71, EIGHTY = 80 };

	enum Chutes { SIXTEEN = 16, FORTY_SEVEN = 47, FORTY_NINE = 49, FIFTY_SIX = 56, SIXTY_TWO = 62, SIXTY_FOUR = 64, EIGHTY_SEVEN = 87, NINETY_THREE = 93, NINETY_FIVE = 95, NINETY_EIGHT = 98 };

	// Build the gameboard
	void buildBoard();         //implemented in .cpp file

	GameBoard() : board(BOARD_SIZE) {
		buildBoard();
	}

	// If player lands on chutes or ladders, returns the new position.
	// Otherwise, returns the player's current position.
	// If the player's position is outside of the gameboard, throws index out of bounds exception
	int checkChutesLadders(int position) {
		if ((position < 0) || (position >= BOARD_SIZE)) {     //checks if position goes over 100 (off board)
			throw range_error("index out of bounds");
		}

		switch (position) {    
			//ladders 
		case ONE:
			return 38;
		case FOUR:
			return 14;
		case NINE:
			return 31;
		case TWENTY_ONE:
			return 42;
		case TWENTY_EIGHT:
			return 84;
		case THIRTY_SIX:
			return 44;
		case FIFTY_ONE:
			return 67;
		case SEVENTY_ONE:
			return 91;
		case EIGHTY:
			return 100;

			//chutes
		case SIXTEEN:
			return 6;
		case FORTY_SEVEN:
			return 26;
		case FORTY_NINE:
			return 11;
		case FIFTY_SIX:
			return 53;
		case SIXTY_TWO:
			return 19;
		case SIXTY_FOUR:
			return 60;
		case EIGHTY_SEVEN:
			return 24;
		case NINETY_THREE:
			return 73;
		case NINETY_FIVE:
			return 75;
		case NINETY_EIGHT:
			return 78;

		default:
			return position;
		}
	}

private:
	// Requirement: use ExtendableVector to store the square
	ExtendableVector<int> board;
	Ladders ladderstorage;
	Chutes chutestorage;
};
