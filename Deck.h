#pragma once

#include <vector>
#include "Card.h"

// Represents a deck of playing cards
class Deck
{
private:
	std::vector<Card> m_cards;
public:
	Deck();

	const std::vector<Card>& getCards() const;
	void shuffle();
	Card dealCard();
};
