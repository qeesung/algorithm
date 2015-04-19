/*************************************************
* @Filename:    searchBinaryTree_v1.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-04-19 09:48:21
* @Version:     1.0
* @Description: 最优二叉搜索树的算法实现，这里首先采用自下而上的方法求解,带有解决方案
**************************************************/


#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define MAX_KEY_COUNT 10// 关键字的数量
void dealBestBSTree(int i , int j ,\
    std::vector<pair<string , double> > keyMap,\
    std::vector<pair<string , double> > fKeyMap);
/**
 * 保存i到j的最优解开
 * 为了就算e[i][i-1] e[j+1][j]这种情况，所以将行设了比列多大一维
 */
double minWeightArray[MAX_KEY_COUNT+2][MAX_KEY_COUNT+1];

/**
 * 为了保存weight i到j的权重之和，不用每次都计算
 * 为了计算weigh[i][i-1]情况，行比列多了一维
 */
double weight[MAX_KEY_COUNT+2][MAX_KEY_COUNT+1];

/**
 * 保存在i到j的切分点
 */
double rootPoint[MAX_KEY_COUNT][MAX_KEY_COUNT];

void printSolution(int i , int j , std::vector<pair<string , double> > keyMap,\
    std::vector<pair<string , double> > fKeyMap)
{
    if( i == j)
    {
        cout<<"from "<<i<<" to "<<j<<" root is "<<keyMap[i].first<<endl;
        return;
    }
    cout<<"from "<<i<<" to "<<j<<" root is "<<keyMap[rootPoint[i][j]].first<<endl;
    printSolution(i , rootPoint[i][j]-1 , keyMap , fKeyMap);
    printSolution(rootPoint[i][j]+1 , j , keyMap , fKeyMap);
    return;
}

/**
 * 为了递归计算出weight[i][j]的值
 * @param  i       左边界，需要从1开始
 * @param  j       右边界
 * @param  keyMap  关键字序列
 * @param  fKeyMap 伪关键字序列
 * @return         i到j的权重
 */
double computeWeight(int i , int j , \
    std::vector<pair<string , double> > keyMap,\
    std::vector<pair<string , double> > fKeyMap)
{
    if(i-1 == j)
        weight[i][j] = fKeyMap[j].second;
    else
        weight[i][j]=computeWeight(i , j-1 , keyMap , fKeyMap)+keyMap[j].second+fKeyMap[j].second;
    return weight[i][j];
}

/**
 * 最优二叉搜索树的接口
 * @param keyMap  关键字序列
 * @param fKeyMap 伪关键字序列
 * @return 返回最优二叉搜索树的权重
 */
double bestBSTree(std::vector<pair<string , double> > keyMap,\
    std::vector<pair<string , double> > fKeyMap)
{
    if(keyMap.size()-1 > MAX_KEY_COUNT)
    {
        cerr<<"key count should less than "<<MAX_KEY_COUNT<<endl;
        return 0.0; 
    }
    /** 多次初始化i到j的权重 */
    for (int k = 1 ; k <= keyMap.size()-1+1 ; ++k)
    {
        computeWeight(k , keyMap.size()-1 , keyMap , fKeyMap);
    }
    cout<<"weight array"<<endl;
    for (int i =1 ; i<= keyMap.size() ; ++i)
    {
        for (int j = 0 ; j<keyMap.size() ; ++j)
        {
            cout<<weight[i][j]<<"\t";
        }
        cout<<endl;
    }
    // 现在已经将权重数据全都保存到weight里面了
    // 
    // 开始计算最优
    dealBestBSTree(1,keyMap.size()-1,keyMap , fKeyMap);
    cout<<"min weight array"<<endl;
    for (int i =1 ; i<= keyMap.size() ; ++i)
    {
        for (int j = 0 ; j<keyMap.size() ; ++j)
        {
            cout<<minWeightArray[i][j]<<"\t";
        }
        cout<<endl;
    }
    return minWeightArray[1][keyMap.size()-1];
}


/**
 * 最优二叉搜索树的实际递归函数
 * @param  i       左边界
 * @param  j       右边界
 * @param  keyMap  关键字序列
 * @param  fKeyMap 伪关键字序列
 * @return         i到j的最优值
 */
void dealBestBSTree(int i , int j ,\
    std::vector<pair<string , double> > keyMap,\
    std::vector<pair<string , double> > fKeyMap)
{
    // 初始化minWeightArray数组，将 i-1 == j的情况全都赋值
    for(int k = i ; k <= j+1 ; ++k)
    {
        minWeightArray[k][k-1] = weight[k][k-1];
    }
    // 下面自下而上的来求解
    for(int k = 0 ; k < j-i+1 ; ++k)
    {
        for(int m = i ; m <= j ; ++m)
        {
            double min = 10.0;
            int rootPos = i;
            for(int w = m ; w <= m+k ; ++w )
            {
                double temp = minWeightArray[m][w-1]+minWeightArray[w+1][m+k]+weight[m][m+k];
                if(temp < min)
                {
                    min = temp;
                    rootPos = w;
                }
            }
            rootPoint[m][m+k] = rootPos;
            minWeightArray[m][m+k] = min;
        }
    }
}

int main(int argc, char const *argv[])
{
    std::vector<pair<string , double> > keyMap;
    std::vector<pair<string , double> > fKeyMap;
    // keyMap[0]是用不到的，只是为了填充，因为关键字是从1开始的
    keyMap.push_back(pair<string , double>("k1", 0.15));
    keyMap.push_back(pair<string , double>("k1", 0.15));
    keyMap.push_back(pair<string , double>("k2", 0.1));
    keyMap.push_back(pair<string , double>("k3", 0.05));
    keyMap.push_back(pair<string , double>("k4", 0.1));
    keyMap.push_back(pair<string , double>("k5", 0.2));

    fKeyMap.push_back(pair<string , double>("d0", 0.05));
    fKeyMap.push_back(pair<string , double>("d1", 0.1));
    fKeyMap.push_back(pair<string , double>("d2", 0.05));
    fKeyMap.push_back(pair<string , double>("d3", 0.05));
    fKeyMap.push_back(pair<string , double>("d4", 0.05));
    fKeyMap.push_back(pair<string , double>("d5", 0.1));

    cout<<"The binary search tree min weight is:"<<bestBSTree(keyMap , fKeyMap)<<endl;
    printSolution(1,keyMap.size()-1,keyMap , fKeyMap);
    while(1);

    return 0;
}