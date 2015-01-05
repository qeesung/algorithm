#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int MAXSUB(const int subArray[] , const int left , const int right , int * leftBorder , int * rightBorder)
{
	if(left==right)
	{
		*leftBorder = left;
		*rightBorder = right;
		return subArray[left];
	}
	// 求解出左右两边的最大子序列
	//并将对应的位置存放在L_* 和R_*里面
	const int mid = (left+right)/2;
	int L_leftSubBorder , L_rightSubBorder;
	int R_leftSubBorder , R_rightSubBorder;
	const int leftMax = MAXSUB(subArray , left , mid , &L_leftSubBorder , &L_rightSubBorder);
	const int rightMax = MAXSUB(subArray , mid+1 , right , &R_leftSubBorder , &R_rightSubBorder);
	//求出中间最大的那个值
	int M_leftSubBoder = mid ;
	int M_rightSubBorder = mid+1;
	int leftMidMax = INT_MIN;
	int rightMidMax = INT_MIN;
	int i,j,sumTemp=0;
	//求i到mid最大的左边部分
	for(i=M_leftSubBoder ; i>=left;--i)
	{		
		sumTemp += subArray[i];
		if(sumTemp > leftMidMax)
		{
			M_leftSubBoder = i;
			leftMidMax = sumTemp;
		}
	}
	//求mid+1到j最大的那个
	sumTemp=0;
	for(j=M_rightSubBorder ; j<=right ; ++j)
	{
		sumTemp += subArray[j];
		if(sumTemp > rightMidMax)
		{
			M_rightSubBorder = j;
			rightMidMax = sumTemp;
		}
	}

	//判断三个里面哪一个比较大
	if(leftMax > rightMax && leftMax > (leftMidMax  + rightMidMax))
	{
		*leftBorder = L_leftSubBorder;
		*rightBorder = L_rightSubBorder;
		return leftMax;
	}
	else if(rightMax  > leftMax && rightMax > (leftMidMax + rightMidMax))
	{
		*leftBorder = R_leftSubBorder;
		*rightBorder = R_rightSubBorder;
		return rightMax;
	}
	else /*if((leftMidMax+rightMidMax) > leftMax && (leftMidMax + rightMidMax) > rightMax)*/
	{
		*leftBorder = M_leftSubBoder;
		*rightBorder = M_rightSubBorder;
		return (leftMidMax + rightMidMax);
	}
}


//得到最大的子序列，并将边界赋值给leftBorder and rightBorder
int getMaxSubArray(const int inputArray[]  , const int arrayLength , int * leftBorder , int * rightBorder)
{
	return MAXSUB(inputArray , 0 , arrayLength-1 , leftBorder , rightBorder);
}

int main(int argc, char const *argv[])
{
	const int array[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	int leftBorder,rightBorder;
	int max = getMaxSubArray(array , sizeof(array)/sizeof(int) , &leftBorder , &rightBorder);
	printf("from %d to %d is the max sub array and the max value is : %d \n",leftBorder , rightBorder , max );
	return 0;
}