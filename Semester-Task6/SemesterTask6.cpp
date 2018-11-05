#include <iostream>
#include <string>
#include<random>
#include<time.h>
using namespace std;
double ** Create(const int );
void Fill(double **, int );
void Print(double ** ,int );
void Destroy(double **, int);
double **AddMatrices(double **, double **, int n);
double **MultiplyMatrices(double **pMatrix1, double **ppMatrix2, int n);


int main() {
	srand(time(0));
	//matrix number input
	int matrix = 4;
	double **p_p_x = Create(matrix);
	Fill(p_p_x, matrix);
	cout << "=============Sample  Matrix= =Two dimension============" << endl;
	Print(p_p_x, matrix);
	Destroy(p_p_x, matrix);

   //Multiplie matrix


	double **matrixA = nullptr;
	double **matrixB = nullptr;

	AddMatrices(matrixA, matrixB, matrix);
	

	free(matrixA);
	free(matrixB);
	getchar();
	return 0;
}

double **Create(const int i) {
	double ** arr;
	arr = new double*[i];

	for (int j = 0; j < i; j++) {
		arr[j] = new double[i];
	}

	return arr;
}


double ** AddMatrices(double **pMatrix1, double **ppMatrix2, int n) {
	pMatrix1 = Create(n);
	ppMatrix2 = Create(n);

	Fill(pMatrix1, n);
	Fill(ppMatrix2, n);

	cout << "================Matrix A=================" << endl;
	Print(pMatrix1, n);
	cout << "================Matrix B=================" << endl;
	Print(ppMatrix2, n);

	cout << "========Result of Multiplication=========" << endl;
	MultiplyMatrices(pMatrix1, ppMatrix2, n);

	cout << "Discard Matrix A" << endl;
	Destroy(pMatrix1, n);
	cout << "Discard Matrix B" << endl;
	Destroy(ppMatrix2, n);

	return 0;
}

double **MultiplyMatrices(double **pMatrix1, double **ppMatrix2, int n){
	double result;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result = pMatrix1[i][j] * ppMatrix2[i][j];
			
			cout << "Result of multiplication matrixA :"<< i <<":" << j << " MatrixB :" << i<< ":" << j  <<"  :" << pMatrix1[i][j] << " * " << ppMatrix2[i][j] << " is " << result << endl;

		}
	}


	return 0;
}



void Fill(double **ppMatrix, int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int range = rand() % 10 + 2;
			double randDouble = ((double)rand() / ((double)RAND_MAX + 1)) * range;
			ppMatrix[i][j] = randDouble;
		}
	}

}

void Print(double **ppMatrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Matrix No," << i  << " and row "<< j <<  ":  " << ppMatrix[i][j] << endl;
		}
	}
}

void Destroy(double **ppMatrix, int n) {
	
	
	for (int i = 0; i < n; i++) {
			
		delete ppMatrix[i];
	}
	delete ppMatrix;
	cout << "Matrix and pointers has been deleted" << endl;
}

