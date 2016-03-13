#include "ComputerPlayer.h"
#include <ctime>
#include <windows.h>

//
//a
//sda
//das
//das
//d
//asd
//asd
//

ComputerPlayer::ComputerPlayer(char humanPlayerSymbol)
{
	symbolChoice(humanPlayerSymbol);
}


ComputerPlayer::~ComputerPlayer()
{
}

void ComputerPlayer::symbolChoice(char humanPlayerSymbol)
{
	if (humanPlayerSymbol == 'x')
		symbol = 'o';
	else
		symbol = 'x';
}

void ComputerPlayer::makeMove(Board & board)
{
	Sleep(100);
	int nrOfOccupiedFields = 0;
	for (int i = 0; i < 9; i++) {
		if (board.board[i] != ' ')
			nrOfOccupiedFields++;
	}
	//check and respons for 2 our symbols in a row (to put 3rd and win)
	//horizontal check
	if (nrOfOccupiedFields >= 3) {
		for (int i = 0; i < 9; i += 3) {
			if (board.board[i] == board.board[i + 1] && board.board[i] == symbol && board.board[i + 2] == ' ') {
				board.board[i + 2] = symbol;
				return;
			}
			if (board.board[i + 1] == board.board[i + 2] && board.board[i + 1] == symbol && board.board[i] == ' ') {
				board.board[i] = symbol;
				return;
			}
			if (board.board[i] == board.board[i + 2] && board.board[i] == symbol && board.board[i + 1] == ' ') {
				board.board[i + 1] = symbol;
				return;
			}
		}
		//vertical check
		for (int i = 0; i < 3; i++) {
			if (board.board[i] == board.board[i + 3] && board.board[i] == symbol && board.board[i + 6] == ' ') {
				board.board[i + 6] = symbol;
				return;
			}

			if (board.board[i + 3] == board.board[i + 6] && board.board[i + 3] == symbol  && board.board[i] == ' ') {
				board.board[i] = symbol;
				return;
			}

			if (board.board[i] == board.board[i + 6] && board.board[i] == symbol  && board.board[i + 3] == ' ') {
				board.board[i + 3] = symbol;
				return;
			}
		}

		//diagonal check

		if (board.board[0] == board.board[4] && board.board[0] == symbol && board.board[8] == ' ') {
			board.board[8] = symbol;
			return;
		}

		if (board.board[4] == board.board[8] && board.board[4] == symbol && board.board[0] == ' ') {
			board.board[0] = symbol;
			return;
		}

		if (board.board[0] == board.board[8] && board.board[0] == symbol && board.board[4] == ' ') {
			board.board[4] = symbol;
			return;
		}

		if (board.board[2] == board.board[4] && board.board[2] == symbol && board.board[6] == ' ') {
			board.board[6] = symbol;
			return;
		}

		if (board.board[4] == board.board[6] && board.board[4] == symbol && board.board[2] == ' ') {
			board.board[2] = symbol;
			return;
		}

		if (board.board[2] == board.board[6] && board.board[2] == symbol && board.board[4] == ' ') {
			board.board[4] = symbol;
			return;
		}

	//----------------------------------------------------------------------------------------------------

		//check and respons for 2 opponent's symbols in a row (to put 3rd and block opponent)
		//horizontal check
		for (int i = 0; i < 9; i += 3) {
			if (board.board[i] == board.board[i + 1] && board.board[i] != ' ' && board.board[i + 2] == ' ') {
				board.board[i + 2] = symbol;
				return;
			}
			if (board.board[i + 1] == board.board[i + 2] && board.board[i + 1] != ' ' && board.board[i] == ' ') {
				board.board[i] = symbol;
				return;
			}
			if (board.board[i] == board.board[i + 2] && board.board[i] != ' ' && board.board[i + 1] == ' ') {
				board.board[i + 1] = symbol;
				return;
			}
		}
		//vertical check
		for (int i = 0; i < 3; i++) {
			if (board.board[i] == board.board[i + 3] && board.board[i] != ' ' && board.board[i + 6] == ' ') {
				board.board[i + 6] = symbol;
				return;
			}

			if (board.board[i + 3] == board.board[i + 6] && board.board[i + 3] != ' '  && board.board[i] == ' ') {
				board.board[i] = symbol;
				return;
			}

			if (board.board[i] == board.board[i + 6] && board.board[i] != ' '  && board.board[i + 3] == ' ') {
				board.board[i + 3] = symbol;
				return;
			}
		}

		//diagonal check

		if (board.board[0] == board.board[4] && board.board[0] != ' ' && board.board[8] == ' ') {
			board.board[8] = symbol;
			return;
		}

		if (board.board[4] == board.board[8] && board.board[4] != ' ' && board.board[0] == ' ') {
			board.board[0] = symbol;
			return;
		}

		if (board.board[0] == board.board[8] && board.board[0] != ' ' && board.board[4] == ' ') {
			board.board[4] = symbol;
			return;
		}

		if (board.board[2] == board.board[4] && board.board[2] != ' ' && board.board[6] == ' ') {
			board.board[6] = symbol;
			return;
		}

		if (board.board[4] == board.board[6] && board.board[4] != ' ' && board.board[2] == ' ') {
			board.board[2] = symbol;
			return;
		}

		if (board.board[2] == board.board[6] && board.board[2] != ' ' && board.board[4] == ' ') {
			board.board[4] = symbol;
			return;
		}
	}
	
	srand(time(NULL));

	if (nrOfOccupiedFields == 0) {
		int helpTab[5] = { 0,2,4,6,8 };
		int x = rand() % 5;
		x = helpTab[x];
		board.board[x] = symbol;
		return;
	}

	if (nrOfOccupiedFields == 1) {
		if (board.board[0] != ' ' || board.board[2] != ' ' || board.board[6] != ' ' || board.board[8] != ' ') {
			board.board[4] = symbol;
			return;
		}
		else if (board.board[4] != ' ') {
			int helpTab[4] = { 0,2,6,8 };
			int x = rand() % 4;
			x = helpTab[x];
			board.board[x] = symbol;
			return;
		}
		else {
			int x;
			do {
				x = rand() % 9;
			} while (board.board[x] != ' ');
			board.board[x] = symbol;
			return;
		}
	}

	if (nrOfOccupiedFields == 2) {
		if (board.board[4] == ' ') {		//free middle of board

			if (board.board[0] == symbol) {
				if (board.board[1] == ' ' && board.board[2] == ' ') {
					board.board[2] = symbol;
					return;
				}
				else {
					board.board[6] = symbol;
					return;
				}
			}
			if (board.board[2] == symbol) {
				if (board.board[1] == ' ' && board.board[0] == ' ') {
					board.board[0] = symbol;
					return;
				}
				else {
					board.board[8] = symbol;
					return;
				} 
			}
			if (board.board[6] == symbol) {
				if (board.board[7] == ' ' && board.board[8] == ' ') {
					board.board[8] = symbol;
					return;
				}
				else {
					board.board[0] = symbol;
					return;
				}
			}
			if (board.board[8] == symbol ) {
				if (board.board[5] == ' ' && board.board[2] == ' ') {
					board.board[2] = symbol;
					return;
				}
				else {
					board.board[6] = symbol;
					return;
				}
			}
		}
		else if (board.board[4] != symbol) {	//middle occupied by opponent
			int x;
			do {
				x = rand() % 9;
			} while (board.board[x] != ' ');
			board.board[x] = symbol;
			return;
		}
		else {									//middle occupied by us
			if (board.board[0] != ' ') {
				board.board[8] = symbol;
				return;
			}
			if (board.board[2] != ' ') {
				board.board[6] = symbol;
				return;
			}
			if (board.board[6] != ' ') {
				board.board[2] = symbol;
				return;
			}
			if (board.board[8] != ' ') {
				board.board[0] = symbol;
				return;
			}
			if (board.board[1] != ' ') {
				int helpTab[2] = { 6,8 };
				int x = rand() % 2;
				x = helpTab[x];
				board.board[x] = symbol;
				return;
			}
			if (board.board[5] != ' ') {
				int helpTab[2] = { 0,6 };
				int x = rand() % 2;
				x = helpTab[x];
				board.board[x] = symbol;
				return;
			}
			if (board.board[7] != ' ') {
				int helpTab[2] = { 0,2 };
				int x = rand() % 2;
				x = helpTab[x];
				board.board[x] = symbol;
				return;
			}
			if (board.board[3] != ' ') {
				int helpTab[2] = { 2,8 };
				int x = rand() % 2;
				x = helpTab[x];
				board.board[x] = symbol;
				return;
			}
		
		}
	}

	if (nrOfOccupiedFields == 3) {
		if (board.board[0] != ' ' && board.board[0] == board.board[8]) {
			int helpTab[4] = { 1,3,5,7 };
			int x = rand() % 4;
			x = helpTab[x];
			board.board[x] = symbol;
			return;
		}
		else if (board.board[2] != ' ' && board.board[2] == board.board[6]) {
			int helpTab[4] = { 1,3,5,7 };
			int x = rand() % 4;
			x = helpTab[x];
			board.board[x] = symbol;
			return;
		}
		else {
			int x;
			do {
				x = rand() % 9;
			} while (board.board[x] != ' ');
			board.board[x] = symbol;
			return;
		}
	}
	if (nrOfOccupiedFields == 4) {
		if (board.board[0] == board.board[4] && board.board[4] == symbol && board.board[6] == ' ') {
			board.board[6] = symbol;
			return;
		}
		if (board.board[2] == board.board[4] && board.board[4] == symbol && board.board[8] == ' ') {
			board.board[8] = symbol;
			return;
		}
		if (board.board[8] == board.board[4] && board.board[4] == symbol && board.board[2] == ' ') {
			board.board[2] = symbol;
			return;
		}
		if (board.board[6] == board.board[4] && board.board[4] == symbol && board.board[0] == ' ') {
			board.board[0] = symbol;
			return;
		}
		if (board.board[0] == symbol && board.board[2] == symbol && board.board[8] == ' ') {
			board.board[8] = symbol;
			return;
		}
		if (board.board[2] == symbol && board.board[8] == symbol && board.board[6] == ' ') {
			board.board[6] = symbol;
			return;
		}
		if (board.board[8] == symbol && board.board[6] == symbol && board.board[0] == ' ') {
			board.board[0] = symbol;
			return;
		}
		if (board.board[6] == symbol && board.board[0] == symbol && board.board[2] == ' ') {
			board.board[2] = symbol;
			return;
		}

	}
	//Rest posibility - random
	int x;
	do {
		x = rand() % 9;
	} while (board.board[x] != ' ');
	board.board[x] = symbol;
	return;
}

char ComputerPlayer::getSymbol()
{
	return symbol;
}

