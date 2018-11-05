#include "Matrix.h"
#include <iostream>
#include <string>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <cstdlib>
using namespace std;

Matrix::Matrix()
{
}

//Constractor Copy  --main programs ---
Matrix::Matrix(int *startflg)
{
	string i, j,flg;
	
	try {
		while (*startflg == 1) {
			if (getMatrixInfo() == false) {
				cout << "create Matrix " << endl;
				cout << "Enter a number of line you want : ";
				cin >> i;
				setLines(stoi(i));
				cout << "create Matrix " << endl;
				cout << "Enter a number of row you want : ";
				cin >> j;
				setRows(stoi(j));
				
				cout << "Start creating matrix " << endl;
				this->ptrMatrix = Create(getLines(), getRows());
				Fill(this->ptrMatrix, getLines(), getRows());
			}
			else {
				cout << "Please select menu" << endl;
				cout << "Enter [1] to input double to matrix " << endl;
				cout << "Enter [2] to refer double of matrix " << endl;
				cout << "Enter [3] to refer whole matrix info " << endl;
				cout << "Enter [4] to calculation two values or change rows and columms" << endl;
				cout << "Enter [0] to exit" << endl;
				cin >> flg;
				/*flg = getchar();*/
				getMatrixMenu(flg, startflg);
			}
			
		}
	}
	catch (exception) {
		cout << "Exception Error occured. Exit this program" << endl;
		exit;
	}
}

Matrix::Matrix(double value)
{
	this->tmpCalcVal = value;

}



