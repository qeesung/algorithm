#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

//归并排序的核心操作
//输入一个子数组，具有左边界left以及右边界right
void MERGE(int subArray[],const int left, const int right)
{
	if(left >= right)
		return;
	int center = (left+right)/2;
	MERGE(subArray,left,center);
	MERGE(subArray,center+1,right);
	//创建两个子数组
	int leftArrayLength = center-left+2;
	int rightArrayLength = right-center+1;
	int leftSubArray[leftArrayLength];//这里需要添加一个无穷大的哨兵，避免每次的边界检测
	int rightSubArray[rightArrayLength];
	int i,j;
	int k;
/*	printf("%d+++%d\n",leftArrayLength,rightArrayLength );
	printf("%s+++++++center:%d++++left:%d+++++right:%d+++\n","left",center,left,right );
*/	for(i=0;i<leftArrayLength-1;++i)
	{
		leftSubArray[i]=subArray[i+left];
	}
/*	printf("\n");
	printf("%s+++++++center:%d++++left:%d+++++right:%d+++\n","right",center,left,right );
*/	for(j=0;j<rightArrayLength-1;++j)
	{
		rightSubArray[j]=subArray[j+center+1];
	}
	leftSubArray[leftArrayLength-1]=INT_MAX;//哨兵
	rightSubArray[rightArrayLength-1]=INT_MAX;

	//开始归并,依次取出最小的放入到目标数组里面
	i=0;
	j=0;
	for(k=left;k<=right;++k)
	{
		if(leftSubArray[i] >= rightSubArray[j])
		{
			subArray[k]=rightSubArray[j];
			++j;
		}
		else
		{
			subArray[k]=leftSubArray[i];
			++i;
		}
	}
}


void mergeSort(int inputArray[] ,const int arrayLength)
{
	MERGE(inputArray,0,arrayLength-1);
}



int main(int argc, char const *argv[])
{
	int i=0;
	int array[]={10,6,9,3,1,8,2,5,4,7};	
	mergeSort(array,sizeof(array)/sizeof(int));
	for(i=0;i<sizeof(array)/sizeof(int);++i)
	{
		printf("%d\t",array[i]);
	}
	printf("\n");
	return 0;
}