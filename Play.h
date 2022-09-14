#pragma once
#include "TicTacToe.h"
#include "GuessGame.h"
#include "OddOrEven.h"




namespace Play
{
	int MainMenu(int aWalletMoney,const int *aHistoryOfWinOrLose);
	void Play(int& aWalletMoney);
};

