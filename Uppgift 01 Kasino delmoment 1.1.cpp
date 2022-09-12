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
bool CheckIfEmptyAt(int anIndex);
void StorWinGame(bool isWin);
bool CheckIfReachMaxWinMoney(int aMaxWinMoney);
void DisplayYouCantPlay();
void SubtractFromWinMoney(int aWinMoney, const int& amountToSubtract);
void ShowAmountOfWin(const int& aWinMoney);
void DisplayWinLose();


static const int locMaxMoney = 5000;
static int locWinMoneyGuess = 0;
static int locWinMoneyOddEven = 0;
static int locMaxWinMoneyGameThree = 0;

static const int arraySize = 5;
int historyWin[arraySize] = { 0 };

//TicTacToe
void ChangeArray(char a[][3], char letter);
void ChangeArrayAtLocation(char a[][3], char letter, int index, int player);
void DipslayArray(char a[][3]);
int AskForInputGame(std::string playerName);
int AskForInputMenu();
int CheckInput();
bool CheckIndexIsUsed(int index);
bool CheckIfFull();
bool CheckIfWin();
bool CheckHorisontalWin();
bool CheckVerticalWin();
bool CheckCurvedLineWin();
bool CheckThisRow(int beginIndex, int player, int toAdd);
void ShowMenu();
void ResetTheGame(char array[][3]);
int RandomIndex();
int EasyEnemi();
int RandomNumber(int aMin, int aMax);
int RandomIndex();
int returnEmptyIndex();
int PlayTicTacToe();

static int const arraySizeSpace = 9;
static int usedSpace[arraySizeSpace]{ 0 };

enum class Player
{
	X = 1,
	O = 2,
};
int playerO = static_cast<int>(Player::O);
int playerX = static_cast<int>(Player::X);

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
			inputNr = PlayTicTacToe();
			break;
		case 4:
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
	std::cout << "3. Play TicTacToe" << std::endl;
	std::cout << "4. Read the rules" << std::endl;
	std::cout << "0. Exit!" << std::endl;
	ShowMoneyLeft(aWalletMoney);
	DisplayWinLose();

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
		ShowAmountOfWin(locWinMoneyOddEven);
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
					StorWinGame(win);

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
					StorWinGame(win);



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
				SubtractFromWinMoney(locWinMoneyOddEven, amountOfMoney);


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
					StorWinGame(lose);


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
	return static_cast<int>(Instruction::Exit);
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
		ShowAmountOfWin(locWinMoneyOddEven);


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

void ShowAmountOfWin(const int& aWinMoney)
{
	std::cout << "=====================================" << std::endl;
	std::cout << "amount of win " << aWinMoney << "$" << std::endl;
	std::cout << "=====================================" << std::endl;
}

