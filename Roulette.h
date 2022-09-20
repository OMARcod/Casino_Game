#pragma once
namespace Roulette
{
	int Play(int& aWalletMoney, int& aTotalWin, int* aHistoryOfWinAndLose);
	int Menu(int& aWalletMoney, int* aHistoryOfWinAndLose);
	int ChoseMenu(const int* aHistoryOfWinAndLose);

	void DrawRoulette(const int* aColumn1, const int* aColumn2, const  int* aColumn3, const int& aColumnSize);
	void InistArray(int* aColumn1, int* aColumn2, int* aColumn3, const int& aColumnSize);
	bool Straigth(const int& aRandomNr);
	bool ColumnBet(const int& aRandomNr, const int* aColumn1, const int* aColumn2, const int* aColumn3, const int& aColumnSize);
	bool Corner(const int& aRandomNr, const int* aColumn1, const int* aColumn2, const int* aColumn3, const int& aColumnSize);
	void BubbleSort(int* anArray, const int anArraySize);
	bool Split(const int& aRandomNr, const int* aColumn1, const int* aColumn2, const int* aColumn3, const int& aColumnSize);
	bool RedBlack(const int& aRandomNr);
	void DrawRedBlackNumber(const int* aRedArray,const int* aBlackArray, const int& aArraySize);
	bool OddOrEven(const int& aRandomNr);

	enum class Game
	{
		Straight = 1,
		OddEven,
		Column,
		Corner,
		Split,
		RedBlack,
	};

};
