#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArray(const int * , const int);
void insertSort(int inputArray[] ,const int arrayLength)
{
	int i,j;
	int tempArray[arrayLength+1];
	//inputArray重新复制到tempArray里面
	for (i = 0; i < arrayLength; ++i)
	{
		tempArray[i+1]=inputArray[i];
	}
	tempArray[0]=0;
	//下面开始对带有哨兵的 tempArray进行排序
	for (i = 1; i <= arrayLength; ++i)
	{
		int temp = tempArray[i];
		for (j = i; temp < tempArray[j-1] ; --j)
		{
			tempArray[j]=tempArray[j-1];
		}
		tempArray[j]=temp;
		// printArray(tempArray,arrayLength+1);
	}
	for (i = 0;i<arrayLength; ++i)
	{
		inputArray[i]=tempArray[i+1];
	}
}

void printArray(const int inputArray[],const int arrayLength)
{
	int i;
	for(i=0;i<arrayLength;++i)
	{
		printf("%d\t",inputArray[i] );
	}
}

int main(int argc, char const *argv[])
{
	int i=0;
	srand((int)time(NULL));
	int array[10];
	for(i=0;i<sizeof(array)/4;++i)
	{
		array[i]=rand()%100;
	}
	printArray(array,sizeof(array)/4);
	insertSort(array,sizeof(array)/4);
	printArray(array,sizeof(array)/4);
	while(1);
	return 0;
}