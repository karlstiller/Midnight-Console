/*
 * Card.cpp
 *
 *  Created on: 22Dec.,2017
 *      Author: Karl
 */

#include "Card.h"

Card::Card(Suit suit, Sequence sequence)
	: m_suit(suit)
	, m_sequence(sequence)
{
}

std::string
Card::ToString()
{
	std::string string;
	if (m_suit.value == Suit::Value::Joker)
	{
		string = m_suit.ToString() + "\n";
	}
	else
	{
		string = m_sequence.ToString() + " " + m_suit.ToString() + "\n";
	}
	return string;
}
