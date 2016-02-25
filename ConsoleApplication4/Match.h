#pragma once
#include <iostream>
#include "Board.h"

class Match
{
	char player;
public:
	Match(Board &board);
	~Match();
	void move(Board &board);
	bool ifEndOfGame(Board const &board);
	bool ifWin(Board const &board);
	bool ifDraw(Board const &board);
	int fieldNrToNumericKeybord(int fieldNumber);
	void validateIntigerInput(int &input);
	void validateFieldNumber(int &input, Board const &board);
};

