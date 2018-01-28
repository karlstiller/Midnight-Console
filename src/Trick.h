/*
 * Trick.h
 *
 *  Created on: 30 Dec. 2017
 *      Author: Karl
 *
 *  Description: This class represents a game of midnight of one card from each
 *                player.
 */

#ifndef SRC_GAME_H_
#define SRC_GAME_H_

#include "Card.h"
#include <vector>

class Player;

class PlayedSequence
{
public:
	bool operator() (const PlayedSequence& lhs, const PlayedSequence& rhs) const
	{
		return lhs.m_sequence.GetValue() < rhs.m_sequence.GetValue();
	}
	PlayedSequence(const Sequence &_sequence, Player &_player)
	: m_sequence(_sequence)
	, m_player(_player) { }
	Sequence GetSequence() const { return m_sequence; };
	Player GetPlayer() const;
private:
	Sequence m_sequence;
	Player &m_player;
};

class Trick
{
public:
	struct PlayedCard
	{
		PlayedCard(const Card &_card, Player &_player)
		: card(_card)
		, player(_player)
		{

		};
		Card card;
		Player &player;
	};

	Trick(const Suit trump);
	~Trick() {};
	void PlayCard(const Card &card, Player &player);
	void GetWinner(Card &card, Player &winner);
	Suit GetBaseSuit() const { return m_base_suit; };
	std::string ToString() const;

private:
	Suit m_trump_suit;
	Suit m_base_suit;
	std::vector<PlayedCard> m_played_cards;
};

#endif /* SRC_GAME_H_ */
