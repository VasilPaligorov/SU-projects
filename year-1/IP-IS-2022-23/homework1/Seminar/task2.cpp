#include <iostream>

using namespace std;

int strlen(char *message) {
    int length;
    for (length = 0; *message != '\0'; ++message)
        length++;
    return length;
}

bool validatePosition(const char startingPosition[]) {
    return (startingPosition[0] >= 'a' && startingPosition[0] <= 'h') &&
           (startingPosition[1] >= '1' && startingPosition[1] <= '8');
}

void setPosition(char position[]) {
    do {
        cout << "Knight starting position: ";
        cin.getline(position, 3);
        if (!validatePosition(position))
            cout << "Invalid table position!" << endl;
    } while (!validatePosition(position));
}

int enterMoves(char moves[]) {
    cout << "Moves (max 64): ";
    cin.getline(moves, 129);
    return strlen(moves) / 2;
}

void copyArray(const char source[], char destination[], int size) {
    for (; size; size--)
        destination[size - 1] = source[size - 1];
}

void makeMoves(char moves[], int movesCount, char position[]) {
    bool isCorrect = true;
    char newPosition[3];
    copyArray(position, newPosition, 3);
    for (int i = 0; i < movesCount * 2; i++) {
        switch (moves[i]) {
            case 'u':
                i % 2 ? newPosition[1] += 1 : newPosition[1] += 2;
                break;
            case 'd':
                i % 2 ? newPosition[1] -= 1 : newPosition[1] -= 2;
                break;
            case 'l':
                i % 2 ? newPosition[0] -= 1 : newPosition[0] -= 2;
                break;
            case 'r':
                i % 2 ? newPosition[0] += 1 : newPosition[0] += 2;
                break;
            default:
                isCorrect = false;
                break;
        }

        if (!isCorrect || !validatePosition(newPosition)) {
            cout << "Not all moves are valid. The knight cannot move ";
            i % 2 ? cout << moves[i - 1] << moves[i] : cout << moves[i] << moves[i + 1];
            cout << ". The final position of the knight is " << position[0] << position[1] << ".";
            return;
        }

        if (i % 2)
            copyArray(newPosition, position, 3);
    }
    cout << "All moves are valid. The final position of the knight is " << position[0] << position[1] << "." << endl;
}

int main() {
    char position[3], moves[129];
    setPosition(position);
    int movesCount = enterMoves(moves);
    makeMoves(moves, movesCount, position);
}
