#include "TicTacToe.h"

int TicTacToe::PlayTicTacToe(int& aWalletMoney)
{
	char array2D[3][3];
	int index = 0;
	bool lose = false;
	bool win = true;

	bool isPlaying = true;
	bool firstPlayer = true;

	TicTacShowMenu();
	index = AskForInputMenu();

	std::string playerName = "";
	int amountOfMoney = 0;
	bool GameNotExit = true;

	if (SharedFuncitons::CheckIfReachMaxWinMoney(globalTotalWinMoneyTicTac))
	{
		SharedFuncitons::DisplayYouCantPlay();
		return static_cast<int>(Instruction::Exit);
	}

	while (aWalletMoney != static_cast<int>(Instruction::Empty))
	{

		if (index == 0)
		{
			GameNotExit = false;
			return static_cast<int>(Instruction::Exit);
		}
		else
		{
			system("cls");

			if (aWalletMoney > static_cast<int>(Instruction::Empty))
			{

				amountOfMoney = SharedFuncitons::AskAmountMoney(aWalletMoney);

			}
			SharedFuncitons::ShowAmountOfWin(globalTotalWinMoneyTicTac);

			std::cout << "First Player Name: ";
			std::cin >> playerName;

			system("cls");
			ChangeArray(array2D, ' ');
			DipslayTicTacArray(array2D);
			std::cout << "Type the the number of the box that you want to use:" << std::endl;
		}
		bool wantToPlay = true;

		while (GameNotExit)
		{
			while (wantToPlay)
			{
				while (isPlaying)
				{
					if (firstPlayer)
					{
						index = AskForInputGame(playerName);
					}
					else
					{
						index = returnRandomEmptyIndex();
					}
					if (CheckIndexIsUsed(index))
					{
						std::cout << index << ": box is used! Pleas chose another box" << std::endl;
					}
					else
					{
						if (firstPlayer)
						{
							ChangeArrayAtLocation(array2D, 'X', index, static_cast<int>(Player::X));
							firstPlayer = false;
						}
						else
						{
							ChangeArrayAtLocation(array2D, 'O', index, static_cast<int>(Player::O));
							firstPlayer = true;
						}
						DipslayTicTacArray(array2D);
					}
					if (CheckIfWin())
					{
						if (firstPlayer)
						{
							SharedFuncitons::MoneyMath(aWalletMoney, -amountOfMoney);
							SharedFuncitons::SubtractFromWinMoney(globalTotalWinMoneyTicTac, amountOfMoney);
							SharedFuncitons::StoreWinOrLose(lose);


							std::cout << "the comp have Won!" << std::endl;
							isPlaying = false;
						}
						else
						{
							SharedFuncitons::MoneyMath(aWalletMoney, amountOfMoney * 3);
							globalTotalWinMoneyTicTac += amountOfMoney * 3;
							SharedFuncitons::StoreWinOrLose(win);



							std::cout << playerName << " You Won!" << std::endl;
							isPlaying = false;
						}
					}
					else if (CheckIfArrayIsFull())
					{
						std::cout << "The box is full" << std::endl;
						isPlaying = false;
					}
				}

				if (SharedFuncitons::CheckIfReachMaxWinMoney(globalTotalWinMoneyTicTac) || aWalletMoney == static_cast<int>(Instruction::Empty))
				{
					SharedFuncitons::DisplayYouCantPlay();
					wantToPlay = false;
					ResetTheGame(array2D);
					return static_cast<int>(Instruction::Exit);
				}
				else
				{
					std::cout << "==========================" << std::endl;
					std::cout << "Do you want to play again?" << std::endl;
					std::cout << "1. Yes" << std::endl;
					std::cout << "0. No!" << std::endl;
					if (AskForInputMenu() == 0)
					{
						wantToPlay = false;
						ResetTheGame(array2D);
					}
					else
					{
						isPlaying = true;
						ResetTheGame(array2D);

						if (aWalletMoney > 0)
						{
							amountOfMoney = SharedFuncitons::AskAmountMoney(aWalletMoney);
							system("pause");

						}
					}
				}
			}

			TicTacShowMenu();
			index = AskForInputMenu();
			if (index == 0)
			{
				GameNotExit = false;
			}
			else
			{
				wantToPlay = true;
				isPlaying = true;
				system("cls");
				ChangeArray(array2D, ' ');
				DipslayTicTacArray(array2D);
				std::cout << "Type the the number of the box that you want to use:" << std::endl;
			}
		}
	}

	return static_cast<int>(Instruction::Exit);
}

