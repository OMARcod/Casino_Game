#include "Play.h"
#include "SharedFuncitons.h"
void Play::Play(int& aWalletMoney)
{
	
	int inputNr = 0;
	bool isPlaying = true;
	int choiceOne = 1, choiceTwo = 2, choiceThree = 3, choiceZero = 0;

	static int historyOfWinAndLose[globalArraySize] = { 0 };

	inputNr = MainMenu(aWalletMoney, historyOfWinAndLose);

	while (isPlaying && aWalletMoney != 0)
	{
		switch (inputNr)
		{
		case 1:
			system("cls");
			inputNr = GuessGame::Menu(aWalletMoney, historyOfWinAndLose);
			break;
		case 2:
			system("cls");
			inputNr = OddOrEven::Menu(aWalletMoney, historyOfWinAndLose);
			break;
		case 3:
			system("cls");
			SharedFuncitons::GamesRules();
			inputNr = TicTacToe::Play(aWalletMoney, historyOfWinAndLose);
			break;
		case 4:
			system("cls");
			SharedFuncitons::GamesRules();
			inputNr = GuessTheNrGame::Menu(aWalletMoney, historyOfWinAndLose);
			break;
		case 5:
			system("cls");
			SharedFuncitons::GamesRules();
			inputNr = Roulette::Menu(aWalletMoney, historyOfWinAndLose);
			break;
		case 6:
			system("cls");
			SharedFuncitons::GamesRules();
			inputNr = SharedFuncitons::CheckExit();
			break;
		case 0:
			isPlaying = false;
			break;

		case 7:
			inputNr = MainMenu(aWalletMoney, historyOfWinAndLose);

			break;
		default:
			bool wrongInput = true;
			while (wrongInput)
			{
				std::cout << "pleas chose one of the option" << std::endl;
				inputNr = SharedFuncitons::ReadInputInteger();
				if (inputNr == choiceZero || inputNr == choiceOne || inputNr == choiceTwo || inputNr == choiceThree)
				{
					wrongInput = false;
				}
			}
			break;
		}

	}
}

int Play::MainMenu(int aWalletMoney,const int *aHistoryOfWinOrLose)
{

	system("cls");

	std::cout << "=== Welcome To The Kasino Game =====" << std::endl;
	std::cout << std::endl;
	std::cout << "1. Play: Guess The sum" << std::endl;
	std::cout << "2. Play: odd and even numbers" << std::endl;
	std::cout << "3. Play TicTacToe" << std::endl;
	std::cout << "4. Play Guess between 1 and 100" << std::endl;
	std::cout << "5. Play Roulette Game" << std::endl;
	std::cout << "6. Read the rules" << std::endl;
	std::cout << "0. Exit!" << std::endl;
	SharedFuncitons::ShowMoneyLeft(aWalletMoney);
	SharedFuncitons::DisplayWinLose(aHistoryOfWinOrLose);


	int inputNr = SharedFuncitons::ReadInputInteger();

	return inputNr;
}


