#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <string>

using namespace std;
#define KIND_SIZE 11
/** 这个是每一个长度下的单价 */
int price[]={0,1,5,8,9,10,17,17,20, 24 ,30};

int dealMaxProfit(int n , int maxProfit[] , int devidePos[]);
/**
 * 得到最大的利润
 * @param  n 钢条的长度
 * @return   最大的利润
 */
int getMaxProfit(int n , int devidePos[])
{
    if(n < 0 || n > KIND_SIZE)
        return 0;
    int maxProfit[KIND_SIZE];
    for (int i = 0; i < KIND_SIZE; ++i)
    {
        maxProfit[i] = INT_MIN;
        devidePos[i] = i;
    }
    maxProfit[0] = 0;
    dealMaxProfit(n , maxProfit , devidePos);
    return maxProfit[n];
}

/**
 * 处理得到<n长度的利润
 * @param  n         钢条的长度
 * @param  maxProfit 最大的利润
 * @return           对应长度为n的最大的利润
 */
int dealMaxProfit(int n , int maxProfit[] , int devidePos[])
{
    if(n == 0)
        return 0;
    for (int i = 1; i <= n; ++i)
    {
        int max = INT_MIN;
        int pos=i;
        for (int j = 1; j <= i; ++j)
        {// 每次都是将最优子结构求出来，再求上层的
            int temp = price[j]+maxProfit[i-j];
            if(max < temp)
            {
                max = temp;
                pos = j;
            }
        } 
        devidePos[i] = pos;
        maxProfit[i] = max;
    }
}

void printCutSolution(int n , int devidePos[])
{
    if(n < 0 || n >= KIND_SIZE)
        return ;
    if( n == devidePos[n])
    {
        printf("%s\n", "not devide" );
        return;
    }
    printf("%d steel bar device into %d and %d \n", n , n - devidePos[n] , devidePos[n] );
    printCutSolution(n - devidePos[n] , devidePos);
}

int main(int argc, char const *argv[])
{
    while(1)
    {   
        int devidePos[KIND_SIZE];
        int steelBarLen; 
        cout<<"Enter the steel Bar Length(0-10)>";
        cin >> steelBarLen;
        cout<<"Max profit is : "<<getMaxProfit(steelBarLen , devidePos)<<endl;
        printCutSolution(steelBarLen , devidePos);
    }
    return 0;
}