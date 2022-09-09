#include <iostream>
#include <random>

std::random_device seed;
std::mt19937 rndEngine(seed());

void GamesRules();
int CheckExit();
int ReadInputInteger();
char ReadInputChar();
int GuessGame(int& aWalletMoney);
void ShowMoneyLeft(int aWalletMoney);
int ShowMenu(int aWalletMoney);
int AskAmountMoney(int aWalletMoney);
int PlayOddAndEven(int& aWalletMoney);
int OddAndEvenGameMenu(int& aWalletMoney);
void Play(int& aWalletMoney);
int GuessGameMenu(int& aWalletMoney);
enum class Instructions
{
    Exit = 5,
};


int main()
{
    int walletMoney = 1000;

    Play(walletMoney);

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

void Play(int& aWalletMoney)
{

    int inputNr = 0;
    bool okInput = true;
    bool isPlaying = true;
    int amountOfMoney = 0;
    int choiceOne = 1, choiceTwo = 2, choiceThree = 3, choiceZero = 0;
    inputNr = ShowMenu(aWalletMoney);

    while (isPlaying && aWalletMoney != 0)
    {
        switch (inputNr)
        {
        case 1:
            system("cls");
            inputNr = GuessGameMenu(aWalletMoney);
            break;
        case 2:
            system("cls");
            inputNr = OddAndEvenGameMenu(aWalletMoney);
            break;
        case 3:
            system("cls");
            GamesRules();
            inputNr = CheckExit(); 
            break;
        case 0:
            isPlaying = false;
            break;

        case 5:
            inputNr = ShowMenu(aWalletMoney);

            break;
        default:
            bool wrongInput = true;
            while (wrongInput)
            {
                std::cout << "pleas chose one of the option" << std::endl;
                inputNr = ReadInputInteger();
                if (inputNr == choiceZero || inputNr == choiceOne || inputNr == choiceTwo || inputNr == choiceThree)
                {
                    wrongInput = false;
                }
            }
            break;
        }

    }
}

int ShowMenu(int aWalletMoney)
{

    system("cls");

    std::cout << "=== Welcome To The Kasino Game =====" << std::endl;
    std::cout << std::endl;
    std::cout << "1. Play: guess game" << std::endl;
    std::cout << "2. Play: odd and even numbers" << std::endl;
    std::cout << "3. Read the rules" << std::endl;
    std::cout << "0. Exit!" << std::endl;
    ShowMoneyLeft(aWalletMoney);
    int inputNr = ReadInputInteger();

    return inputNr;
}
int AskAmountMoney(int aWalletMoney)
{
    std::cout << "How much money you want to play with? .. You Have: " << aWalletMoney << " $" << std::endl;
    int inputNr = 0;
    bool wrongInput = true;
    while (wrongInput)
    {
        std::cout << "Your Input: ";
        inputNr = ReadInputInteger();
        if (inputNr > aWalletMoney)
        {
            std::cout << "chose other amount you don't have enough money" << std::endl;
        }
        else if (inputNr < 0)
        {
            std::cout << "NOT VALID! chose other amount" << std::endl;
        }
        else if (inputNr > 0 && inputNr <= aWalletMoney)
        {
            wrongInput = false;
        }
        if (inputNr == aWalletMoney)
        {
            std::cout << "Warrning you now have used all your money" << std::endl;
        }
    }

    return inputNr;
}

int PlayOddAndEven(int& aWalletMoney)
{
    std::uniform_int_distribution<int> rndDist(1, 6);

    int dice1 = 0;
    int dice2 = 0;
    int inputNr = 0;
    int result = 0;

    bool wrongGuess = true;
    bool isPlaying = true;

    int amountOfMoney = 0;
    std::cout << "======================OBS======================" << std::endl;

    std::cout << "if the two dices is odd and you chose odd you win!" << std::endl;
    std::cout << "if the two dices is even and you chose even you win!" << std::endl;
    std::cout << "else you lose!" << std::endl;
    std::cout << "======================OBS======================\n" << std::endl;

    while (isPlaying && aWalletMoney != 0)
    {
        wrongGuess = true;
        dice1 = rndDist(rndEngine);
        dice2 = rndDist(rndEngine);

        int tempDice1 = dice1;
        int tempDice2 = dice2;
        dice1 = (dice1 % 2);
        dice2 = (dice2 % 2);
        int even = 0;
        int odd = 1;

        if (aWalletMoney > 0)
        {

            amountOfMoney = AskAmountMoney(aWalletMoney);

        }

        std::cout << "I have thrown 2 dices!  ";
        std::cout << "What do want to chose? odd or even" << std::endl;
        std::cout << std::endl;
        std::cout << "1. odd" << std::endl;
        std::cout << "0. even" << std::endl;
        std::cout << "=======================================" << std::endl;

        std::cout << "Your Input: ";


        while (wrongGuess)
        {
            inputNr = ReadInputInteger();

            if (inputNr == odd && dice1 == odd && dice2 == odd)
            {
                system("cls");
                //add the win money to the wallet
                int winMoney = (amountOfMoney * 3);
                aWalletMoney += winMoney;
                ShowMoneyLeft(aWalletMoney);

                std::cout << "dice1:  " << tempDice1 << "  ||   dice2: " << tempDice2 << std::endl;

                std::cout << "congratulatiions you guessed right" << std::endl;
                wrongGuess = false;



                std::cout << "Do you want to play one more time ? y/n" << std::endl;


                if (ReadInputChar() == 'n')
                {
                    isPlaying = false;
                    return static_cast<int>(Instructions::Exit); //exit to the menue
                }
                else
                {
                    system("cls");
                }
            }
            else if (inputNr == even && dice1 == even && dice2 == even)
            {
                system("cls");

                //add the win money to the wallet
                int winMoney = (amountOfMoney * 3);
                aWalletMoney += winMoney;
                ShowMoneyLeft(aWalletMoney);

                std::cout << "dice1:  " << tempDice1 << "  ||   dice2: " << tempDice2 << std::endl;


                std::cout << "congratulatiions you guessed right" << std::endl;
                wrongGuess = false;


                std::cout << "Do you want to play one more time ? y/n" << std::endl;


                if (ReadInputChar() == 'n')
                {
                    isPlaying = false;
                    return static_cast<int>(Instructions::Exit); //exit to the menu
                }
                else
                {
                    system("cls");
                }
            }
            else if (inputNr == odd || inputNr == even)
            {
                system("cls");

                int lossMoney = amountOfMoney;
                aWalletMoney -= lossMoney;
                ShowMoneyLeft(aWalletMoney);
                wrongGuess = false;

                if (aWalletMoney == 0)
                {
                    isPlaying = false;
                    return static_cast<int>(Instructions::Exit); //exit to the menu
                }
                else
                {
                    std::cout << "dice1:  " << tempDice1 << "  ||   dice2: " << tempDice2 << std::endl;

                    std::cout << "you have lost!" << std::endl;
                    std::cout << "Do you want to play one more time ? y/n" << std::endl;

                    if (ReadInputChar() == 'n')
                    {
                        isPlaying = false;
                        return static_cast<int>(Instructions::Exit); //exit to the menu
                    }
                    else
                    {
                        system("cls");
                    }
                }
            }
            else
            {
                std::cout << "Please Enter 1. even or 0. odd " << std::endl;
            }


        }//end of while (wrongGuess)


    }
}
int OddAndEvenGameMenu(int& aWalletMoney)
{
    bool isPlaying = true;
    int inputNr = 0;

    while (isPlaying && aWalletMoney != 0)
    {
        system("cls");
        std::cout << "==== Odd and even Game ====" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Play" << std::endl;
        std::cout << "2. Read the rules" << std::endl;
        std::cout << "0. Exit!" << std::endl;
        inputNr = ReadInputInteger();

        switch (inputNr)
        {
        case 1:
            system("cls");
            PlayOddAndEven(aWalletMoney);
            break;

        case 2:
            system("cls");
            GamesRules();
            inputNr = CheckExit();
            break;

        case 0:
            isPlaying = false;
            break;
        case 5:
            system("cls");
            std::cout << "==== Odd and even Game ====" << std::endl;
            std::cout << std::endl;
            std::cout << "1. Play" << std::endl;
            std::cout << "2. Read the rules" << std::endl;
            std::cout << "0. Exit!" << std::endl;
            inputNr = ReadInputInteger();
            break;

        default:
            bool wrongInput = true;
            while (wrongInput)
            {
                std::cout << "pleas chose one of the option" << std::endl;
                int inputNr = ReadInputInteger();
                if (inputNr == 0 || inputNr == 1 || inputNr == 2)
                {
                    wrongInput = false;
                }
            }
            break;
        }
    }
    return static_cast<int>(Instructions::Exit);
}
void GamesRules()
{
    std::cout << "==== The Rules =====" << std::endl;
    std::cout << std::endl;
    std::cout << ">> You have only 1000$ in your account" << std::endl;
    std::cout << ">> If you lose the 1000$ then you will be kicked out of the casino" << std::endl;
    std::cout << ">> If you win in the Odd and even game you get 3x the money you chose to play with" << std::endl;
    std::cout << ">> If you win in the Guess Game you get 2x the money you chose to play with" << std::endl;
    std::cout << ">> Good luck .. Exit to go back to the menu" << std::endl;
    std::cout << "0. Exit!" << std::endl;
}
int CheckExit()
{
    int inputNr = ReadInputInteger();
    bool wrongInput = true;
    while (wrongInput)
    {
        switch (inputNr)
        {
        case 0:
            wrongInput = false;
            break;
        default:
            std::cout << "Enter 0 to exit" << std::endl;
            inputNr = ReadInputInteger();
            break;
        }
    }
    return static_cast<int>(Instructions::Exit); //return to menue
}
void ShowMoneyLeft(int aWalletMoney)
{

    std::cout << "====================" << std::endl;
    std::cout << "Money left: " << aWalletMoney << std::endl;
    std::cout << "====================" << std::endl;
}
int ReadInputInteger()
{
    bool okInput = true;
    int inputNr = 0;

    while (okInput)
    {
        std::cin >> inputNr;


        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Type an INTEGER!" << std::endl;
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            okInput = false;
        }
    }
    return inputNr;
}
char ReadInputChar()
{
    bool okInput = true;
    char inputChar = 'e';


    while (okInput)
    {
        std::cin >> inputChar;

        if (inputChar == 'y' || inputChar == 'n')
        {
            okInput = false;
        }
        else
        {
            std::cout << "your input is worng! .. y/n ?" << std::endl;
        }
    }
    return inputChar;
}

