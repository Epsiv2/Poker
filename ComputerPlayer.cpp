#include "ComputerPlayer.h"
#include <iostream>
#include <random>


// Implements the computer player's turn in the poker game
std::vector<Card> ComputerPlayer::playTurn(Deck& deck)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> cardsDis(0, 4);
    int cardsToReplace = cardsDis(gen);

    std::vector<Card> exchangedCards;

	// Randomly select cards to replace and exchange them with new cards from the deck
    for (int i = 0; i < cardsToReplace; ++i)
    {
        std::uniform_int_distribution<> indexDistribution(
            0,
            static_cast<int>(getHand().size()) - 1
        );

        int index = indexDistribution(gen);

        exchangedCards.push_back(getHand()[index]);

        removeCard(index);
        addCard(deck.dealCard());
    }

	// Display the computer's action
    return exchangedCards;
}