void TicTacToe::ResetTheGame(char anArray[][3])
{
	for (int i = 0; i < globalArraySize; i++)
	{
		globalUsedSpaces[i] = static_cast<int>(Instruction::Empty);
	}
	ChangeArray(anArray, ' ');
	DipslayTicTacArray(anArray);
}

int TicTacToe::AskForInputGame(const std::string& aPlayerName)
{
	int index = 0;
	std::cout << aPlayerName << " Input: ";

	index = CheckInput();
	while (index < 1 || index > globalArraySize)
	{
		std::cout << "Pleas Enter a number between 1 and 9 ...." << std::endl;
		std::cout << "Your Input: ";
		index = CheckInput();
	}
	return  index;
}

int TicTacToe::EasyEnemi()
{
	int index = 0;

	index = RandomIndex();
	while (index < 1 || index > globalArraySize)
	{
		std::cout << "Pleas Enter a number between 1 and 9 ...." << std::endl;
		std::cout << "Your Input: ";
		index = RandomIndex();
	}
	return  index;
}

int TicTacToe::RandomIndex()
{
	int lastIndex = globalArraySize - 1;
	int index = RandomNumber(1, lastIndex);
	bool isUsed = true;
	while (isUsed)
	{
		if (globalUsedSpaces[index] > 0 && globalUsedSpaces[index] < 3)
		{
			index = RandomNumber(1, lastIndex);
		}
		else
		{
			return index;
		}
	}

	return 0;
}

int TicTacToe::RandomNumber(int aMin, int aMax)
{
	std::uniform_int_distribution<int> rndDist(aMin, aMax);
	int randomNr = rndDist(rndEngine);
	return randomNr;
}

int TicTacToe::returnRandomEmptyIndex()
{
	int index = 5;
	for (int i = 0; i < 5; i++)
	{
		if (!(CheckIndexIsUsed(index)))
		{
			return index;
		}
		index = RandomNumber(1, 9);
	}

	int RandomLoop = RandomNumber(0, 10);
	if (RandomLoop > 5)
	{
		for (int i = 1; i < globalArraySize + 1; i++)
		{
			if (!(CheckIndexIsUsed(i)))
			{
				return i;
			}
			RandomLoop = RandomNumber(0, 10);
		}
	}
	else
	{
		for (int i = globalArraySize; i > 0; i--)
		{
			if (!(CheckIndexIsUsed(i)))
			{
				return i;
			}
			RandomLoop = RandomNumber(0, 10);
		}
	}

	return 0;
}

int TicTacToe::AskForInputMenu()
{
	int index = 0;
	std::cout << "Your Input: ";

	index = CheckInput();
	while (index < 0 || index > 1)
	{
		std::cout << "Pleas Enter 0 or 1 ...." << std::endl;
		std::cout << "Your Input: ";
		index = CheckInput();
	}
	return  index;
}

int TicTacToe::CheckInput()
{
	int input;
	std::cin >> input;
	while (true)
	{
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "You have entered wrong input" << std::endl;
			std::cin >> input;
		}
		if (!std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			break;
		}
	}
	return input;
}

void TicTacToe::DipslayTicTacArray(char anArray[][3])
{
	int boxNr = 1;

	system("cls");
	std::cout << "-----------------" << std::endl;
	for (int i = 0; i < globalBoxSize; i++)
	{
		for (int k = 0; k < globalBoxSize; k++)
		{
			std::cout << " | " << anArray[i][k];
		}
		std::cout << " | ";

		std::cout << "\t\t";
		for (int j = 0; j < globalBoxSize; j++)
		{
			std::cout << " | " << boxNr;
			boxNr++;
		}
		std::cout << " | ";

		std::cout << "\n-----------------" << std::endl;
	}
}

void TicTacToe::ChangeArray(char anArray[][3], char aLetter)
{
	for (int i = 0; i < globalBoxSize; i++)
	{
		for (int k = 0; k < globalBoxSize; k++)
		{
			anArray[i][k] = aLetter;
		}
	}
}

bool TicTacToe::CheckIndexIsUsed(int anIndex)
{
	bool isUsed = false;
	if (globalUsedSpaces[anIndex - 1] == static_cast<int>(Instruction::Win) || globalUsedSpaces[anIndex - 1] == static_cast<int>(Instruction::Lose))
	{
		isUsed = true;
	}
	return isUsed;
}

