#pragma once
#include <iostream>
#include "Board.h"
#include "Player.h"

class Match
{
	char activePlayer;
public:
	Match(Board &board, Player &player1, Player &player2);
	~Match();
	//void move(Board &board);
	bool ifEndOfGame(Board const &board);
	bool ifWin(Board const &board);
	bool ifDraw(Board const &board);
	static int fieldNrToNumericKeybord(int fieldNumber);
	static void validateIntigerInput(int &input);
	static void validateFieldNumber(int &input, Board const &board);
};

