#include <iostream>
#include <cmath>

using namespace std;

int main() {
//  T1
    int day;
    cout << "Enter day number of the week: ";
    cin >> day;
    switch (day) {
        case 1:
            cout << "Monday";
            break;
        case 2:
            cout << "Tuesday";
            break;
        case 3:
            cout << "Wednesday";
            break;
        case 4:
            cout << "Thursday";
            break;
        case 5:
            cout << "Friday";
            break;
        case 6:
            cout << "Saturday";
            break;
        case 7:
            cout << "Sunday";
            break;
        default:
            cout << "Invalid number";
            break;
    }

//  T2
    int year;
    cout << "Enter year: ";
    cin >> year;

    cout << (year % 4 == 0 ?
             year % 100 == 0 ?
             year % 400 == 0 ?
             "Leap year"
                             : "Not leap year"
                             : "Leap year"
                           : "Not leap year"
    );

//  T3
    int a , b;
    cout<<"Enter a in a*x + b = 0: ";
    cin>>a;
    cout<<"Enter b in a*x + b = 0: ";
    cin>>b;

    if(a == 0){
        if(b == 0)
            cout<<"Every x is solution";
        else
            cout<<"No solutions";
    }
    else
        cout<<ceil(((-1 * (double)b)/(double)a)*100.0)/100.0;

// T4
    int c;
    cout<<"Enter a in a*x*x + b*x + c = 0: ";
    cin>>a;
    cout<<"Enter b in a*x*x + b*x + c = 0: ";
    cin>>b;
    cout<<"Enter c in a*x*x + b*x + c = 0: ";
    cin>>c;

    double d;
    if(b%2==0){
        d = ((double)b/2)*((double)b/2) - a*c;
        if (d<0)
            cout<<"No solutions";
        else
            cout<<"x1 = "<< (-(double)b/2) + sqrt(d)/(double)a<<" x2 = "<< (-(double)b/2) - sqrt(d)/(double)a;
    }
    else{
        d = b*b - 4*a*c;
        if (d<0)
            cout<<"No solutions";
        else
            cout<<"x1 = "<< (-b + sqrt(d))/2*(double)a<<" x2 = "<< (-b - sqrt(d))/2*(double)a;
    }

//  Т5
    int x , y, quadrant;
    cout<<"Enter x of the point: ";
    cin>> x;
    cout<<"Enter y of the point: ";
    cin>> y;
    if (x == 0 && y == 0)
        cout<<"The point ("<<x<<","<<y<<") is on the center O";
    else if(x == 0)
        cout<<"The point ("<<x<<","<<y<<") is on Oy";
    else if(y == 0)
        cout<<"The point ("<<x<<","<<y<<") is on Ox";
    else{
        if(x>0 && y>0)
            quadrant=1;
        else if(x<0 && y>0)
            quadrant=2;
        else if(x<0 && y<0)
            quadrant=3;
        else
            quadrant=4;
        cout<<"The point ("<<x<<","<<y<<") is in quadrant "<<quadrant;
    }
    return 0;
}