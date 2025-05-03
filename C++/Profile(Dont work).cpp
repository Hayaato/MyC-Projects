#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <vector>

using namespace std;
string logF;
int file(const string& fileName, int del);
int s;

void append();
void checkp();
void prov();
void reg();
void vhod();
void prov2();
int main() {

	SetConsoleCP(65001); // Устанавливает кодировку ввода UTF-8
	SetConsoleOutputCP(65001); // Устанавливает кодировку вывода UTF-8
    prov();
}

void prov() {
    cout << "Вход[1], Регистрация[2], Выход[3] " << endl;
    cin >> s;

    if (s == 1) {
        vhod();
        
    }
    else if (s == 2) {
        reg();
    }
    else if (s == 3) {
        system("cls");
    }
    else {
        cout << "Введите корректное число" << endl;
        prov();
    }
}

void reg() {
    string password;
    string login;

    cout << "Для регистрации введите логин" << endl;
    cin >> login;

    login += ".txt";

    cout << "Введите пароль" << endl;
    cin >> password;

    ofstream regFile(login, ios_base::out | ios_base::app);

        if (regFile.is_open()) {
            regFile << password;
            ifstream checkFile(login);
            if (checkFile.peek() != ifstream::traits_type::eof()) {
                checkFile.close();
                regFile.close();
                cout << "Логин занят" << endl;
                prov();
            }
            else {

                regFile.close();
                checkFile.close();
                cout << "Регистрация успешна." << endl;
                vhod();
            }
            }

        else {
        cout << "Ошибка открытия файла для записи." << endl;
        prov();
     }
}
void vhod() {
    string pass;
    string log;
    string log2;
    string temp;
    cout << "Введите ваш логин: ";
    cin >> log;
    logF = log;
    log += ".txt";
    cout << endl;
    ifstream log1(log);

    getline(log1, temp);
    ifstream checkFile(log);
    if (checkFile.peek() != ifstream::traits_type::eof()) {
        checkFile.close();
        cout << "Введите пароль: ";
        cin >> pass;
        cout << endl;
        if (temp == pass) {
            cout << "Вход успешен!" << endl;
            prov2();
        }
        else {
            cout << "Вы ввели не корректный пароль" << endl;
            vhod();
        }
    }
    else {
        cout << "Вы ввели не корректный логин" << endl;
        prov();
    }
        

}
void prov2() {
    int m;
    cout << "Здраствуйте," << logF << ".Посмотреть профиль[1],Корректировать профиль[2],Выход[3]" << endl;
    cin >> m;
    if (m == 1) {
        checkp();
    }
    else if (m == 2) {
        append();
    }
    else if (m == 3) {
        cout << "Выключение...";
        system("cls");
    }
    else {
        cout << "Введите корректный символ" <<  endl;
        prov2();
    }
}
void checkp() {
    string fayl;
    string pass1;
    fayl = logF;
    fayl += ".txt";

    // Проверка существования файла
    ifstream fileCheck(fayl);
    if (!fileCheck.good()) {
        cerr << "Файл не существует." << endl;
        return;
    }
    fileCheck.close();

    ifstream pass(fayl);

    if (!pass.good()) {
        cerr << "Ошибка открытия файла для чтения." << endl;
        return;
    }

    
    cout << "Ваш логин:" << logF << endl;

    
    if (getline(pass, pass1)) {
        cout << "Ваш пароль:" << pass1 << endl;
    }
    else {
        cerr << "Ошибка чтения пароля из файла." << endl;
        pass.close();
        return;
    }

    if (getline(pass, pass1)) {
        cout << "Ваш ник:" << pass1 << endl;
    }
    else {
        cerr << "Ошибка чтения ника из файла." << endl;
        pass.close();
        return;
    }

    if (getline(pass, pass1)) {
        cout << "Ваш возраст:" << pass1 << endl;
    }
    else {
        cerr << "Ошибка чтения возраста из файла." << endl;
        pass.close();
        return;
    }

    pass.close();
}
void append() {
    int r;
    string np;
    string nn;
    string na;
    string fayl;
    fayl = logF;
    fayl += ".txt";

    cout << "Что вы хотите изменить? Пароль[1], Имя[2], Возраст[3], Выход[4]" << endl;
    cin >> r;
    if (r == 1) {
        file(fayl, 1);  // Передаем имя файла и номер строки для удаления
        ofstream app(fayl, ios::out | ios::app);
        cout << "Введите новый пароль: ";
        cin >> np;
        cout << endl;
        app << np;
        app.close();
        void prov2();
    }
    else if (r == 2) {
        file(fayl, 2);  // Передаем имя файла и номер строки для удаления
        ofstream app(fayl, ios::out | ios::app);
        cout << "Введите новое имя: ";
        cin >> nn;
        cout << endl;
        app << endl;
        app << nn;
        app.close();
        void prov2();

    }
    else if (r == 3) {
        file(fayl, 2);  // Передаем имя файла и номер строки для удаления
        ofstream app(fayl, ios::out | ios::app);
        cout << "Введите новый возраст: ";
        cin >> na;
        cout << endl;
        app << endl;
        app << endl;
        app << na;
        app.close();
        void prov2();
    }
    else if (r == 4) {
        system("cls");
    }
    else {
        cout << "Введите корректный символ" << endl;
        append();
    }
}

int file(const string& fileName, int del) {
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл для чтения!" << std::endl;
        return 1;
    }

    int lineNumberToDelete = del;
    int currentLineNumber = 1;

    std::string tempFileName = "temp.txt";
    std::ofstream tempFile(tempFileName);
    if (!tempFile.is_open()) {
        std::cerr << "Не удалось открыть временный файл для записи!" << std::endl;
        inputFile.close();
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        if (currentLineNumber != lineNumberToDelete) {
            tempFile << line << std::endl;
        }
        currentLineNumber++;
    }

    inputFile.close();
    tempFile.close();

    if (std::remove(fileName.c_str()) != 0) {
        std::cerr << "Не удалось удалить оригинальный файл." << std::endl;
        return 1;
    }

    if (std::rename(tempFileName.c_str(), fileName.c_str()) != 0) {
        std::cerr << "Не удалось заменить файл." << std::endl;
        return 1;
    }

    std::cout << "Строка с номером " << lineNumberToDelete << " успешно удалена из файла." << std::endl;

    return 0;
}