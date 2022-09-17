#include "Roulette.h"
#include "SharedFuncitons.h"

int Roulette::Play(int& aWalletMoney, int& aTotalWin, int* aHistoryOfWinOrLose)
{

	int const maxNr = 10;

	std::uniform_int_distribution<int> rndDist(1, maxNr);

	int randomNr = 0;
	int inputNr = 0;
	bool wrongGuess = true;
	bool isPlaying = true;
	bool win = true;
	bool lose = false;
	int choseNr = 0;
	int amountOfMoney = 0;
	//int odd = 1;
	int even = 0;

	bool isWin = false;


	while (isPlaying)
	{
		choseNr = ChoseMenu();
		if (choseNr != static_cast<int>(Instruction::Exit))
		{
			system("cls");
			SharedFuncitons::ShowAmountOfWin(aTotalWin);
			if (aWalletMoney > 0)
			{
				amountOfMoney = SharedFuncitons::AskAmountMoney(aWalletMoney);
			}

			randomNr = rndDist(rndEngine);
			if (choseNr == 1)
			{
				wrongGuess = true;
				std::cout << "guess the random nr between (1 and 10) ?" << std::endl;
				std::cout << "Your Input: ";
				while (wrongGuess)
				{
					inputNr = SharedFuncitons::ReadInputInteger();
					if (inputNr > maxNr)
					{
						std::cout << "The number can't be bigger than " << maxNr << std::endl;
						std::cout << "Your Input: ";

					}
					else if (inputNr < static_cast<int>(Instruction::Empty))
					{
						std::cout << "The number can't be lower than " << static_cast<int>(Instruction::Empty) << std::endl;
						std::cout << "Your Input: ";
					}
					else if (randomNr != inputNr)
					{
						wrongGuess = false;
						isWin = false;
					}
					else
					{
						wrongGuess = false;
						isWin = true;
					}
				}
			}
			else if (choseNr == 2)
			{
				if (randomNr % 2 == even)
				{
					isWin = false;
				}
				else
				{
					isWin = true;
				}
			}
			else if (choseNr == 3)
			{
				if (randomNr % 2 == even)
				{
					isWin = true;

				}
				isWin = false;
			}
		}
		else
		{
			return static_cast<int>(Instruction::Exit);
		}
		if (!isWin)
		{
			system("cls");

			SharedFuncitons::MoneyMath(aWalletMoney, -amountOfMoney);

			SharedFuncitons::SubtractFromWinMoney(aTotalWin, amountOfMoney);

			if (aWalletMoney == 0)
			{
				isPlaying = false;
				return static_cast<int>(Instruction::Exit);
			}
			else
			{
				std::cout << "you have lost!\t\tThe Number was: " << randomNr << std::endl;
				SharedFuncitons::StoreWinOrLose(lose, aHistoryOfWinOrLose);
				if (SharedFuncitons::CheckIfReachMaxWinMoney(aTotalWin))
				{
					SharedFuncitons::DisplayYouCantPlay();
					isPlaying = false;
					return static_cast<int>(Instruction::Exit);
				}
				else
				{
					std::cout << "Do you want to play one more time ? y/n" << std::endl;
					if (SharedFuncitons::ReadInputChar() == 'n')
					{
						isPlaying = false;
						return static_cast<int>(Instruction::Exit);
					}
					else
					{
						system("cls");
					}
				}
			}
		}
		if (isWin)
		{
			system("cls");
			std::cout << "==================" << std::endl;
			std::cout << "congratulatiions you guessed right\t\tThe Number was: " << randomNr << std::endl;
			SharedFuncitons::StoreWinOrLose(win, aHistoryOfWinOrLose);

			SharedFuncitons::MoneyMath(aWalletMoney, amountOfMoney * 2);
			aTotalWin += amountOfMoney * 2;

			if (SharedFuncitons::CheckIfReachMaxWinMoney(aTotalWin))
			{
				SharedFuncitons::DisplayYouCantPlay();
				isPlaying = false;
				return static_cast<int>(Instruction::Exit);
			}
			else
			{
				std::cout << "Do you want to play one more time ? y/n" << std::endl;
				if (SharedFuncitons::ReadInputChar() == 'n')
				{
					isPlaying = false;
					return static_cast<int>(Instruction::Exit);
				}
				else
				{

					system("cls");
				}
			}
		}
	}


	return static_cast<int>(Instruction::Exit);
}

