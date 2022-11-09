#include <iostream>

using namespace std;

int abs(int number) {
    return number < 0 ? -number : number;
}

int pow(int number, int number2) {
    int pow = 1;
    for (; number2; --number2)
        pow *= number;

    return pow;
}

int min(int number, int number2) {
    return number > number2 ? number2 : number;
}

int max(int number, int number2) {
    return number > number2 ? number : number2;
}

int minOfThree(int number, int number2, int number3) {
    return number < number2 ? number < number3 ? number : number3 : number2 < number3 ? number2 : number3;
}

int maxOfThree(int number, int number2, int number3) {
    return number > number2 ? number > number3 ? number : number3 : number2 > number3 ? number2 : number3;
}

bool isUpper(char letter) {
    return letter >= 'A' && letter <= 'Z';
}

bool isLower(char letter) {
    return letter >= 'a' && letter <= 'z';
}

bool isLetter(char symbol) {
    return (symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z');
}

bool isDigit(char symbol) {
    return symbol >= '0' && symbol <= '9';
}

char toUpper(char symbol) {
    int space = 'a' - 'A';
    return char(symbol - space);
}

char toLower(char symbol) {
    int space = 'a' - 'A';
    return char(symbol + space);
}

int countDigitInNumber(int number, int digit) {
    int counter = 0;
    while (number) {
        if (number % 10 == digit)
            counter++;
        number /= 10;
    }
    return counter;
}

bool isPrime(int number) {

    if (number == 1) {
        return false;
    }

    for (int i = 0; i <= number / 2; i++) {
        if (i == 1)
            continue;
        else if (!(number % i)) {
            return false;
        }
    }

    return true;
}

bool isDouble(int number, int number2) {
    if (isPrime(number) && isPrime(number2))
        return (number + 2 == number2);
    else
        return false;
}

int main() {

    // TO
    int number, digit, number2;
    do {
        cout << "Enter number: ";
        cin >> number;
    } while (number <= 0);

    for (int i = 0; i <= (number * number) - 1; ++i) {
        int factorial = 1;
        if (i % number == 0)
            cout << endl;
        for (int j = i; j; --j)
            factorial *= j;
        cout << factorial << " ";
    }
    // T1 - functions

    //    T2
    do {
        cout << "Enter number: ";
        cin >> number;
    } while (number <= 100);
    do {
        cout << "Enter digit: ";
        cin >> digit;
    } while (digit <= 0);
    cout << number << " contains " << digit << " " << countDigitInNumber(number, digit) << " times.";

    //    T3
    do {
        cout << "Enter number: ";
        cin >> number;
    } while (number <= 0);
    do {
        cout << "Enter number: ";
        cin >> number2;
    } while (number2 <= 0);
    cout << number << " and " << number2 << (isDouble(number, number2) ? " are double prime" : " aren't double prime");
    return 0;
}