int GuessGame(int& aWalletMoney)
{
    std::uniform_int_distribution<int> rndDist(1, 6);

    int const nrOfTryAllowed = 3;
    int const maxSum = 12;


    int dice1 = 0;
    int dice2 = 0;
    int inputNr = 0;
    int sumOfDices = 0;
    int nrOfTry = nrOfTryAllowed;
    bool wrongGuess = true;
    bool isPlaying = true;

    int amountOfMoney = 0;

    std::cout << "======================OBS======================" << std::endl;
    std::cout << "if the sum of the two dice is not equal your answer you will lose" << std::endl;
    std::cout << "if you the sum is equal then you get 2x the money you put" << std::endl;
    std::cout << "======================OBS======================\n" << std::endl;

    while (isPlaying)
    {
        wrongGuess = true;
        dice1 = rndDist(rndEngine);
        dice2 = rndDist(rndEngine);
        sumOfDices = dice1 + dice2;

        if (aWalletMoney > 0)
        {
            amountOfMoney = AskAmountMoney(aWalletMoney);
        }

        std::cout << "I have thrown 2 dices!  ";
        std::cout << "guess the sum of the two dices ? "<< std::endl;

        std::cout << "Your Input: ";

        while (wrongGuess)
        {
            inputNr = ReadInputInteger();
            if (inputNr > maxSum)
            {
                std::cout << "The number can't be bigger than " << maxSum << std::endl;
                std::cout << "Your Input: ";

            }
            else
            {
                if (nrOfTry <= 0)
                {
                    system("cls");

                    int lossMoney = amountOfMoney;
                    aWalletMoney -= lossMoney;
                    ShowMoneyLeft(aWalletMoney);
                    wrongGuess = false;

                    if (aWalletMoney == 0)
                    {
                        isPlaying = false;
                        return static_cast<int>(Instructions::Exit); //exit to the menue
                    }
                    else
                    {
                        std::cout << "you have lost!" << std::endl;
                        std::cout << "Do you want to play one more time ? y/n" << std::endl;

                        if (ReadInputChar() == 'n')
                        {
                            isPlaying = false;
                            return static_cast<int>(Instructions::Exit); //exit to the menue
                        }
                        else
                        {
                            nrOfTry = nrOfTryAllowed;
                            system("cls");
                        }
                    }

                }
                if (inputNr > sumOfDices)
                {
                    nrOfTry--;

                    std::cout << "==================" << std::endl;
                    std::cout << "less" << "                           ||Try left:" << nrOfTry << std::endl;

                    std::cout << "Your Input: ";
                }
                else if (inputNr < sumOfDices)
                {
                    nrOfTry--;

                    std::cout << "==================" << std::endl;
                    std::cout << "greater" << "                          ||Try left:" << nrOfTry << std::endl;

                    std::cout << "Your Input: ";

                }
                else
                {
                    system("cls");
                    std::cout << "==================" << std::endl;
                    std::cout << "congratulatiions you guessed right" << std::endl;
                    wrongGuess = false;

                    int winMoney = (amountOfMoney * 2);
                    aWalletMoney += winMoney;
                    ShowMoneyLeft(aWalletMoney);

                    std::cout << "Do you want to play one more time ? y/n" << std::endl;

                    if (ReadInputChar() == 'n')
                    {
                        isPlaying = false;
                        return static_cast<int>(Instructions::Exit); //exit to the menue
                    }
                    else
                    {
                        nrOfTry = nrOfTryAllowed;
                        system("cls");
                    }
                }

            } //end of if (inputNr > 12)
        }//end of while (wrongGuess)
    }//end of  while (isPlaying)

}
int GuessGameMenu(int& aWalletMoney)
{
    bool isPlaying = true;
    int inputNr = 0;

    while (isPlaying && aWalletMoney != 0)
    {
        system("cls");
        std::cout << "==== Guess Game ====" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Play" << std::endl;
        std::cout << "2. Read the rules" << std::endl;
        std::cout << "0. Exit!" << std::endl;
        inputNr = ReadInputInteger();

        switch (inputNr)
        {
        case 1:
            system("cls");
            GuessGame(aWalletMoney);
            break;

        case 2:
            system("cls");
            GamesRules();
            inputNr = CheckExit();
            break;

        case 0:
            isPlaying = false;
            break;

        case 5:
            system("cls");
            std::cout << "==== Guess Game ====" << std::endl;
            std::cout << std::endl;
            std::cout << "1. Play" << std::endl;
            std::cout << "2. Read the rules" << std::endl;
            std::cout << "0. Exit!" << std::endl;
            inputNr = ReadInputInteger();
            break;

        default:
            bool wrongInput = true;
            while (wrongInput)
            {
                std::cout << "pleas chose one of the option" << std::endl;
                int inputNr = ReadInputInteger();
                if (inputNr == 0 || inputNr == 1 || inputNr == 2)
                {
                    wrongInput = false;
                }
            }
            break;
        }
    }
    return static_cast<int>(Instructions::Exit);
}