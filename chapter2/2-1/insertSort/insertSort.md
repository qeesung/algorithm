#插入排序的算法实现

##自己在实现带有哨兵的插入排序算法的时候，发现有两种思路：  

- 1.在内存里面重新分配一块比输入数组inputArray长度大一的temp数组，空出temp数组的第一个位置，然后把inputArray从第emp数组的第二个位置复制进去，既有temp[i+1]=inputArray[i]，i<arrayLength，再把第一个位置temp[0]赋值一个足够小的数字INT_MIN，以temp[0]为哨兵，进行插入排序，最后再把temp数组从第二个元素(temp[1])开始，重新复制到从第一个元素(inputArray[0])开始的inputArray数组里面，返回。  

- 2.第二种方法就是每开始一次输入，就把将要进行插入inputArray[j]的元素赋值给inputArray[0],这样就可以起到一个哨兵的作用，但是这样做需要把inputArray数组第一个元素暂存起来,否则数组的第一个元素会丢失,最后再把inputArray[0]进行插入处理..

##下面是两种方案的实现:

- 第一种实现
	```
	void insertSort(int inputArray[] ,const int arrayLength)
	{
		int i,j;
		int tempArray[arrayLength+1];
		//inputArray重新复制到tempArray里面
		for (i = 0; i < arrayLength; ++i)
		{
			tempArray[i+1]=inputArray[i];
		}
		tempArray[0]=INT_MIN;
		//下面开始对带有哨兵的 tempArray进行排序
		for (i = 1; i <= arrayLength; ++i)
		{
			int temp = tempArray[i];
			for (j = i; temp < tempArray[j-1] ; --j)
			{
				tempArray[j]=tempArray[j-1];
			}
			tempArray[j]=temp;
		}
		for (i = 0;i<arrayLength; ++i)
		{
			inputArray[i]=tempArray[i+1];
		}
	}
	```

- 第二种实现  
	```
	void insertSort(int inputArray[] , const int arrayLength)
	{
		int i,j;
		int tempArray[arrayLength+1];
		//inputArray重新复制到tempArray里面
		for (i = 0; i < arrayLength; ++i)
		{
			tempArray[i+1]=inputArray[i];
		}
		tempArray[0]=INT_MIN;
		//下面开始对带有哨兵的 tempArray进行排序
		for (i = 1; i <= arrayLength; ++i)
		{
			int temp = inputArray[i];
			for (j = i; temp < tempArray[j-1] ; --j)
			{
				tempArray[j]=tempArray[j-1];
			}
			tempArray[j]=temp;
		}
		for (i = 0;i<arrayLength; ++i)
		{
			inputArray[i]=tempArray[i+1];
		}
	}
	```
- 实验结果：
	```
	#include <stdio.h>
	#include <stdlib.h>  

	void insertSort(int inputArray[],const int arrayLength )
	{
		/*...*/
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
		return 0;
	}
	```
	
<p><a href="http://blog.csdn.net/ii1245712564/article/details/42079225">插入排序的博客地址:http://blog.csdn.net/ii1245712564/article/details/42079225</a></p>

