#include <iostream>
#include <cmath>

using namespace std;

void setMessage(char message[], char **matrix, int matrixRows, int matrixCols, int xAdded) {
    int k = 0;
    for (int i = 0; i < matrixRows; ++i) {
        for (int j = 0; j < matrixCols; ++j) {
            message[k] = matrix[i][j];
            k++;
        }
    }
    message[k-xAdded] = '\0';
}

void createMatrix(char **&matrix, int matrixCols, int matrixRows) {
    matrix = new char *[matrixCols];

    for (int i = 0; i < matrixRows; ++i)
        matrix[i] = new char[matrixRows + 1];
}

void deleteMatrix(char **&matrix, int matrixRows) {

    for (int i = 0; i < matrixRows; ++i)
        delete[] matrix[i];

    delete[] matrix;
}

int strlen(char *message) {
    int length;
    for (length = 0; *message != '\0'; ++message)
        length++;
    return length;
}

void filterMessage(char message[]) {
    int length = strlen(message), j = 0;

    for (int i = 0; i < length; ++i) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[j] = message[i];
            j++;
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[j] = (char) (message[i] - 32);
            j++;
        }
    }
    message[j] = '\0';
}

int fillMatrix(const char message[], char **&matrix, int matrixCols, int matrixRows) {
    int k = 0, xCounter = 0;
    for (int i = 0; i < matrixRows; ++i) {
        for (int j = 0; j < matrixCols; ++j) {
            if (message[k] == '\0') {
                matrix[i][j] = 'X';
                xCounter++;
            } else {
                matrix[i][j] = message[k];
                k++;
            }
        }
        matrix[i][matrixRows + 1] = '\0';
    }
    return xCounter;
}

void reverseMatrix(char **&matrix, int matrixRows, int matrixCols) {
    for (int i = 0; i <= matrixRows / 2; ++i) {
        for (int j = 0; j < matrixCols; ++j) {
            if (i == matrixRows / 2 && j == matrixCols / 2)
                break;
            char c = matrix[i][j];
            matrix[i][j] = matrix[matrixRows - i - 1][matrixCols - j - 1];
            matrix[matrixRows - i - 1][matrixCols - j - 1] = c;
        }
    }
}

void encryptMatrix(char message[], char **matrix, int matrixRows, int matrixCols) {
    int i, startingRow = 0, startingCol = 0, count = 0, length = matrixRows * matrixCols;

    while (startingRow < matrixRows && startingCol < matrixCols) {
        if (count == length)
            break;

        for (i = startingRow; i < matrixRows; ++i) {
            message[count] = matrix[i][startingCol];
            count++;
        }
        startingCol++;

        if (count == length)
            break;

        for (i = startingCol; i < matrixCols; ++i) {
            message[count] = matrix[matrixRows - 1][i];
            count++;
        }
        matrixRows--;

        if (count == length)
            break;

        if (startingRow < matrixRows) {
            for (i = matrixRows - 1; i >= startingRow; --i) {
                message[count] = matrix[i][matrixCols - 1];
                count++;
            }
            matrixCols--;
        }

        if (count == length)
            break;

        if (startingCol < matrixCols) {
            for (i = matrixCols - 1; i >= startingCol; --i) {
                message[count] = matrix[startingRow][i];
                count++;
            }
            startingRow++;
        }
    }
    message[count] = '\0';
}


void decryptMatrix(const char message[], char **&matrix, int matrixRows, int matrixCols) {
    int i, startingRow = 0, startingCol = 0, count = 0, length = matrixRows * matrixCols;
    while (startingRow < matrixRows && startingCol < matrixCols) {
        if (count == length)
            break;

        for (i = startingRow; i < matrixRows; ++i) {
            matrix[i][startingCol] = message[count];
            count++;
        }
        startingCol++;

        if (count == length)
            break;

        for (i = startingCol; i < matrixCols; ++i) {
            matrix[matrixRows - 1][i] = message[count];
            count++;
        }
        matrixRows--;

        if (count == length)
            break;

        if (startingRow < matrixRows) {
            for (i = matrixRows - 1; i >= startingRow; --i) {
                matrix[i][matrixCols - 1] = message[count];
                count++;
            }
            matrixCols--;
        }

        if (count == length)
            break;

        if (startingCol < matrixCols) {
            for (i = matrixCols - 1; i >= startingCol; --i) {
                matrix[startingRow][i] = message[count];
                count++;
            }
            startingRow++;
        }
    }
}

int main() {
    int key, matrixCols, matrixRows, xAdded;
    char message[256];
    char **matrix;

    do {
        cout << "Enter key (key can't be 0): ";
        cin >> key;
    } while (key == 0);

    matrixCols = abs(key);

    cin.ignore(1, '\n');
    cout << "Enter your message: ";
    cin.getline(message, 256);

    filterMessage(message);

    matrixRows = ceil((double) strlen(message) / matrixCols);

    createMatrix(matrix, matrixCols, matrixRows);

    xAdded = fillMatrix(message, matrix, matrixCols, matrixRows);

    if (key < 0)
        reverseMatrix(matrix, matrixRows, matrixCols);

    encryptMatrix(message, matrix, matrixRows, matrixCols);

    cout << "Encrypted message: " << message << endl;

    decryptMatrix(message, matrix, matrixRows, matrixCols);

    if (key < 0)
        reverseMatrix(matrix, matrixRows, matrixCols);

    setMessage(message, matrix, matrixRows, matrixCols, xAdded);

    cout << "Decrypted message: " << message << endl;

    deleteMatrix(matrix, matrixRows);
}