void TicTacToe::ChangeArrayAtLocation(char anArray[][3], char aLetter, int anIndex, int aPlayer)
{
	int row = 0;
	int column = 0;

	switch (anIndex)
	{
	case 1:
		row = 0;
		column = 0;
		globalUsedSpaces[anIndex - 1] += aPlayer;

		break;
	case 2:
		row = 0;
		column = 1;
		globalUsedSpaces[anIndex - 1] += aPlayer;

		break;
	case 3:
		row = 0;
		column = 2;
		globalUsedSpaces[anIndex - 1] += aPlayer;
		break;
	case 4:
		row = 1;
		column = 0;
		globalUsedSpaces[anIndex - 1] += aPlayer;
		break;
	case 5:
		row = 1;
		column = 1;
		globalUsedSpaces[anIndex - 1] += aPlayer;
		break;
	case 6:
		row = 1;
		column = 2;
		globalUsedSpaces[anIndex - 1] += aPlayer;
		break;
	case 7:
		row = 2;
		column = 0;
		globalUsedSpaces[anIndex - 1] += aPlayer;
		break;
	case 8:
		row = 2;
		column = 1;
		globalUsedSpaces[anIndex - 1] += aPlayer;
		break;
	case 9:
		row = 2;
		column = 2;
		globalUsedSpaces[anIndex - 1] += aPlayer;
		break;
	default:
		break;
	}

	anArray[row][column] = aLetter;
}

bool TicTacToe::CheckIfArrayIsFull()
{
	bool isFull = false;
	int nrOfBoxesUsed = 0;
	for (int i = 0; i < globalArraySize; i++)
	{
		if (globalUsedSpaces[i] == static_cast<int>(Instruction::Win) || globalUsedSpaces[i] == static_cast<int>(Instruction::Lose))
		{
			nrOfBoxesUsed++;
		}
	}
	if (nrOfBoxesUsed >= globalArraySize)
	{
		isFull = true;
	}
	return isFull;
}

bool TicTacToe::CheckIfWin()
{
	bool isWin = CheckHorisontalWin();

	if (!isWin)
	{
		isWin = CheckVerticalWin();

		if (!isWin)
		{
			isWin = CheckCurvedLineWin();
		}
	}

	return isWin;
}

bool TicTacToe::CheckHorisontalWin()
{
	bool isWin = false;
	int startIndex = 0;
	int nrToAdd = 1;
	for (int i = 0; i < globalBoxSize; i++)
	{
		if (CheckThisRow(startIndex, static_cast<int>(Player::X), nrToAdd))
		{
			isWin = true;
			break;
		}
		else if (CheckThisRow(startIndex, static_cast<int>(Player::O), nrToAdd))
		{
			isWin = true;
			break;
		}
		startIndex += 3;
	}

	return isWin;
}

bool TicTacToe::CheckVerticalWin()
{
	bool isWin = false;
	int startIndex = 0;
	int nrToAdd = 3;
	for (int i = 0; i < globalBoxSize; i++)
	{
		if (CheckThisRow(startIndex, static_cast<int>(Player::X), nrToAdd))
		{
			isWin = true;
			break;
		}
		else if (CheckThisRow(startIndex, static_cast<int>(Player::O), nrToAdd))
		{
			isWin = true;
			break;
		}
		startIndex += 1;
	}
	return isWin;
}

bool TicTacToe::CheckThisRow(int aStartIndex, int aPlayer, int toAdd)
{
	if (globalUsedSpaces[aStartIndex] == aPlayer && globalUsedSpaces[aStartIndex + toAdd] == aPlayer && globalUsedSpaces[aStartIndex + (toAdd * 2)] == aPlayer)
	{
		return true;
	}
	return false;
}

bool TicTacToe::CheckCurvedLineWin()
{
	bool isWin = false;
	int line = 2;
	int secuondLine = 2;
	int firstLine = 0;

	int nrToAdd = 4;
	for (int i = 0; i < line; i++)
	{

		if (CheckThisRow(firstLine, static_cast<int>(Player::X), nrToAdd))
		{
			isWin = true;
			break;
		}
		else if (CheckThisRow(firstLine, static_cast<int>(Player::O), nrToAdd))
		{
			isWin = true;
			break;
		}
	}
	nrToAdd = 2;
	for (int i = 0; i < line; i++)
	{
		if (CheckThisRow(secuondLine, static_cast<int>(Player::X), nrToAdd))
		{
			isWin = true;
			break;
		}
		else if (CheckThisRow(secuondLine, static_cast<int>(Player::O), nrToAdd))
		{
			isWin = true;
			break;
		}
	}
	return isWin;
}

void TicTacToe::TicTacShowMenu()
{
	system("cls");
	std::cout << "================================" << std::endl;
	std::cout << "Welcome to the Tic Tac Toe Game!" << std::endl;
	std::cout << "================================" << std::endl;
	SharedFuncitons::DisplayWinLose();
	SharedFuncitons::ShowAmountOfWin(globalTotalWinMoneyTicTac);
	std::cout << "1. Play New Game" << std::endl;
	std::cout << "0. Exit" << std::endl;
}

