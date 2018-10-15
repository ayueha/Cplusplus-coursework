#include <iostream>
#include <string>
#include<random>
#include<time.h>
using namespace std;
double ** Create(const int );
void Fill(double **, int );
void Print(double ** ,int );
void Destroy(double **, int);
//double **AddMatrices(double **pMatrix1, **double **ppMatrix2, int n);
//double **MultiplyMatrices(double **pMatrix1, **double **ppMatrix2, int n);


int main() {
	srand(time(0));
	int matrix = 4;
	//static double **p_p_x; //= new double*[maxtrixNumber];
	
	//cout << ** p_p_x << endl;

	double **p_p_x = Create(matrix);
	cout << &p_p_x << endl;
	Fill(p_p_x, matrix);
	Print(p_p_x, matrix);
	Destroy(p_p_x, matrix);

   //Multiplie matrix
	double **pMatrix1;
	double **ppPMatrix2;
	double **p = AddMatrices(pMatrix1, ppPMatrix2, matrix);



	getchar();
	return 0;
}

double **Create(const int i) {
	double ** arr;
	arr = new double*[i];
	cout << &arr << endl;

	for (int j = 0; j < i; j++) {
		arr[j] = new double[i];
	}
	cout << &arr << endl;

	return arr;
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
	delete ppMatrix;

}


//double **AddMatrices(double **pMatrix1, **double **ppMatrix2, int n) {
//}
//double **MultiplyMatrices(double **pMatrix1, **double **ppMatrix2, int n) {
//	return 0;
//}