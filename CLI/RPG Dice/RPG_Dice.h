#pragma once
#include "Headers_and_appINFO.h"

class RPG_Dice
{
public:
	RPG_Dice();

	void OutputRollBuffer();
	void Instructions();
	void GetUserInput();
	bool DiceRoll();
	void ResetConsole();

private:
	std::vector<std::pair<int, int>> RB; //Roll Buffer <what die had been rolled, what number was given>
	int UI; //User's Input

	void GenerateRoll(int);
};
