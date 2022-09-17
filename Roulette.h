#pragma once
namespace Roulette
{
	int Play(int& aWalletMoney, int& aTotalWin, int* aHistoryOfWinAndLose);
	int Menu(int& aWalletMoney, int* aHistoryOfWinAndLose);
	int ChoseMenu(); //new
	void DrawRoulette(const int* aColumn1,const int* aColumn2,const  int* aColumn3,const int &aSize);
	void InistArray(int *aColumn1,int *aColumn2,int *aColumn3,const int &aSize);
	bool Straigth(const int& aRandomNr);
	bool ColumnBet(const int &aRandomNr,const int* aColumn1,const int* aColumn2, const int* aColumn3,const int& aSize);
	bool Corner(const int& aRandomNr, const int* aColumn1, const int* aColumn2, const int* aColumn3, const int& aSize);
	void BubbleSort(int* anArray, const int anArraySize);
};


