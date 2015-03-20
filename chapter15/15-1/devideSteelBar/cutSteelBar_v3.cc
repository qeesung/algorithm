#include <iostream>
#include <limits.h>
using namespace std;

#define KIND_SIZE 11
#define COST 2
/** 每种长度的基本价格 */
int price[]={0,1,5,8,9,10,17,17,20,24,30};

int dealMaxProfit(int , int *);
int getMaxProfit(int n)
{
    if(n <=0 || n >= KIND_SIZE)
        return 0;
    int maxProfit[KIND_SIZE];
    for (int i = 0; i <KIND_SIZE; ++i)
    {
        maxProfit[i] = INT_MIN;
    }
    dealMaxProfit(n , maxProfit);
    return maxProfit[n];
}

int dealMaxProfit(int n , int maxProfit[])
{
    maxProfit[0] = 0;
    for (int i = 1; i < KIND_SIZE; ++i)
    {
        int max = INT_MIN;
        for (int j = 1; j < i ; ++j)
        {
            int maxTemp = price[j]+maxProfit[i-j]-COST;
            if(max < maxTemp)
                max = maxTemp;
        }
        max = max>price[i]?max:price[i];
        maxProfit[i] = max;
    }
    return maxProfit[n];
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