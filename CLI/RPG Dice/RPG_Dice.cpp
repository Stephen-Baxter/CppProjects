#include "RPG_Dice.h"

RPG_Dice::RPG_Dice()
{
	RB.clear();
	UI = 0;

	SetConsoleTitle(L"RPG Dice");
}

void RPG_Dice::OutputRollBuffer()
{
	std::cout << "Roll buffer: ";

	if (!RB.empty())
	{
		for (size_t i = 0; i < RB.size(); i++)
		{
			std::cout << "Roll" << i + 1 << "-d" << RB.at(i).first << "-" << RB.at(i).second << "  ";
		}
	}
	else
	{
		std::cout << "No dice have been rolled.";
	}
}

void RPG_Dice::Instructions()
{
	std::cout << "\n";
	std::cout << "Please type \n";
	std::cout << "[a] for a d4 \n";
	std::cout << "[b] for a d6 \n";
	std::cout << "[c] for a d8 \n";
	std::cout << "[d] for a d10 \n";
	std::cout << "[e] for a d12 \n";
	std::cout << "[f] for a d20 \n";
	std::cout << "[g] to clear the roll buffer \n";
	std::cout << "[h] to end app \n";
}

void RPG_Dice::GetUserInput()
{
	UI = _getch();
}

bool RPG_Dice::DiceRoll()
{
	switch (UI)
	{
	case 97: //a
		GenerateRoll(4);
		break;
	case 98: //b
		GenerateRoll(6);
		break;
	case 99: //c
		GenerateRoll(8);
		break;
	case 100: //d
		GenerateRoll(10);
		break;
	case 101: //e
		GenerateRoll(12);
		break;
	case 102: //f
		GenerateRoll(20);
		break;
	case 103: //g
		RB.clear();
		std::cout << "Dice roll buffer is clear.";
		Sleep(1000);
		break;
	case 104: //h
		std::cout << "Thank you for using this app.";
		Sleep(1000);
		return false;
		break;
	default:
		std::cout << "Invalid input.";
		Sleep(800);
		break;
	}

	return true;
}

void RPG_Dice::ResetConsole()
{
	HANDLE stdOut;
	CONSOLE_SCREEN_BUFFER_INFO CSBI;
	DWORD count;

	stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (stdOut == INVALID_HANDLE_VALUE)
	{
		return;
	}

	if (!GetConsoleScreenBufferInfo(stdOut, &CSBI))
	{
		return;
	}

	if (!FillConsoleOutputCharacter(stdOut, (TCHAR)' ', CSBI.dwSize.X * CSBI.dwSize.Y, {0, 0}, &count))
	{
		return;
	}

	SetConsoleCursorPosition(stdOut, {0, 0});
}

void RPG_Dice::GenerateRoll(int a)
{
	int randNumber;

	for (int i = 0; i < 10; i++)
	{
		std::random_device generator;
		std::uniform_int_distribution<int> distribution(1, a);
		std::cout << (randNumber = distribution(generator)) << " \r";
		Sleep(100 * (i + 1));
	}

	RB.push_back(std::make_pair(a, randNumber));
}
