#pragma once

#include <vector>
#include "Card.h"
#include "Deck.h"

// Represents a player in the poker game
class Player
{
private:

    std::vector<Card> m_hand;

public:
	// Adds a card to the player's hand
    void addCard(const Card& card);
	// Returns the player's hand of cards
	const std::vector<Card>& getHand() const;
	// Removes a card from the player's hand at the specified index
	void removeCard(int index);
	// Exchanges cards in the player's hand with new cards from the deck
	std::vector<Card> exchangeCards(Deck& deck);
};