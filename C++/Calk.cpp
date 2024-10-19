#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;
void s1();
void next();
void math();
int b;
float res;
string sim;
float f;
float s;
int main() {
	SetConsoleCP(65001); // Устанавливает кодировку ввода UTF-8
	SetConsoleOutputCP(65001); // Устанавливает кодировку вывода UTF-8
	cout << "Выберите действие1(+,-,*,/)" << endl;

	cin >> sim;
	if (sim != "+" && sim != "-" && sim != "*" && sim != "/") {
		cout << "Введите корректный символ"<< endl;
		sim = "";
		main();
	}
	else {
		s1();
	}
	
}
void math(){
	if (sim == "+") {
		res = f + s;
	}
	else if(sim == "-") {
		res = f - s;
	}
	else if (sim == "*") {
		res = f * s;
	}
	else if(sim == "/") {
		res = f / s;
	}

	cout << "Число равно: " << res << endl;
	next();
}
void next(){
	cout << "Выберите действие:Продолжить[1],Закончить[2]" << endl;
	cin >> b;
	if (b == 1) {
		main();
	}
	else if (b == 2) {
	}
	else {
		cout << "Введите корректное число" << endl;
		next();
	}
}
void s1() {
	cout << "Введите первое число" << endl;
	cin >> f;
	cout << "Введите второе число" << endl;
	cin >> s;

	math();
}