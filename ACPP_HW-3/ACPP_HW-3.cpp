#include <iostream>
#include "ArithmeticMean.h"
#include "Matrix.h"

int main()
{
	std::list<double> DList{ 0.35, 3.65, 1.0, -3.70, -0.25 };
	AMean(DList);
    std::cout << "DList contains ";
    for (auto n : DList)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    size_t mat_size = 2;
    Matrix matrix(mat_size);
    for (size_t i = 0; i < mat_size; i++)
        for (size_t j = 0; j < mat_size; j++)
            matrix.SetValue((double) i+j, i, j);
    matrix.mPrint();
    std::cout << "matrix determinant: " << matrix.GetDet() << std::endl;


}
