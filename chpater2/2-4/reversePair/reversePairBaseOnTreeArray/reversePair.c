#include "reversePair.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void MERGE(struct disrect_s subArray[] , int left , int right)
{
	if(left >= right)
		return;
	int mid = (left+right)/2;

	MERGE(subArray , left , mid);
	MERGE(subArray , mid+1 , right);

	int i=0;
	int j=0;
	int k=0;

	int leftSubArrayLength=mid-left+2;
	int rightSubArrayLength = right-mid+1;
	struct disrect_s leftSubArray[leftSubArrayLength];
	struct disrect_s rightSubArray[rightSubArrayLength];

	for(i=0;i<leftSubArrayLength-1;++i)
	{
		leftSubArray[i]=subArray[left+i];
	}
	for(j=0;j<rightSubArrayLength-1;++j)
	{
		rightSubArray[j]=subArray[mid+1+j];
	}
	leftSubArray[leftSubArrayLength-1].value=INT_MAX;
	rightSubArray[rightSubArrayLength-1].value=INT_MAX;
	//merge
	i=0;
	j=0;
	for(k=left;k<=right;++k)
	{
		if(leftSubArray[i].value<=rightSubArray[j].value)
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


void mergeSort(struct disrect_s inputArray[] , const int arrayLength)
{
	MERGE(inputArray , 0 , arrayLength-1);
}


int reverserPairNumber(const int inputArray[] , const int arrayLength)
{
	TreeArray treeArray=NULL;
	struct disrect_s disrectArray[arrayLength];
	int reversePairCount=0;

	int tempArray[arrayLength];
	int i;
	//赋值
	for (i = 0; i < arrayLength; ++i)
	{
		disrectArray[i].value = inputArray[i];
		disrectArray[i].index=i;
	}
	//以nlogn来排序
	mergeSort(disrectArray , arrayLength);

	for(i=0 ; i<arrayLength ;++i)
	{
		tempArray[disrectArray[i].index]=i+1;
	}
	for (i = 0; i < arrayLength; ++i)
	{
		printf("%d\t", tempArray[i]);
	}
	//一个一个的插入到树状数组里面去
	createTreeArray(&treeArray,NULL,arrayLength);
	for (i = 0; i < arrayLength; ++i)
	{
		// fprintf(stderr, "%s+++%d\n","Hello1",tempArray[i] );
	 	updateTreeArray(treeArray,tempArray[i],1);
	 	reversePairCount+=(i+1-getSumN(treeArray , tempArray[i]));//加上每个对应逆序对的数量
		// fprintf(stderr, "%s\n","Hello2" );
	}
	return reversePairCount;
}