int Roulette::Menu(int& aWalletMoney, int* aHistoryOfWinOrLose)
{
	bool isPlaying = true;
	int inputNr = 0;
	static int totalWin = 0;


	while (isPlaying && aWalletMoney != 0)
	{
		system("cls");
		std::cout << "==== Roulette Game ====" << std::endl;
		std::cout << std::endl;
		std::cout << "1. Play" << std::endl;
		std::cout << "2. Read the rules" << std::endl;
		std::cout << "0. Exit!" << std::endl;
		std::cout << "==================" << std::endl;
		SharedFuncitons::DisplayWinLose(aHistoryOfWinOrLose);
		SharedFuncitons::ShowAmountOfWin(totalWin);

		inputNr = SharedFuncitons::ReadInputInteger();

		switch (inputNr)
		{
		case 1:
			if (SharedFuncitons::CheckIfReachMaxWinMoney(totalWin))
			{
				SharedFuncitons::DisplayYouCantPlay();
			}
			else
			{
				system("cls");
				Play(aWalletMoney, totalWin, aHistoryOfWinOrLose);
			}
			break;

		case 2:
			system("cls");
			SharedFuncitons::GamesRules();
			inputNr = SharedFuncitons::CheckExit();
			break;

		case 0:
			isPlaying = false;
			break;

		case 5:
			system("cls");
			std::cout << "==== Guess Game ====" << std::endl;
			std::cout << std::endl;
			std::cout << "1. Play" << std::endl;
			std::cout << "2. Read the rules" << std::endl;
			std::cout << "0. Exit!" << std::endl;
			inputNr = SharedFuncitons::ReadInputInteger();
			break;

		default:
			bool wrongInput = true;
			while (wrongInput)
			{
				std::cout << "pleas chose one of the option" << std::endl;
				inputNr = SharedFuncitons::ReadInputInteger();
				if (inputNr == 0 || inputNr == 1 || inputNr == 2)
				{
					wrongInput = false;
				}
			}
			break;
		}
	}
	return static_cast<int>(Instruction::Exit);
}

int Roulette::ChoseMenu()
{
	std::cout << "======================OBS======================" << std::endl;
	std::cout << "1. You can guess where the ball will land between (1 and 10)" << std::endl;
	std::cout << "2. You guess if the ball will land on odd number" << std::endl;
	std::cout << "3. You guess if the ball will land on even number" << std::endl;
	std::cout << "0. Exit" << std::endl;
	std::cout << "======================OBS======================\n" << std::endl;

	int choseNr = SharedFuncitons::ReadInputInteger();
	bool wrongInput = true;
	while (wrongInput)
	{
		switch (choseNr)
		{
		case 1:
			return choseNr;
			break;
		case 2:
			return choseNr;
			break;
		case 3:
			return choseNr;
			break;
		case 0:
			wrongInput = false;
			break;
		default:
			std::cout << "Pleas chose one of the optione" << std::endl;
			choseNr = SharedFuncitons::ReadInputInteger();
			break;
		}
	}
	return static_cast<int>(Instruction::Exit);
}


	//Column bet 
// ask which collomn 1 2 or 3 
//check if the random nr = .. an array[12] begin with comomn++;

	//Corner 
//ask for 4 input ... number should be (n,n+1,n+3,n+4) else is not valid 
//to do so sort the array form min to max 
//and applay that validation (n,n+1,n+3,n+4)

	//Staright
//ask for any number guess number ... between 0 and 36

	//Split
//ask for 2 input
// sort the numbers
//  .. number should be (n,n+1) or (n, n+3) 
//	.. number (n, n+3) the lowest number should not be comomn 3 and largets from 2
//	.. number (n, n+3) the lowest not colomn 1 and largest colomn 3
// same thing with (n, n+1)
// 
// 
	//Red/Black
//
//
// 
// 
//