#include <iostream>

using namespace std;

int main() {
//  T1
    int number;
    do {
        cout << "Enter number: ";
        cin >> number;
    } while (!(number >= 10 && number <= 100));

//  Т3
    int factorial = 1;
    cout << "Enter number: ";
    cin >> number;

    for (int i = number; i; --i)
        factorial *= i;

    cout << number << "! = " << factorial;


//  T4
    for (int i = 100; i < 1000; ++i) {
        if (i % 10 != i / 10 % 10 && i % 10 != i / 100 && i / 10 % 10 != i / 100)
            cout << i << endl;
    }

//  Т5
    for (int i = 100; i < 1000; ++i) {
        int product = 1;
        int k = i;
        while (k) {
            product *= k % 10;
            k /= 10;
        }
        if (!product)
            continue;
        if (!(i % product))
            cout << i << endl;
    }
    return 0;
}
