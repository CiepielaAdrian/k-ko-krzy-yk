#include "Player.h"

Player::Player(char playerSymbol) : symbol(playerSymbol)
{
}

Player::~Player()
{
}

void Player::setSymbol(char symbol)
{
	this->symbol = symbol;
}


