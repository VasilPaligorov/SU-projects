#include <iostream>
#include <cmath>

using namespace std;

int main() {
//  W2 T1
    int apples, pears, bananas;
    cout<<"Enter the number of apples: ";
    cin>>apples;
    cout<<"Enter the number of pears: ";
    cin>>pears;
    cout<<"Enter the number of bananas: ";
    cin>>bananas;
    cout<<"Traicho, don't forget to buy "<<apples<<" apples, "<< pears <<" pears and "<< bananas <<" bananas!";

//  T2
    int n1, n2;
    cout<<"Enter number 1: ";
    cin>>n1;
    cout<<"Enter number 2: ";
    cin>>n2;
    cout<<"The sum is: "<<n1+n2<<endl<<"The difference is: "<<n1-n2<<endl<<"The product is: "<<n1*n2;

// T3
    int seconds;
    cout << "Enter seconds: ";
    cin>>seconds;
    cout<<seconds/60/60/24<<" days, "<<seconds/60/60%24<<" hours, "<<seconds/60%60<<" minutes and "<<seconds%60<<" seconds";

// T4

    int number;
    cout << "Enter number: ";
    cin >> number;

    cout << "Reversed number is: ";
    cout << number % 10;
    number = number / 10;
    cout << number % 10;
    number = number / 10;
    cout << number % 10;
    number = number / 10;
}
