/*************************************************
* @Filename:    fractionPackage.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-04-30 14:44:28
* @Version:     1.0
* @Description: 贪心策略，分数背包问题
**************************************************/

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

#define PACKAGE_CAPACITY 50

/**
 * 求得goodslist对应的最大价值,我们首先假设物品按照平均价值降序排序
 * @param  goodsList 商品列表
 * @return           最大价值
 */
unsigned fractionPackage(std::vector<pair<unsigned , unsigned> > goodsList)
{
    unsigned valueSum=0;
    unsigned capacitySum=0;
    for (int i = 0; i < goodsList.size(); ++i)
    {
        // 转完这次就退出
        if(goodsList[i].second + capacitySum >= PACKAGE_CAPACITY)
        {
            valueSum+=(PACKAGE_CAPACITY - capacitySum)*(goodsList[i].first/goodsList[i].second);
            return valueSum;
        }
        valueSum+=goodsList[i].first;
        capacitySum+=goodsList[i].second;
    }
    return valueSum;
}

int main(int argc, char const *argv[])
{
    std::vector<pair<unsigned , unsigned> > goodsList;
    goodsList.push_back(pair<unsigned , unsigned>(60,10));
    goodsList.push_back(pair<unsigned , unsigned>(100,20));
    goodsList.push_back(pair<unsigned , unsigned>(120,30));
    cout<<"max value is : "<<fractionPackage(goodsList)<<endl;
    while(1);
    return 0;
}



