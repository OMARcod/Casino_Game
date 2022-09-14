#include "OddOrEven.h"

int OddOrEven::Play(int& aWalletMoney)
{
	std::uniform_int_distribution<int> rndDist(1, 6);

	int dice1 = 0;
	int dice2 = 0;
	int inputNr = 0;

	bool win = true;
	bool lose = false;

	bool wrongGuess = true;
	bool isPlaying = true;

	int amountOfMoney = 0;
	std::cout << "======================OBS======================" << std::endl;

	std::cout << "if the two dices is odd and you chose odd you win!" << std::endl;
	std::cout << "if the two dices is even and you chose even you win!" << std::endl;
	std::cout << "else you lose!" << std::endl;
	std::cout << "======================OBS======================\n" << std::endl;

	while (isPlaying && aWalletMoney != 0)
	{
		wrongGuess = true;
		dice1 = rndDist(rndEngine);
		dice2 = rndDist(rndEngine);

		int tempDice1 = dice1;
		int tempDice2 = dice2;
		dice1 = (dice1 % 2);
		dice2 = (dice2 % 2);
		int even = 0;
		int odd = 1;

		if (aWalletMoney > 0)
		{

			amountOfMoney = SharedFuncitons::AskAmountMoney(aWalletMoney);

		}
		SharedFuncitons::ShowAmountOfWin(globalTotalWinMoneyOddEven);
		std::cout << "I have thrown 2 dices!  ";
		std::cout << "What do want to chose? odd or even" << std::endl;
		std::cout << std::endl;
		std::cout << "1. odd" << std::endl;
		std::cout << "0. even" << std::endl;
		std::cout << "=======================================" << std::endl;


		std::cout << "Your Input: ";


		while (wrongGuess)
		{
			inputNr = SharedFuncitons::ReadInputInteger();

			if (inputNr == odd && dice1 == odd && dice2 == odd)
			{
				system("cls");

				SharedFuncitons::MoneyMath(aWalletMoney, amountOfMoney * 3);
				globalTotalWinMoneyOddEven += amountOfMoney * 3;

				if (SharedFuncitons::CheckIfReachMaxWinMoney(globalTotalWinMoneyOddEven))
				{
					SharedFuncitons::DisplayYouCantPlay();
					isPlaying = false;
					return static_cast<int>(Instruction::Exit);
				}
				else
				{
					std::cout << "dice1:  " << tempDice1 << "  ||   dice2: " << tempDice2 << std::endl;

					std::cout << "congratulatiions you guessed right" << std::endl;
					wrongGuess = false;
					SharedFuncitons::StoreWinOrLose(win);

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
			else if (inputNr == even && dice1 == even && dice2 == even)
			{
				system("cls");


				SharedFuncitons::MoneyMath(aWalletMoney, amountOfMoney * 3);
				globalTotalWinMoneyOddEven += amountOfMoney * 3;

				if (SharedFuncitons::CheckIfReachMaxWinMoney(globalTotalWinMoneyOddEven))
				{
					SharedFuncitons::DisplayYouCantPlay();
					isPlaying = false;
					return static_cast<int>(Instruction::Exit);
				}
				else
				{
					std::cout << "dice1:  " << tempDice1 << "  ||   dice2: " << tempDice2 << std::endl;


					std::cout << "congratulatiions you guessed right" << std::endl;
					wrongGuess = false;
					SharedFuncitons::StoreWinOrLose(win);



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
			else if (inputNr == odd || inputNr == even)
			{
				system("cls");

				SharedFuncitons::MoneyMath(aWalletMoney, -amountOfMoney);
				SharedFuncitons::SubtractFromWinMoney(globalTotalWinMoneyOddEven, amountOfMoney);


				wrongGuess = false;

				if (aWalletMoney == 0)
				{
					isPlaying = false;
					return static_cast<int>(Instruction::Exit);
				}
				else
				{
					std::cout << "dice1:  " << tempDice1 << "  ||   dice2: " << tempDice2 << std::endl;
					std::cout << "you have lost!" << std::endl;
					std::cout << "Do you want to play one more time ? y/n" << std::endl;
					SharedFuncitons::StoreWinOrLose(lose);


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
			else
			{
				std::cout << "Please Enter 1. even or 0. odd " << std::endl;
			}
		}
	}
	return static_cast<int>(Instruction::Exit);
}

int OddOrEven::Menu(int& aWalletMoney)
{
	bool isPlaying = true;
	int inputNr = 0;

	while (isPlaying && aWalletMoney != 0)
	{
		system("cls");
		std::cout << "==== Odd and even Game ====" << std::endl;
		std::cout << std::endl;
		std::cout << "1. Play" << std::endl;
		std::cout << "2. Read the rules" << std::endl;
		std::cout << "0. Exit!" << std::endl;
		SharedFuncitons::DisplayWinLose();
		SharedFuncitons::ShowAmountOfWin(globalTotalWinMoneyOddEven);


		inputNr = SharedFuncitons::ReadInputInteger();

		switch (inputNr)
		{
		case 1:
			if (SharedFuncitons::CheckIfReachMaxWinMoney(globalTotalWinMoneyOddEven))
			{
				SharedFuncitons::DisplayYouCantPlay();
			}
			else
			{
				system("cls");
				Play(aWalletMoney);
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
			std::cout << "==== Odd and even Game ====" << std::endl;
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
