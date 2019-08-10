#include "RPG_Dice.h"

int main()
{
	RPG_Dice RPG_Dice;

	do
	{
		RPG_Dice.ResetConsole();

		RPG_Dice.OutputRollBuffer();

		RPG_Dice.Instructions();

		RPG_Dice.GetUserInput();

	} while (RPG_Dice.DiceRoll());


	return 0;
}
