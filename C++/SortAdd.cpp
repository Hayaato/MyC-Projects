#include <iostream>
#include <chrono>
#include <string>
#include <windows.h>
using namespace std;
void RandomArr(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand() % 1000;
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
		cout << arr[i] << endl;
	}
}
void ArrSum(int*& arr1, int arr2[], const int SIZE1, const int SIZE2) {
	int* SumArr = new int[SIZE1 + SIZE2];

	for (int i = 0; i < SIZE1; i++) {
			SumArr[i] = arr1[i];
	}
	for (int j = 0; j < SIZE1; j++) {
			SumArr[SIZE1 + j] = arr2[j];
	}
	delete[] arr1;
	arr1 = SumArr;
}

int main()
{	
	
	srand(time(NULL));
	SetConsoleCP(65001); // Устанавливает кодировку ввода UTF-8
	SetConsoleOutputCP(65001); // Устанавливает кодировку вывода UTF-8
	cout << "Введите длину массива 1" << endl;
	int lenth1;
	cin >> lenth1;
	cout << "Введите длину массива 2" << endl;
	int lenth2;
	cin >> lenth2;
	auto start_time = chrono::steady_clock::now();
	cout << endl;
	const int SIZE1 = lenth1;
	const int SIZE2 = lenth2;
	int* arr1 = new int[SIZE1];
	int* arr2 = new int[SIZE2];
	
	
	ArrSum(arr1, arr2, SIZE1, SIZE2);
	RandomArr(arr1, SIZE1+SIZE2);
	/*PrintArr(arr1, SIZE1 + SIZE2);*/
	cout << "сортировка" << endl;
	SortArr(arr1, SIZE1+SIZE2);
	PrintArr(arr1, SIZE1+SIZE2);

	delete[] arr1;
	delete[] arr2;
	auto end_time = chrono::steady_clock::now();
	auto elapsed_ns = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
	cout << elapsed_ns.count() << " ms\n";
	
}