#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


//交换number1和number2
inline void exchange(int * number1 , int * number2)
{
	int temp=*number1;
	*number1=*number2;
	*number2=temp;
}


void selectSort(int inputArray[],int arrayLength)
{
	//分析选择排序的算法
	int i,j;                                       //=> c1 1
	int min=INT_MAX;                               //=> c2 1
	int pos=-1;//用于记录最小数据的位置所在             //=> c3 1
	for(i=0;i<arrayLength-1;++i)                   //=> c4 n-1
	{	                                           //=> 
		min = inputArray[i];
		pos=i;
		//下面开始搜寻从i开始的最小数据            	   //=>
		for(j=i;j<arrayLength;++j)             //=> c5 (n-1 + n-2 + n-3 + ... +1)=(n-1)(n)/2
		{                                          //=> 
			if(inputArray[j] < min)                //=>	c6 (n-1)(n)/2
			{                                      //=> 
				min = inputArray[j];               //=> c7 最差(n-1)n/2,最好0*n
				pos = j;//记录位置              	   //=> c8 最差(n-1)n/2，做好0*n
			}                                      //=>
		}                                          //=>
		//交换两个位置的数据                    	   //=>
		exchange(&inputArray[i] , &inputArray[pos]); //=> c9 (n-1)*3
	}                                              //=>
}
//循环不变性就是在排序第j个元素之前，A[0,...,j-1]就已经有序了

//最好的情况：
// c1+c2+c3+c4(n-1)+c5(n-1)n/2+c6(n-1)n/2+c9(n-1)*3=theta n^2
//最坏的情况：
// c1+c2+c3+c4(n-1)+c5(n-1)n/2+c6(n-1)n/2+c7(n-1)n/2+c8(n-1)n/2+c9(n-1)*3=theta n^2


int main(int argc, char const *argv[])
{
	int i=0;
	int array[10]={10,3,4,2,9,6,7,5,1,8};
	selectSort(array,sizeof(array)/sizeof(int));
	for(i=0;i<sizeof(array)/sizeof(int);++i)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
	return 0;
}