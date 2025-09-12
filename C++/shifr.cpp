#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <ctime>
#include <cstdlib>
using namespace std;

string encrypt(int length, char alphabet[], char revAlp[], string input) {
    for (int i = 0; i < length; i++) {
        char temp = input[i];
        for (int j = 0; j < 62; j++) {
            if (temp == alphabet[j]) {
                input[i] = revAlp[j];
                break;
            }
        }
    }
    return input;
}

string decrypt(int length, char alphabet[], char revAlp[], string input) {
    for (int i = 0; i < length; i++) {
        char temp = input[i];
        for (int j = 0; j < 62; j++) {
            if (temp == revAlp[j]) {
                input[i] = alphabet[j];
                break;
            }
        }
    }
    return input;
}

void Print(char Arr[], const int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        cout << Arr[i];
    }
    cout << endl;
}

void RandomizeArr(char arr[], char RandomArr[], const int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        RandomArr[i] = arr[i];
    }
    for (int i = 0; i < SIZE; i++) {
        int j = rand() % SIZE;
        swap(RandomArr[i], RandomArr[j]);
    }
}

int main() {
    srand(time(NULL));
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    string input;
    cout << "Enter phrase (without 'Space') to encrypt: ";
    cin >> input;
    cout << endl;

    int length = input.length();

    char alphabetOrig[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
    };

    char alphabet[62];
    RandomizeArr(alphabetOrig, alphabet, 62);

    cout << input << endl;

    input = encrypt(length, alphabet, alphabetOrig, input);
    cout << input << endl;

    input = decrypt(length, alphabet, alphabetOrig, input);
    cout << input << endl;

    Print(alphabet, 62);
}
