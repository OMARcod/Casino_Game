#pragma once

#include <iostream>
#include <random>
static std::random_device seed;
static std::mt19937 rndEngine(seed());



static const int globalMaxMoney = 5000;
static int globalTotalWinMoneyGuess = 0;
static int globalTotalWinMoneyOddEven = 0;
static int globalTotalWinMoneyTicTac = 0;
static const int globalArraySize = 5;
static int globalHistoryOfWinAndLose[globalArraySize] = { 0 };

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
	void StoreWinOrLose(bool aWinOrLose);
	bool CheckIfReachMaxWinMoney(int aMaxWinMoney);
	void SubtractFromWinMoney(int aWinMoney, const int& anAmountToSubtract);
	void ShowAmountOfWin(const int& aWinMoney);
	void DisplayWinLose();
	void DisplayYouCantPlay();
	void GamesRules();
	bool CheckIfEmptyAt(int anIndex);
	int CheckExit();

};

