/*
 * Card.h
 *
 *  Created on: 22Dec.,2017
 *      Author: Karl
 */

#ifndef CARD_H_
#define CARD_H_

#include "Primatives.h"
#include <string>

class Card
{
public:
	Card(Suit suit, Sequence sequence);
	~Card() {};
	Suit GetSuit() { return m_suit; };
	Sequence GetSequence() { return m_sequence; };
	std::string ToString();
private:
	Suit m_suit;
	Sequence m_sequence;
};

#endif /* CARD_H_ */
