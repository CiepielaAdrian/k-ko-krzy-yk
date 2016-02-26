#pragma once
#include "Board.h"
class Player
{
protected:
	char symbol;
public:
	Player(char playerSymbol = 'o');
	virtual ~Player();
	virtual void makeMove(Board &board) = 0;
	void setSymbol(char symbol);
	virtual char getSymbol() = 0;
};

