#include "Menu.h"
#include "Match.h"
#include "Board.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

#include <iostream>
using namespace std;

Menu::Menu()
{
	startInfo();
	actionChoice();
}


Menu::~Menu()
{
}

void Menu::startInfo()
{
	cout << "*********************************************" << endl;
	cout << "               Kolko i krzyzyk               " << endl;
	cout << "*********************************************" << endl << endl;
}


void Menu::actionChoice() {
	int action;
	cout << "1.Singleplayer" << endl;
	cout << "2.Multiplayer" << endl;
	cout << "3.Wyjscie" << endl;
	cin >> action;
	system("cls");

	if(action == 1) {
		SinglePlayer();
	}
	else if (action == 2) {
		MultiPlayer();
	}
}


void Menu::MultiPlayer() 
{
	char symbol;
	cout << "Podaj symbol pierwszego gracza (o - kolko, x - krzyzyk):" << endl;
	cin >> symbol;
	ValidateCharInput(symbol);
	system("cls");
	HumanPlayer player1(symbol);

	if (symbol == 'o')
		symbol = 'x';
	else
		symbol = 'o';

	HumanPlayer player2(symbol);
	Board board;
	Match match(board, player1, player2);
}

void Menu::SinglePlayer() 
{

}

void Menu::ValidateCharInput(char &input)
{
	while (1)
	{
		std::cin.ignore(1000, '\n');				// clear out any additional input from the stream
		if (std::cin.gcount() > 1) {				// if we cleared out more than one additional character
			std::cout << "Nieprawidlowy symbol! Wybierz symbol jeszcze raz. " << std::endl;
			cout << "Podaj symbol pierwszego gracza (o - kolko, x - krzyzyk):" << endl;
			std::cin >> input;
			continue;								// we'll consider this input to be invalid
		}

		if (input != 'o' && input != 'x') {
			std::cout << "Nieprawidlowy symbol! Wybierz symbol jeszcze raz. " << std::endl;
			cout << "Podaj symbol pierwszego gracza (o - kolko, x - krzyzyk):" << endl;
			std::cin >> input;
			continue;
		}
		break;
	}
}

