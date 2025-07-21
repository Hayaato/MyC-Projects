#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

char alphabet[62] = {
    'A','B','C','D','E','F','G','H','I','J','K','L','M',
    'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
    'a','b','c','d','e','f','g','h','i','j','k','l','m',
    'n','o','p','q','r','s','t','u','v','w','x','y','z',
    '0','1','2','3','4','5','6','7','8','9'
};

char revAlp[62] = {
    'Z','Y','X','W','V','U','T','S','R','Q','P','O','N',
    'M','L','K','J','I','H','G','F','E','D','C','B','A',
    'z','y','x','w','v','u','t','s','r','q','p','o','n',
    'm','l','k','j','i','h','g','f','e','d','c','b','a',
    '9','8','7','6','5','4','3','2','1','0'
};

string encrypt(string input) {
    for (int i = 0; i < input.length(); i++) {
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

string decrypt(string input) {
    for (int i = 0; i < input.length(); i++) {
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

string User1(string message) {
    string tempmessage;

    cout << "User1: ";
    cin >> tempmessage;
    cout << endl;
    return tempmessage;
}

string User2(string message) {
    string tempmessage;

    cout << "User2: ";
    cin >> tempmessage;
    cout << endl;
    return tempmessage;
}

int main() {
    SetConsoleCP(65001); // Ввод UTF-8
    SetConsoleOutputCP(65001); // Вывод UTF-8
    string message = "";
    while (true) {
        message = User1(message);
        message = User2(message);
    }
    return 0;
}
