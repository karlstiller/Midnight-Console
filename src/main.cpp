/*
 * main.cpp
 *
 *  Created on: 29 Dec. 2017
 *      Author: Karl
 */
#include <iostream>
#include "Player.h"
#include "Game.h"

int main(int argc, char * argv[])
{
	// Create players
	Player person_1("Keith Stiller");
	Player person_2("Jan Stiller");
	Player person_3("Anna Stiller");
	Player person_4("Karl Stiller");

	std::vector<Player> players;
	// First person is first dealer
	players.push_back(person_1);
	players.push_back(person_2);
	players.push_back(person_3);
	players.push_back(person_4);

	Game game(players, 10);
}


