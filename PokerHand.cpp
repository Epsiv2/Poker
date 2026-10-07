#include "PokerHand.h"
#include <iostream>
#include <array>

// Constructor that initializes the poker hand with a vector of cards
PokerHand::PokerHand(const std::vector<Card>& cards)
    : m_cards(cards)
{
}

// Returns an array containing the counts of each rank in the hand
std::array<int, 15> PokerHand::getRankCounts() const
{
	std::array<int, 15> rankCount{};
	for (const Card& card : m_cards)
	{
		int rank = static_cast<int>(card.getRank());
		rankCount[rank]++;
	}
	return rankCount;
}

// Evaluates the poker hand and returns its rank
HandRank PokerHand::evaluate() const
{
    if (m_cards.size() != 5)
    {
		return HandRank::HighCard;
    }

	std::array<int, 15> rankCount = getRankCounts();

	// Check for flush
    bool isFlush = true;

    for (const Card& card : m_cards)
    {
        if (card.getSuit() != m_cards[0].getSuit())
        {
            isFlush = false;
            break;
        }
    }

	// Check for straight
    bool straight = false;

    for (int rank = 2; rank <= 10; ++rank)
    {
        if (rankCount[rank] > 0 &&
            rankCount[rank + 1] > 0 &&
            rankCount[rank + 2] > 0 &&
            rankCount[rank + 3] > 0 &&
            rankCount[rank + 4] > 0)
        {
            straight = true;
            break;
        }
    }

	// Check for Ace-low straight (A-2-3-4-5)
    if (rankCount[14] &&
        rankCount[2] > 0 &&
        rankCount[3] > 0 &&
        rankCount[4] > 0 &&
        rankCount[5] > 0)
    {
        straight = true;
    }

	// Check for pairs, three of a kind, and four of a kind
	bool fourOfAKind = false;
	bool threeOfAKind = false;
	int pairs = 0;

	// Count the occurrences of each rank
	for (int count : rankCount)
	{
		if (count == 4)
		{
			fourOfAKind = true;
		}
		else if (count == 3)
		{
			threeOfAKind = true;
		}
		else if (count == 2)
		{
			pairs++;
		}
	}

	// Determine the hand rank based on the checks above
	if (isFlush && rankCount[10] && rankCount[11] && rankCount[12] && rankCount[13] && rankCount[14])
	{
		return HandRank::RoyalFlush;
	}
	else if (isFlush && straight)
	{
		return HandRank::StraightFlush;
	}
	else if (fourOfAKind)
	{
		return HandRank::FourOfAKind;
	}
	else if (threeOfAKind && pairs == 1)
	{
		return HandRank::FullHouse;
	}
	else if (isFlush)
	{
		return HandRank::Flush;
	}
	else if (straight)
	{
		return HandRank::Straight;
	}
	else if (threeOfAKind)
	{
		return HandRank::ThreeOfAKind;
	}
	else if (pairs == 2)
	{
		return HandRank::TwoPair;
	}
	else if (pairs == 1)
	{
		return HandRank::OnePair;
	}

	return HandRank::HighCard;

}

// Returns the name of the hand rank as a string
std::string PokerHand::getHandRankName() const
{
	switch (evaluate())
	{
	case HandRank::HighCard:
		return "High Card";
	case HandRank::OnePair:
		return "One Pair";
	case HandRank::TwoPair:
		return "Two Pair";
	case HandRank::ThreeOfAKind:
		return "Three of a Kind";
	case HandRank::FourOfAKind:
		return "Four of a Kind";
	case HandRank::Flush:
		return "Flush";
	case HandRank::Straight:
		return "Straight";
	case HandRank::FullHouse:
		return "Full House";
	case HandRank::RoyalFlush:
		return "Royal Flush";
	case HandRank::StraightFlush:
		return "Straight Flush";

	}
	return "Unknown";
}

std::vector<int> PokerHand::getComparisonValues() const
{
    std::array<int, 15> rankCount = getRankCounts();
    HandRank handRank = evaluate();

    std::vector<int> values;

    // Straight / Straight Flush
    if (handRank == HandRank::Straight ||
        handRank == HandRank::StraightFlush)
    {
        for (int high = 14; high >= 6; --high)
        {
            if (rankCount[high] > 0 &&
                rankCount[high - 1] > 0 &&
                rankCount[high - 2] > 0 &&
                rankCount[high - 3] > 0 &&
                rankCount[high - 4] > 0)
            {
                values.push_back(high);
                return values;
            }
        }

        // Ace-low straight: A-2-3-4-5
        if (rankCount[14] > 0 &&
            rankCount[2] > 0 &&
            rankCount[3] > 0 &&
            rankCount[4] > 0 &&
            rankCount[5] > 0)
        {
            values.push_back(5);
        }
    }
    // Four of a Kind
    if (handRank == HandRank::FourOfAKind)
    {
        for (int rank = 14; rank >= 2; --rank)
        {
            if (rankCount[rank] == 4)
            {
                values.push_back(rank);
                break;
            }
        }

        for (int rank = 14; rank >= 2; --rank)
        {
            if (rankCount[rank] == 1)
            {
                values.push_back(rank);
                break;
            }
        }
    }

    // Full House
    else if (handRank == HandRank::FullHouse)
    {
        for (int rank = 14; rank >= 2; --rank)
        {
            if (rankCount[rank] == 3)
            {
                values.push_back(rank);
                break;
            }
        }

        for (int rank = 14; rank >= 2; --rank)
        {
            if (rankCount[rank] == 2)
            {
                values.push_back(rank);
                break;
            }
        }
    }

    // Three of a Kind
    else if (handRank == HandRank::ThreeOfAKind)
    {
        for (int rank = 14; rank >= 2; --rank)
        {
            if (rankCount[rank] == 3)
            {
                values.push_back(rank);
                break;
            }
        }

        for (int rank = 14; rank >= 2; --rank)
        {
            if (rankCount[rank] == 1)
            {
                values.push_back(rank);
            }
        }
    }

    // Two Pair
    else if (handRank == HandRank::TwoPair)
    {
        for (int rank = 14; rank >= 2; --rank)
        {
            if (rankCount[rank] == 2)
            {
                values.push_back(rank);
            }
        }

        for (int rank = 14; rank >= 2; --rank)
        {
            if (rankCount[rank] == 1)
            {
                values.push_back(rank);
            }
        }
    }

    // One Pair
    else if (handRank == HandRank::OnePair)
    {
        for (int rank = 14; rank >= 2; --rank)
        {
            if (rankCount[rank] == 2)
            {
                values.push_back(rank);
            }
        }

        for (int rank = 14; rank >= 2; --rank)
        {
            if (rankCount[rank] == 1)
            {
                values.push_back(rank);
            }
        }
    }

    // High Card / Flush
    else
    {
        for (int rank = 14; rank >= 2; --rank)
        {
            for (int count = 0; count < rankCount[rank]; ++count)
            {
                values.push_back(rank);
            }
        }
    }

    return values;
}

// Compares this hand with another hand and returns true if this hand beats the other hand
bool PokerHand::beats(const PokerHand& other) const
{
    if (evaluate() != other.evaluate())
    {
        return evaluate() > other.evaluate();
    }

    return getComparisonValues() > other.getComparisonValues();
}