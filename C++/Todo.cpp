#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

void zap();
void zap1();
void agree();
int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	int v;
	cout << "Вы хотите записать новые дела (Старые будут удалены) [1], или пересмотреть старые [2],Подтвердить выполнение[3]Закончить[4]? " << endl;
	cin >> v;
	switch(v){
	case 1:
		zap();
		break;
	case 2:
		zap1();
		break;
	case 3:
		agree();
		break;
	case 4:
		cout << "Заканчиваю...";
		exit(0);
	default:
		cout << "Введите 1,2,3,4";
		exit(0);
	}
	return 0;
}

void zap() {
	string day1, day2, day3;
	int check;
	cout<<"Введите [1]Чтобы записать дела на сегодня,[2]Завтра[3]После-завтра[4]Выйти в главное меню[5]Закончить" << endl;
	cin >> check;
	switch(check){
	case 1: {
		cout << "Что будем делать сегодня? "<<endl;
		cin.ignore();
		getline(cin, day1);
		ofstream fday1("Data/day1.txt", ios_base::out | ios_base::trunc);
		if (fday1.is_open()) {
			fday1 << day1;
			fday1.close();
		}
		zap();
		break;
	}
	case 2: {
		cout << "Что будем делать завтра? " << endl;
		cin.ignore();
		getline(cin, day2);
		ofstream fday2("Data/day2.txt", ios_base::out | ios_base::trunc);
		if (fday2.is_open()) {
			fday2 << day2;
			fday2.close();
		}
		zap();
		break;
	}
	case 3: {
		cout << "Что будем делать после-завтра? "<<endl;
		cin.ignore();
		getline(cin, day3);
		ofstream fday3("Data/day3.txt", ios_base::out | ios_base::trunc);
		if (fday3.is_open()) {
			fday3 << day3;
			fday3.close();
		}
		zap();
		break;
	}
	case 4:
		main();
		break;
	case 5:
		cout << "Заканчиваю...";
		exit(0);
	default:
		cout << "Введите корректное число" << endl;
		main();
	}
	main();
}
void zap1() {
	cout << "Сегодня мы должны сделать: ";
	ifstream d1("Data/day1.txt");
	string temp1;
	getline(d1, temp1);
	cout << temp1 << endl;
	cout << "Завтра мы должны сделать: ";
	ifstream d2("Data/day2.txt");
	string temp2;
	getline(d2, temp2);
	cout << temp2 << endl;
	cout << "После завтра мы должны сделать: ";
	ifstream d3("Data/day3.txt");
	string temp3;
	getline(d3, temp3);
	cout << temp3 << endl;
	main();
}
void agree() {
	string plus = " +";
	int check = 0;
	cout << "Сегодня мы должны сделать: ";
	ifstream d1("Data/day1.txt");
	string temp1;
	getline(d1, temp1);
	cout << temp1 << endl;
	cout << "Завтра мы должны сделать: ";
	ifstream d2("Data/day2.txt");
	string temp2;
	getline(d2, temp2);
	cout << temp2 << endl;
	cout << "После завтра мы должны сделать: ";
	ifstream d3("Data/day3.txt");
	string temp3;
	getline(d3, temp3);
	d1.close();
	d2.close();
	d3.close();
	cout << temp3 << endl;
	cout << "Чтобы подтверидь выполнение,Введите [1],[2],[3].Либо [4] чтобы закончить,[5]Чтобы перейти в главное меню" << endl;
	cin >> check;
	switch(check){
	case 1: {
		ofstream fday1("Data/day1.txt", ios_base::out | ios_base::trunc);
		if (fday1.is_open()) {
			fday1 << temp1+"+";
			fday1.close();
			agree();
		}
		break;
	}
	case 2: {
		ofstream fday2("Data/day2.txt", ios_base::out | ios_base::trunc);
		if (fday2.is_open()) {
			fday2 << temp2 + "+";
			fday2.close();
			agree();
		}
		break;
	}
	case 3: {
		ofstream fday3("Data/day3.txt", ios_base::out | ios_base::trunc);
		if (fday3.is_open()) {
			fday3 << temp3 + "+";
			fday3.close();
			agree();
		}
		break;
	}
	case 4:
		cout << "Завершение...";
		exit(0);
	case 5:
		main();
		break;
	default:
		cout << "Введите корректное значение" << endl;
		main();
	}
}
