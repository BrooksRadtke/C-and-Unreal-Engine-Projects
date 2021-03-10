// GuessMyNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Initial number is random
// Ask user to enter a guess
// Give feedback if they guessed too high, low or correct
// Continue until they get the answer correct
int main()
{
    int iSecret, iGuess;

    // Initialize random seed
    srand(time(NULL));

    // Generate secret number between 1 and 10
    iSecret = rand() % 10 + 1;

    do
    {
        printf("Guess the number that is between 1 and 10: ");
        scanf_s("%d", &iGuess);
        if (iSecret < iGuess) puts("The secret number is lower");
        else if (iSecret > iGuess) puts("The secret number is higher");
    }         
    while (iSecret != iGuess);

    puts("You found the secret number!");
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
