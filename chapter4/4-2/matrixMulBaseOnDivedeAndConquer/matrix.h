#ifndef _MATRIX_H
#define _MATRIX_H


class Matrix
{
public:
	Matrix(const int **inputArray , const int & dimension);
	~Matrix(){};
	Matrix(const Matrix & matrix);

	//赋值运算符
	const Matrix& operator=(const Matrix & matrix);
	//矩阵乘法
	Matrix operator*(const Matrix & matrix)const;
	//矩阵加法
	Matrix operator+(const Matrix & matrix)const;
	//矩阵减法
	Matrix operator-(const Matrix & matrix)const;
	//得到矩阵的一个子矩阵
	Matrix subMatrix(const int & x , const int & y , const int & dimension) const;
private:
	const int dimension;//维数
	int node[dimension][dimension];//每一个节点的数据
};

#endif