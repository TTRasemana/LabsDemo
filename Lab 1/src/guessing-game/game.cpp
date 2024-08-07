#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

int main()
{
    // Seed the random number generator with the current time
    srand(time(0));

    // Generate a secret random number between 1 and 100
    int secretRandomNumber = rand() % 100 + 1;

    int guess,chances = 5; 

    using namespace std;

    cout << " Number Guessing Game! Guess a number between 1-100 "<< endl;

    for (int i = 1; i <= 5; i++)
    {

        cout << "Enter your guess (remaining chances: " << chances << "): ";
        cin >> guess;
        chances--;

        if (guess == secretRandomNumber)
        {
            cout << "You win" << endl;
            break;
        }
        else if (chances == 0)
        {
            cout << "You lose" << endl;
            break;
        }
        else if (guess < secretRandomNumber)
        {
            cout << "Guess higher." << endl;
        }
        else if (guess > secretRandomNumber)
        {
            cout << "Guess lower." << endl;
        }
    }

    return 0;
}
