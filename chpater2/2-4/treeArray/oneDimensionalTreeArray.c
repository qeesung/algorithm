#include <stdio.h>
#include <stdlib.h>
//这里需要构造的时一个一维的树状数组

int lowbit(const int indexNumber)
{
	return indexNumber&(-indexNumber);
	//这里采用补码的思想
}


// index表示更行的那个数组的索引
void updateTreeArray(int treeArray[],int index , const int value)
{	
	// 其中treeArray[0]表示了数组的长度
	while(index <=treeArray[0])//将所有的父节点更新
	{
		treeArray[index]+=value;
		index+=lowbit(index);
	}
	return ;
}


//计算前N1到N2之间的元素的和
int getSumN(const int treeArray[] ,int index)
{
	if(index < 1 || index > treeArray[0])
	{
		fprintf(stderr, "%s\n","wrong array index" );
		return 0;
	}
	int sum=0;
	while(index > 0)
	{
		sum += treeArray[index];
		index -= lowbit(index); 
	}
	return sum;
}

//在基于array的基础上创建树状数组
void createTreeArray(int treeArray[], const int array[])
{
	int i=0;
	int j=0;
	for(i=0;i<=array[0];++i)
	{
		treeArray[i]=0;
	}

	for (i = 1; i <=array[0]; ++i)
	{
		for(j=i-lowbit(i)+1;j<=i;++j)
		{
			treeArray[i]+=array[j];
		}
	}
	treeArray[0]=array[0];
	return ;
}

void printArray(const int array[])
{
	int i=0;
	for(i=1;i<=array[0];++i)
	{
		printf("%d\t",array[i] );
	}
	printf("\n");
}

void setValue(int array[]  ,int treeArray[] , int index , int value )
{
	int temp = value-array[index];
	if(index < 1 || index > array[0])
		return;
	array[index]=value;
	updateTreeArray(treeArray , index , temp);
}

int main(int argc, char const *argv[])
{
	int i=0,j=0;
	int array[]={10,1,2,3,4,5,6,7,8,9,10};//第一位表示对应的元素个数
	int treeArray[sizeof(array)/sizeof(int)];
	createTreeArray(treeArray , array);
	setValue(array ,treeArray, 2 , 0);
	printArray(array);
	printArray(treeArray);
	while(1)
	{
		int temp;
		printf("%s",">" );
		scanf("%d",&temp);
		printf("%d\n",getSumN(treeArray,temp));
	}
	return 0;
}