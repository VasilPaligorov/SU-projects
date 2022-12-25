#include <iostream>

using namespace std;

unsigned int MAX_SIZE = 100;

void inputArr(int n, int arr[n]) {
    for (int i = 0; i < n; ++i) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
}

void printArrOnEvenIndex(int n, int arr[n]) {
    for (int i = 0; (i < n); ++i)
        if (i % 2 == 0)
            cout << "arr[" << i << "] = " << arr[i] << endl;
}

void printArr(int n, int arr[n]) {
    for (int i = 0; (i < n); ++i)
        cout << "arr[" << i << "] = " << arr[i] << endl;
}

int numberOfElements(int n, const int arr[n]) {
    int counter = 0;
    for (int i = 1; i < n - 1; i++)
        if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1])
            counter++;
    return counter;
}

int sizeOfArr(const char arr[]) {
    int i = 0;
    for (; arr[i] != '\0'; i++);
    return i;
}

bool isPalindrome(char arr[]) {
    int length = sizeOfArr(arr);
    for (int i = 0; i < length / 2; i++)
        if (arr[i] != arr[length - i - 1])
            return false;
    return true;
}

void reverseArr(int n, int arr[n]) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

void bubbleSort(int n, int arr[n]) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int main() {
    int number;
    cin >> number;
    int arr[number];
    inputArr(number, arr);

//  T2
    printArrOnEvenIndex(number, arr);

//    T3
    cout << numberOfElements(number, arr);

//    T4
    char arr2[MAX_SIZE];
    cin.getline(arr2, MAX_SIZE);
    cout << sizeOfArr(arr2);

//    T5
    cout << isPalindrome(arr2);

//    T7
    reverseArr(number, arr);
    printArr(number, arr);

//    T8
    bubbleSort(number, arr);
    printArr(number, arr);
}