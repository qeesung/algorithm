#ifndef _TREEARRAY_H
#define _TREEARRAY_H

//树状数组的通用接口

struct treeArray_t
{
	int * node;	
	int treeLength;
};

typedef struct treeArray_t * TreeArray;


static int lowbit(const int number)
{
	  return number&(-number);
}

//创建一个数组并将其初始化
void createTreeArray( TreeArray * treeArrayPtr , const int inputArray[] , const int arrayLength);
//更新一个树状数组
void updateTreeArray(TreeArray treeArray ,int index , const int num );
//求前n项和的值
int getSumN(TreeArray treeArray , int index );
//销毁一个树状数组
void destoryTreeArray(TreeArray treeArray);
//打印一个treearray
void printTreeArray(const TreeArray treeArray);


#endif