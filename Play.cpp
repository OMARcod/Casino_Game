#include "Play.h"

void Play::Play(int& aWalletMoney)
{

	int inputNr = 0;
	bool isPlaying = true;
	int choiceOne = 1, choiceTwo = 2, choiceThree = 3, choiceZero = 0;
	inputNr = MainMenu(aWalletMoney);

	while (isPlaying && aWalletMoney != 0)
	{
		switch (inputNr)
		{
		case 1:
			system("cls");
			inputNr = GuessGame::Menu(aWalletMoney);
			break;
		case 2:
			system("cls");
			inputNr = OddOrEven::Menu(aWalletMoney);
			break;
		case 3:
			system("cls");
			SharedFuncitons::GamesRules();
			inputNr = TicTacToe::PlayTicTacToe(aWalletMoney);
			break;
		case 4:
			system("cls");
			SharedFuncitons::GamesRules();
			inputNr = SharedFuncitons::CheckExit();
			break;
		case 0:
			isPlaying = false;
			break;

		case 5:
			inputNr = MainMenu(aWalletMoney);

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

int Play::MainMenu(int aWalletMoney)
{

	system("cls");

	std::cout << "=== Welcome To The Kasino Game =====" << std::endl;
	std::cout << std::endl;
	std::cout << "1. Play: guess game" << std::endl;
	std::cout << "2. Play: odd and even numbers" << std::endl;
	std::cout << "3. Play TicTacToe" << std::endl;
	std::cout << "4. Read the rules" << std::endl;
	std::cout << "0. Exit!" << std::endl;
	SharedFuncitons::ShowMoneyLeft(aWalletMoney);
	SharedFuncitons::DisplayWinLose();


	int inputNr = SharedFuncitons::ReadInputInteger();

	return inputNr;
}


