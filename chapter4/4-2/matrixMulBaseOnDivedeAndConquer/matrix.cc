#include "matrix.h"
#include <iostream>

Matrix::Matrix(const int **inputArray , const int & _dimension):_dimension(dimension)
{
	if(inputArray != NULL)
		for (int i = 0; i < dimension; ++i)
		{
			for(int j=0;j<dimension;++j)
			{
				node[i][j]=inputArray[i][j];
			}
		}
	else
		for (int i = 0; i < dimension; ++i)
		{
			for(int j=0;j<dimension;++j)
			{
				node[i][j]=0;
			}
		}
}

Matrix::Matrix(const Matrix & matrix):dimension(matrix.dimension)
{
	for (int i = 0; i < dimension; ++i)
	{
		for(int j=0;j<dimension;++j)
		{
			node[i][j]=matrix.node[i][j];
		}
	}	
}

const Matrix& Matrix::operator=(const Matrix & matrix)
{
	if(matrix.dimension!=dimension)
		return *this;
	for (int i = 0; i < dimension; ++i)
	{
		for(int j=0;j<dimension;++j)
		{
			node[i][j]=matrix.node[i][j];
		}
	}	
	return *this;
}

Matrix Matrix::operator*(const Matrix & matrix) const
{
	if(matrix.dimension != dimension)
		return Matrix(0,matrix.dimension);
	if(this->dimension == matrix.dimension )
	{
		Matrix newMatrix(0,1);
		newMatrix.node[0][0] = node[0][0]*matrix.node[0][0];
		return newMatrix;
	}
	Matrix A11 = subMatrix(0,0,dimension/2);
	Matrix A12 = subMatrix(dimension/2,0,dimension/2);
	Matrix A21 = subMatrix(0,dimension/2,dimension/2);
	Matrix A22 = subMatrix(dimension/2,dimension/2,dimension/2);
	C11=A11*B11 + A12*A21;
	C12=A11*B12 + A12*B22;
	C21=A21*B11 + A22*B21;
	C22=A21*B12 + A22*B22;
	Matrix C(0,dimension);
	C.Merge(0,0,C11);
	C.Merge(dimension/2,0,C12);
	C.Merge(0,dimension/2,C21);
	C.Merge(dimension/2,dimension/2,C22);
	return C;
}

Matrix Matrix::operator+(const Matrix & matrix) const
{
	if(matrix.dimension != dimension)
		return Matrix(0,matrix.dimension);
	Matrix newMatrix(0,matrix.dimension);
	for (int i = 0; i < dimension; ++i)
	{
		for(int j=0;j<dimension;++j)
		{
			newMatrix.node[i][j]=node[i][j]+matrix.node[i][j];
		}
	}
	return newMatrix;
}

Matrix Matrix::operator+(const Matrix & matrix) const
{
	if(matrix.dimension != dimension)
		return Matrix(0,matrix.dimension);
	Matrix newMatrix(0,matrix.dimension);
	for (int i = 0; i < dimension; ++i)
	{
		for(int j=0;j<dimension;++j)
		{
			newMatrix.node[i][j]=node[i][j]-matrix.node[i][j];
		}
	}
	return newMatrix;
}

Matrix Matrix::subMatrix(int & x , int & y , int & dimension) const
{
	if(dimension < 0)
		return Matrix(0,0);
	if(this->dimension-x < dimension || this->dimension-y < dimension)
		std::cerr<<"wrong sub matrix border"<<std::endl;
	Matrix newMatrix(0,dimension);
	for (int i = x; i < x+dimension; ++i)
	{
		for(j=y;j<y+dimension;++j)
		{
			newMatrix->node[i-x][j-y]=this->node[i][j];
		}
	}
	return newMatrix;
}