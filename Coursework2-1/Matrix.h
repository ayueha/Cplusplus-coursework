#pragma once
#include <iostream>
#include <string>


using namespace std;
class Matrix
{
public:
	Matrix();
	Matrix(int *);
	Matrix(double);
	~Matrix();
	double ** Create(int,int);
	void setLines(int);
	int getLines();
	void setRows(int);
	int getRows();
	void Fill(double**, int ,int);
	void setValueCol();
	double getValueCol(int, int);
	bool getMatrixInfo();
	double getMatrixValue(int,int);
	void getMatrixMenu(string, int *);
	void printMatrix();
	double createRandom();
	void setSerchIndexLine(int);
	int getSerchIndexLine();
	void setSerchIndexRow(int);
	int getSerchIndexRow();
	void setValueinfo(string);
	double getValueInfo();
	double addision(double, double);
	double substraction(double, double);
	double comparison(double, double);
	//void someCalc(double, double);
	void factorial(double, double);
	void assigment(string);
	void setCalcValueA(double);
	void setCalcValueB(double);
	double getCalcValueA();
	double getCalcValueB();
	bool setCalcBase();
	void setmatrixA(int,int);
	void setmatrixB(int, int);
	void clearValues();
	void transpositionMatrix(int,int);
	void setTransposedMatrix(int, int,double);
	
	//ƒNƒ‰ƒX‚ÌOverload
	double operator+(const Matrix& val) {
		return this->tmpCalcVal + val.tmpCalcVal;
	}
	double operator-(const Matrix& val) {
		return this->tmpCalcVal - val.tmpCalcVal;
	}
	double operator*(const Matrix& val) {
		return this->tmpCalcVal * val.tmpCalcVal;
	}


private:
	double **ptrMatrix;
	double **transedMatrix;
	int rows;
	int serchIndexLine;
	int lines;
	int serchIndexRow;
	int flg;
	double setdouble;
	double calcValueA;
	double calcValueB;
	double *matrixValueA;
	double *matrixValueB;
	double tmpCalcVal;
};

