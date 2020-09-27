#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty << " secure server room...\n";
    std::cout << "Enter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int Sum = CodeA + CodeB + CodeC;
    const int Product = CodeA * CodeB * CodeC;

    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code \n";
    std::cout << "+ The codes add up to: " << Sum << std::endl;
    std::cout << "+ The codes multiply to give: " << Product << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;
    const bool bSuccessfulGuess = Sum == GuessSum && Product == GuessProduct;

    if (bSuccessfulGuess)
    {
        std::cout << "\n** Congratulations! You have extracted the file. **\n";
    }
    else
    {
        std::cout << "\n** Sorry! You have failed extracting the file. **\n";
    }

    return (bSuccessfulGuess);
}

int main()
{
    srand(time(NULL)); //create a new random sequence based on time of day

    const int MaxDifficulty = 5;
    int LevelDifficulty = 1;

    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }

    std::cout << "\nCongratulations! You have extracted all the files!\n";
    return 0;
}