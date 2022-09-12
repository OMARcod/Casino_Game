#include <iostream>
#include <random>

std::random_device seed;
std::mt19937 rndEngine(seed());

void GamesRules();
int CheckExit();
int ReadInputInteger();
char ReadInputChar();
void ShowMoneyLeft(int aWalletMoney);
int ShowMenu(int aWalletMoney);
int AskAmountMoney(int aWalletMoney);
int PlayOddAndEven(int& aWalletMoney);
int OddAndEvenGameMenu(int& aWalletMoney);
void Play(int& aWalletMoney);
int GuessGame(int& aWalletMoney);
int GuessGameMenu(int& aWalletMoney);
void MoneyMath(int& aWalletMoney, int someAmountOfMoney);


//New Functions
bool checkIfEmptyAt(int anIndex);
void StoreWinGame(bool isWin);
bool CheckIfReachMaxWinMoney(int aMaxWinMoney);
void DisplayYouCantPlay();
void subtractFromWinMoney(int aWinMoney, const int& amountToSubtract);
void showAmountOfWin(const int& aWinMoney);

static const int locMaxMoney = 5000;
static int locWinMoneyGuess = 0;
static int locWinMoneyOddEven = 0;
static int locMaxWinMoneyGameThree = 0;

static const int arraySize = 5;
int historyWin[arraySize] = { 0 };



enum class Instruction
{
	Exit = 5,
	Win = 1,
	Lose = 2,
	Empty = 0,
};


int main()
{
	int walletMoney = 1000;



	Play(walletMoney);

	if (walletMoney <= 0)
	{
		std::cout << "\n ======== You lost all your money ... you can't play anymore! ======== " << std::endl;
	}
	else
	{
		std::cout << "Money left: " << walletMoney << std::endl;
		std::cout << "Goodby! " << std::endl;
	}

	std::cin.get();
}

void Play(int& aWalletMoney)
{

	int inputNr = 0;
	bool okInput = true;
	bool isPlaying = true;
	int amountOfMoney = 0;
	int choiceOne = 1, choiceTwo = 2, choiceThree = 3, choiceZero = 0;
	inputNr = ShowMenu(aWalletMoney);

	while (isPlaying && aWalletMoney != 0)
	{
		switch (inputNr)
		{
		case 1:
			system("cls");
			inputNr = GuessGameMenu(aWalletMoney);
			break;
		case 2:
			system("cls");
			inputNr = OddAndEvenGameMenu(aWalletMoney);
			break;
		case 3:
			system("cls");
			GamesRules();
			inputNr = CheckExit();
			break;
		case 0:
			isPlaying = false;
			break;

		case 5:
			inputNr = ShowMenu(aWalletMoney);

			break;
		default:
			bool wrongInput = true;
			while (wrongInput)
			{
				std::cout << "pleas chose one of the option" << std::endl;
				inputNr = ReadInputInteger();
				if (inputNr == choiceZero || inputNr == choiceOne || inputNr == choiceTwo || inputNr == choiceThree)
				{
					wrongInput = false;
				}
			}
			break;
		}

	}
}

int ShowMenu(int aWalletMoney)
{

	system("cls");

	std::cout << "=== Welcome To The Kasino Game =====" << std::endl;
	std::cout << std::endl;
	std::cout << "1. Play: guess game" << std::endl;
	std::cout << "2. Play: odd and even numbers" << std::endl;
	std::cout << "3. Read the rules" << std::endl;
	std::cout << "0. Exit!" << std::endl;
	ShowMoneyLeft(aWalletMoney);
	int inputNr = ReadInputInteger();

	return inputNr;
}

int AskAmountMoney(int aWalletMoney)
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

