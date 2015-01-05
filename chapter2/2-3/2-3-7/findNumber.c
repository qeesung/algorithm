#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// 给定一个整数X和一个序列S，在S里面找出两个数a1,a2,使得a1+a2=X。
// 1.这里首先采用归并排序将S进行排序(nlogn)
// 2.然后遍历整个数组，对数组里面的每一个元素S[i]，都用二分查找的方法来查找S[i]-X元素(nlogn)

static void MERGE(int subArray[] , const int left , const int right)
{
	if(left>=right)
		return;
	int center = (left+right)/2;
	//再递归求解子问题
	MERGE(subArray , left, center);
	MERGE(subArray , center+1 , right);
	//说明之前的两个子数组已经有序了，循环不变式成立
	const int leftSubArrayLength=center-left+2;
	const int rightSubArrayLength=right-center+1;
	int leftSubArray[leftSubArrayLength];
	int rightSubArray[rightSubArrayLength];
	int i,j,k;
	//开始赋值
	for (i = 0; i < leftSubArrayLength-1; ++i)
	{
		leftSubArray[i]=subArray[i+left];
	}
	for(j=0;j<rightSubArrayLength-1;++j)
	{
		rightSubArray[j]=subArray[j+center+1];
	}
	rightSubArray[rightSubArrayLength-1]=INT_MAX;
	leftSubArray[leftSubArrayLength-1]=INT_MAX;
	//将数组导入到原数组里面去
	i=0;
	j=0;
	for(k=left;k<=right;++k)
	{
		if(leftSubArray[i]<rightSubArray[j])
		{
			subArray[k]=leftSubArray[i];
			++i;
		}
		else
		{
			subArray[k]=rightSubArray[j];
			++j;
		}
	}
	return;
}

void mergeSort(int inputArray[] , const int arrayLength)
{
	MERGE(inputArray,0,arrayLength-1);
}

//二分查找算法
static int binarySearch(const int searchArray[] , const int left,const int right,const int targetNumber)
{
	if(left>right)
		return -1;
	const int center =(left+right)/2;
	if(searchArray[center]==targetNumber)
		return center;
	else if(searchArray[center]>targetNumber)
		return binarySearch(searchArray , left ,center-1,targetNumber);
	else
		return binarySearch(searchArray , center+1 , right , targetNumber);
}

int findPos(const int searchArray[] , const int arrayLength, const int targetNumber)
{
	return binarySearch(searchArray , 0 , arrayLength , targetNumber);
}

bool findNumber(int searchArray[] , const int arrayLength,const int X)
{
	bool flag=false;
	int i=0;
	//进行排序
	mergeSort(searchArray , arrayLength);
	//对数组里面的每一个元素都进行二分查找
	for(i=0;i<arrayLength;++i)
	{
		int temp = X-searchArray[i];
		int pos;
		if((pos = findPos(searchArray , arrayLength, temp))!=-1 && pos !=i && pos > i)
		{
			printf("find : %d --- %d\n",i , pos );
			flag=true;
		}
	}
	return flag;
}

int main(int argc, char const *argv[])
{
	int array[]={10,4,2,6,3,9,1,5,8,7};
	int i;
	printf("\n");
	while(1)
	{
		int temp;
		for(i=0;i<sizeof(array)/sizeof(int);++i)
		{
			printf("%d\t",array[i]);
		}
		printf("\n");
		printf("%s",">");
		scanf("%d",&temp);
		if(!findNumber(array,sizeof(array)/sizeof(int),temp))
			printf("%s\n","can not find!" );
	}
	return 0;
}