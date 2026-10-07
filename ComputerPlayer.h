#pragma once
#include "Player.h"
#include "Deck.h"


class ComputerPlayer : public Player
{
public:
	std::vector<Card> playTurn(Deck& deck);
};