// Author: Mikhail Terentev
// Instructor: Dave Harden
// Class CS 110B Programming Fundamentals: C++
// Name of file: a2_1.cpp
// Assignment 2.1 (Loops Review)


/* Write a program that asks the user to enter a date in the format specified above(month / day / 2 - digit - year).
The program should then determine whether the month times the day is equal to the year.
If so, it should display a message saying the date is magic.Otherwise it should display a message saying the date is not magic. */

#include <iostream>
using namespace std;

int main()
{
    bool play = true;

    // Game loop:
    while (play)
    {
        // Variables
        int card1;
        int card2;
        int sum;    // total sum

        // Random number generation 1-10
        card1 = rand() % 10 + 1;
        card2 = rand() % 10 + 1;
        cout << "First cards: " << card1 << ", " << card2 << endl;
        sum = card1 + card2;
        cout << "Total: " << sum << endl;

        bool responseUser;      // for "Would you like to play again?"
        bool gameFinished;      // condition of game
        responseUser = false;
        gameFinished = false;
        char response;          // user's input

        // Loop if continue playing:
        while (!gameFinished)
        {
            responseUser = false;

            while (!responseUser)
            {
                cout << "Do you want another card?  (y/n): ";
                cin >> response;
                responseUser = (response == 'y') || (response == 'n');
            }

            if (response == 'y')
            {
                int card = rand() % 10 + 1;
                cout << "Card: " << card << endl;
                sum += card;
                cout << "Total: " << sum << endl;

                if (sum > 21)
                {
                    cout << "Bust!" << endl;                // if gaymer got more than 21 in sum
                    gameFinished = true;
                 }
                else if (sum == 21)
                {
                    cout << "Congratulations!" << endl;     // if gaymer got 21 in sum
                    gameFinished = true;
                }
            }
            else
            {
                gameFinished = true;    // game over
            }

        }

        // Game over:
        responseUser = false;

        while (!responseUser)
        {
            cout << "Would you like to play again? (y/n): ";
            cin >> response;
            responseUser = (response == 'y') || (response == 'n');
        }

        play = (response == 'y');  // play again -> go to begin game loop
    }
}

/*
Output:

First cards: 2, 8
Total: 10
Do you want another card?  (y/n): y
Card: 5
Total: 15
Do you want another card?  (y/n): y
Card: 1
Total: 16
Do you want another card?  (y/n): y
Card: 10
Total: 26
Bust!
Would you like to play again? (y/n): y
First cards: 5, 9
Total: 14
Do you want another card?  (y/n): y
Card: 9
Total: 23
Bust!
Would you like to play again? (y/n): y
First cards: 3, 5
Total: 8
Do you want another card?  (y/n): y
Card: 6
Total: 14
Do you want another card?  (y/n): y
Card: 6
Total: 20
Do you want another card?  (y/n): y
Card: 2
Total: 22
Bust!
Would you like to play again? (y/n): y
First cards: 8, 2
Total: 10
Do you want another card?  (y/n): y
Card: 2
Total: 12
Do you want another card?  (y/n): y
Card: 6
Total: 18
Do you want another card?  (y/n): y
Card: 3
Total: 21
Congratulations!
Would you like to play again? (y/n): n

C:\Users\mnter\source\repos\a2_1\Debug\a2_1.exe (process 16156) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/
