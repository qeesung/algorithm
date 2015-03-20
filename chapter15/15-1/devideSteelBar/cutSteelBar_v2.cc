#include <iostream>
#include <limits.h>
#include <string>

using namespace std;
#define KIND_SIZE 11
/** 这个是每一个长度下的单价 */
int price[]={0,1,5,8,9,10,17,17,20, 24 ,30};

int dealMaxProfit(int n , int maxProfit[]);
/**
 * 得到最大的利润
 * @param  n 钢条的长度
 * @return   最大的利润
 */
int getMaxProfit(int n)
{
    if(n < 0 || n > KIND_SIZE)
        return 0;
    int maxProfit[KIND_SIZE];
    for (int i = 0; i < KIND_SIZE; ++i)
    {
        maxProfit[i] = INT_MIN;
    }
    maxProfit[0] = 0;
    dealMaxProfit(n , maxProfit);
    return maxProfit[n];
}

/**
 * 处理得到<n长度的利润
 * @param  n         钢条的长度
 * @param  maxProfit 最大的利润
 * @return           对应长度为n的最大的利润
 */
int dealMaxProfit(int n , int maxProfit[])
{
    if(n == 0)
        return 0;
    for (int i = 1; i <= n; ++i)
    {
        int max = INT_MIN;
        for (int j = 1; j <= i; ++j)
        {// 每次都是将最优子结构求出来，再求上层的
            int temp = price[j]+maxProfit[i-j];
            if(max < temp)
                max = temp;
        } 
        maxProfit[i] = max;
    }
}

int main(int argc, char const *argv[])
{
    while(1)
    {   
        int steelBarLen; 
        cout<<"Enter the steel Bar Length(0-10)>";
        cin >> steelBarLen;
        cout<<"Max profit is : "<<getMaxProfit(steelBarLen)<<endl;
    }
    return 0;
}