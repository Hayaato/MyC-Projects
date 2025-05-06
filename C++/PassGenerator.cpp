#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <ctime>
#include <cstdlib>
using namespace std;
string Generator(const char alphabet[], int length) {
	string gen;
	for (int i = 0; i < length; i++) {
		gen += alphabet[rand() % 62];
	}
	return gen;
}

int main()
{
	srand(time(NULL));
	SetConsoleCP(65001); 
	SetConsoleOutputCP(65001); 
	int UserLength;
	bool UseNum;
	cout << "Hello, Whats length password do u want?: ";
	cin >> UserLength;
	if (UserLength <= 0 ) {
		cout << "Pass length cant be >= 0!" << endl;
		return 1;
	}

	char alphabetOrig[] = {
	   'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
	   'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
	   '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	cout << Generator(alphabetOrig, UserLength);
}
