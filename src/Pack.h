/*
 * Pack.h
 *
 *  Created on: 22Dec.,2017
 *      Author: Karl
 */

#ifndef PACK_H_
#define PACK_H_

#include <deque>
#include "Card.h"

class Pack
{
public:
	Pack();
	virtual ~Pack() {};
	std::string ToString() const;
	void Shuffle();
	Card DealOne();
private:
	std::deque<Card> pack;
};

#endif /* PACK_H_ */

