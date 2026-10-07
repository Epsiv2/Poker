#include "Deck.h"
#include <algorithm>
#include <random>



Deck::Deck()
{
	// Initialize the deck with 52 cards
	for (int suit = 0; suit < 4; ++suit)
	{
		for (int rank = 2; rank <= 14; ++rank)
		{
			m_cards.emplace_back(
				static_cast<Suit>(suit), 
				static_cast<Rank>(rank));
		}
	}
}

Card Deck::dealCard()
{
	// Check if the deck is empty
	Card card = m_cards.back();
	m_cards.pop_back();
	return card;
}

// Shuffles the deck using the Fisher-Yates algorithm
void Deck::shuffle()
{
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(m_cards.begin(), m_cards.end(), g);
}