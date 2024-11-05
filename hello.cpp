#include <iostream>
#include <string>
#include <random>
using namespace std;

int main()
{
    // Exercise 1:
    string quotes[7];
    string DoW[7] = {"Monday", "Teusday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    for (int i = 0; i < 7; i++)
    {
        cout << DoW[i] << "\nEnter Quote: " << endl;
        getline(cin, quotes[i]);
    }
    printf("\n");
    for (int i = 0; i < 7; i++)
    {
        cout << quotes[i] << endl;
    }

    // Exercise 2:
    int energy = 5;
    int supplies = 0;
    int day = 0;

    while (energy > 0 && supplies < 10)
    {
        int choice;
        day++;
        cout << "\nDay " << day << ":" << endl;

        cout << "1. Search for supplies (costs 1 energy, adds 1 supply)\n2. Rest(restores 2 energy, but doesn’t add supplies)" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            energy--;
            supplies++;
            cout << "Energy: " << energy << endl;
            cout << "Supplies: " << supplies << endl;
            break;
        case 2:
            energy += 2;
            break;
        }

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
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist6(100, 999);

    int guess;
    char tryAgain;

    do
    {
        cout << "Enter the three digit passcode: " << endl;
        cin >> guess;

        if (guess == dist6(rng))
        {
            cout << "You unlocked the box!" << endl;
            break;
        }
        cout << "Do you want to try again? (Y/N)" << endl;
        cin >> tryAgain;
    } while (tryAgain != 'N' && tryAgain != 'n');

    return 0;
}