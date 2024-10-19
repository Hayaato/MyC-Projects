#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>

using namespace std;
void FillArr(int* arr, int& size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10;
    }
    
}
void ShowArr(const int* const arr, int& size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
void push_back(int*& arr, int& size, const int value) {
    
    int* arr1 = new int[size+1];
    for (int i = 0; i < size; i++) {
        arr1[i] = arr[i];
    }
    arr1[size] = value;
    size++;
    delete[] arr;
    arr = arr1;
}
void pop_back(int*& arr, int& size) {
    size--;
    int* arr1 = new int[size];
    for (int i = 0; i < size; i++) {
        arr1[i] = arr[i];
    }
    
    
    delete[] arr;
    arr = arr1;
    
}

  
int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    int value = 1;
    int size = 5;
    int* arr = new int[size];
    FillArr(arr, size);
    ShowArr(arr, size);
    push_back(arr, size, value);
    ShowArr(arr, size);
    pop_back(arr, size);
    ShowArr(arr, size);
    
    delete[] arr;
    

    
}

