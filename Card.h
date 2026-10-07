#pragma once

#include <string>


// Represents the suit of a playing card
enum class Suit
{
    Clubs,
    Diamonds,
    Hearts,
    Spades
};


// Represents the rank of a playing card
enum class Rank
{
    Two = 2,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};


// Represents a playing card with a suit and rank
class Card
{
private:
    Suit m_suit;
    Rank m_rank;

public:
    Card(Suit suit, Rank rank);

    Suit getSuit() const;
    Rank getRank() const;

    std::string toString() const;
};

