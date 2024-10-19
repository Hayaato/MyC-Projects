#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <ctime>
#include <cstdlib>
using namespace std;
string encrypt(int length, char alphabet[], char revAlp[],string input) {
    for (int i = 0; i < length; i++) {
        char temp = input[i];
        for (int j = 0; j < 62; j++) {
            if (temp == alphabet[j]) {
                input[i] = revAlp[j];
               
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

            }


        }
    }
    return input;
}
void Print(char Arr[], const int SIZE) {
    for (int i = 1; i < SIZE; i++) {
        cout << Arr[i];
    }
    cout << endl;
}
void RandomizeArr(char arr[], char RandomArr[], const int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i != j) {
                if (RandomArr[i] == RandomArr[j]) {
                    RandomArr[i] = arr[rand() % 62];
                    j = 0;
                    
                }
            }
        } 
    }
}
    int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string input;
    cout << "Enter a prhase(Without 'Space') to encrypt: ";
    cin >> input; cout << endl;
    basic_string <char>::size_type size, length;;
    length = input.length();
    char alphabet[62];  
    cout << length<< endl;

    char alphabetOrig[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    
    RandomizeArr(alphabetOrig, alphabet, 62);
    cout << input << endl;
    input = encrypt(length, alphabet, alphabetOrig, input);
    cout << input<< endl;
    input = decrypt(length, alphabet, alphabetOrig, input);
    cout << input<<endl;
    
    
    Print(alphabet, 62);
    
}

