#include <stdio.h>
#include <stdlib.h>

void insertSort(int inputArray[] , int arrayLength)
{
	//加入一个哨兵来加速整个排序的过程
	int i,j;
	int temp = inputArray[0];//把第一个元素提取出来保存
	for (i = 1; i < arrayLength ; ++i)
	{
		int k=0;
		inputArray[0] = inputArray[i];
		// 这里算法是稳定的
		for (j = i; inputArray[0] < inputArray[j-1] ; --j)
		{
			inputArray[j]=inputArray[j-1];
		}
		inputArray[j]=inputArray[0];
	}
	inputArray[0]=temp;
	//再把之前保存的第一个元素temp插入到数组里面
	for (i = 1;inputArray[i]<temp && i < arrayLength; ++i)
	{
			inputArray[i-1]=inputArray[i];
	}
	inputArray[i-1]=temp;

}

void printArray(int inputArray[],int arrayLength)
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