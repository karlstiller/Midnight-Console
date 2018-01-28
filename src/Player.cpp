/*
 * Player.cpp
 *
 *  Created on: 29 Dec. 2017
 *      Author: Karl
 */

#include "Player.h"
#include <unistd.h>
#include <iostream>

Card
Player::PlayCard(const Trick &trick)
{
	std::vector<Card> base_suit_hand;
	for (auto card : m_hand)
	{
		if (card.GetSuit() == trick.GetBaseSuit())
		{
			base_suit_hand.push_back(card);
		}
	}
	Card playing_card = m_hand.back();
	m_hand.pop_back();
	sleep(1);

	std::cout << m_name << " plays a " << playing_card.ToString() << std::endl;
	return playing_card;
}


