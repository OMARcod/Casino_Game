#include "GuessGame.h"
#include "SharedFuncitons.h"



int GuessGame::Play(int& aWalletMoney,int& aTotalWin,int *aHistoryOfWinOrLose)
{
	std::uniform_int_distribution<int> rndDist(1, 6);

	int const nrOfTryAllowed = 3;
	int const maxSum = 12;

	int dice1 = 0;
	int dice2 = 0;
	int inputNr = 0;
	int sumOfDices = 0;
	int nrOfTry = nrOfTryAllowed;
	bool wrongGuess = true;
	bool isPlaying = true;
	bool win = true;
	bool lose = false;

	int amountOfMoney = 0;

	std::cout << "======================OBS======================" << std::endl;
	std::cout << "if the sum of the two dice is not equal your answer you will lose" << std::endl;
	std::cout << "if you the sum is equal then you get 2x the money you put" << std::endl;
	std::cout << "======================OBS======================\n" << std::endl;


	while (isPlaying)
	{
		wrongGuess = true;
		nrOfTry = nrOfTryAllowed;
		dice1 = rndDist(rndEngine);
		dice2 = rndDist(rndEngine);
		sumOfDices = dice1 + dice2;

		if (aWalletMoney > 0)
		{
			amountOfMoney = SharedFuncitons::AskAmountMoney(aWalletMoney);
		}
		SharedFuncitons::ShowAmountOfWin(aTotalWin);
		std::cout << "guess the sum of the two dices ?" << std::endl;

		std::cout << "Your Input: ";

		while (wrongGuess)
		{
			if (!(nrOfTry < 1))
			{
				inputNr = SharedFuncitons::ReadInputInteger();
			}



			if (inputNr > maxSum)
			{
				std::cout << "The number can't be bigger than " << maxSum << std::endl;
				std::cout << "Your Input: ";

			}
			else
			{
				if (nrOfTry < 1)
				{

					system("cls");

					SharedFuncitons::MoneyMath(aWalletMoney, -amountOfMoney);

					SharedFuncitons::SubtractFromWinMoney(aTotalWin, amountOfMoney);

					wrongGuess = false;

					if (aWalletMoney == 0)
					{
						isPlaying = false;
						return static_cast<int>(Instruction::Exit);
					}
					else
					{
						std::cout << "you have lost!\t\tThe Number was: "<< sumOfDices << std::endl;
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

								nrOfTry = nrOfTryAllowed;
								system("cls");
							}
						}
					}

				}
				if (inputNr > sumOfDices)
				{
					nrOfTry--;
					if (!(nrOfTry < 1))
					{
						std::cout << "==================" << std::endl;
						std::cout << "less" << "                           ||Try left:" << nrOfTry << std::endl;

						std::cout << "Your Input: ";
					}

				}
				else if (inputNr < sumOfDices)
				{

					nrOfTry--;
					if (!(nrOfTry < 1))
					{
						std::cout << "==================" << std::endl;
						std::cout << "greater" << "                          ||Try left:" << nrOfTry << std::endl;

						std::cout << "Your Input: ";
					}
				}
				else
				{
					system("cls");
					std::cout << "==================" << std::endl;
					std::cout << "congratulatiions you guessed right" << std::endl;
					wrongGuess = false;
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

							nrOfTry = nrOfTryAllowed;
							system("cls");
						}
					}
				}
			}

		}
		system("cls");
	}
	return 0;
}

int GuessGame::Menu(int& aWalletMoney,int *aHistoryOfWinOrLose)
{
	bool isPlaying = true;
	int inputNr = 0;
	static int totalWin = 0;


	while (isPlaying && aWalletMoney != 0)
	{
		system("cls");
		std::cout << "==== Guess Game ====" << std::endl;
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