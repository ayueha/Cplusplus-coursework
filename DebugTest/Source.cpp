// http://www.tud.ttu.ee/im/viktor.leppikson/ICS0017%20Java%20to%20C.pdf#page=11
// https://en.cppreference.com/w/cpp/language/operator_arithmetic
#include <stdio.h>
#include <iostream>
#include <ostream>
#include <istream>

class Matrix {
private:
	int rows;
	int cols;
	double **matrix;
	void createMatrix() {
		matrix = (double **)malloc(rows * sizeof(double *));
		for (int i = 0; i < rows; i++)
			matrix[i] = (double *)malloc(cols * sizeof(double));
	}
	void fillMatrix() {
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				matrix[i][j] = rand() % 100;
	}
public:
	Matrix() {
		rows = 3;
		cols = 3;
		createMatrix();
		fillMatrix();
	};
	Matrix(int _rows, int _cols) {
		rows = _rows;
		cols = _cols;
		createMatrix();
		fillMatrix();
	}
	Matrix(const Matrix& oldMatrix) {
		rows = oldMatrix.rows;
		cols = oldMatrix.cols;
		createMatrix();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++)
				matrix[i][j] = oldMatrix.matrix[i][j];
		}
	};
	~Matrix() {
		if (matrix) {
			for (int i = 0; i < rows; i++) free(matrix[i]);
			free(matrix);
		}
	};
	int getRows() {
		return rows;
	}
	int getCols() {
		return cols;
	}
	double getCell(int x, int y) {
		if (x >= rows || y >= cols) {
			throw("Error: Coordinates very big");
		}

		return matrix[x][y];
	}
	void setCell(int x, int y, double newValue) {
		if (x >= rows || y >= cols) {
			throw("Error: Coordinates very big");
		}

		matrix[x][y] = newValue;
	}

	// Operator functions
	Matrix operator+(const Matrix& m2)const {
		Matrix newMatrix(rows, cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				newMatrix.matrix[i][j] = matrix[i][j] + m2.matrix[i][j];
			}
		}
		return newMatrix;
	};
	Matrix operator-(const Matrix& m2)const {
		Matrix newMatrix(rows, cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				newMatrix.matrix[i][j] = matrix[i][j] - m2.matrix[i][j];
			}
		}
		return newMatrix;
	};
	Matrix operator*(const Matrix& m2)const {
		Matrix newMatrix(rows, cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				newMatrix.matrix[i][j] = 0;
				for (int k = 0; k < rows; k++)
					newMatrix.matrix[i][j] += matrix[i][k] * m2.matrix[k][j];
			}
		}
		return newMatrix;
	}
	Matrix& operator=(const Matrix& m2) {
		rows = m2.rows;
		cols = m2.cols;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				matrix[i][j] = m2.matrix[i][j];
			}
		}
		return *this;
	}

	// Compound assignments
	Matrix operator+=(const Matrix& m2)const {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				matrix[i][j] = matrix[i][j] + m2.matrix[i][j];
			}
		}
		return *this;
	};
	Matrix operator-=(const Matrix& m2)const {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				matrix[i][j] = matrix[i][j] - m2.matrix[i][j];
			}
		}
		return *this;
	};
	Matrix operator*=(const Matrix& m2) {
		Matrix result = (*this) * m2;
		(*this) = result;
		return *this;
	}

	// Comparison
	bool operator==(const Matrix &m2) const {
		if (rows != m2.rows) return false;
		if (cols != m2.cols) return false;
		bool isEqual = true;
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++) {
				if (matrix[i][j] != m2.matrix[i][j]) {
					isEqual = false;
					break;
				}
			}
		return isEqual;
	}

	// Scalar
	Matrix operator^(const double x) const {
		Matrix newMatrix(rows, cols);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				newMatrix.matrix[i][j] = matrix[i][j] * x;
		return newMatrix;
	}

	// Transpose
	Matrix operator!()const {
		Matrix newMatrix(cols, rows);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				newMatrix.matrix[j][i] = matrix[i][j];
		return newMatrix;
	}

	// Cout
	friend std::ostream& operator << (std::ostream &os, const Matrix &m) {
		for (int i = 0; i < m.rows; i++) {
			for (int j = 0; j < m.cols; j++) {
				std::cout << m.matrix[i][j] << " ";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
		return std::cout;
	}

	friend std::istream& operator>> (std::istream &in, Matrix &m)
	{
		for (int i = 0; i < m.rows; ++i) {
			for (int j = 0; j < m.cols; ++j)
				if (!(in >> m.matrix[i][j])) return in;
		}
		return in;
		// Since operator>> is a friend of the Point class, we can access Point's members directly.
		// note that parameter point must be non-const so we can modify the class members with the input values

		return in;
	}

};


int main()
{
	// Testing empty constructor
	Matrix m1;
	std::cout << "m1 = Matrix() \n" << m1;

	// Testing accessor functions
	std::cout << "Number of rows: " << m1.getRows() << "\n";
	std::cout << "Number of columns: " << m1.getCols() << "\n";
	std::cout << "Cell at 1, 1: " << m1.getCell(1, 1) << "\n";
	m1.setCell(1, 1, 55);
	std::cout << "Cell at 1, 1 now: " << m1.getCell(1, 1) << "\n";

	// Testing with parameters and copy constructor
	Matrix m2(1, 2);
	std::cout << "\nm2 = Matrix(1, 2) \n" << m2;
	Matrix m3(m2);
	std::cout << "m3 = Matrix(m2) \n" << m3;

	// Operator functions
	printf("\n\n===Operator functions===\n\n");

	std::cout << "2 example matrices for testing operators \n";
	Matrix m5(2, 2);
	std::cout << "m5 \n" << m5;
	Matrix m6(2, 2);
	std::cout << "m6 \n" << m6;

	Matrix m7 = m5 + m6;
	std::cout << "m7 = m5+m6 \n" << m7;

	Matrix m8 = m5 - m6;
	std::cout << "m8 = m5-m6 \n" << m8;

	Matrix m9 = m5;
	std::cout << "m9 = m5 \n" << m9;

	Matrix m10 = m5 * m6;
	std::cout << "m10 = m5*m6 \n" << m10;

	// Compound assignments
	printf("\n\n===Compound assignments===\n\n");
	m5 += m6;
	std::cout << "m5 += m6 \n" << m5;
	m5 -= m6;
	std::cout << "m5 -= m6 \n" << m5;
	m5 *= m6;
	std::cout << "m5 *= m6 \n" << m5;

	// Comparison
	printf("\n\n===Comparison===\n\n");
	Matrix m_c1(1, 1);
	Matrix m_c2(1, 1);
	std::cout << "m_c1 = Matrix(1,1) \n" << m_c1;
	std::cout << "m_c2 = Matrix(1,1) \n" << m_c2;
	std::cout << "m5 == m6 \n" << (m_c1 == m_c2);
	m_c1.setCell(0, 0, m_c2.getCell(0, 0));
	std::cout << "\n m5 == m6 \n" << (m_c1 == m_c2);

	// Scalar multiplication
	printf("\n\n===Scalar multiplication===\n");
	Matrix m_s1(2, 2);
	std::cout << "m_s1 = Matrix(2,2) \n" << m_s1;
	Matrix m_s2 = m_s1 ^ 3;
	std::cout << "m_s2 =m_s1 ^ 3 \n" << m_s2;

	// Transpose
	printf("\n\n===Transpose===\n");
	Matrix m_t1(1, 2);
	std::cout << "m_t1 = Matrix(1,2) \n" << m_t1;
	Matrix m_t2 = !m_t1;
	std::cout << "m_t2 = !m_t1 \n" << m_t2;

	// CIN
	printf("\n\n===CIN===\n");
	Matrix m_in(2, 2);
	std::cin >> m_in;
	std::cout << "m_in \n" << m_in;

	// Exceptions
	Matrix m_e1(2, 2);
	try {
		std::cout << "\nException: m_e1(2,2).getCell(3,3): " << m_e1.getCell(3, 3);
	}
	catch (const char* msg) {
		std::cerr << msg << std::endl;
	}
}
