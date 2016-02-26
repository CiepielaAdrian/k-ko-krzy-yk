#pragma once
class Menu
{

public:
	Menu();
	~Menu();

	void startInfo();
	static void actionChoice();
	static void MultiPlayer();
	static void SinglePlayer();
	static void ValidateCharInput(char &input);

};

