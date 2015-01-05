#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int getMaxSubArray(const int inputArray [] , const int arrayLength , int * leftBorder ,  int * rightBorder)
{
	int i,j;
	int left,right;
	int max=INT_MIN;
	int sum=0;
	for(i=0;i<arrayLength ;++i)
	{
		sum=0;
		for(j=i;j<arrayLength;++j)
		{
			sum+=inputArray[j];
			if(sum > max)
			{
				left = i;
				right = j;
				max = sum;
			}
		}
	}
	*leftBorder = left;
	*rightBorder = right;
	return max;
}

int main(int argc, char const *argv[])
{
	const int array[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	int leftBorder,rightBorder;
	int max = getMaxSubArray(array , sizeof(array)/sizeof(int) , &leftBorder , &rightBorder);
	printf("from %d to %d is the max sub array and the max value is : %d \n",leftBorder , rightBorder , max );
	return 0;
}