#include "SharedFuncitons.h"
#include <iostream>


int SharedFuncitons::ReadInputInteger()
{
	bool okInput = true;
	int inputNr = 0;

	while (okInput)
	{
		std::cin >> inputNr;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Type an INTEGER!" << std::endl;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			okInput = false;
		}
	}
	return inputNr;
}
char SharedFuncitons::ReadInputChar()
{
	bool okInput = true;
	char inputChar = 'e';

	while (okInput)
	{
		std::cin >> inputChar;

		if (inputChar == 'y' || inputChar == 'n')
		{
			okInput = false;
		}
		else
		{
			std::cout << "your input is worng! .. y/n ?" << std::endl;
		}
	}
	return inputChar;
}
int SharedFuncitons::AskAmountMoney(int aWalletMoney)
{
	std::cout << "How much money you want to play with? .. You Have: " << aWalletMoney << " $" << std::endl;
	int inputNr = 0;
	bool wrongInput = true;
	while (wrongInput)
	{
		std::cout << "Your Input: ";
		inputNr = ReadInputInteger();
		if (inputNr > aWalletMoney)
		{
			std::cout << "chose other amount you don't have enough money" << std::endl;
		}
		else if (inputNr < 0)
		{
			std::cout << "NOT VALID! chose other amount" << std::endl;
		}
		else if (inputNr > 0 && inputNr <= aWalletMoney)
		{
			wrongInput = false;
		}
		if (inputNr == aWalletMoney)
		{
			std::cout << "Warrning you now have used all your money" << std::endl;
		}
	}

	return inputNr;
}
void SharedFuncitons::ShowMoneyLeft(int aWalletMoney)
{

	std::cout << "====================" << std::endl;
	std::cout << "Money left: " << aWalletMoney << std::endl;
	std::cout << "====================" << std::endl;
}
void SharedFuncitons::MoneyMath(int& aWalletMoney, int someAmountOfMoney)
{
	aWalletMoney += someAmountOfMoney;
	ShowMoneyLeft(aWalletMoney);
}
void SharedFuncitons::StoreWinOrLose(bool isWin, int* aHistoryOfWinOrLose)
{
	bool ok = true;
	while (ok)
	{
		if (isWin)
		{
			for (int i = 0; i < globalArraySize; i++)
			{
				if (CheckIfEmptyAt(aHistoryOfWinOrLose[i]))
				{
					aHistoryOfWinOrLose[i] = static_cast<int>(Instruction::Win);
					return;
				}
			}
		}
		else
		{
			for (int i = 0; i < globalArraySize; i++)
			{
				if (CheckIfEmptyAt(aHistoryOfWinOrLose[i]))
				{
					aHistoryOfWinOrLose[i] = static_cast<int>(Instruction::Lose);
					return;
				}
			}
		}
		int temp = 0;
		for (int i = globalArraySize - 1; i > 0; i--)
		{
			temp = aHistoryOfWinOrLose[i - 1];
			aHistoryOfWinOrLose[i - 1] = aHistoryOfWinOrLose[i];
			aHistoryOfWinOrLose[i] = temp;
		}
		aHistoryOfWinOrLose[0] = static_cast<int>(Instruction::Empty);
	}
}
bool SharedFuncitons::CheckIfReachMaxWinMoney(const int aMaxWinMoney)
{
	int const MaxMoney = 5000;
	bool isReached = aMaxWinMoney >= MaxMoney;
	return isReached;
}
void SharedFuncitons::SubtractFromWinMoney(int& aWinMoney, const int& anAmountToSubtract)
{
	if (aWinMoney > anAmountToSubtract)
	{
		aWinMoney -= anAmountToSubtract;
	}
	else
	{
		aWinMoney = 0;
	}
}
void SharedFuncitons::ShowAmountOfWin(const int& aWinMoney)
{
	std::cout << "=====================================" << std::endl;
	std::cout << "amount of win " << aWinMoney << "$" << std::endl;
	std::cout << "=====================================" << std::endl;
}
void SharedFuncitons::DisplayWinLose(const int* aHistoryOfWinOrLose)
{
	for (int i = 0; i < globalArraySize; i++)
	{
		if (aHistoryOfWinOrLose[i] == static_cast<int>(Instruction::Win))
		{
			std::cout << i + 1 << ": win ";
		}
		else if (aHistoryOfWinOrLose[i] == static_cast<int>(Instruction::Lose))
		{
			std::cout << i + 1 << ": lose ";
		}
		else
		{
			std::cout << i + 1 << ": empty ";
		}
		std::cout << "|| ";

	}
	std::cout << std::endl;
}
void SharedFuncitons::DisplayYouCantPlay()
{
	std::cout << "=====================================" << std::endl;
	std::cout << "You Can't play this game any more" << std::endl;
	system("pause");
}
void SharedFuncitons::GamesRules()
{
	std::cout << "==== The Rules =====" << std::endl;
	std::cout << std::endl;
	std::cout << ">> You have only 1000$ in your account" << std::endl;
	std::cout << ">> If you lose the 1000$ then you will be kicked out of the casino" << std::endl;
	std::cout << ">> If you win in the Odd and even game you get 3x the money you chose to play with" << std::endl;
	std::cout << ">> If you win in the Guess Game you get 2x the money you chose to play with" << std::endl;
	std::cout << ">> Good luck .. Exit to go back to the menu" << std::endl;
	std::cout << "0. Exit!" << std::endl;
}
bool SharedFuncitons::CheckIfEmptyAt(int anIndex)
{
	return anIndex == static_cast<int>(Instruction::Empty);
}
int SharedFuncitons::CheckExit()
{
	int inputNr = SharedFuncitons::ReadInputInteger();
	bool wrongInput = true;
	while (wrongInput)
	{
		switch (inputNr)
		{
		case 0:
			wrongInput = false;
			break;
		default:
			std::cout << "Enter 0 to exit" << std::endl;
			inputNr = SharedFuncitons::ReadInputInteger();
			break;
		}
	}
	return static_cast<int>(Instruction::Exit);
}

