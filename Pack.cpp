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
	Suit suit_it(Suit::Spades);
	for (; suit_it.value <= Suit::Hearts; ++suit_it )
	{
		Sequence sequence_it(Sequence::Two);
		for (; sequence_it.value <= Sequence::A; ++sequence_it)
		{
			pack.push_back(Card(suit_it, sequence_it));
		}
	}

	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(pack.begin(), pack.end(), g);

	std::cout << "Shuffled pack is: " << std::endl;
	for (auto card : pack)
	{
		std::cout << card.ToString() << std::endl;
	}
}

