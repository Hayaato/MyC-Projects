#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <vector>

using namespace std;
void moving(char Way,int PlayerPosition[2],const int ROWS,const int COLS,char arr[15][40]){
    if(Way == 'W'|| Way == 'w'){
        PlayerPosition[0]--;
    }
    else if(Way == 'A'||Way == 'a'){
        PlayerPosition[1]--;
    }
    else if(Way == 'S'||Way == 's'){
        PlayerPosition[0]++;
    }
    else if(Way == 'D'||Way == 'd'){
        PlayerPosition[1]++;
    }
    else{
        
    }
}
void Refresh(int PlayerPosition[2],const int ROWS,const int COLS,char arr[15][40]){
    int X = PlayerPosition[0];
    int Y = PlayerPosition[1];
    arr[X][Y] = '*';
}
void PrintArr(const int ROWS,const int COLS,char arr[15][40]){
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }

}
void FillArr(const int ROWS,const int COLS, char arr[15][40]){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            arr[i][j] = '-';
        }
    }
}
int main(){
    SetConsoleCP(65001); 
	SetConsoleOutputCP(65001);
    const int ROWS = 15;
    const int COLS = 40;
    char matrix[ROWS][COLS];
    int PlayerPosition[2] = {7, 20};
    char Way;
    
    while (true){
    FillArr(ROWS, COLS, matrix);
    Refresh(PlayerPosition, ROWS, COLS, matrix);
    PrintArr(ROWS, COLS, matrix);
    cin >> Way;
    moving(Way,PlayerPosition, ROWS, COLS, matrix);

    }
    
    //     W
    //   A * D
    //     S
}