int PlayOddAndEven(int& aWalletMoney)
{
	std::uniform_int_distribution<int> rndDist(1, 6);

	int dice1 = 0;
	int dice2 = 0;
	int inputNr = 0;
	int result = 0;

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
		if (dice1 == odd && dice2 == odd)
		{
			std::cout << "odd" << std::endl;
		}
		else if (dice1 == even && dice2 == even)
		{
			std::cout << "even" << std::endl;
		}
		else
		{
			std::cout << ":(" << std::endl;
		}

		if (aWalletMoney > 0)
		{

			amountOfMoney = AskAmountMoney(aWalletMoney);

		}
		showAmountOfWin(locWinMoneyOddEven);
		std::cout << "I have thrown 2 dices!  ";
		std::cout << "What do want to chose? odd or even" << std::endl;
		std::cout << std::endl;
		std::cout << "1. odd" << std::endl;
		std::cout << "0. even" << std::endl;
		std::cout << "=======================================" << std::endl;


		std::cout << "Your Input: ";


		while (wrongGuess)
		{
			inputNr = ReadInputInteger();

			if (inputNr == odd && dice1 == odd && dice2 == odd)
			{
				system("cls");

				MoneyMath(aWalletMoney, amountOfMoney * 3);
				locWinMoneyOddEven += amountOfMoney * 3;

				if (CheckIfReachMaxWinMoney(locWinMoneyOddEven))
				{
					DisplayYouCantPlay();
					isPlaying = false;
					return static_cast<int>(Instruction::Exit);
				}
				else
				{
					std::cout << "dice1:  " << tempDice1 << "  ||   dice2: " << tempDice2 << std::endl;

					std::cout << "congratulatiions you guessed right" << std::endl;
					wrongGuess = false;

					std::cout << "Do you want to play one more time ? y/n" << std::endl;

					if (ReadInputChar() == 'n')
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


				MoneyMath(aWalletMoney, amountOfMoney * 3);
				locWinMoneyOddEven += amountOfMoney * 3;

				if (CheckIfReachMaxWinMoney(locWinMoneyOddEven))
				{
					DisplayYouCantPlay();
					isPlaying = false;
					return static_cast<int>(Instruction::Exit);
				}
				else
				{
					std::cout << "dice1:  " << tempDice1 << "  ||   dice2: " << tempDice2 << std::endl;


					std::cout << "congratulatiions you guessed right" << std::endl;
					wrongGuess = false;


					std::cout << "Do you want to play one more time ? y/n" << std::endl;


					if (ReadInputChar() == 'n')
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

				MoneyMath(aWalletMoney, -amountOfMoney);
				subtractFromWinMoney(locWinMoneyOddEven, amountOfMoney);


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

					if (ReadInputChar() == 'n')
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
}

int OddAndEvenGameMenu(int& aWalletMoney)
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
		showAmountOfWin(locWinMoneyOddEven);


		inputNr = ReadInputInteger();

		switch (inputNr)
		{
		case 1:
			if (CheckIfReachMaxWinMoney(locWinMoneyOddEven))
			{
				DisplayYouCantPlay();
			}
			else
			{
				system("cls");
				PlayOddAndEven(aWalletMoney);
			}
			break;

		case 2:
			system("cls");
			GamesRules();
			inputNr = CheckExit();
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
			inputNr = ReadInputInteger();
			break;

		default:
			bool wrongInput = true;
			while (wrongInput)
			{
				std::cout << "pleas chose one of the option" << std::endl;
				int inputNr = ReadInputInteger();
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

void MoneyMath(int& aWalletMoney, int someAmountOfMoney)
{
	aWalletMoney += someAmountOfMoney;
	ShowMoneyLeft(aWalletMoney);
}

int CheckExit()
{
	int inputNr = ReadInputInteger();
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
			inputNr = ReadInputInteger();
			break;
		}
	}
	return static_cast<int>(Instruction::Exit);
}

void ShowMoneyLeft(int aWalletMoney)
{

	std::cout << "====================" << std::endl;
	std::cout << "Money left: " << aWalletMoney << std::endl;
	std::cout << "====================" << std::endl;
}

int ReadInputInteger()
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

char ReadInputChar()
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

void GamesRules()
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

void showAmountOfWin(const int& aWinMoney)
{
	std::cout << "=====================================" << std::endl;
	std::cout << "amount of win " << locWinMoneyGuess << "$" << std::endl;
	std::cout << "=====================================" << std::endl;
}

void subtractFromWinMoney(int aWinMoney, const int& amountToSubtract)
{
	if (aWinMoney > amountToSubtract)
	{
		locWinMoneyGuess -= amountToSubtract;
	}
	else
	{
		locWinMoneyGuess = 0;
	}
}

void DisplayYouCantPlay()
{
	std::cout << "=====================================" << std::endl;
	std::cout << "You Can't play this game any more" << std::endl;
	system("pause");
}

int GuessGame(int& aWalletMoney)
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

	int amountOfMoney = 0;
	//int amountOfWinMoney = 0;

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
			amountOfMoney = AskAmountMoney(aWalletMoney);
		}
		showAmountOfWin(locWinMoneyGuess);
		std::cout << "guess the sum of the two dices ? \t\t" << sumOfDices << std::endl;

		std::cout << "Your Input: ";

		while (wrongGuess)
		{
			if (!(nrOfTry < 1))
			{
				inputNr = ReadInputInteger();
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

					MoneyMath(aWalletMoney, -amountOfMoney);

					subtractFromWinMoney(locWinMoneyGuess, amountOfMoney);

					wrongGuess = false;

					if (aWalletMoney == 0)
					{
						isPlaying = false;
						return static_cast<int>(Instruction::Exit);
					}
					else
					{
						std::cout << "you have lost!" << std::endl;

						if (CheckIfReachMaxWinMoney(locWinMoneyGuess))
						{
							DisplayYouCantPlay();
							isPlaying = false;
							return static_cast<int>(Instruction::Exit);
						}
						else
						{
							std::cout << "Do you want to play one more time ? y/n" << std::endl;
							if (ReadInputChar() == 'n')
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

					MoneyMath(aWalletMoney, amountOfMoney * 2);
					locWinMoneyGuess += amountOfMoney * 2;

					if (CheckIfReachMaxWinMoney(locWinMoneyGuess))
					{
						DisplayYouCantPlay();
						isPlaying = false;
						return static_cast<int>(Instruction::Exit);
					}
					else
					{
						std::cout << "Do you want to play one more time ? y/n" << std::endl;
						if (ReadInputChar() == 'n')
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

}

int GuessGameMenu(int& aWalletMoney)
{
	bool isPlaying = true;
	int inputNr = 0;

	while (isPlaying && aWalletMoney != 0)
	{
		system("cls");
		std::cout << "==== Guess Game ====" << std::endl;
		std::cout << std::endl;
		std::cout << "1. Play" << std::endl;
		std::cout << "2. Read the rules" << std::endl;
		std::cout << "0. Exit!" << std::endl;
		showAmountOfWin(locWinMoneyGuess);

		inputNr = ReadInputInteger();

		switch (inputNr)
		{
		case 1:
			if (CheckIfReachMaxWinMoney(locWinMoneyGuess))
			{
				DisplayYouCantPlay();
			}
			else
			{
				system("cls");
				GuessGame(aWalletMoney);
			}
			break;

		case 2:
			system("cls");
			GamesRules();
			inputNr = CheckExit();
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
			inputNr = ReadInputInteger();
			break;

		default:
			bool wrongInput = true;
			while (wrongInput)
			{
				std::cout << "pleas chose one of the option" << std::endl;
				int inputNr = ReadInputInteger();
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

////fucntion to Play the other casino game
////funciton to display 5 last played games 
////function to display the history of played games
//
////function to display if player won more than 400$ or if lose more than 400

//fucntion to see if the player have won more than 5000 in a single game
bool CheckIfReachMaxWinMoney(int aMaxWinMoney)
{
	bool isReached = aMaxWinMoney >= locMaxMoney;
	return isReached;
}

void StoreWinGame(bool isWin)
{
	bool ok = true;
	while (ok)
	{
		if (isWin)
		{
			for (int i = 0; i < 5; i++)
			{
				if (checkIfEmptyAt(i))
				{
					historyWin[i] = static_cast<int>(Instruction::Win);
					return;
				}
			}
		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
				if (checkIfEmptyAt(i))
				{
					historyWin[i] = static_cast<int>(Instruction::Lose);
					return;
				}
			}
		}

		//if is full
		//stor the make the fist element emepty
		//push the rest to one element to the right
		int temp = 0;
		for (int i = 0; i < arraySize - 1; i++)
		{
			temp = historyWin[i + 1];
			historyWin[i + 1] = historyWin[i];
		}
		historyWin[0] = static_cast<int>(Instruction::Empty);
	}


}

bool checkIfEmptyAt(int anIndex)
{
	return anIndex == static_cast<int>(Instruction::Empty);
}


