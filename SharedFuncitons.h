#pragma once

#include <iostream>
#include <random>
static std::random_device seed;
static std::mt19937 rndEngine(seed());

static const int globalArraySize = 5;

enum class Instruction
{
	Exit = 5,
	Win = 1,
	Lose = 2,
	Empty = 0,
};


namespace SharedFuncitons
{
	int ReadInputInteger();
	char ReadInputChar();
	int AskAmountMoney(int aWalletMoney);
	void ShowMoneyLeft(int aWalletMoney);
	void MoneyMath(int& aWalletMoney, int someAmountOfMoney);
	void StoreWinOrLose(bool aWinOrLose, int* aHistoryOfWinOrLose);
	bool CheckIfReachMaxWinMoney(const int aMaxWinMoney);
	void SubtractFromWinMoney(int& aWinMoney, const int& anAmountToSubtract);
	void ShowAmountOfWin(const int& aWinMoney);
	void DisplayWinLose(const int* aHistoryOfWinOrLose);
	void DisplayYouCantPlay();
	void GamesRules();
	bool CheckIfEmptyAt(int anIndex);
	int CheckExit();
};

