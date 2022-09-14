#pragma once
#include "SharedFuncitons.h"
namespace GuessTheNrGame
{
	int Play(int& aWalletMoney, int& aTotalWinGuess, int* aHistoryOfWinAndLose);
	int Menu(int& aWalletMoney, int* aHistoryOfWinAndLose);
};	