Matrix::~Matrix()
{
	for (int i = 0; i < this->lines; i++) {
		this->ptrMatrix[i];

	}
	delete this->ptrMatrix;

	if (transedMatrix != nullptr) {
		for (int i = 0; i < this->rows; i++) {
			this->transedMatrix[i];

		}
		delete this->transedMatrix;
	}
	
	delete this->matrixValueA;
	delete this->matrixValueB;

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
void Matrix::setLines(int value) { //create matrix --Line number
	string num;
	while (value < 1) {
		cout << "String or 0 has been entered by user. Please Enter more than 1 ";
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
	if (value == 0) {
		cout << "No row matrix has been nominated or invalid string has been enterd ...set row number as 0" << endl;
	}
	this->rows = value;
}
int Matrix::getRows() //get Row information
{
	return this->rows;
}

void Matrix::setSerchIndexLine(int value)
{
	if (value > getLines()) {
		cout <<"Invalid range has been inputed automatically set 0" << endl;
		this->serchIndexLine = 0;
	}
	else if (value ==0 ) {
		cout << "0 or invalid string has been entered if it is invalid number, 0 automatically set" << endl;
		this->serchIndexLine = 0;
	}
	else {
		this->serchIndexLine = value;
	}

}
int Matrix::getSerchIndexLine()
{
	return this->serchIndexLine;
}

void Matrix::setSerchIndexRow(int value)
{
	if (value > getRows()) {
		cout << "Invalid range has been inputed automatically set 0" << endl;
		this->serchIndexLine = 0;
	}
	else if (value == 0) {
		cout << "0 or invalid string has been entered if it is invalid number, 0 automatically set" << endl;
		this->serchIndexLine = 0;
	}
	else {
		this->serchIndexRow = value;
	}

}
int Matrix::getSerchIndexRow()
{
	return this->serchIndexRow;
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

void Matrix::setValueCol() {//set certain number of combination in matrix;
	string tmp;
	cout << "Please Enter double or integer:";
	cin >> tmp;
	setValueinfo(tmp);

	cout << "Previous Number of " << getSerchIndexLine() << " and Row : " << getSerchIndexRow() << " is " << this->ptrMatrix[getSerchIndexLine()][getSerchIndexRow()] <<endl;
	this->ptrMatrix[getSerchIndexLine()][getSerchIndexRow()] = getValueInfo();
	cout << "Current Number of " << getSerchIndexLine() << " and Row : " << getSerchIndexRow() << " is " << this->ptrMatrix[getSerchIndexLine()][getSerchIndexRow()] << endl;

}


double Matrix::getValueCol( int line, int row) { //get certain number of combination in matrix;
	try{
		
		if (line >=getLines()  || row >=getRows()) {
			cout << "Invalid range range 0:0 automatically returns" << endl;
			return this->ptrMatrix[0][0];
		}
		else {
			cout << "Line no :" << line << " and row no :" << row << " is " << this->ptrMatrix[line][row] << endl;
			return ptrMatrix[line][row];

		}
	}catch(exception){
		cout << "Invalid matrix number has been choosed, automatically set 0 as matrix " << endl;
		return this->ptrMatrix[0][0];
	}
	
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

void Matrix::setCalcValueA(double value) {
	this->calcValueA =value;
}

void Matrix::setCalcValueB(double value) {
	this->calcValueB = value;
}

double Matrix::getCalcValueA() {
	return this->calcValueA;
}

double Matrix::getCalcValueB() {
	return this->calcValueB;
}

double Matrix::getMatrixValue(int line, int row) {
	try {
		if (line < getLines() && row < getRows()) {
			return this->ptrMatrix[line][row];
		}
	}
	catch(exception){
			cout << "Invalid matrix number has been choosed, automatically set 0 as matrix " << endl;
			return this->ptrMatrix[0][0];
	}
		
}

void Matrix::setmatrixA(int line, int row) {
	try {
		if (line >= getLines() || row >= getRows()) {
			cout << "Invalid range automatically set  line 0: row 0" << endl;
			this->matrixValueA = &this->ptrMatrix[0][0];
		}
		else {
			this->matrixValueA = &this->ptrMatrix[line][row];
		}
	}
	catch (exception) {
		cout << "Invalid matrix number has been choosed" << endl;
	}
}
void Matrix::setmatrixB(int line, int row) {
	try {
		if (line >= this->lines || row >= this->rows) {
			cout << "Invalid range automatically set line:0 row:0" << endl;
			this->matrixValueB = &this->ptrMatrix[0][0];
		}
		else
		{
			this->matrixValueB = &this->ptrMatrix[line][row];
		}
	}catch (exception) {
			cout << "Invalid matrix number has been choosed" << endl;
	}
}


void Matrix::getMatrixMenu(string flg, int *startflg)
{
	try{
	string i, j;
		switch (stoi(flg)) {
			case 0:
				*startflg = 0;

			break;
			case 1:
				cout << "Enter search index of Line number" << endl;
				cin >> i;
				setSerchIndexLine(stoi(i));
				if (getRows() > 0) {
					cout << "Enter search inndex of " << endl;
					cin >> j;
					setSerchIndexRow(stoi(j));
				}
				else {
					setSerchIndexRow(stoi("0"));
				}
			
				setValueCol();
				*startflg = 1;
				break;
			case 2:
				cout << "Enter search index of Line number" << endl;
				cin >> i;
				setSerchIndexLine(stoi(i));
				if (getRows() > 0) {
					cout << "Enter search inndex of " << endl;
					cin >> j;
					setSerchIndexRow(stoi(j));
					cout << "Index is Line :" << getSerchIndexLine() << " and Row : " << getSerchIndexRow() << endl;
					cout << getMatrixValue(getSerchIndexLine(), getSerchIndexRow()) << endl;
				}
				getValueCol(getSerchIndexLine(), getSerchIndexRow());
				*startflg = 1;
				break;
			case 3:
				printMatrix();
				*startflg = 1;
				break;
			case 4:
				double result;

			
				cout << "Plase choose calculation menu " << endl;
				cout << "Adittion Enter                               [1]" << endl;
				cout << "Substraction Enter                           [2]" << endl;
				cout << "Assignment Enter                             [3]" << endl;
				cout << "Comparison Enter                             [4]" << endl;
				cout << "addition/substraction/multiplication Enter   [5]" << endl;
				cout << "Fatorial Enter                               [6]" << endl;
				cout << "Transposing rows and columns                 [7]" << endl;
				cin >> i;
				string optionString;
				switch (stoi(i)) {
				case 1:
					if (setCalcBase()){
						cout << "Result of adittion is  : "<< addision(getCalcValueA(), getCalcValueB()) << endl;
					}
					break;
				case 2:
					if (setCalcBase()) {
						cout << "Result of substraction is  : " << substraction(getCalcValueA(), getCalcValueB()) << endl;
					}
					break;
				case 3:
					if (setCalcBase()) {
						cout << "Choose replacement option" << endl;
						cout << "Replace valueA with valueB  Enter [A]" << endl;
						cout << "Replace valueB with valueA  Enter [B]" << endl;
						cin >> optionString;
						assigment(optionString);
					}
					break;
				case 4: 
					if (setCalcBase()) {
						result = comparison(getCalcValueA(), getCalcValueB());
						if (result == getCalcValueA()) {
							cout << "value A is bigger than value B" << endl;
						}
						else if (result == getCalcValueB()) {
							cout << "value B is bigger than value A" << endl;
						}
					}
					break;
				case 5:
					if (setCalcBase()) {
						double resultCalcOverlaodAdd, resultCalcOverlaodSub, resultCalcOverlaodMulti;
						cout << "Execute additions, substrcations and multiplications base on operator overloading" << endl;
						Matrix objA(getCalcValueA());
						Matrix objB(getCalcValueB());
						resultCalcOverlaodAdd = objA + objB;
						resultCalcOverlaodSub = objA - objB;
						resultCalcOverlaodMulti = objA * objB;

						cout << "Adiddion : " << resultCalcOverlaodAdd << " Substraction : " << resultCalcOverlaodSub <<" Multiplication : " << resultCalcOverlaodMulti << endl;

					}
					break;
				case 6:
					double k;
					if (setCalcBase()){
						cout << "Execute Factorial" << endl;
						cout << "Please enter a integer of factorial" << endl;
						cin >> k;
						cout << "Value A  ";
						factorial(k, getCalcValueA());
						cout << "Value B  ";
						factorial(k, getCalcValueB());
					}
					break;
				case 7:
					if (getRows() > 0) {
						transedMatrix = Create(getRows(), getLines());
						//Fill values as rows and columns transposisiotn.
						transpositionMatrix(getLines(), getRows());
						cout << "To see the result, Back to the main menu and choose [3]" << endl;
					}
					else {
						cout << "This option can choose only when matrix has two dimensions" << endl;
					}
					break;
				default:
					cout << "Choose option number listed on the menu" << endl;
						break;
				}

				break;
		}
		//clear values and pointers
		clearValues();
	}
	catch (exception) {
		cout << "Exception Error occured. Exit this program" << endl;
		exit;
	}

	
}

void Matrix::printMatrix()
{
	for (int i = 0; i < getLines(); i++) {
		if (getRows() > 0) {
			for (int j = 0; j < getRows(); j++) {
				cout << "Matrix No," << i << " and row " << j << ":  " << this->ptrMatrix[i][j] << endl;
			}
		}
		else {
			cout << "Matrix No," << i << ":  " << this->ptrMatrix[i][0] << endl;
		}
	}

	if (this->transedMatrix!=nullptr) {		
			if (getRows() > 0 ) {
				cout << "Transposed Matrix is ......" << endl;
				for (int i = 0; i < getRows(); i++) {
					for (int j = 0; j < getLines(); j++) {
						cout << "Matrix No," << i << " and row " << j << ":  " << this->transedMatrix[i][j] << endl;
					}
				}
			}
			else {
				cout << "No transposed Matrix has been generated ......." << endl;
			}
	}

}


double Matrix::createRandom()
{
	int range = rand() % 10 + 2;
	double randDouble = ((double)rand() / ((double)RAND_MAX + 1)) * range;
	return randDouble;
}


void Matrix::setValueinfo(string tmp)
{
	try{
		this->setdouble = stod(tmp);
	}
	catch (exception e) {
		cout << "Bad string , value automatically set as 0" << endl;
		this->setdouble = 0;
	}


}

double Matrix::getValueInfo()
{
	return this->setdouble;
}


double Matrix::addision(double valueFomer , double valueLatter)
{
	return valueFomer+ valueLatter;
}

double Matrix::substraction(double valueFomer, double valueLatter)
{
	return valueFomer - valueLatter;
}


double Matrix::comparison(double valueFomer, double valueLatter)
{
	if (valueFomer > valueLatter) {
		return valueFomer;
	}
	else {
		return valueLatter;
	}

}

bool Matrix::setCalcBase() {
	try{
		string i, j;
		cout << "Enter search index of Line number" << endl;
		cin >> i;

		setSerchIndexLine(stoi(i));
		if (getRows() > 0) {
			cout << "Enter search inndex of " << endl;
			cin >> j;

			setSerchIndexRow(stoi(j));
			cout << "Index is Line :" << getSerchIndexLine() << " and Row : " << getSerchIndexRow() << endl;
			cout << getMatrixValue(getSerchIndexLine(), getSerchIndexRow()) << endl;
		}
		setCalcValueA(getValueCol(getSerchIndexLine(), getSerchIndexRow()));
		setmatrixA(getSerchIndexLine(), getSerchIndexRow());

		cout << "Enter search index of Line number" << endl;
		cin >> i;

		setSerchIndexLine(stoi(i));
		if (getRows() > 0) {
			cout << "Enter search inndex of " << endl;
			cin >> j;

			setSerchIndexRow(stoi(j));
			cout << "Index is Line :" << getSerchIndexLine() << " and Row : " << getSerchIndexRow() << endl;
			cout << getMatrixValue(getSerchIndexLine(), getSerchIndexRow()) << endl;
		}
		setCalcValueB( getValueCol(getSerchIndexLine(), getSerchIndexRow()));
		setmatrixB(getSerchIndexLine(), getSerchIndexRow());

		if (getCalcValueB() == 0 && getCalcValueA() == 0) {
			return false;
		}
		else {
			return true;
		}

	}
	catch (exception) {
		cout << "Invalid number has been entered this calculation will be aborted " << endl;
		return false;
	}
	
}



void Matrix::factorial(double fNumber, double value)
{
	cout << "Result of factorial is " << pow(value, fNumber) << endl;
}


void Matrix::assigment(string option) {
	transform(option.begin(),option.end(),option.begin(),toupper);
	
	if (option == "A") {
		//a->b
		*this->matrixValueA = this->calcValueB;
	}
	else if (option == "B") {
		//b->a
		*this->matrixValueB = this->calcValueA;
	}
	else {
		cout << "Invalid option" << endl;
	}

}

void Matrix::clearValues() {
	this->calcValueA = 0;
	this->calcValueB = 0;
	this->matrixValueA = nullptr;
	this->matrixValueB = nullptr;
}

void Matrix::transpositionMatrix(int line, int row) {

	for (int i = 0; i < line; i++) {
		for (int j = 0; j <=line; j++) {
			setTransposedMatrix(j, i, getMatrixValue(i, j));

		}
	}
}

void Matrix::setTransposedMatrix(int line, int row, double value) {
	this->transedMatrix[line][row] = value;
}