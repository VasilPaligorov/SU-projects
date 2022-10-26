#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int meters, sumOfMeters = 0;
    cout << "Enter meters: ";
    cin >> meters;

    if (meters > 0) {
//        for (; meters; meters--) {
//            sumOfMeters += meters * 2;
//        }

        sumOfMeters = meters * meters + meters;

        cout << "Meters: " << sumOfMeters;
        return 0;
    }
    cout << "Invalid number of meters!";
    return 1;
}
