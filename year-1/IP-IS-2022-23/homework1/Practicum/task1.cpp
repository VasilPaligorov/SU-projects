#include <iostream>

using namespace std;

void play(int myNumber) {
    int number;
    cout << "Let's play guess the number!\n";
    for (int i = 3; i; --i) {
        cout << "Enter number between 0 and 2147483647: ";
        cin >> number;
        if (number < myNumber)
            cout << number << " is lower than our number.\nYou have " << i - 1 << " more tries.\n\n";
        else if (number > myNumber)
            cout << number << " is higher than our number.\nYou have " << i - 1 << " more tries.\n\n";
        else {
            cout << "Congratulations, you guessed the number!";
            return;
        }
    }
    
    cout << "Sorry, you've run out of tries. Our number was " << myNumber;
}

int main() {
    srand(time(nullptr));
    int myNumber = rand();

    play(myNumber);
}
