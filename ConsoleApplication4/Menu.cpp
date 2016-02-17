#include "Menu.h"
#include "Match.h"
#include "Board.h"

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
	cout << "1.Nowa gra" << endl;
	cout << "2.Wyjscie" << endl;
	cin >> action;
	system("cls");

	if(action == 1) {
		Board board;
		Match match(board);
		while (!match.ifEndOfGame(board))
			match.move(board);
	}
}



