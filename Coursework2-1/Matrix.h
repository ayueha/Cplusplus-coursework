#pragma once
#include <iostream>
#include <string>
using namespace std;
class Matrix
{
public:
	Matrix();
	Matrix(int startflg);
	~Matrix();
	double ** Create(const int, const int);
	void setLines(int);
	int getLines();
	void setRows(int);
	int getRows();
	void Fill(double**, int ,int);
	void setValueCol(int, int);
	void getValueCol(int, int);
	bool getMatrixInfo();
	int getMatrixMenu(string);
	void printMatrix();
	double createRandom();
	void setSerchIndexLine(int);
	int getSerchIndexLine();
	void setSerchIndexRow(int);
	int getSerchIndexRow();
private:
	double **ptrMatrix;
	int rows, serchIndexLine;
	int lines, serchIndexRow;

};

