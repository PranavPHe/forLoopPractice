// Pranav Pramod
// 11/5/2024
// Extra: Day Counter

// Imports
#include <iostream>
#include <string>
#include <random>
using namespace std;

int main()
{
    // Exercise 1:
    // Array of weeks and quotes
    string quotes[7];
    string DoW[7] = {"Monday", "Teusday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    // Getting input for each day
    for (int i = 0; i < 7; i++)
    {
        cout << DoW[i] << "\nEnter Quote: " << endl;
        getline(cin, quotes[i]);
    }
    printf("\n");
    // Printing the quotes at the end
    for (int i = 0; i < 7; i++)
    {
        cout << quotes[i] << endl;
    }

    // Exercise 2:
    int energy = 5;
    int supplies = 0;
    int day = 0;

    // Runs while there is energy and the supplies is not at 10
    while (energy > 0 && supplies < 10)
    {
        int choice;
        day++;
        // Creates a day counter (Extra)
        cout << "\nDay " << day << ":" << endl;

        // Asks the user to enter 1 or 2
        cout << "1. Search for supplies (costs 1 energy, adds 1 supply)\n2. Rest(restores 2 energy, but doesn’t add supplies)" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            // If they enter 1, subtract energy, but add supplies. Print out the remaining. 
            energy--;
            supplies++;
            cout << "Energy: " << energy << endl;
            cout << "Supplies: " << supplies << endl;
            break;
        case 2:
            // If they enter 2, add 2 energy.
            energy += 2;
            break;
        }

        // If supplies exceeds or equals 10, You win. Otherwise, if you run out of energy before you reach 10 supplies, you will lose. Prints a message accordingly.
        if (supplies >= 10)
        {
            cout << "\nCongratulations" << endl;
        }
        else if (energy <= 0)
        {
            cout << "\nYou lost!" << endl;
        }
    }

    // Exercise 3
    // Creates a random 3 digit code. 
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist6(100, 999);

    int guess;
    char tryAgain;

    do
    {
        // Takes in user input for a guess
        cout << "Enter the three digit passcode: " << endl;
        cin >> guess;

        // If the guess is equal to the random code, you unlock the box. 
        if (guess == dist6(rng))
        {
            cout << "You unlocked the box!" << endl;
            break;
        }
        // Otherwise, you will be asked to try again.
        cout << "Do you want to try again? (Y/N)" << endl;
        cin >> tryAgain;

        // This loop will continue until the user enters a letter that is neither N nor n.
    } while (tryAgain != 'N' && tryAgain != 'n');

    return 0;
}
