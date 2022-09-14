#pragma once
#include"SharedFuncitons.h"
#include<iostream>

namespace TicTacToe
{
	static int const globalArraySize = 9;

	enum class Player
	{
		X = 1,
		O = 2,
		BoxSize = 3,
	};

	int Play(int& aWalletMoney, int* aHistoryOfWinOrLose);
	void ResetTheGame(char anArray[][3],int *aUsedSpace);
	int AskForInputGame(const std::string& aPlayerName);
	int RandomNumber(int aMin, int aMax);
	int returnRandomEmptyIndex(const int* aUsedSpace);
	int AskForInputMenu();
	int CheckInput();
	void DipslayTicTacArray(char anArray[][3]);
	void ChangeArray(char anArray[][3], char aLetter);
	bool CheckIndexIsUsed(int anIndex, const int* aUsedSpace);
	void ChangeArrayAtLocation(char anArray[][3], char aLetter, int anIndex, int aPlayer, int* aUsedSpace);
	bool CheckIfArrayIsFull(const int* aUsedSpace);
	bool CheckIfWin(const int* aUsedSpace);
	bool CheckHorisontalWin(const int* aUsedSpace);
	bool CheckVerticalWin(const int* aUsedSpace);
	bool CheckThisRow(int aStartIndex, int aPlayer, int aNrToAdd, const  int *aUsedSpace);
	bool CheckCurvedLineWin(const int* aUsedSpace);
	void TicTacShowMenu(const int& aTotalWin, int* aHistoryOfWinOrLose);
};

