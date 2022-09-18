#include "Roulette.h"
#include "SharedFuncitons.h"

int Roulette::Play(int& aWalletMoney, int& aTotalWin, int* aHistoryOfWinOrLose)
{
	int const maxNr = 36;

	std::uniform_int_distribution<int> rndDist(0, maxNr);

	int randomNr = 0;
	bool isPlaying = true;
	int amountOfMoney = 0;
	int even = 0;

	bool isWin = false;

	int const arrayColumnSize = 12;
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

			if (choseNr == 1)
			{
				system("cls");
				DrawRoulette(column1, column2, column3, arrayColumnSize);
				isWin = Straigth(randomNr);
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
			else if (choseNr == 4)
			{
				system("cls");
				DrawRoulette(column1, column2, column3, arrayColumnSize);
				isWin = ColumnBet(randomNr, column1, column2, column3, arrayColumnSize);
			}
			else if (choseNr == 5)
			{
				system("cls");
				DrawRoulette(column1, column2, column3, arrayColumnSize);
				isWin = Corner(randomNr, column1, column2, column3, arrayColumnSize);
			}
			else if (choseNr == 6)
			{
				system("cls");
				DrawRoulette(column1, column2, column3, arrayColumnSize);
				isWin = Split(randomNr, column1, column2, column3, arrayColumnSize);
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
				SharedFuncitons::StoreWinOrLose(isWin, aHistoryOfWinOrLose);
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
			SharedFuncitons::StoreWinOrLose(isWin, aHistoryOfWinOrLose);

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
			std::cout << "==== Roulette Game ====" << std::endl;
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
	std::cout << "1. You can guess where the ball will land between (0 and 36)" << std::endl;
	std::cout << "2. You guess if the ball will land on odd number" << std::endl;
	std::cout << "3. You guess if the ball will land on even number" << std::endl;
	std::cout << "4. Guess in wich collomn the ball will land" << std::endl;
	std::cout << "5. Corner Game" << std::endl;
	std::cout << "6. Split Game" << std::endl;
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
		case 4:
			return choseNr;
			break;
		case 5:
			return choseNr;
			break;
		case 6:
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
	//New

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
	//New

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
	//New
	for (int i = 0; i < aSize; i++)
	{
		std::cout << "---";
	}
	std::cout << std::endl;


}

void Roulette::InistArray(int* aColumn1, int* aColumn2, int* aColumn3, const int& aSize)
{
	int nrToAdd = 3;

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
	bool wrongGuess = true;
	int maxNr = 36;
	bool isWin = false;

	std::cout << "guess the where the ball will land form 0 to 36?" << std::endl;
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
	bool wrongGuess = true;
	int maxNr = 3;
	int choise = 1;
	bool isWin = false;

	std::cout << "Which collomnt you want to chose" << std::endl;
	std::cout << "chose between (1 or 2 or 3)" << std::endl;

	while (wrongGuess)
	{
		std::cout << "Your Input: ";
		int inputNr = SharedFuncitons::ReadInputInteger();
		if (inputNr > maxNr || inputNr < choise)
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
	int maxNr = 36;
	int choise = 1;
	bool isWin = false;
	const int arraySize = 4;
	int inputNr[arraySize];

	std::cout << "Type the four numbers where you think the ball will land!\t\t" << aRandomNr << std::endl;

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

		int temp = 0;

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
	int maxNr = 36;
	int choise = 1;
	bool isWin = false;
	const int arraySize = 2;
	int inputNr[arraySize];

	std::cout << "Type the four numbers where you think the ball will land!\t\t" << aRandomNr << std::endl;

	while (wrongInput)
	{
		std::cout << "Nr 1: ";
		inputNr[0] = SharedFuncitons::ReadInputInteger();
		std::cout << "Nr 2: ";
		inputNr[1] = SharedFuncitons::ReadInputInteger();


		int temp = 0;

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
				if (inputNr[0] == aColumn3[i])
				{
					if (inputNr[1] == aColumn1[i])
					{
						wrongInput = true;
						break;
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
//		the number 1 should not be from collomn 1 and 2 from 2 
//		and 2 from 1 and 1 from 2
// 
	//Red/Black
// 
//
// 
// 
//