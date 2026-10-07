#include "Player.h"
#include <iostream>


// Adds a card to the player's hand
void Player::addCard(const Card& card)
{
	if (m_hand.size() >= 5)
	{
		std::cout << "Player's hand is full!" << std::endl;
		return; // Prevent adding more than 5 cards to the hand
	}
    m_hand.push_back(card);
}

// Returns the player's hand of cards
const std::vector<Card>& Player::getHand() const
{
	return m_hand;
}

// Removes a card from the player's hand at the specified index
void Player::removeCard(int index)
{
	if (index < 0 || index >= m_hand.size())
	{
		std::cout << "Invalid index!" << std::endl;
		return; // Prevent removing a card at an invalid index
	}
	m_hand.erase(m_hand.begin() + index);
}

std::vector<Card> Player::exchangeCards(Deck& deck)
{
    int amount;

    std::cout << "\nHow many cards do you want to exchange? (0-4): ";
    std::cin >> amount;

    if (amount < 0 || amount > 4)
    {
        std::cout << "Invalid number of cards!" << std::endl;
        return {};
    }

    std::vector<int> indexes;
    std::vector<Card> exchangedCards;

    for (int i = 0; i < amount; ++i)
    {
        int index;

        std::cout << "Choose card index to exchange (0-4): ";
        std::cin >> index;

        if (index < 0 || index >= static_cast<int>(m_hand.size()))
        {
            std::cout << "Invalid index! Try again." << std::endl;
            --i;
            continue;
        }

        bool alreadySelected = false;

        for (int selectedIndex : indexes)
        {
            if (selectedIndex == index)
            {
                alreadySelected = true;
                break;
            }
        }

        if (alreadySelected)
        {
            std::cout << "You already selected this card!" << std::endl;
            --i;
            continue;
        }

        indexes.push_back(index);
        exchangedCards.push_back(m_hand[index]);
    }

    // Remove cards from highest index to lowest
    for (int i = static_cast<int>(indexes.size()) - 1; i >= 0; --i)
    {
        removeCard(indexes[i]);
    }

    // Deal replacement cards
    for (int i = 0; i < amount; ++i)
    {
        addCard(deck.dealCard());
    }

    return exchangedCards;
}