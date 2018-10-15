#pragma once
#include <iostream>
#include <string>
using namespace std;
class Matrix
{
public:
	Matrix();
	Matrix(int *);
	~Matrix();
	double ** Create(int,int);
	void setLines(int);
	int getLines();
	void setRows(int);
	int getRows();
	void Fill(double**, int ,int);
	void setValueCol(int, int);
	void getValueCol(int, int);
	bool getMatrixInfo();
	void getMatrixMenu(string, int *);
	void printMatrix();
	double createRandom();
	void setSerchIndexLine(int);
	int getSerchIndexLine();
	void setSerchIndexRow(int);
	int getSerchIndexRow();
	bool getValueinfo(string);
private:
	double **ptrMatrix;
	int rows;
	int serchIndexLine;
	int lines;
	int serchIndexRow;
	int flg;
};

