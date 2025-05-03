#include <iostream>
#include <string>
#include <windows.h>
#include <chrono>
using namespace std;
void RandomArr(int arr[], const int SIZE, const int Random) {
	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand() % Random;
	}
}

void SortArr(int arr[], const int SIZE) {
	int temp;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
				if (arr[i] < arr[j]) {
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
		}
	}
}

void PrintArr(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		cout <<"Итерация:"<< i << "   Число:" << arr[i] << endl;
	}
}
int main()
{	

	srand(time(NULL));
	SetConsoleCP(65001); // Устанавливает кодировку ввода UTF-8
	SetConsoleOutputCP(65001); // Устанавливает кодировку вывода UTF-81
	//cout << "Введите длину массива" << endl;
	int Random = 1000;
	int lenth = 1000;
	//cin >> lenth;
	//cout << "Введите максимальное число массива" << endl;
	//cin >> Random;
	auto start_time = chrono::steady_clock::now();
	lenth--;
	cout << endl;
	const int SIZE = lenth;
	int *arr = new int[SIZE];
	RandomArr(arr,SIZE,Random);
	//PrintArr(arr, SIZE);

	cout << "сортировка" << endl;
	SortArr(arr, SIZE);
	//PrintArr(arr, SIZE);
	auto end_time = chrono::steady_clock::now();
	auto elapsed_ns = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
	cout << elapsed_ns.count() << " ms\n";
	delete[] arr;
	
}
