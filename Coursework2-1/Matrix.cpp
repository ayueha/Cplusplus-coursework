#include "Matrix.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

Matrix::Matrix()
{
}

//Constractor Copy  --main programs ---
Matrix::Matrix(int startflg)
{
	string i, j,flg;
	while (startflg == 1) {
		if (getMatrixInfo()) {
			cout << "create Matrix " << endl;
			cout << "Enter a number of line you want";
			cin >> i;
			setLines(stoi(i));
			cout << "create Matrix " << endl;
			cout << "Enter a number of row you want";
			cin >> j;
			setRows(stoi(j));

			cout << "Start creating matrix " << endl;
			ptrMatrix = Create(getLines(), getRows());
			Fill(ptrMatrix, getLines(), getRows());
		}
		else {
			cout << "Please select menu" << endl;
			cout << "Enter [1] to input double to matrix " << endl;
			cout << "Enter [2] to refer double of matrix " << endl;
			cout << "Enter [3] to refer whole matrix info " << endl;
			cout << "Enter [0] to exit" << endl;
			flg = getchar();
			startflg = getMatrixMenu(flg);
		}

	}
}

Matrix::~Matrix()
{
	delete ptrMatrix;
}

double ** Matrix::Create(const int lines, const int rows) //create matrix
{
	double ** arr;
	arr = new double*[lines];

		for (int i = 0; i < lines; i++) {
			arr[i] = new double[rows];
		}
		cout << &arr << endl;

	return arr;
}
void Matrix::setLines(int value) { //create matrix --Line number
	string num;
	while (value = 0) {
		cout << "Please Enter more than 0";
		cin >> num;
		value = stoi(num);
	}
	this->lines = value;
}

int Matrix::getLines()  //get line information
{
	return this->lines;
}
void Matrix::setRows(int value) {//create matrix --Row number
	this->rows = value;
}
int Matrix::getRows() //get Row information
{
	return this->rows;
}

void Matrix::setSerchIndexLine(int value)
{
	this->serchIndexLine = value;
}
int Matrix::getSerchIndexLine()
{
	return this->serchIndexLine;
}

void Matrix::setSerchIndexRow(int value)
{
	this->serchIndexRow = value;
}
int Matrix::getSerchIndexRow()
{
	return this->serchIndexRow;
}


void Matrix::Fill(double **ppMatrix, int line, int row) //create matrix -- creattion process  --
{
	for (int i = 0; i < line; i++) {	
		if (row > 0) {
			for (int j = 0; j < row; j++) {
				ppMatrix[i][j] = createRandom();
			}
		}
		else {
			ppMatrix[i][0] = createRandom();
		}

	}
}

void Matrix::setValueCol(int line , int row) {//set certain number of combination in matrix;

}


void Matrix::getValueCol( int line, int row) { //get certain number of combination in matrix;

}

bool Matrix::getMatrixInfo()
{
	if (this->ptrMatrix == nullptr) {
		return false;
	}
	else {
		return true;
	}

}


int Matrix::getMatrixMenu(string flg)
{
	string i, j;
	switch (stoi(flg)) {
		case 0:
			return 0;
		break;
		case 1:

			//setValueCol(int line, int row)
			return 1;
			break;
		case 2:
			cout << "Enter search index of Line number" << endl;
			cin >> i;
			setSerchIndexLine(stoi(i));
			if (getRows()>0) {
				cout << "Enter search inndex of " << endl;
				cin >> j;
				setSerchIndexRow(stoi(j));
				cout << "Index is Line :" << getSerchIndexLine() << " and Row : " << getSerchIndexRow() << endl;
				cout << this->ptrMatrix[getSerchIndexLine()][getSerchIndexRow()] << endl;
			}
			//getValueCol( int line, int row)
			return 1;
			break;
		case 3:
			
			return 1;
			break;
	}
	
}

void Matrix::printMatrix()
{
	for (int i = 0; i < this->lines; i++) {
		if (rows > 0) {
			for (int j = 0; j < this->rows; j++) {
				cout << "Matrix No," << i << " and row " << j << ":  " << this->ptrMatrix[i][j] << endl;
			}
		}
		else {
			cout << "Matrix No," << i << ":  " << this->ptrMatrix[i][0] << endl;
		}
	}
}


double Matrix::createRandom()
{
	srand(time(0));
	int range = rand() % 10 + 2;
	double randDouble = ((double)rand() / ((double)RAND_MAX + 1)) * range;
	return randDouble;
}