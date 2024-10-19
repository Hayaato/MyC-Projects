#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>
using namespace std;
const int col = 3;
const int line = 3;
bool checkWin(string arr[line][col], string player) {
    // Проверка по горизонтали, вертикали и диагоналям
    for (int i = 0; i < 3; ++i) {
        if (arr[i][0] == player && arr[i][1] == player && arr[i][2] == player) {
            return true;  // Победа по горизонтали
        }
        if (arr[0][i] == player && arr[1][i] == player && arr[2][i] == player) {
            return true;  // Победа по вертикали
        }
    }
    if (arr[0][0] == player && arr[1][1] == player && arr[2][2] == player) {
        return true;  // Победа по диагонали
    }
    if (arr[0][2] == player && arr[1][1] == player && arr[2][0] == player) {
        return true;  // Победа по диагонали
    }
    return false;
}
void PrintArr(string arr[line][col]) {
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j]<< " ";
        }
        cout << endl;
    }
}
void FillArr0(string arr[line][col]) {
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = ".";
        }
    }
}
void FillArr(string arr[line][col],int f,int s,string value) {
    f--;
    s--;
    if (arr[f][s] == ".") {
        arr[f][s] = value;
    }
    else {
        cout << "Введите не занятую ячейку";
        exit(1);
    }
}
void GameN(string arr[line][col], int& End);
void GameK(string arr[line][col], int& End);
void GameN(string arr[line][col], int& End) {
    int f;
    int s;
    End++;
    if (End == 9) {
        cout << "Закончились ходы";
        return;
    }
    cout << "Ход Ноликов!" << endl;
    PrintArr(arr);
    cout << "Введите сначала строку, а потом столбец (1-3)" << endl;
    cin >> s >> f; // Переставил местами, чтобы сначала вводить столбец, а потом строку
    FillArr(arr, f, s, "0");
    PrintArr(arr);
    if (checkWin(arr, "0")) {
        cout << "Нолики победили!";
        return;
    }
    system("cls");
    GameK(arr, End);
}

void GameK(string arr[line][col], int& End) {
    int f;
    int s;
    End++;
    if (End == 9) {
        cout << "Закончились ходы";
        return;
    }
    cout << "Ход Крестиков!" << endl;
    PrintArr(arr);
    cout << "Введите сначала строку, а потом столбец (1-3)" << endl;;
    cin >> s >> f; // Переставил местами, чтобы сначала вводить столбец, а потом строку
    FillArr(arr, f, s, "X");
    system("cls");
    PrintArr(arr);
    if (checkWin(arr, "X")) {
        cout << "Крестики победили!";
        return;
    }
    system("cls");
    GameN(arr, End);
}
int main() {
	SetConsoleCP(65001); // Устанавливает кодировку ввода UTF-8
	SetConsoleOutputCP(65001); // Устанавливает кодировку вывода UTF-8
    cout << "Крестики нолики!" << endl;
    string arr[line][col];
    int Finish = 0;
    int &End = Finish;
    FillArr0(arr);
    GameK(arr,End);
}