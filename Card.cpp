#include "Card.h"

// Constructs a card with the given suit and rank
Card::Card(Suit suit, Rank rank) : m_suit(suit), m_rank(rank) {}


// Returns the suit of the card
Suit Card::getSuit() const
{
	return m_suit;
}

// Returns the rank of the card
Rank Card::getRank() const
{
	return m_rank;
}


// Returns a string representation of the card, e.g., "Ace of Spades"
std::string Card::toString() const
{
	std::string rankName;
	switch (m_rank)
	{
	case Rank::Two:
		rankName = "2";
		break;
	case Rank::Three:
		rankName = "3";
		break;
	case Rank::Four:
		rankName = "4";
		break;
	case Rank::Five:
		rankName = "5";
		break;
	case Rank::Six:
		rankName = "6";
		break;
	case Rank::Seven:
		rankName = "7";
		break;
	case Rank::Eight:
		rankName = "8";
		break;
	case Rank::Nine:
		rankName = "9";
		break;
	case Rank::Ten:
		rankName = "10";
		break;
	case Rank::Jack:
		rankName = "Jack";
		break;
	case Rank::Queen:
		rankName = "Queen";
		break;
	case Rank::King:
		rankName = "King";
		break;
	case Rank::Ace:
		rankName = "Ace";
		break;
	}
	std::string suitName;
	switch (m_suit)
	{
	case Suit::Clubs:
		suitName = "Clubs";
		break;
	case Suit::Diamonds:
		suitName = "Diamonds";
		break;
	case Suit::Hearts:
		suitName = "Hearts";
		break;
	case Suit::Spades:
		suitName = "Spades";
		break;
	}
	return rankName + " of " + suitName;
}