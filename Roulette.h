#pragma once
namespace Roulette
{
	int Play(int& aWalletMoney, int& aTotalWin, int* aHistoryOfWinAndLose);
	int Menu(int& aWalletMoney, int* aHistoryOfWinAndLose);
	int ChoseMenu();
	void DrawRoulette(const int* aColumn1, const int* aColumn2, const  int* aColumn3, const int& aSize);
	void InistArray(int* aColumn1, int* aColumn2, int* aColumn3, const int& aSize);
	bool Straigth(const int& aRandomNr);
	bool ColumnBet(const int& aRandomNr, const int* aColumn1, const int* aColumn2, const int* aColumn3, const int& aSize);
	bool Corner(const int& aRandomNr, const int* aColumn1, const int* aColumn2, const int* aColumn3, const int& aSize);
	void BubbleSort(int* anArray, const int anArraySize);
	bool Split(const int& aRandomNr, const int* aColumn1, const int* aColumn2, const int* aColumn3, const int& aSize);
	bool RedBlack(const int& aRandomNr);
	void DrawRedBlackNumber(const int* aRedArray,const int* aBlackArray, const int& aArraySize);
	bool OddOrEven(const int& aRandomNr);

};


//use Enumns 
	//in Menu 
	//in numbers
//Delete all hard coded values .. and make constant values instade

//