/*
 * Pack.cpp
 *
 *  Created on: 22 Dec. 2017
 *      Author: Karl
 */

#include "Pack.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>

Pack::Pack()
{
	// Add all the normal cards
	Suit suit_it(Suit::Spades);
	for (; suit_it.value <= Suit::Hearts; ++suit_it )
	{
		Sequence sequence_it(Sequence::Two);
		for (; sequence_it.value <= Sequence::A; ++sequence_it)
		{
			pack.push_back(Card(suit_it, sequence_it));
		}
	}

	// Add the Jokers
	Sequence sequence_it(Sequence::Two);
	for (; sequence_it.value <= Sequence::Five; ++sequence_it)
	{
		pack.push_back(Card(Suit::Joker, sequence_it));
	}
}

void
Pack::Shuffle()
{
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(pack.begin(), pack.end(), g);
}

Card
Pack::DealOne()
{
	Card temp = pack.front();
	pack.pop_front();
	return temp;
}

std::string
Pack::ToString() const
{
	std::string pack_string;
	for (auto card : pack)
	{
		pack_string += card.ToString() + ", ";
	}
	return pack_string;
}
