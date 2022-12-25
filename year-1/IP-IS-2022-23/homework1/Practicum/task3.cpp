#include <iostream>

using namespace std;

void modifyString(char *&string, int length) {
    for (; length; --length) {
        if (string[length - 1] >= 'A' && string[length - 1] <= 'Z')
            string[length - 1] += 32;
        else if (string[length - 1] >= 'a' && string[length - 1] <= 'z')
            string[length - 1] -= 32;
        else if (string[length - 1] >= '0' && string[length - 1] <= '9')
            string[length - 1] = '#';
    }
}

int main() {
    int length;
    cout << "Enter length of the string: ";
    cin >> length;

    cout << "Enter the string: ";
    char *string = new char[length + 1];
    cin.ignore(1, '\n');
    cin.getline(string, length + 1);

    modifyString(string, length);
    cout << "New string: " << string;
    
    delete[] string;
}
