//
//  GameBoard.cpp
//

#include "GameBoard.hpp"

// Build the gameboard
// If the landing square is a chute, set the position to the corresponding lower square
// I.e., player slides down to the lower square
// If the landing square is a ladder, set the position to the corresponding higher square
// Player climbs up to the higher square
// Otherwise, player stays put at the landing square
void GameBoard::buildBoard() {
	for (int i = 0; i < 100; i++) {     //uses a for loop to create 100 spots
		board.insert(i, i + 1);
	}
}
