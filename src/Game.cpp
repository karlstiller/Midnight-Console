/*
 * Game.cpp
 *
 *  Created on: 27 Sep. 2018
 *      Author: Karl
 */

#include <iostream>
#include <functional>
#include "Game.h"

Game::Game(std::vector<Player>& players, const uint8_t& max_cards)
{
	for (const auto& player : players)
	{
		tricks_won.insert(std::make_pair(player, 0));
	}

	std::cout << "Starting midnight game to a maximum of " << static_cast<int>(max_cards) << " cards" << std::endl;
	for (auto round = 1; round <= max_cards; ++round)
	{
		Pack pack(2);
		pack.Shuffle();
		std::cout << "Shuffling..." << std::endl;

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
			tricks_won[winner]++;
		}
		std::cout << "Waiting" << std::endl;
		char pause_str[100];
		for (auto& player : tricks_won)
		{
			std::cout << player.first.GetName() << " won " << static_cast<int>(player.second) <<" tricks" << std::endl;
			player.second = 0;
		}

		scanf("%100s", pause_str);
	}
}


