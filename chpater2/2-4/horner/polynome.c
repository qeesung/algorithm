#include <stdio.h>
#include <stdlib.h>

//用霍纳规则来求解多项式的解


//得到X^n的值
int getXn(const int x , const int n)
{
	if(n==1)
		return x;
	if(n==0)
		return 1;
	int temp = getXn(x , n/2);
	//偶数情况
	if(n%2==0)
		return temp*temp;
	//基数情况
	else
		return temp*temp*x;


}

// 传入参数为多项式系数ai,对应的多项式的乘积因子，maxIndex是多项式里面的最大的那个系数，也是数组的长度
// 其实这里可以使用链表来简化数组长度的因素
int polynomeNormal(const int ai[] ,const int x, const int maxIndex)
{
	int result = 0;
	int i=0;
	for (i = 0; i <=maxIndex; ++i)
	{
		result+=ai[i]*getXn(x,i);
	}	
	return result;
}

//这个是霍纳解法
int polynomeHorner(const int ai[] , const int x , const int maxIndex)
{
	int result=0;
	int i=0;
	for(i=maxIndex;i>=0;--i)
	{
		result =ai[i]+x*result;
	}
	return result;
}


int main(int argc, char const *argv[])
{
	int ai[]={-5,1,3,-1,2};
	int x = 3;
	int maxIndex=4;
	printf("normal algorithm:%d\n",polynomeNormal(ai , x, maxIndex));
	printf("hornor algorithm:%d\n",polynomeHorner(ai , x, maxIndex));
	return 0;
}
