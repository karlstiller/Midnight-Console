/*
 * main.cpp
 *
 *  Created on: 29 Dec. 2017
 *      Author: Karl
 */

#include "Pack.h"
#include "Player.h"
#include "Trick.h"
#include <iostream>
//#include <unistd.h>

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

	std::cout << "Starting game!" << std::endl;
	for (auto round = 1; round < 11; ++round)
	{
		Pack pack(2);
		pack.Shuffle();

		for (auto deal_count = 0; deal_count < round; ++deal_count)
		{
			for (auto &player : players)
			{
				Card card = pack.DealOne();
				player.DealCard(card);
			}
		}

		Card trump_card = pack.DealOne();
		std::cout << "Trump Card is " << trump_card.ToString() << std::endl;

		// Players now need to play their cards
		for (auto play_count = 0; play_count < round; ++play_count)
		{
			Trick trick(trump_card.GetSuit());
			// TODO This loop needs to start with the previous winner or player following the dealer on first round
			for (auto &player : players)
			{
				trick.PlayCard(player.PlayCard(trick), player);
			}

			std::cout << trick.ToString() <<std::endl;

			Card card(Suit::INVALID, Sequence::INVALID);
			Player winner("INVALID");
			trick.GetWinner(card, winner);
			std::cout << "Winner is: " << winner.GetName() << " " << card.ToString() << std::endl;
		}
		std::cout << "Waiting" << std::endl;
		char pause_str[100];
		scanf("%100s", pause_str);
	}
}


