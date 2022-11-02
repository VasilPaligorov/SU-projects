#include <iostream>

using namespace std;

int main() {
//  T1
    int number, factorial = 1;
    cout << "Enter number: ";
    cin >> number;

    for (int i = number; i; --i)
        factorial *= i;

    cout << number << "! = " << factorial;

//    T2
    int sum = 0;
    do {
        cout << "Enter number: ";
        cin >> number;
        sum += number;
    } while (number);

    cout << "The sum is: " << sum;

//    T3
    do {
        cout << "Enter number: ";
        cin >> number;
    } while (number <= 0);

    while (number) {
        sum += number % 10;
        number /= 10;
    }

    cout << "The sum is: " << sum;
// T4
    do {
        cout << "Enter number: ";
        cin >> number;
    } while (number <= 0);

    if (number == 1) {
        cout << "The number is not prime";
        return 0;
    }

    for (int i = 0; i <= number / 2; i++) {
        if (i == 1)
            continue;
        else if (!(number % i)) {
            cout << "The number is not prime.";
            return 0;
        }
    }

    cout << "The number is prime.";

// T5
    int previousNumber = 0, nextNumber = 1;
    do {
        cout << "Enter number: ";
        cin >> number;
    } while (number <= 0);

    while (number) {
        cout << nextNumber + previousNumber << " ";
        nextNumber += previousNumber;
        previousNumber = nextNumber - previousNumber;
        number--;
    }

// T6
    do {
        cout << "Enter number: ";
        cin >> number;
    } while (number <= 0);

    for (int i = 0; i <= number; ++i) {
        for (int j = i; j; --j)
            cout << "-";
        for (int k = number - i; k; --k)
            cout << "+";
        cout << endl;
    }

    return 0;
}
