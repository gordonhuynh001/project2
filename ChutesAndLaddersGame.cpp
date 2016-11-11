//
//  ChutesAndLaddersGame.cpp
//

#include <iostream>
#include <string>

#include "ChutesAndLaddersGame.hpp"
#include "GameBoard.hpp"
#include "Player.hpp"

using namespace std;

// constructor with the default value of a minimum players
ChutesAndLaddersGame::ChutesAndLaddersGame(int nPlayers) : winner("no winner"), nPlayers(nPlayers) {
	Player Gordon;
	Player Huynh;
	Gordon.setName("Gordon");
	Huynh.setName("Huynh");
	store.enqueue(Gordon);
	store.enqueue(Huynh);
}


// destructor - dequeue players from the queue
ChutesAndLaddersGame::~ChutesAndLaddersGame() {
	// TODO: implement this function properly
	if (!store.empty()) {      //dequeues players if array queue is not empty
		store.dequeue();
	}
}

// reset the game - rebuild the list of players
//        (i.e., the list should be the same as in the constructor).
//        Place all players at the figurative square zero
void ChutesAndLaddersGame::resetGame() {
	winner = "no winner";
	while (!store.empty()) {
		store.dequeue();
	};

	Player player1, player2;
	player1 = Player("Gordon");
	player2 = Player("Huynh");

	store.enqueue(player1);
	store.enqueue(player2);
}

// Play the chutes and ladders until a player reaches the winning square 100
//    - Each player takes turn to roll the die and moves to the new square by invoking rollDieAndMove.
//         If the new square is outside of the board, the player stays put
//    - Player's new position is checked against the game board's checkChutesLadders
//    - checkChutesLadders returns a different square if player lands on a chute or a ladder
//    - Player's position is then set to the new position as indicated by checkChutesLadders
//          If player lands on a chute or a ladder, player slides down or climbs up
//    - If player lands on the winning square 100, game is over
//    - playGame returns after congratulating and printing the winner's name
void ChutesAndLaddersGame::playGame() {
	while (winner == "no winner") {
		Player temp = store.front();
		temp.setPostion(temp.rollDieAndMove());
			temp.setPostion(gameBoard.checkChutesLadders(temp.getPostion()));

		if (temp.getPostion() == 100) {              //checks winner
			winner = temp.getName();
			cout << winner << " is the winner.";
		}

		else if (temp.getPostion() != 100) {         //dequeues player, next player goes
			store.dequeue();
			store.enqueue(temp);
		}
	}
}
