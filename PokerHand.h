#pragma once
#include <array>
#include <vector>
#include "Card.h"

enum class HandRank
{
	HighCard,
	OnePair,
	TwoPair,
	ThreeOfAKind,
	Straight,
	Flush,
	FullHouse,
	FourOfAKind,
	StraightFlush,
	RoyalFlush
};

class PokerHand
{
private:
	std::vector<Card> m_cards; // The cards in the poker hand

	std::array<int, 15> getRankCounts() const; // Returns an array containing the counts of each rank in the hand

	std::vector<int> getComparisonValues() const; // Returns a vector of values used for comparing hands of the same rank

	
public:
	PokerHand(const std::vector<Card>& cards);// Constructor that initializes the poker hand with a vector of cards

	HandRank evaluate() const; // Evaluates the poker hand and returns its rank

	std::string getHandRankName() const; // Returns the name of the hand rank as a string

	bool beats(const PokerHand& other) const; // Compares this hand with another hand and returns true if this hand beats the other hand
};



