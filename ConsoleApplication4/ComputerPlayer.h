#pragma once
#include "Player.h"
#include "HumanPlayer.h"

class ComputerPlayer : public Player
{
public:
	ComputerPlayer(char humanPlayerSymbol);
	virtual ~ComputerPlayer();
	void symbolChoice(char humanPlayerSymbol);
	virtual void makeMove(Board &board);
	virtual char getSymbol();
};