void SubtractFromWinMoney(int aWinMoney, const int& amountToSubtract)
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
	bool win = true;
	bool lose = false;

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
		ShowAmountOfWin(locWinMoneyGuess);
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

					SubtractFromWinMoney(locWinMoneyGuess, amountOfMoney);

					wrongGuess = false;

					if (aWalletMoney == 0)
					{
						isPlaying = false;
						return static_cast<int>(Instruction::Exit);
					}
					else
					{
						std::cout << "you have lost!" << std::endl;
						StorWinGame(lose);

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
					StorWinGame(win);

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
		ShowAmountOfWin(locWinMoneyGuess);

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


//New
bool CheckIfReachMaxWinMoney(int aMaxWinMoney)
{
	bool isReached = aMaxWinMoney >= locMaxMoney;
	return isReached;
}

void StorWinGame(bool isWin)
{
	bool ok = true;
	while (ok)
	{
		if (isWin)
		{
			for (int i = 0; i < 5; i++)
			{
				if (CheckIfEmptyAt(historyWin[i]))
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
				if (CheckIfEmptyAt(historyWin[i]))
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
		for (int i = 4; i > 0; i--)
		{
			temp = historyWin[i - 1];
			historyWin[i - 1] = historyWin[i];
			historyWin[i] = temp;
		}
		historyWin[0] = static_cast<int>(Instruction::Empty);
	}
}

bool CheckIfEmptyAt(int anIndex)
{
	return anIndex == static_cast<int>(Instruction::Empty);
}

void DisplayWinLose()
{
	for (int i = 0; i < 5; i++)
	{
		if (historyWin[i] == 1)
		{
			std::cout << i + 1 << ": win ";
		}
		else if (historyWin[i] == 2)
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


//TicTacToe

int PlayTicTacToe()
{
	const int row = 3, column = 3;
	char array2D[3][3];
	int index = 0;


	bool isPlaying = true;
	bool firstPlayer = true;
	ShowMenu();
	index = AskForInputMenu();

	std::string player1 = "";
	std::string player2 = "";

	bool GameNotExit = true;

	if (index == 0)
	{
		GameNotExit = false;
	}
	else
	{
		system("cls");
		std::cout << "First Player Name: ";
		std::cin >> player1;


		system("cls");
		ChangeArray(array2D, ' ');
		DipslayArray(array2D);
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
					index = AskForInputGame(player1);
				}
				else
				{
					index = returnEmptyIndex();
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
					DipslayArray(array2D);
				}
				if (CheckIfWin())
				{
					if (firstPlayer)
					{
						std::cout << "the comp have Won!" << std::endl;
						isPlaying = false;
					}
					else
					{
						std::cout << player2 << " You Won!" << std::endl;
						isPlaying = false;
					}
				}
				else if (CheckIfFull())
				{
					std::cout << "The box is full" << std::endl;
					isPlaying = false;
				}
			}

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
			}
		}

		ShowMenu();
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
			std::cout << "First Player Name: ";
			std::cin >> player1;
			std::cout << "Secund Player Name: ";
			std::cin >> player2;

			system("cls");
			ChangeArray(array2D, ' ');
			DipslayArray(array2D);
			std::cout << "Type the the number of the box that you want to use:" << std::endl;
		}
	}


	return static_cast<int>(Instruction::Exit);
}

void ResetTheGame(char array[][3])
{
	for (int i = 0; i < arraySizeSpace; i++)
	{
		usedSpace[i] = 0;
	}
	ChangeArray(array, ' ');
	DipslayArray(array);
}

int AskForInputGame(std::string playerName)
{
	int index = 0;
	std::cout << playerName << " Input: ";

	index = CheckInput();
	while (index < 1 || index > arraySizeSpace)
	{
		std::cout << "Pleas Enter a number between 1 and 9 ...." << std::endl;
		std::cout << "Your Input: ";
		index = CheckInput();
	}
	return  index;
}

int EasyEnemi()
{
	int index = 0;

	index = RandomIndex();
	while (index < 1 || index > arraySizeSpace)
	{
		std::cout << "Pleas Enter a number between 1 and 9 ...." << std::endl;
		std::cout << "Your Input: ";
		index = RandomIndex();
	}
	return  index;
}

int RandomIndex()
{

	int lastIndex = arraySizeSpace - 1;
	int index = RandomNumber(1, lastIndex);
	bool isUsed = true;
	while (isUsed)
	{
		if (usedSpace[index] > 0 && usedSpace[index] < 3)
		{
			index = RandomNumber(1, lastIndex);
		}
		else
		{
			return index;
		}
	}
}

int RandomNumber(int aMin, int aMax)
{

	std::uniform_int_distribution<int> rndDist(aMin, aMax);
	int randomNr = rndDist(rndEngine);
	return randomNr;
}

int returnEmptyIndex()
{
	int RandomLoop = RandomNumber(0, 10);


	int random = 5;

	for (int i = 0; i < 5; i++)
	{
		if (!(CheckIndexIsUsed(random)))
		{
			return random;
		}
		random = RandomNumber(1, 9);
	}

	if (RandomLoop > 5)
	{
		for (int i = 1; i < arraySizeSpace + 1; i++)
		{
			if (!(CheckIndexIsUsed(i)))
			{
				return i;
			}
		}
	}
	else
	{
		for (int i = arraySizeSpace; i > 0; i--)
		{
			if (!(CheckIndexIsUsed(i)))
			{
				return i;
			}
		}
	}

}

int AskForInputMenu()
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

int CheckInput()
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

void DipslayArray(char a[][3])
{
	int boxNr = 1;

	system("cls");
	std::cout << "-----------------" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			std::cout << " | " << a[i][k];
		}
		std::cout << " | "; //last 

		//other box
		std::cout << "\t\t";
		for (int i = 0; i < 3; i++)
		{
			std::cout << " | " << boxNr;
			boxNr++;
		}
		std::cout << " | "; //last 


		std::cout << "\n-----------------" << std::endl;
	}
}

