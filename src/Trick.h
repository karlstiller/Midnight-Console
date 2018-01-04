/*
 * Trick.h
 *
 *  Created on: 30 Dec. 2017
 *      Author: Karl
 *
 *  Description: This class represents a game of midnight of one card from each
 *                player. The game class contains a std::set which after all
 *                players have played, the first object in the set is the
 *                winner, and the first card played defines the base suit for
 *                the game.
 */

#ifndef SRC_GAME_H_
#define SRC_GAME_H_

#include "Card.h"
#include "Player.h"

class PlayedSequence
{
public:
	struct PlayedCard
	{
		PlayedCard(const Sequence &_sequence, Player &_player)
		: sequence(_sequence)
		, player(_player)
		{

		};

		Sequence sequence;
		Player &player;
	};

	bool operator() (const PlayedSequence& lhs, const PlayedSequence& rhs) const
	{
		return lhs.m_card.sequence.GetValue() < rhs.m_card.sequence.GetValue();
	}
	PlayedSequence(const Sequence &_sequence, Player &_player)
	: m_card(_sequence, _player) { }
	Sequence GetSequence() const { return m_card.sequence; };
	Player GetPlayer() const { return m_card.player; };
private:
	 PlayedCard m_card;
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
	std::string ToString() const;

private:
	Suit m_trump_suit;
	Suit m_base_suit;
	std::vector<PlayedCard> m_played_cards;
};

#endif /* SRC_GAME_H_ */
