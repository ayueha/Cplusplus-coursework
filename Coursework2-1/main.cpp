#include "Matrix.h"
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
string menu();
int main() {
	//init pointer
	int *flg;
	int num = 1;
	flg = &num;

	cout << "This program create matrix. \n setup a matrix \n draw the data from matrix" << endl;
	while (*flg==1) {
		*flg = stoi(menu());
		
		if (*flg == 0) {
			break;
		}
		else {
			Matrix matrix(flg);
		}
	}
	cout << "Program has been aborted" << endl;
	Sleep(5 * 1000);
	return 0;
}

string menu() {
	string pc;
	cout << "Select menu" << endl;
	cout << "Create Matrix: Enter [1]" << endl;
	cout << "Exit program : Enter [0]" << endl;
	pc = getchar();

	return pc;
}