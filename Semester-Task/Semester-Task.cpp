// Semester-Task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <random>
#include <time.h>

using namespace std;

int * Bubble(int, int*);

int main(){

	//配列長生成
	srand(time(0));
	int arrayLength;
	arrayLength = rand() % 10 + 2;

	int * randNumbers = new int[arrayLength];
	//配列内容生成
	for (int i = 0; i < arrayLength; i++) {
		randNumbers[i] = rand();
	}

	int * result;

	//メイン処理開始
	result = Bubble(arrayLength, randNumbers);
	for (int i = 0; i < arrayLength; i++) {
			cout << *randNumbers++ <<endl;
	}
	//free(randNumbers);
	delete[]randNumbers;
	return 0;
}

int * Bubble(int arrayLength, int* array) {
	int tmpA, tmpB;
	for (int i = 0; i < arrayLength; i++) {
		for (int j = i+1; j < arrayLength-1; j++) {
			if (array[i] > array[j] ) {
					tmpA = array[i];
					tmpB = array[j];
					array[i] = tmpB;
					array[j] = tmpA;
				}
			}

	}

	return 0;
}