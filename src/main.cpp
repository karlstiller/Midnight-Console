/*
 * main.cpp
 *
 *  Created on: 29 Dec. 2017
 *      Author: Karl
 */

#include "Pack.h"
#include "Person.h"
#include <iostream>
#include <unistd.h>

int main(int argc, char * argv[])
{
	// Create players
	Person person_1("Keith Stiller");
	Person person_2("Jan Stiller");
	Person person_3("Anna Stiller");
	Person person_4("Karl Stiller");

	std::vector<Person> players;
	players.push_back(person_1);
	players.push_back(person_2);
	players.push_back(person_3);
	players.push_back(person_4);

	for (auto round = 1; round < 11; ++round)
	{
		Pack pack;
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
			std::vector<Card> round_set;
			for (auto &player : players)
			{
				round_set.push_back(player.PlayCard());
			}
			// Who won?  Who cares for now...
		}
		std::cout << "Waiting" << std::endl;
		char pause_str[100];
		scanf("%100s", pause_str);
	}
}


