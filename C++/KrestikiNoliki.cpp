#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <vector>
int sh = 0;
int f1;
int s1;
int f;
int s;

using namespace std;
int main();
bool checkWin(int player);
void gameN();
void gameK();
void printMatrix();
std::vector<std::vector<int>> matrix(3, std::vector<int>(3, 0));
void WrongAnswer(int v){
    cout << "Введите 1 или 2" << endl;
    cin >> v;
}
void menu2(){
        cout << "Чтобы выиграть нужно собрать 3 крестика или нолика в ряд. Ход начинают крестом. Введите сначала ряд по вертикале, а затем по горизонтали, где 0 - первая строка, а 2 - последняя." << endl;
        chrono::seconds duration(3);
        this_thread::sleep_for(duration);
        system("cls");
        main();
}
int main() {
	SetConsoleCP(65001); // Устанавливает кодировку ввода UTF-8
	SetConsoleOutputCP(65001); // Устанавливает кодировку вывода UTF-8

    int v;
    cout << "Игра крестики-нолики. Для того чтобы начать введите [1], чтобы посмотреть инструкцию введите [2]: ";
    cin >> v;

    switch(v) {
    case 1:
        printMatrix();
        gameK();
    
    case  2: 
        menu2();
    
    default:
        WrongAnswer(v);
        switch(v){
        case 1:
            gameK();
        
        case 2: 
            menu2();
        
        default:
            WrongAnswer(v);
            main();
        }
    }
    return 0;
}



 void printMatrix(){
     cout << "Крестики-нолики:\n";
     for (int i = 0; i < 3; ++i) {
         for (int j = 0; j < 3; ++j) {
             cout << matrix[i][j] << " ";
         }
         cout << '\n';
     }
 }
 void gameK(){
     if (sh == 8) {
         cout << "Кончились ходы";
     }
     sh++;
     cout << "Ход крестиков,Введите сначала первое число затем второе от 1-3 " << endl;
     cin >> f;
     cin >> s;
     if ((f != 1 && f != 2 && f != 3) || (s != 1 && s != 2 && s != 3)) {
         cout << "Введите корректное число" << endl;
         gameK();
         sh--;
     }

     f--;
     s--;
     if (matrix[f][s] != 1 && matrix[f][s] != 2) {
         matrix[f][s] = 1;
     }
     else {
         cout << "введите корректное число" << endl;
         sh--;
         gameK();
     }

     system("cls");
     printMatrix();
     if (checkWin(1)) {
         cout << "Крестики выиграли!" << endl;
         return;
     }
     gameN();
 
 }
 void gameN() {
     if (sh == 8) {
         cout << "Кончились ходы";
         
     }
     sh++;

     cout << "Ход ноликов,Введите сначала первое число затем второе от 1-3 " << endl;
     cin >> f1;
     cin >> s1;
     if ((f1 != 1 && f1 != 2 && f1 != 3) || (s1 != 1 && s1 != 2 && s1 != 3)) {
         cout << "Введите корректное число" << endl;
         gameN();
         sh--;
     }
     f1--;
     s1--;

     if (matrix[f1][s1] != 1 && matrix[f1][s1] != 2) {
         matrix[f1][s1] = 2;
     }
     else {
         cout << "Введите корректное число" << endl;
         sh--;
         gameN();
     }

     system("cls");
     printMatrix();
     if (checkWin(2)) {
         cout << "Нолики выиграли!" << endl;
         return;
     }
     gameK();


 }
 bool checkWin(int player) {
     // Проверка по горизонтали, вертикали и диагоналям
     for (int i = 0; i < 3; ++i) {
         if (matrix[i][0] == player && matrix[i][1] == player && matrix[i][2] == player) {
             return true;  // Победа по горизонтали
         }
         if (matrix[0][i] == player && matrix[1][i] == player && matrix[2][i] == player) {
             return true;  // Победа по вертикали
         }
     }
     if (matrix[0][0] == player && matrix[1][1] == player && matrix[2][2] == player) {
         return true;  // Победа по диагонали
     }
     if (matrix[0][2] == player && matrix[1][1] == player && matrix[2][0] == player) {
         return true;  // Победа по диагонали
     }
     return false;
 }

