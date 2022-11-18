#include <iostream>
#include <cmath>

using namespace std;

double max(double number, double number2) {
    return number > number2 ? number : number2;
}

bool isPrime(int number) {
    if (number == 1)
        return false;
    for (int i = 0; i <= number / 2; i++) {
        if (i == 1)
            continue;
        else if (!(number % i)) {
            return false;
        }
    }
    return true;
}

void printFirst100Primes() {
    for (int number = 0; number < 100; ++number)
        if (isPrime(number))
            cout << number << ", ";
}

int reverseNumber(int number) {
    int digitCounter = 0, reversedNumber = 0;
    for (int i = number; i; i /= 10)
        digitCounter++;
    for (; digitCounter; digitCounter--) {
        reversedNumber += number % 10 * (int) pow(10, digitCounter);
        number /= 10;
    }
    return reversedNumber / 10;
}

bool isPalindrome(int number) {
    return reverseNumber(number) == number;
}

void printFirstNPalindromes(int number) {
    for (int i = 1; i <= number; i++)
        if (isPalindrome(i))
            cout << i << ", ";
}

bool isPowOf2(int number) {
    while (number % 2 == 0 && number)
        number /= 2;

    return number;
}

bool isPow(int number, int number2) {
    while (number % number2 == 0 && number)
        number /= number2;

    return number;
}

int whichPow(int number, int number2) {
    int powCounter = 0;
    for (; number % number2 == 0 && number; number /= number2)
        powCounter++;
    return powCounter;
}

int main() {

    // T1
    double number, number2;
    cout << "Enter first number: ";
    cin >> number;
    cout << "Enter second number: ";
    cin >> number2;

    cout << "The biggest number is: " << max(number, number2);

    //T2
    printFirst100Primes();

    //T3
    do {
        cout << "Enter first number: ";
        cin >> number;
    } while (number <= 0);

    printFirstNPalindromes(number);

    //T4
    do {
        cout << "Enter first number: ";
        cin >> number;
    } while (number <= 0);
    cout << "The number " << number << (isPowOf2((int) number) ? " is power of 2" : " isn't power of 2");

    //T5
    do {
        cout << "Enter first number: ";
        cin >> number;
    } while (number <= 0);

    do {
        cout << "Enter first number: ";
        cin >> number2;
    } while (number2 <= 0);

    cout << "The number " << number << (isPow((int) number, (int) number2) ? " is power of " : " isn't power of ")
         << number2 << endl;
    if (isPow((int) number, (int) number2))
        cout << number2 << "^" << whichPow((int) number, (int) number2) << " = " << number;
    return 0;

}