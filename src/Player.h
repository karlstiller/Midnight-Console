/*
 * Player.h
 *
 *  Created on: 29 Dec. 2017
 *      Author: Karl
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Card.h"
#include "Trick.h"
#include <vector>

class Player
{
public:
	Player(const std::string &name)
	: m_name(name)
	{ };

	~Player() {};
	void ClearCards() { m_hand.clear(); };
	void DealCard(Card &card) { m_hand.push_back(card); };
	Card PlayCard(const Trick &trick);
	std::string GetName() { return m_name; };
private:
	std::string m_name;
	std::vector<Card> m_hand;
};

#endif /* PLAYER_H_ */
