#pragma once
#include <stdio.h>
#include <iostream>
#include <istream>
#include <time.h>
#include <string>

class Matrix
{

public:
	Matrix();
	~Matrix();
	int setLines(int);
	int setRows(int);

	double ** Create(int, int);
	void Fill( int, int);
	void setValueCol();
	double getMatrixValue(int, int);
	void printMatrix();
	double createRandom();

private:
	double **ptrMatrix;
	double **transedMatrix;
	int serchIndexLine;
	int serchIndexRow;
	int rows;
	int lines;
};

