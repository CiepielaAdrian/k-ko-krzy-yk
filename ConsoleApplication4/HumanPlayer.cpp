#include "HumanPlayer.h"
#include <iostream>

HumanPlayer::HumanPlayer(char playerSymbol) : Player(playerSymbol)
{

}


HumanPlayer::~HumanPlayer()
{
}

void HumanPlayer::makeMove(Board &board)
{
	int fieldNumber;
	std::cout << "Ruch gracza: " << Player::symbol << std::endl;
	std::cout << "Podaj numer pola: " << std::endl;
	std::cin >> fieldNumber;

	Match::validateFieldNumber(fieldNumber, board);

	board.board[fieldNumber] = symbol;
	//system("cls");
	//board.drawBoard();
}

char HumanPlayer::getSymbol()
{
	return symbol;
}


