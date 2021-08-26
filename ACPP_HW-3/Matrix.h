#pragma once
#include<iostream>

class Matrix
{
private:
	double** m_matrix;
	size_t m_size;
	void getMatrixWithoutRowAndCol(double** matrix, size_t size, size_t row, size_t col, double** newMatrix);
	double matrixDet(double** matrix, size_t size);
public:
	Matrix();
	Matrix(size_t size);
	Matrix(const Matrix& m);
	~Matrix();

	Matrix operator=(const Matrix& m);

	void SetValue(double val, size_t i, size_t j);

	double GetValue(size_t i, size_t j) const;
	double GetDet();

	void mPrint() const;
};

