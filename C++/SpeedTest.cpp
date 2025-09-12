#include <iostream>
#include <chrono>
using namespace std;

int foo_if(int x) {
    if (x == 1) return 10;
    else if (x == 2) return 20;
    else if (x == 3) return 30;
    else if (x == 4) return 40;
    else return -1;
}

int foo_switch(int x) {
    switch (x) {
    case 1: return 10;
    case 2: return 20;
    case 3: return 30;
    case 4: return 40;
    default: return -1;
    }
}

int main() {
    const int N = 100000000; // 100 млн
    volatile int sum = 0;

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        sum += foo_if(i % 20); // значения от 0 до 4
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "if-else: " 
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        sum += foo_switch(i % 20);
    }
    end = chrono::high_resolution_clock::now();
    cout << "switch: " 
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;

    cout << "sum = " << sum << endl;
}
