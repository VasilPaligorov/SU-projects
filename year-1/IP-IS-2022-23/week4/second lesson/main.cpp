#include <iostream>

using namespace std;

int main() {
    //  T1
    int month, year;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;


    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        cout << "This month has 31 days";
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        cout << "This month has 30 days";
    else if (month == 2) {
        bool isLeap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
        cout << (isLeap ? "This month has 29 days" : "This month has 28 days");
    } else
        cout << "Invalid number";

    //T2
    int number;
    cout << "Enter number: ";
    cin >> number;


    if (number == 0 || number == 6 || number == 9)
        cout << "One circle";
    else if (number == 8)
        cout << "Two circles";
    else if (number == 1 || number == 2 || number == 3 || number == 4 || number == 5 || number == 7)
        cout << "No circles";
    else
        cout << "Invalid number";

    switch (number) {
        case 0:
            cout << "Zero";
            break;
        case 1:
            cout << "One";
            break;
        case 2:
            cout << "Two";
            break;
        case 3:
            cout << "Three";
            break;
        case 4:
            cout << "Four";
            break;
        case 5:
            cout << "Five";
            break;
        case 6:
            cout << "Six";
            break;
        case 7:
            cout << "Seven";
            break;
        case 8:
            cout << "Eight";
            break;
        case 9:
            cout << "Nine";
            break;
        default:
            cout<<"Invalid number";
            break;
    }

// T3
    cout << "Enter year: ";
    cin >> year;

    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        cout<<"Year is leap.";
    else
        cout<<"Year isn't leap.";

// T4
    int a, b, c;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;
    if((a+b)>c && (a+c)>b && (c+b)>a)
        cout<<"Triangle";
    else
        cout<<"Not triangle";


    return 0;
}