#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "ComputerPlayer.h"
#include "PokerHand.h"

using namespace std;

// Displays the player's hand of cards
void displayHand(const Player& player, const string& name)
{
	cout << "\n" << name << "'s hand: " << endl;
	for (const Card& card : player.getHand())
	{
		cout << card.toString() << endl;
	}
}

// Tests the evaluation of a poker hand and compares it to the expected result
void testHand(const vector<Card>& cards, const string& expected)
{
	PokerHand hand(cards);

	cout << "Detected: " << hand.getHandRankName() << " | Expected: " << expected << endl;
}

// Displays the player's and opponent's hands in a table format
void displayTable(
	const Player& player,
	const PokerHand& playerHand,
	const Player& opponent,
	const PokerHand& opponentHand)
{
	cout << "\n====================== POKER ======================\n\n";

	cout << left
		<< setw(35) << "PLAYER"
		<< "COMPUTER" << endl;

	cout << left
		<< setw(35) << "------"
		<< "--------" << endl;

	const auto& playerCards = player.getHand();
	const auto& opponentCards = opponent.getHand();

	for (size_t i = 0; i < 5; ++i)
	{
		string playerCard =
			to_string(i + 1) + ". " + playerCards[i].toString();

		string opponentCard =
			to_string(i + 1) + ". " + opponentCards[i].toString();

		cout << left
			<< setw(35) << playerCard
			<< opponentCard << endl;
	}

	cout << endl;

	cout << left
		<< setw(35)
		<< ("Hand Rank: " + playerHand.getHandRankName())
		<< ("Hand Rank: " + opponentHand.getHandRankName())
		<< endl;
}

// Clears the console screen
void clearScreen()
{
    system("cls");
}

// Test the Deck and Card classes
int main()
{
    char playAgain;

    do
    {
        clearScreen();
        // Create game objects
        Deck deck;
        Player player;
        ComputerPlayer opponent;

        // Shuffle the deck
        deck.shuffle();

        // Deal 5 cards to the player
        for (int i = 0; i < 5; ++i)
        {
            player.addCard(deck.dealCard());
        }

        // Deal 5 cards to the computer
        for (int i = 0; i < 5; ++i)
        {
            opponent.addCard(deck.dealCard());
        }

        // Evaluate initial hands
        PokerHand playerHand(player.getHand());
        PokerHand opponentHand(opponent.getHand());

        // Display initial table
        displayTable(player, playerHand, opponent, opponentHand);

        // Player exchanges cards
        std::vector<Card> playerExchanged = player.exchangeCards(deck);

        // Clear the screen after player's exchange
        clearScreen();

        // Computer takes its turn
        std::vector<Card> opponentExchanged = opponent.playTurn(deck);

        // Re-evaluate hands after exchange
        PokerHand newPlayerHand(player.getHand());
        PokerHand newOpponentHand(opponent.getHand());

        // Display final table
        displayTable(player, newPlayerHand, opponent, newOpponentHand);

		// Display exchanged cards
        cout << "\nPlayer exchanged "
            << playerExchanged.size()
            << " card(s):" << endl;

        for (const Card& card : playerExchanged)
        {
            cout << "- " << card.toString() << endl;
        }

        cout << "\nComputer exchanged "
            << opponentExchanged.size()
            << " card(s):" << endl;

        for (const Card& card : opponentExchanged)
        {
            cout << "- " << card.toString() << endl;
        }

        // Determine the winner
        if (newPlayerHand.beats(newOpponentHand))
        {
            cout << "\nPlayer wins!" << endl;
        }
        else if (newOpponentHand.beats(newPlayerHand))
        {
            cout << "\nOpponent wins!" << endl;
        }
        else
        {
            cout << "\nDraw!" << endl;
        }

        cout << "\nPlay again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThanks for playing!" << endl;

    return 0;
}