#include <iostream>
#include <string>
using namespace std;
void RandomArr(int arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand() % 100;
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
int main()
{	
	srand(time(NULL));
	
	setlocale(LC_ALL, "Russian");
	cout << "Введите длину массива" << endl;
	int lenth;
	cin >> lenth;
	cout << endl;
	const int SIZE = lenth;
	int *arr = new int[SIZE];
	RandomArr(arr,SIZE);
	PrintArr(arr, SIZE);
	cout << "сортировка" << endl;
	SortArr(arr, SIZE);
	PrintArr(arr, SIZE);
	delete[] arr;
}
