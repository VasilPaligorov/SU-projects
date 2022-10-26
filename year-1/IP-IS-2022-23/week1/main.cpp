#include <iostream>
#include <cmath>

using namespace std;

int main() {
//    Task 1:
    int firstNumber, secondNumber, thirdNumber;
    cin>>firstNumber>>secondNumber>>thirdNumber;
    cout<<firstNumber+secondNumber+thirdNumber;

//    Task 2:
    int a, b, c, d;
    char separator;

    cout<<"Enter point1 (x,y)"<<endl;
    cin >> separator >> a >> separator >> b >> separator;

    cout<<"Enter point2 (x1,y1)"<<endl;
    cin >> separator >> c >> separator >> d >> separator;

    cout<<"The distance is: "<<sqrt(pow(c-a,2) + pow(d-b,2));

//    Task 3:
    int changer;
    cout<<"Enter number 1:"<<endl;
    cin>>firstNumber;
    cout<<"Enter number 2:"<<endl;
    cin>>secondNumber;

    changer = secondNumber;
    secondNumber = firstNumber;
    firstNumber = changer;

    cout<<"First number is "<<firstNumber<<endl<<"Second number is "<<secondNumber;

//    Task 4:
    int number, sum=0;
    cout<< "Enter number:"<<endl;
    cin>>number;

    while (number){
        sum = sum + number % 10;
        number = number / 10;
    }

    cout<<"The sum is "<<sum;

//    HW1
    int x1, y1, x;
    cout<<"Enter building size (x,y):"<<endl;
    cin >> separator >> x1 >> separator >> y1 >> separator;
    cout<<"Enter tile size:"<<endl;
    cin >> x;

    cout<<"You need "<<(x1*y1)/pow(x,2)<<" tiles";
}
