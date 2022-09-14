#pragma once
#include"SharedFuncitons.h"
#include<iostream>

namespace TicTacToe
{
	static int const globalArraySize = 9;
	static int const globalBoxSize = 3;
	static int globalUsedSpaces[globalArraySize]{ 0 };

	enum class Player
	{
		X = 1,
		O = 2,
	};


	void ChangeArray(char anArray[][3], char aLetter);
	void ChangeArrayAtLocation(char anArray[][3], char aLetter, int anIndex, int aPlayer);
	void DipslayTicTacArray(char anArray[][3]);
	int AskForInputGame(const std::string& aPlayerName);
	int AskForInputMenu();
	int CheckInput();
	bool CheckIndexIsUsed(int anIndex);
	bool CheckIfArrayIsFull();
	bool CheckIfWin();
	bool CheckHorisontalWin();
	bool CheckVerticalWin();
	bool CheckCurvedLineWin();
	bool CheckThisRow(int aStartIndex, int aPlayer, int aNrToAdd);
	void TicTacShowMenu();
	void ResetTheGame(char anArray[][3]);
	int EasyEnemi();
	int RandomNumber(int aMin, int aMax);
	int RandomIndex();
	int returnRandomEmptyIndex();
	int PlayTicTacToe(int& aWalletMoney);
};

