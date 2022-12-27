#include <iostream>
#include <cmath>

using namespace std;

int rollDice() {
    int number = 0;

    for (int i = 0; i < 5; ++i)
        number += (rand() % 6 + 1) * (int) pow(10, i);

    return number;
}

bool checkThreeIdentical(int number) {
    int digits[6] = {0};

    for (; number; number /= 10)
        digits[number % 10 - 1]++;

    for (int i = 0; i < 6; ++i)
        if (digits[i] > 2)
            return true;

    return false;
}

int calculateDiceRolls() {
    int rolls = 0;

    for (int i = 0; i != 3; rolls++)
        checkThreeIdentical(rollDice()) ? i++ : i = 0;

    return rolls;
}

int main() {
    srand(time(nullptr));
    cout << "Pencho, you will need " << calculateDiceRolls() << " dice rolls.";
}
