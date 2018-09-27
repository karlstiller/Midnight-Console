/*
 * Game.h
 *
 *  Created on: 27 Sep. 2018
 *      Author: Karl
 */

#ifndef GAME_H_
#define GAME_H_

#include <map>
#include "Pack.h"
#include "Player.h"
#include "Trick.h"

class Game
{
public:
	Game(std::vector<Player>& players, const uint8_t& max_cards);
private:
	//std::map<std::reference_wrapper<Player>, uint16_t> tricks_won;
	std::map<Player, uint16_t> tricks_won;
	uint8_t dealer_index;
	uint8_t lead_index;
};

#endif /* SRC_GAME_H_ */
