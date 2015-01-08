#include <iostream>
#include "matrix.h"

using namespace std;

int main(int argc, char const *argv[])
{
	int array1[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int array2[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	Matrix matrix1(array1,3);
	Matrix matrix1(array2,3);
	Matrix result = matrix1 * matrix2;
	return 0;
}