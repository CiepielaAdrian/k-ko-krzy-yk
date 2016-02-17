#include "Board.h"
#include <iostream>
using namespace std;

Board::Board()
{
	for (int i = 0; i < 9; i++)
		board[i] = ' ';
}


Board::~Board()
{
}

void Board::drawBoard()
{
	for (int i = 0; i < 9; i+=3) {
		cout << "   |   |   " << endl;
		cout << " " << board[i] << " | " << board[i + 1] << " | " << board[i + 2] << " " << endl;
		if (i == 6) 
			cout << "   |   |   " << endl;
		else
			cout << "___|___|___" << endl;
	}

}
