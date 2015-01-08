#include <stdio.h>
#include <stdlib.h>
#include "../matrix/matrix.h"

Matrix matrixMul(Matrix matrix1 , Matrix matrix2)
{
	int i,j,k1,k2;
	if(matrix1->dimension != matrix2->dimension)
	{
		fprintf(stderr, "%s\n","two matrix arguments must have same dimension" );
		return NULL;
	}
	Matrix  newMatrix  = (Matrix)malloc(sizeof(struct matrix));
	if(newMatrix == NULL)
	{
		fprintf(stderr, "%s\n","Out Of Space!" );
		return NULL;
	}

	for(i=0;i<matrix1->dimension;++i)
	{	
		for(j=0;j<matrix1->dimension;++j)
		{
			int sum=0;
			for(k1=0;k1<matrix1->dimension;++k1)
			{
				sum+=matrix1->node[i][k1]*matrix2->node[k1][j];
			}
			newMatrix->node[i][j]=sum;
		}
	}
	newMatrix->dimension=matrix1->dimension;
	return newMatrix;
}

void printMatrix(Matrix matrix)
{
	int i,j;
	for(i=0;i<matrix->dimension;++i)
	{
		for(j=0;j<matrix->dimension;++j)
		{
			printf("%d\t", matrix->node[i][j]);
		}
		printf("\n");
	}
}

Matrix createMatrix(int (*inputArray)[3] , const int dimension)
{
	int i,j;
	Matrix newMatrix = (Matrix)malloc(sizeof(struct matrix));
	if(newMatrix==NULL)
	{
		fprintf(stderr, "%s\n","Out Of Space" );
		return NULL;
	}
	for(i=0;i<dimension;++i)
	{
		for(j=0;j<dimension;++j)
		{
			newMatrix->node[i][j] = inputArray[i][j];
		}
	}
	newMatrix->dimension=dimension;
}

int main(int argc, char const *argv[])
{
	int array1[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int array2[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	Matrix matrix1 = createMatrix(array1 , 3);
	Matrix matrix2 = createMatrix(array2, 3);
	Matrix matrix3 = NULL;
	printMatrix(matrix1);
	printf("-----------------------\n");
	printMatrix(matrix2);
	matrix3= matrixMul(matrix1, matrix2);
	if(matrix3 != NULL)
	{
		printf("-----------------------\n");
		printMatrix(matrix3);
	}
	free(matrix1);
	free(matrix2);
	free(matrix3);
	return 0;
}