#include "Matrix.h"

void Matrix::getMatrixWithoutRowAndCol(double** matrix, size_t size, size_t row, size_t col, double** newMatrix)
{
    size_t offsetRow = 0;
    size_t offsetCol = 0; 
    for (size_t i = 0; i < size - 1; i++) {
        if (i == row) {
            offsetRow = 1;
        }

        offsetCol = 0;
        for (size_t j = 0; j < size - 1; j++) {
            if (j == col) {
                offsetCol = 1;
            }

            newMatrix[i][j] = matrix[i + offsetRow][j + offsetCol];
        }
    }
}

double Matrix::matrixDet(double** matrix, size_t size)
{
    double det = 0;
    int degree = 1;

    if (size == 1) {
        return matrix[0][0];
    }

    else if (size == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else {
        double** newMatrix = new double* [size - 1];
        for (size_t i = 0; i < size - 1; i++) {
            newMatrix[i] = new double[size - 1];
        }

        for (size_t j = 0; j < size; j++) {

            getMatrixWithoutRowAndCol(matrix, size, 0, j, newMatrix);

            det = det + (degree * matrix[0][j] * matrixDet(newMatrix, size - 1));

            degree = -degree;
        }


        for (size_t i = 0; i < size - 1; i++) {
            delete[] newMatrix[i];
        }
        delete[] newMatrix;
    }

    return det;
}

Matrix::Matrix() : m_size(0), m_matrix(nullptr)
{
}

Matrix::Matrix(size_t size) : m_size(size)
{
    m_matrix = (double**) new double * [m_size]; 

    for (size_t i = 0; i < m_size; i++)
        m_matrix[i] = (double*)new double[m_size];

    for (size_t i = 0; i < m_size; i++)
        for (size_t j = 0; j < m_size; j++)
            m_matrix[i][j] = 0;
}

Matrix::Matrix(const Matrix& m)
{
    m_size = m.m_size;

    m_matrix = (double**) new double* [m_size];

    for (size_t i = 0; i < m_size; i++)
        m_matrix[i] = (double*)new double[m_size];

    for (size_t i = 0; i < m_size; i++)
        for (size_t j = 0; j < m_size; j++)
            m_matrix[i][j] = m.m_matrix[i][j];
}

Matrix::~Matrix()
{
    if (m_size > 0)
    {
        for (size_t i = 0; i < m_size; i++)
            delete[] m_matrix[i];
        delete[] m_matrix;
    }
}

Matrix Matrix::operator=(const Matrix& m)
{
    if (m_size > 0)
    {
        for (size_t i = 0; i < m_size; i++)
            delete[] m_matrix[i];
        delete[] m_matrix;
    }

    m_size = m.m_size;

    m_matrix = (double**) new double* [m_size];

    for (size_t i = 0; i < m_size; i++)
        m_matrix[i] = (double*)new double[m_size];

    for (size_t i = 0; i < m_size; i++)
        for (size_t j = 0; j < m_size; j++)
            m_matrix[i][j] = m.m_matrix[i][j];
    return *this;
}

void Matrix::SetValue(double val, size_t i, size_t j)
{
    if ((i < 0) || (i >= m_size))
        return;
    if ((j < 0) || (j >= m_size))
        return;
    m_matrix[i][j] = val;
}

double Matrix::GetValue(size_t i, size_t j) const
{
    if (m_size > 0)
        return m_matrix[i][j];
    else
        return 0.0;
}

double Matrix::GetDet()
{
	return matrixDet(m_matrix, m_size);
}

void Matrix::mPrint() const
{
    std::cout << "---------------------" << std::endl;
    for (size_t i = 0; i < m_size; i++)
    {
        for (size_t j = 0; j < m_size; j++)
            std::cout << m_matrix[i][j] << "\t";
        std::cout << std::endl;
    }
    std::cout << "---------------------" << std::endl << std::endl;
}