void ChangeArray(char a[][3], char letter)
{
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			a[i][k] = letter;
		}
	}
}

bool CheckIndexIsUsed(int index)
{
	bool isUsed = false;
	if (usedSpace[index - 1] == 1 || usedSpace[index - 1] == 2)
	{
		isUsed = true;
	}
	return isUsed;
}

void ChangeArrayAtLocation(char a[][3], char letter, int index, int player)
{
	int row = 0;
	int column = 0;

	switch (index)
	{
	case 1:
		row = 0;
		column = 0;
		usedSpace[index - 1] += player;

		break;
	case 2:
		row = 0;
		column = 1;
		usedSpace[index - 1] += player;

		break;
	case 3:
		row = 0;
		column = 2;
		usedSpace[index - 1] += player;
		break;
	case 4:
		row = 1;
		column = 0;
		usedSpace[index - 1] += player;
		break;
	case 5:
		row = 1;
		column = 1;
		usedSpace[index - 1] += player;
		break;
	case 6:
		row = 1;
		column = 2;
		usedSpace[index - 1] += player;
		break;
	case 7:
		row = 2;
		column = 0;
		usedSpace[index - 1] += player;
		break;
	case 8:
		row = 2;
		column = 1;
		usedSpace[index - 1] += player;
		break;
	case 9:
		row = 2;
		column = 2;
		usedSpace[index - 1] += player;
		break;
	default:
		break;
	}

	a[row][column] = letter;
}

bool CheckIfFull()
{
	bool isFull = false;
	int nrOfBoxesUsed = 0;
	for (int i = 0; i < arraySizeSpace; i++)
	{
		if (usedSpace[i] == 1 || usedSpace[i] == 2)
		{
			nrOfBoxesUsed++;
		}
	}
	if (nrOfBoxesUsed >= arraySizeSpace)
	{
		isFull = true;
	}
	return isFull;
}

bool CheckIfWin()
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

bool CheckHorisontalWin()
{
	bool isWin = false;
	int beginIndex = 0;
	int row = 3;
	for (int i = 0; i < row; i++)
	{
		if (CheckThisRow(beginIndex, playerX, 1))
		{
			isWin = true;
			break;
		}
		else if (CheckThisRow(beginIndex, playerO, 1))
		{
			isWin = true;
			break;
		}
		beginIndex += 3;
	}

	return isWin;
}

bool CheckVerticalWin()
{
	bool isWin = false;
	int beginIndex = 0;
	int column = 3;
	for (int i = 0; i < column; i++)
	{
		if (CheckThisRow(beginIndex, playerX, 3))
		{
			isWin = true;
			break;
		}
		else if (CheckThisRow(beginIndex, playerO, 3))
		{
			isWin = true;
			break;
		}
		beginIndex += 1;
	}
	return isWin;
}

bool CheckThisRow(int beginIndex, int player, int toAdd)
{
	if (usedSpace[beginIndex] == player && usedSpace[beginIndex + toAdd] == player && usedSpace[beginIndex + (toAdd * 2)] == player)
	{
		return true;
	}
	return false;
}

bool CheckCurvedLineWin()
{
	bool isWin = false;
	int line = 2;
	int secuondLine = 2; //box that begin in indix 2
	int firstLine = 0; //box that begin at index 0
	for (int i = 0; i < line; i++)
	{

		if (CheckThisRow(firstLine, playerX, 4))
		{
			isWin = true;
			break;
		}
		else if (CheckThisRow(firstLine, playerO, 4))
		{
			isWin = true;
			break;
		}
	}
	for (int i = 0; i < line; i++)
	{
		if (CheckThisRow(secuondLine, playerX, 2))
		{
			isWin = true;
			break;
		}
		else if (CheckThisRow(secuondLine, playerO, 2))
		{
			isWin = true;
			break;
		}
	}
	return isWin;
}

void ShowMenu()
{
	system("cls");
	std::cout << "================================" << std::endl;
	std::cout << "Welcome to the Tic Tac Toe Game!" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "1. Play New Game" << std::endl;
	std::cout << "0. Exit" << std::endl;
}


