/**
 * 这个是自顶向下的求法
 */
#include <iostream>
#include <string>
#include <limits.h>
 #include <stdio.h>

using namespace std;

#define KIND_SIZE 11
/** 每种长度的基本价格 */
int price[]={0,1,5,8,9,10,17,17,20,24,30};

int dealMaxProfit(int n , int maxProfit[] , int devidePos[]);
/**
 * 得到最大的利润
 * @param  n 钢条长度
 * @return   最大利润
 */
int getMaxProfit(int n , int devidePos[])
{   
    if( n < 0 || n > KIND_SIZE)
        return 0;
    int maxProfit[KIND_SIZE];//记录每个长度下的最大利润是多少
    for (int i = 0; i <  KIND_SIZE ; ++i)
    {
        maxProfit[i] = INT_MIN;
        devidePos[i] = i; 
    }
    maxProfit[0] = 0;
    dealMaxProfit(n , maxProfit , devidePos);
    return maxProfit[n];
}

/**
 * 将每个长度对应的比n小的钢条最大利润都保存在maxProfit里面
 * @param n         钢条长度
 * @param maxProfit 保存最大利润的数组
 * @return          返回长度为n的最大利润
 */
int dealMaxProfit(int n , int maxProfit[] , int devidePos[])
{
    if( n == 0)
        return 0;
    /** 表示之前已经算过了 */
    if(maxProfit[n]!= INT_MIN) 
        return maxProfit[n];
    /** 没有算过那么就算一遍 */
    int max = INT_MIN;
    int pos = n;xia
    for (int i = 1; i < n+1; ++i)
    {
        int temp = price[i]+dealMaxProfit(n-i, maxProfit  ,devidePos); 
        if(max < temp)
        {
            max = temp;
            pos = i;
        }
    }
    maxProfit[n] = max;
    devidePos[n] = pos;
    return max;
}

/**
 * 检验输入的字符串是不是全是数字
 * @param  str 数字的字符串
 * @return     全是数字为 true , 否则false
 */
bool inputIsNumber(std::string & str)
{
    for (std::string::iterator iter = str.begin(); iter != str.end(); ++iter)
    {
        if(isdigit(*iter))
            return false;
    }
    return true;
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