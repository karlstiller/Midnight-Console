/*
 * Trick.cpp
 *
 *  Created on: 30 Dec. 2017
 *      Author: Karl
 */

#include "Trick.h"
#include "Player.h"
#include <cassert>
#include <iostream>

Trick::Trick(const Suit trump)
: m_trump_suit(trump)
, m_base_suit(Suit::INVALID)
{}

void
Trick::PlayCard(const Card &card, Player &person)
{
	if (m_played_cards.empty())
	{
		if (card.GetSuit() == Suit::Joker)
		{
			m_base_suit = m_trump_suit;
		}
		else
		{
			Suit::FromInt(card.GetSuit().GetValue(), m_base_suit);
		}
	}
	m_played_cards.push_back(PlayedCard(card, person));
}

void
Trick::GetWinner(Card &card, Player &winner)
{
	// Search for Jokers...backwards!
	for (auto joker_winner = m_played_cards.crbegin(); joker_winner != m_played_cards.crend(); ++joker_winner)
	{
		if (joker_winner->card.GetSuit().GetValue() == Suit::Joker)
		{
			card = joker_winner->card;
			winner = joker_winner->player;
			return;
		}
	}

	std::vector<PlayedSequence> trump_cards;
	for (const auto &played_card : m_played_cards)
	{
		if (played_card.card.GetSuit().GetValue() == m_trump_suit.GetValue())
		{
			trump_cards.push_back(PlayedSequence(played_card.card.GetSequence(), played_card.player));
		}
	}
	if (!trump_cards.empty())
	{
		Sequence highest_card;
		for (const auto &trump : trump_cards)
		{
			if (highest_card.GetValue() < trump.GetSequence().GetValue())
			{
				highest_card = trump.GetSequence();
			}
		}

		//Find largest trump.. make sure its the last one in the vector.
		for (auto trump_winner = trump_cards.crbegin(); trump_winner != trump_cards.crend(); ++trump_winner)
		{
			if (trump_winner->GetSequence() == highest_card)
			{
				card = Card(m_trump_suit, trump_winner->GetSequence());
				winner = trump_winner->GetPlayer();
				return;
			}
		}
	}

	// No trump card played
	std::vector<PlayedSequence> base_cards;
	for (const auto &played_card : m_played_cards)
	{
		if (played_card.card.GetSuit().GetValue() == m_base_suit.GetValue())
		{
			base_cards.push_back(PlayedSequence(played_card.card.GetSequence(), played_card.player));
		}
	}
	if (!base_cards.empty())
	{
		Sequence highest_card;
		for (const auto &card : base_cards)
		{
			if (highest_card.GetValue() < card.GetSequence().GetValue())
			{
				highest_card = card.GetSequence();
			}
		}

		// Find largest card.. make sure its the last one in the vector.
		for (auto base_winner = base_cards.crbegin(); base_winner != base_cards.crend(); ++base_winner)
		{
			if (base_winner->GetSequence() == highest_card)
			{
				card = Card(m_trump_suit, base_winner->GetSequence());
				winner = base_winner->GetPlayer();
				return;
			}
		}
	}
	assert(true);
	return;
}

Player
PlayedSequence::GetPlayer() const
{
	return m_player;
};

std::string
Trick::ToString() const
{
	std::string string;
	string = "Base suit is: " + m_base_suit.ToString() + "\n";
	string += "Trump suit is: " + m_trump_suit.ToString() + "\n";
	for (auto played_card : m_played_cards)
	{
		string += played_card.player.GetName() + " played " + played_card.card.ToString() + "\n";
	}
	return string;
}
