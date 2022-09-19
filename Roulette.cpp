#include "Roulette.h"
#include "SharedFuncitons.h"

int Roulette::Play(int& aWalletMoney, int& aTotalWin, int* aHistoryOfWinOrLose)
{
	const int maxNr = 36;

	std::uniform_int_distribution<int> rndDist(0, maxNr);

	int randomNr = 0;
	bool isPlaying = true;
	int amountOfMoney = 0;

	bool isWin = false;

	const int arrayColumnSize = 12;
	int column1[12] = { 0 };
	int column2[12] = { 0 };
	int column3[12] = { 0 };
	InistArray(column1, column2, column3, arrayColumnSize);
	DrawRoulette(column1, column2, column3, arrayColumnSize);

	while (isPlaying)
	{
		int choseNr = ChoseMenu();
		if (choseNr != static_cast<int>(Instruction::Exit))
		{
			system("cls");
			SharedFuncitons::ShowAmountOfWin(aTotalWin);
			if (aWalletMoney > 0)
			{
				amountOfMoney = SharedFuncitons::AskAmountMoney(aWalletMoney);
			}

			randomNr = rndDist(rndEngine);

			switch (choseNr)
			{
			case static_cast<int>(Game::Straight):
				system("cls");
				DrawRoulette(column1, column2, column3, arrayColumnSize);
				isWin = Straigth(randomNr);
				break;
			case static_cast<int>(Game::OddEven):
				system("cls");
				DrawRoulette(column1, column2, column3, arrayColumnSize);
				isWin = OddOrEven(randomNr);
				break;
			case  static_cast<int>(Game::Column):
				system("cls");
				DrawRoulette(column1, column2, column3, arrayColumnSize);
				isWin = ColumnBet(randomNr, column1, column2, column3, arrayColumnSize);
				break;
			case static_cast<int>(Game::Corner):
				system("cls");
				DrawRoulette(column1, column2, column3, arrayColumnSize);
				isWin = Corner(randomNr, column1, column2, column3, arrayColumnSize);
				break;
			case static_cast<int>(Game::Split):
				system("cls");
				DrawRoulette(column1, column2, column3, arrayColumnSize);
				isWin = Split(randomNr, column1, column2, column3, arrayColumnSize);
				break;
			case static_cast<int>(Game::RedBlack):
				system("cls");
				isWin = RedBlack(randomNr);
				break;
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

			if (aWalletMoney == static_cast<int>(Instruction::Empty))
			{
				isPlaying = false;
				return static_cast<int>(Instruction::Exit);
			}
			else
			{
				SharedFuncitons::StoreWinOrLose(isWin, aHistoryOfWinOrLose);
				std::cout << "============" << std::endl;
				SharedFuncitons::DisplayWinLose(aHistoryOfWinOrLose);
				std::cout << "============" << std::endl;

				std::cout << "you have lost!\t\tThe Number was: " << randomNr << std::endl;
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
			SharedFuncitons::StoreWinOrLose(isWin, aHistoryOfWinOrLose);
			std::cout << "============" << std::endl;
			SharedFuncitons::DisplayWinLose(aHistoryOfWinOrLose);
			std::cout << "==================" << std::endl;
			std::cout << "congratulatiions you guessed right\t\tThe Number was: " << randomNr << std::endl;

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
	std::cout << "1. Straight Game" << std::endl;
	std::cout << "2. Odd or Even" << std::endl;
	std::cout << "3. Column Bet" << std::endl;
	std::cout << "4. Corner Game" << std::endl;
	std::cout << "5. Split Game" << std::endl;
	std::cout << "6. Red Or Black Game" << std::endl;
	std::cout << "0. Exit" << std::endl;
	std::cout << "======================OBS======================\n" << std::endl;

	int choseNr = SharedFuncitons::ReadInputInteger();
	bool wrongInput = true;
	while (wrongInput)
	{
		switch (choseNr)
		{
		case static_cast<int>(Game::Straight):
			return choseNr;
			break;
		case static_cast<int>(Game::OddEven):
			return choseNr;
			break;
		case static_cast<int>(Game::Column):
			return choseNr;
			break;
		case static_cast<int>(Game::Corner):
			return choseNr;
			break;
		case static_cast<int>(Game::Split):
			return choseNr;
			break;
		case static_cast<int>(Game::RedBlack):
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

void Roulette::DrawRoulette(const int* aColumn1, const int* aColumn2, const  int* aColumn3, const int& aSize)
{

	for (int i = 0; i < aSize; i++)
	{
		std::cout << "---";
	}
	std::cout << std::endl;
	for (int i = 0; i < aSize; i++)
	{
		std::cout << aColumn1[i] << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < aSize; i++)
	{
		std::cout << "---";
	}
	std::cout << std::endl;
	for (int i = 0; i < aSize; i++)
	{
		std::cout << aColumn2[i] << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < aSize; i++)
	{
		std::cout << "---";
	}
	std::cout << std::endl;
	for (int i = 0; i < aSize; i++)
	{
		std::cout << aColumn3[i] << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < aSize; i++)
	{
		std::cout << "---";
	}
	std::cout << std::endl;
}

void Roulette::InistArray(int* aColumn1, int* aColumn2, int* aColumn3, const int& aSize)
{
	const int nrToAdd = 3;
	int elementNr = 3;

	for (int i = 0; i < aSize; i++)
	{
		aColumn1[i] = elementNr;
		elementNr += nrToAdd;
	}
	elementNr = 2;
	for (int i = 0; i < aSize; i++)
	{
		aColumn2[i] = elementNr;
		elementNr += nrToAdd;
	}

	elementNr = 1;
	for (int i = 0; i < aSize; i++)
	{
		aColumn3[i] = elementNr;
		elementNr += nrToAdd;
	}
}

bool Roulette::Straigth(const int& aRandomNr)
{
	const int maxNr = 36;
	bool wrongGuess = true;
	bool isWin = false;


	std::cout << "guess where the ball will land between (0 and 36)?" << std::endl;
	while (wrongGuess)
	{
		std::cout << "Your Input: ";
		int inputNr = SharedFuncitons::ReadInputInteger();
		if (inputNr > maxNr)
		{
			std::cout << "The number can't be bigger than " << maxNr << std::endl;

		}
		else if (inputNr < static_cast<int>(Instruction::Empty))
		{
			std::cout << "The number can't be lower than " << static_cast<int>(Instruction::Empty) << std::endl;
		}
		else if (aRandomNr != inputNr)
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
	return isWin;
}

bool Roulette::ColumnBet(const int& aRandomNr, const int* aColumn1, const int* aColumn2, const int* aColumn3, const int& aSize)
{
	const int maxNr = 3;
	const int minNr = 1;
	bool wrongGuess = true;
	bool isWin = false;

	std::cout << "Guess in wich collomn the ball will land" << std::endl;
	std::cout << "Which collomn you want to chose" << std::endl;
	std::cout << "chose between (1 or 2 or 3)" << std::endl;

	while (wrongGuess)
	{
		std::cout << "Your Input: ";
		int inputNr = SharedFuncitons::ReadInputInteger();
		if (inputNr > maxNr || inputNr < minNr)
		{
			std::cout << "Please chose between 1 or 2 or 3" << std::endl;
		}
		else
		{
			wrongGuess = false;
		}
		if (!wrongGuess && inputNr == 1)
		{
			for (int i = 0; i < aSize; i++)
			{
				if (aRandomNr == aColumn1[i])
				{
					isWin = true;
					return isWin;
				}
			}
		}
		else if (!wrongGuess && inputNr == 2)
		{
			for (int i = 0; i < aSize; i++)
			{
				if (aRandomNr == aColumn2[i])
				{
					isWin = true;
					return isWin;
				}
			}
		}
		else if (!wrongGuess)
		{
			for (int i = 0; i < aSize; i++)
			{
				if (aRandomNr == aColumn3[i])
				{
					isWin = true;
					return isWin;
				}
			}
		}
	}
	return isWin;
}

bool Roulette::Corner(const int& aRandomNr, const int* aColumn1, const int* aColumn2, const int* aColumn3, const int& aSize)
{
	bool wrongInput = true;
	bool isWin = false;
	const int arraySize = 4;
	int inputNr[arraySize];

	std::cout << "Type the four numbers where you think the ball will land!" << std::endl;

	while (wrongInput)
	{
		wrongInput = false;

		std::cout << "Nr 1: ";
		inputNr[0] = SharedFuncitons::ReadInputInteger();
		std::cout << "Nr 2: ";
		inputNr[1] = SharedFuncitons::ReadInputInteger();
		std::cout << "Nr 3: ";
		inputNr[2] = SharedFuncitons::ReadInputInteger();
		std::cout << "Nr 4: ";
		inputNr[3] = SharedFuncitons::ReadInputInteger();


		BubbleSort(inputNr, arraySize);

		for (int i = 0; i < arraySize; i++)
		{
			std::cout << "------";
		}
		std::cout << std::endl;

		for (int i = 0; i < arraySize; i++)
		{
			std::cout << inputNr[i] << " ";
		}
		std::cout << std::endl;

		for (int i = 0; i < arraySize; i++)
		{
			std::cout << "------";
		}
		std::cout << std::endl;

		for (int i = 0; i < aSize; i++)
		{
			if (inputNr[0] == aColumn1[i] || inputNr[0] == aColumn3[i])
			{
				for (size_t j = 0; j < aSize; j++)
				{
					if (inputNr[3] == aColumn3[j] || inputNr[0] == aColumn1[j])
					{
						wrongInput = true;
						break;
					}
				}
			}
		}
		if (!wrongInput)
		{
			if (inputNr[0] == inputNr[1] - 1)
			{
				if (inputNr[1] == inputNr[2] - 2)
				{
					if (inputNr[2] == inputNr[3] - 1)
					{
						wrongInput = false;
					}
					else
					{
						wrongInput = true;
					}
				}
				else
				{
					wrongInput = true;
				}
			}
			else
			{
				wrongInput = true;
			}
		}

		if (!wrongInput)
		{
			for (int i = 0; i < 4; i++)
			{
				if (aRandomNr == inputNr[i])
				{
					isWin = true;
					return isWin;
				}
			}
			isWin = false;
			return isWin;
		}
		if (wrongInput)
		{
			std::cout << "the order is not write pleace chose other numbers!" << std::endl;
			system("pause");
			system("cls");
			DrawRoulette(aColumn1, aColumn2, aColumn3, aSize);
		}
	}
	isWin = false;
	return isWin;
}

void Roulette::BubbleSort(int* anArray, const int anArraySize)
{
	int temp = 0;
	for (int i = 0; i < anArraySize; i++) {
		for (int j = i + 1; j < anArraySize; j++)
		{
			if (anArray[j] < anArray[i]) {
				temp = anArray[i];
				anArray[i] = anArray[j];
				anArray[j] = temp;
			}
		}
	}
}

bool Roulette::Split(const int& aRandomNr, const int* aColumn1, const int* aColumn2, const int* aColumn3, const int& aColumnSize)
{
	bool wrongInput = true;
	bool isWin = false;
	const int arraySize = 2;
	int inputNr[arraySize];

	std::cout << "Type the two numbers where you think the ball will land!" << std::endl;

	while (wrongInput)
	{
		std::cout << "Nr 1: ";
		inputNr[0] = SharedFuncitons::ReadInputInteger();
		std::cout << "Nr 2: ";
		inputNr[1] = SharedFuncitons::ReadInputInteger();



		BubbleSort(inputNr, arraySize);

		for (int i = 0; i < arraySize; i++)
		{
			std::cout << "------";
		}
		std::cout << std::endl;

		for (int i = 0; i < arraySize; i++)
		{
			std::cout << inputNr[i] << " ";
		}
		std::cout << std::endl;

		for (int i = 0; i < arraySize; i++)
		{
			std::cout << "------";
		}
		std::cout << std::endl;



		if (inputNr[0] == inputNr[1] - 1)
		{
			wrongInput = false;
			for (int i = 0; i < aColumnSize; i++)
			{
				if (inputNr[0] == aColumn1[i])
				{
					for (int j = 0; j < aColumnSize; j++)
					{
						if (inputNr[1] == aColumn3[j])
						{
							wrongInput = true;
							break;
						}
					}
					
				}
			}
		}
		else if (inputNr[0] == inputNr[1] - 3)
		{
			wrongInput = false;
		}
		else
		{
			wrongInput = true;
		}

		if (!wrongInput)
		{
			for (int i = 0; i < arraySize; i++)
			{
				if (aRandomNr == inputNr[i])
				{
					isWin = true;
					return isWin;
				}
			}
			isWin = false;
			return isWin;
		}
		if (wrongInput)
		{
			std::cout << "the order is not write pleace chose other numbers!" << std::endl;
			system("pause");
			system("cls");
			DrawRoulette(aColumn1, aColumn2, aColumn3, aColumnSize);
		}
	}
	isWin = false;
	return isWin;
}

bool Roulette::RedBlack(const int& aRandomNr)
{
	

	bool isWin = false;
	int choise;
	const int red = 0;
	const int black = 1;
	bool wrongInput = true;


	const int arraySizeRedBlack = 18;
	const int arraySizeRoullete = 36;

	int redArray[arraySizeRedBlack];
	int blackArray[arraySizeRedBlack];

	int indexRed = 0;
	int indexBlack = 0;
	for (int i = 1; i < arraySizeRoullete + 1; i++)
	{
		if (i % 2 == 0)
		{
			redArray[indexRed] = i;
			indexRed++;
		}
		else
		{
			blackArray[indexBlack] = i;
			indexBlack++;
		}
	}




	system("cls");
	DrawRedBlackNumber(redArray, blackArray, arraySizeRedBlack);
	std::cout << "Guess in which color the ball will land" << std::endl;
	std::cout << "Red Or Black?" << std::endl;
	std::cout << "0. Red" << std::endl;
	std::cout << "1. Black" << std::endl;
	std::cout << std::endl;

	choise = SharedFuncitons::ReadInputInteger();


	while (wrongInput)
	{
		if (choise >= red && choise <= black)
		{
			wrongInput = false;
			if (choise == red)
			{
				for (int i = 0; i < arraySizeRedBlack; i++)
				{
					if (aRandomNr == redArray[i])
					{
						isWin = true;
						return isWin;
					}
				}

			}
			else
			{
				for (int i = 0; i < arraySizeRedBlack; i++)
				{
					if (aRandomNr == blackArray[i])
					{
						isWin = true;
						return isWin;
					}
				}
			}
			isWin = false;
			return isWin;
		}
		else
		{
			system("cls");
			DrawRedBlackNumber(redArray, blackArray, arraySizeRedBlack);
			std::cout << "0. Red" << std::endl;
			std::cout << "1. Black" << std::endl;
			std::cout << "pleace chose 0 OR 1" << std::endl;
			std::cout << std::endl;
			choise = SharedFuncitons::ReadInputInteger();
		}
	}



	return isWin;
}

void Roulette::DrawRedBlackNumber(const int* aRedArray, const int* aBlackArray, const int& aArraySize)
{
	std::cout << "Red Numbers: " << std::endl;
	for (size_t i = 0; i < aArraySize; i++)
	{
		std::cout << aRedArray[i] << " ";
	}

	std::cout << std::endl;

	std::cout << "Black Numbers: " << std::endl;
	for (size_t i = 0; i < aArraySize; i++)
	{
		std::cout << aBlackArray[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;


}

bool Roulette::OddOrEven(const int& aRandomNr)
{
	bool isWin = false;
	bool wrongInput = true;
	int choise;
	const int odd = 1;
	const int even = 0;

	
	std::cout << "Guess if the ball will land on odd number or even number" << std::endl;
	std::cout << "Odd Or Even?" << std::endl;
	std::cout << "0. Even" << std::endl;
	std::cout << "1. Odd" << std::endl;
	std::cout << std::endl;

	choise = SharedFuncitons::ReadInputInteger();


	while (wrongInput)
	{
		if (choise >= even && choise <= odd)
		{
			wrongInput = false;
			if (choise == even)
			{
				if (aRandomNr % 2 == even)
				{
					isWin = true;
					return isWin;
				}
			}
			else
			{
				if (aRandomNr % 2 == odd)
				{
					isWin = true;
					return isWin;
				}
			}
			isWin = false;
			return isWin;
		}
		else
		{
			system("cls");
			std::cout << "Odd Or Even?" << std::endl;
			std::cout << "0. Odd" << std::endl;
			std::cout << "1. Even" << std::endl;
			std::cout << "pleace chose 0 OR 1" << std::endl;
			std::cout << std::endl;
			choise = SharedFuncitons::ReadInputInteger();
		}
	}
	return isWin;
}


