#include "Match.h"
#include "Board.h"
#include "Menu.h"


Match::Match(Board &board) : player('x')
{
	board.drawBoard();
}

Match::~Match()
{
}

void Match::move(Board &board)
{
	if (player == 'o')
		player = 'x';
	else
		player = 'o';

	int fieldNumber;
	
	std::cout << "Ruch gracza: " << player << std::endl;
	std::cout << "Podaj numer pola: " << std::endl;
	std::cin >> fieldNumber;

	validateFieldNumber(fieldNumber, board);

	board.board[fieldNumber] = player;
	system("cls");
	board.drawBoard();
}

bool Match::ifEndOfGame(Board const &board) {
	if (Match::ifWin(board)) {
		std::cout << "Wygrywa gracz: " << player << std::endl << std::endl;
		Menu::actionChoice();
		return true;
	}
	else if (Match::ifDraw(board)) {
		std::cout << "Remis!" << std::endl << std::endl;
		Menu::actionChoice();
		return true;
	}
	else
		return false;
}

bool Match::ifWin(Board const &board)
{
	if ((board.board[0] == board.board[1] && board.board[1] == board.board[2] && board.board[0] != ' ') || 
		(board.board[3] == board.board[4] && board.board[4] == board.board[5] && board.board[3] != ' ') ||
		(board.board[6] == board.board[7] && board.board[7] == board.board[8] && board.board[6] != ' ') ||
		(board.board[0] == board.board[3] && board.board[3] == board.board[6] && board.board[0] != ' ') ||
		(board.board[1] == board.board[4] && board.board[4] == board.board[7] && board.board[1] != ' ') ||
		(board.board[2] == board.board[5] && board.board[5] == board.board[8] && board.board[2] != ' ') ||
		(board.board[0] == board.board[4] && board.board[4] == board.board[8] && board.board[0] != ' ') ||
		(board.board[2] == board.board[4] && board.board[4] == board.board[6] && board.board[2] != ' '))
		return true;
	else
		return false;
}


bool Match::ifDraw(Board const &board)
{
	if (board.board[0] != ' ' && board.board[1] != ' ' && board.board[2] != ' ' &&
		board.board[3] != ' ' && board.board[4] != ' ' && board.board[5] != ' ' &&
		board.board[6] != ' ' && board.board[7] != ' ' && board.board[8] != ' ')
		return true;
	else
		return false;
}

int Match::fieldNrToNumericKeybord(int fieldNumber)
{
	switch (fieldNumber) {
	case 7:
		fieldNumber = 0;
		break;
	case 8:
		fieldNumber = 1;
		break;
	case 9:
		fieldNumber = 2;
		break;
	case 4:
		fieldNumber = 3;
		break;
	case 5:
		fieldNumber = 4;
		break;
	case 6:
		fieldNumber = 5;
		break;
	case 1:
		fieldNumber = 6;
		break;
	case 2:
		fieldNumber = 7;
		break;
	case 3:
		fieldNumber = 8;
		break;
	}
	return fieldNumber;
}

void Match::validateIntigerInput(int &input)
{
	while (1)
	{
		if (std::cin.fail())							// no extraction took place
			{
				std::cin.clear();						// reset the state bits back to goodbit so we can use ignore()
				std::cin.ignore(1000, '\n');			// clear out the bad input from the stream
				std::cout << "Nieprawidlowe pole! Wybierz pole jeszcze raz: " << std::endl;
				std::cin >> input;
				continue;								// try again
			}

			std::cin.ignore(1000, '\n');				// clear out any additional input from the stream
			if (std::cin.gcount() > 1)					// if we cleared out more than one additional character
				continue;								// we'll consider this input to be invalid

			break;
	}
}

void Match::validateFieldNumber(int &input, Board &board)
{
	validateIntigerInput(input);

	int numericKey = fieldNrToNumericKeybord(input);

	while (board.board[numericKey] != ' ') {
		if (numericKey < 1 || numericKey > 9)
			std::cout << "Nieprawidlowe pole! Wybierz pole jeszcze raz: " << std::endl;
		else
			std::cout << "To pole jest zajete! Wybierz pole jeszcze raz: " << std::endl;

		std::cin >> input;
		validateIntigerInput(input);
		numericKey = fieldNrToNumericKeybord(input);
	}
	input = numericKey;
}
