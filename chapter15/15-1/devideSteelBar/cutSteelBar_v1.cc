/**
 * 这个是自顶向下的求法
 */
#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

#define KIND_SIZE 11
/** 每种长度的基本价格 */
int price[]={0,1,5,8,9,10,17,17,20,24,30};

int dealMaxProfit(int n , int maxProfit[]);
/**
 * 得到最大的利润
 * @param  n 钢条长度
 * @return   最大利润
 */
int getMaxProfit(int n)
{   
    if( n < 0 || n > KIND_SIZE)
        return 0;
    int maxProfit[KIND_SIZE];//记录每个长度下的最大利润是多少
    for (int i = 0; i <  KIND_SIZE ; ++i)
    {
        maxProfit[i] = INT_MIN;  
    }
    maxProfit[0] = 0;
    dealMaxProfit(n , maxProfit);
    return maxProfit[n];
}

/**
 * 将每个长度对应的比n小的钢条最大利润都保存在maxProfit里面
 * @param n         钢条长度
 * @param maxProfit 保存最大利润的数组
 * @return          返回长度为n的最大利润
 */
int dealMaxProfit(int n , int maxProfit[])
{
    if( n == 0)
        return 0;
    /** 表示之前已经算过了 */
    if(maxProfit[n]!= INT_MIN)
        return maxProfit[n];
    /** 没有算过那么就算一遍 */
    int max = INT_MIN;
    for (int i = 1; i < n+1; ++i)
    {
        int temp = price[i]+dealMaxProfit(n-i, maxProfit); 
        if(max < temp)
            max = temp;
    }
    maxProfit[n] = max;
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