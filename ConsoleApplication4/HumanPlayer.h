#pragma once
#include "Player.h"
#include "Board.h"
#include "Match.h"

class HumanPlayer : public Player
{
public:
	HumanPlayer(char playerSymbol);
	virtual ~HumanPlayer();
	virtual void makeMove(Board &board);
	virtual char getSymbol();
};

