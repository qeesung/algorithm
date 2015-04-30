/*************************************************
* @Filename:    zeroOnePackage.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-04-30 10:49:31
* @Version:     1.0
* @Description: 典型的0-1背包问题，采用动态规划自上而下求解
**************************************************/

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/** 背包的容量 */
#define PACKAGE_CAPACITY 50
/** 最多有十个商品 */
#define MAX_GOODS_NUM 10
/** 用来保存商品没有没有选中过 */
bool packageChoose[MAX_GOODS_NUM];
/** 用来存储对应的最大价值 maxValue[i][w]表示后面i个商品装入w容量背包最大价值 */
unsigned maxValue[MAX_GOODS_NUM][PACKAGE_CAPACITY];

unsigned dealZeroOnePackage(unsigned pos , unsigned weight , \
    std::vector<pair<unsigned , unsigned> > & goodsList);
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
    dealZeroOnePackage(0,PACKAGE_CAPACITY,goodsList);
    return maxValue[0][PACKAGE_CAPACITY];
}

/**
 * 具体的递归求解
 * @param  pos       开始位置
 * @param  weight    剩余容量
 * @param  goodsList 商品列表
 * @return           对应pos开始容量为weight的最大值
 */
unsigned dealZeroOnePackage(unsigned pos , unsigned weight , \
    std::vector<pair<unsigned , unsigned> > & goodsList)
{
    if(pos >= goodsList.size() || weight == 0)
        return 0;
    if(maxValue[pos][weight] != 0 )
        return maxValue[pos][weight];
    // 下面开始递归求解
    unsigned temp1 = dealZeroOnePackage(pos+1,weight , goodsList);
    if(weight >= goodsList[pos].second)
    {
        unsigned temp2 = dealZeroOnePackage(pos+1, weight - goodsList[pos].second, goodsList)+\
                         goodsList[pos].first;
        unsigned retValue = temp1>temp2?temp1:temp2; 
        /** 判断pos位置到底选不选 */
        if(temp1 <= temp2)
        {
            packageChoose[pos]=true;
        }
        maxValue[pos][weight]= retValue;               
        return retValue;
    }
    else
    {
        maxValue[pos][weight]=temp1;
        return temp1;
    }
}

void printChoose()
{
    for (unsigned i = 0; i < MAX_GOODS_NUM ; ++i)
    {
        if(packageChoose[i])
            cout<<"g"<<i<<"\t";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    std::vector<pair<unsigned , unsigned> > goodsList;
    goodsList.push_back(pair<unsigned , unsigned>(60,10));
    goodsList.push_back(pair<unsigned , unsigned>(100,20));
    goodsList.push_back(pair<unsigned , unsigned>(120,30));
    cout<<"max value is : "<<zeroOnePackage(goodsList)<<endl;
    printChoose();
    while(1);
    return 0;
}



