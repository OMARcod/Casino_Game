#include <iostream>
#include "Play.h"

int main()
{
	int walletMoney = 1000;

	Play::Play(walletMoney);

	if (walletMoney <= 0)
	{
		std::cout << "\n ======== You lost all your money ... you can't play anymore! ======== " << std::endl;
	}
	else
	{
		std::cout << "Money left: " << walletMoney << std::endl;
		std::cout << "Goodby! " << std::endl;
	}

	std::cin.get();
}

