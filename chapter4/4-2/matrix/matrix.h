#ifndef _MATRIX_H
#define _MATRIX_H

#define MAXDIMENSION 20
struct matrix
{
	int node[MAXDIMENSION][MAXDIMENSION];
	unsigned int dimension;
};
typedef struct matrix * Matrix;

// //创建一个矩阵
// Matrix createMatrix(const int inputArray[][] , const int arrayLength );
// //矩阵相乘
// Matrix matrixMul(Matrix matrix1 , Matrix matrix2);
// //矩阵相加
// Matrix matrixAdd(Matrix matrix1 , Matrix matrix2);
// //矩阵相减
// Matrix matrixSub(Matrix matrix1 , Matrix matrix2);

// //


#endif