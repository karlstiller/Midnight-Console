/*
 * Person.cpp
 *
 *  Created on: 29 Dec. 2017
 *      Author: Karl
 */

#include "Person.h"
#include <unistd.h>
#include <iostream>

Card
Person::PlayCard()
{
	Card playing_card = m_hand.back();
	m_hand.pop_back();
	sleep(1);

	std::cout << m_name << " plays a " << playing_card.ToString() << std::endl;
	return playing_card;
}


