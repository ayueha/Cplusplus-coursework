#pragma once
#include <iostream>
#include <string>


using namespace std;
class Matrix
{
public:
	Matrix();
	Matrix(int *);
	Matrix(int,int);
	Matrix(const Matrix& mtr);
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
	Matrix operator+(const Matrix& val)const {
		Matrix mtr(val.lines, val.rows);
		for (int i = 0; i < val.lines; i++) {
			for (int j = 0; j < val.rows; j++) {
				mtr.ptrMatrix[i][j] = this->ptrMatrix[i][j] + val.ptrMatrix[i][j];
			}
		}
		return mtr;
	}
	Matrix operator-(const Matrix& val) {
		Matrix mtr(val.lines, val.rows);
		for (int i = 0; i < val.lines; i++) {
			for (int j = 0; j < val.rows; j++) {
				mtr.ptrMatrix[i][j] = this->ptrMatrix[i][j] - val.ptrMatrix[i][j];
			}
		}
		return mtr;
	}
	Matrix operator*(const Matrix& val) {
		Matrix mtr(val.lines, val.rows);
		for (int i = 0; i < val.lines; i++) {
			for (int j = 0; j < val.rows; j++) {
				mtr.ptrMatrix[i][j] = this->ptrMatrix[i][j] * val.ptrMatrix[i][j];
			}
		}
		return mtr;
	}

	Matrix operator=(const Matrix& val) {
		Matrix mtr(val.lines, val.rows);
		for (int i = 0; i < val.lines; i++) {
			for (int j = 0; j < val.rows; j++) {
				mtr.ptrMatrix[i][j] = this->ptrMatrix[i][j];
			}
		}
		return mtr;
	}

	Matrix operator+=(const Matrix& val) {
		for (int i = 0; i < val.lines; i++) {
			for (int j = 0; j < val.rows; j++) {
				this->ptrMatrix[i][j] = this->ptrMatrix[i][j] + val.ptrMatrix[i][j];
			}
		}
		return *this;
	}

	Matrix operator-=(const Matrix& val) {
		for (int i = 0; i < val.lines; i++) {
			for (int j = 0; j < val.rows; j++) {
				this->ptrMatrix[i][j] = this->ptrMatrix[i][j] - val.ptrMatrix[i][j];
			}
		}
		return *this;
	}

	Matrix operator*=(const Matrix& val) {
		for (int i = 0; i < val.lines; i++) {
			for (int j = 0; j < val.rows; j++) {
				this->ptrMatrix[i][j] = this->ptrMatrix[i][j] * val.ptrMatrix[i][j];
			}
		}
		return *this;
	}

	bool operator ==(const Matrix& val)
	{
		return this->calcValueA == val.calcValueA;
	}

	double operator^(const Matrix& val) const {
		return pow(this->calcValueA, val.calcValueA);
	}	

	Matrix operator!() {
		Matrix mtr(this->rows, this->lines);
		for (int i = 0; i < this->rows; i++)
			for (int j = 0; j < this->lines; j++)
				mtr.ptrMatrix[j][i] = this->ptrMatrix[i][j];
		return mtr;
	}

	friend std::ostream& operator<< (std::ostream &os, const Matrix &mtr) {
		for (int i = 0; i < mtr.lines; i++) {
			for (int j = 0; j < mtr.rows; j++) {
				cout << mtr.ptrMatrix[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		return cout;
	}

	friend std::istream& operator>> (std::istream &inpt, Matrix &val)
	{
		for (int i = 0; i < val.lines; ++i) {
			for (int j = 0; j < val.rows; ++j)
				if (!(inpt >> val.ptrMatrix[i][j])) return inpt;
		}
		return inpt;
		return inpt;
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

