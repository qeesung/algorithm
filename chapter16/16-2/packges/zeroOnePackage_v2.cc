/*************************************************
* @Filename:    zeroOnePackage_v2.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-04-30 14:43:56
* @Version:     1.0
* @Description: 自下而上的求解背包问题，动态规划
**************************************************/

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

#define MAX(a , b) ((a)>(b)?(a):(b))
/** 背包的容量 */
#define PACKAGE_CAPACITY 50
/** 最多有十个商品 */
#define MAX_GOODS_NUM 10
/** 用来保存商品没有没有选中过 */
bool packageChoose[MAX_GOODS_NUM];
/** 用来存储对应的最大价值 maxValue[i][w]表示后面i个商品装入w容量背包最大价值 */
unsigned maxValue[MAX_GOODS_NUM][PACKAGE_CAPACITY+1];

/**
 * 求得goodslist对应的最大价值
 * @param  goodsList 商品列表
 * @return           最大价值
 */
unsigned zeroOnePackage(std::vector<pair<unsigned , unsigned> > goodsList)
{
    for (int i = 0; i < MAX_GOODS_NUM; ++i)
    {
        packageChoose[i]=false;
    }
    for(int k = goodsList[goodsList.size()-1].second; k <= PACKAGE_CAPACITY  ; ++k)
    {
        maxValue[goodsList.size()-1][k] = goodsList[goodsList.size()-1].first;
    }
    /** 自下而上 */
    for (int i = goodsList.size()-2; i >=0 ; --i)
    {
        /** 就是讲所有的i对应的所有对应容量求出来 , 这样做太浪费了*/
        for(int k = goodsList[i].second; k <= PACKAGE_CAPACITY ; ++k)
        {
            maxValue[i][k] = MAX(maxValue[i+1][k] , maxValue[i+1][k - goodsList[i].second]+goodsList[i].first);
        }
    }
    return maxValue[0][PACKAGE_CAPACITY];
}

void printChoose(unsigned pos , unsigned weight , \
    std::vector<pair<unsigned , unsigned> > goodsList)
{
    if(pos >= goodsList.size())
        return;
    if(maxValue[pos][weight] == maxValue[pos+1][weight - goodsList[pos].second]+goodsList[pos].first)
    {
        cout<<"g"<<pos<<"\t";
        printChoose(pos+1 , weight - goodsList[pos].second , goodsList);
    }
    else
    {
        printChoose(pos+1 , weight , goodsList);
    }
}

int main(int argc, char const *argv[])
{
    std::vector<pair<unsigned , unsigned> > goodsList;
    goodsList.push_back(pair<unsigned , unsigned>(60,10));
    goodsList.push_back(pair<unsigned , unsigned>(100,20));
    goodsList.push_back(pair<unsigned , unsigned>(120,30));
    cout<<"max value is : "<<zeroOnePackage(goodsList)<<endl;
    printChoose(0 , PACKAGE_CAPACITY , goodsList);
    while(1);
    return 0;
}



