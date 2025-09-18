#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void In() {
    cout << "In" << endl;
}

void Out() {
    cout << "Out" << endl;
}

void Menu() {
    int menu;
    cout << "Если вы хотите ввести новый пароль в менеджер паролей, Введите [1], Если вы хотите посмотреть старые пароли, Введите [2], Если вы хотите выйти, Введите [3]: " << endl;
    cin >> menu;
    switch (menu){
    case 1: 
        In();
    case 2:
        Out();
    case 3:
        cout << "Выход из программы." << endl;
        exit(0);
    default:
        cout << "Некорректный ввод. Пожалуйста, выберите [1], [2] или [3]." << endl;
    }
}

int main() {
    Menu();
    //ofstream outfile("Data/example.txt");

    //if (!outfile) {
    //    cerr << "Ошибка открытия файла!" << endl;
    //    return 1;
    //}



    //while (getline(infile, line)) {
}
