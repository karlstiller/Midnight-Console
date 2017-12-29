/*
 * Person.h
 *
 *  Created on: 29 Dec. 2017
 *      Author: Karl
 */

#ifndef PERSON_H_
#define PERSON_H_

#include "Card.h"
#include <vector>

class Person
{
public:
	Person(const std::string &name)
	: m_name(name)
	{ };

	~Person() {};
	void ClearCards() { m_hand.clear(); };
	void DealCard(Card &card) { m_hand.push_back(card); };
	Card PlayCard();
private:
	std::string m_name;
	std::vector<Card> m_hand;
};

#endif /* PERSON_H_ */
