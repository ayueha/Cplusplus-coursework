#include "Matrix.h"



Matrix::Matrix()
{

}


Matrix::~Matrix()
{
}

double ** Matrix::Create(int line, int row) //create matrix
{

	double ** arr;
	arr = new double*[line];

	for (int i = 0; i < line; i++) {
		arr[i] = new double[row];
	}
	//cout << &arr << endl;

	return arr;
}

int Matrix::setLines(int value) { //create matrix --Line number
	this->lines = value;
}


int Matrix::setRows(int value) {//create matrix --Row number
	this->rows = value;
}

void Matrix::Fill(double **ppMatrix, int line, int row) //create matrix -- creattion process  --
{
	srand(time(0));
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




double Matrix::createRandom()
{
	int range = rand() % 10 + 2;
	double randDouble = ((double)rand() / ((double)RAND_MAX + 1)) * range;
	return randDouble;
}



int main() {
	Matrix mtr;

	mtr.Create(;
	mtr.Fill
}