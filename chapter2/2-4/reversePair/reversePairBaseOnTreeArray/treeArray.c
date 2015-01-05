#include "treeArray.h"
#include <stdio.h>
#include <stdlib.h>

void createTreeArray(TreeArray * treeArrayPtr  , const int inputArray[] , const int arrayLength)
{
	if(arrayLength <=0)
	{
		fprintf(stderr, "%s\n", "array Length should greater than 0 " );
		return;
	}
	int i=0;
	(*treeArrayPtr) = (TreeArray)malloc(sizeof(struct treeArray_t));
	if((*treeArrayPtr) == NULL)
	{
		fprintf(stderr, "%s\n","Out of space!");
		exit(EXIT_FAILURE);
	}
	(*treeArrayPtr)->node = (int *)malloc(sizeof(int)*(arrayLength+1));
	if((*treeArrayPtr)->node == NULL)
	{
		fprintf(stderr, "%s\n","Out of space!");
		exit(EXIT_FAILURE);		
	}
	(*treeArrayPtr)->treeLength = arrayLength+1;

	//下面开始为树状数组赋值
	if(inputArray == NULL)//默认将全部的树状数组初始化为0
	{
		for ( i = 1; i < (*treeArrayPtr)->treeLength; ++i)
		{
			(*treeArrayPtr)->node[i]=0;
		}
	}
	else
	{
		for ( i = 1; i < (*treeArrayPtr)->treeLength; ++i)
		{
			int sum=0;
			int j;
			for ( j = i-lowbit(i)+1; j <=i; ++j)
			{
				sum+=inputArray[j-1];
			}
			(*treeArrayPtr)->node[i]=sum;
		}
	}
}


void updateTreeArray(TreeArray treeArray , int index ,const int num)
{
	if(treeArray==NULL)
		return;
	while(index <= treeArray->treeLength)
	{
		treeArray->node[index]+=num;
		index +=lowbit(index);
	}
}

int getSumN(TreeArray treeArray , int index)
{
	if(treeArray==NULL)
		return;
	int sum=0;
	while(index >0)
	{
		sum+=treeArray->node[index];
		index -=lowbit(index);
	}
	return sum;
}

void destoryTreeArray(TreeArray treeArray)
{
	if(treeArray==NULL)
		return;
	free(treeArray->node);
	free(treeArray);
	treeArray=NULL;
}


void printTreeArray(const TreeArray treeArray)
{
	if(treeArray==NULL)
		return;
	int i;
	for (i = 1; i < treeArray->treeLength; ++i)
	{
		printf("%d\t",treeArray->node[i]);
		// printf("%d\t",getSumN(treeArray , i));
		fflush(stdout);
	}
	printf("\n");
}