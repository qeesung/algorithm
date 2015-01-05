#include <stdio.h>
#include <stdlib.h>


//通过归并排序来计算逆序对的数量
int MERGE(int subArray[] , const int left , const int right)
{
	if(left >= right)
		return 0;
	int reversePairCount = 0;
	int i ,j,k;
	int center = (left+right)/2;
	//计算左边和右边的逆序对的总数
	reversePairCount+=MERGE(subArray , left , center);
	reversePairCount+=MERGE(subArray , center+1 , right);
	//左右边的子数组
	const int leftSubArrayLength = center-left+1;
	const int rightSubArrayLength = right-center;
	int leftSubArray[leftSubArrayLength];
	int rightSubArray[rightSubArrayLength];

	for(i=0;i<leftSubArrayLength;++i)
	{
		leftSubArray[i]=subArray[left+i];
	}
	for(j=0;j<rightSubArrayLength;++j)
	{
		rightSubArray[j]=subArray[j+center+1];
	}

	i=0;j=0;k=0;
	while(i<leftSubArrayLength && j<rightSubArrayLength)
	{
		if(leftSubArray[i]>rightSubArray[j])
		{
			subArray[k+left]=rightSubArray[j++];
			reversePairCount++;
			++k;
		}
		else
		{
			subArray[k+left]=leftSubArray[i++];
			++k;
		}
	}
	//辨别哪一个数组为空了
	if(j==rightSubArrayLength)//右边数组空了
	{
		reversePairCount+=(leftSubArrayLength-i-1)*rightSubArrayLength;
		while(i<leftSubArrayLength)
		{
			subArray[k+left] = leftSubArray[i];
			++k;
			++i;
		}
	}
	else
	{
		while(j<rightSubArrayLength)
		{
			subArray[k+left]=rightSubArray[j];
			++k;
			++j;
		}
	}
	//剩下的元素基体搬家
	return reversePairCount;
}

int reversePair(const int inputArray[] , const int arrayLength)
{
	int tempArray[arrayLength];
	int i=0;
	int count;
	for(i=0;i<arrayLength ; ++i)
	{
		tempArray[i]=inputArray[i];
	}
	count=MERGE(tempArray , 0 , arrayLength-1);
	for(i=0;i<arrayLength;++i)
	{
		printf("%d\t", tempArray[i]);
	}
	printf("\n" );
	return count;
}


int main(int argc, char const *argv[])
{
	int array[]={9,1,0,5,4};
	printf("reverse pair number is:%d\n",reversePair(array , sizeof(array)/sizeof(int)));
	return 0;
}