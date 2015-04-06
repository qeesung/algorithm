#include <utility>
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

#define MAXTRIX_CHAIN_LENGTH 6

unsigned int mulCost[MAXTRIX_CHAIN_LENGTH][MAXTRIX_CHAIN_LENGTH];
unsigned int solution[MAXTRIX_CHAIN_LENGTH][MAXTRIX_CHAIN_LENGTH];
unsigned int dealMinCost(std::vector<pair<unsigned ,unsigned> > & matrixChain ,\
                         unsigned left ,\
                         unsigned right);
/**
 * 求解最小花费
 * @param  matrixChain 矩阵链
 * @return             最小花费
 */
unsigned int getMinCost(std::vector<pair<unsigned , unsigned> > & matrixChain)
{
    if(matrixChain.size() <=1)
        return 0;
    dealMinCost(matrixChain ,0, matrixChain.size()-1);
    return mulCost[0][MAXTRIX_CHAIN_LENGTH-1];
}


unsigned int dealMinCost(std::vector<pair<unsigned ,unsigned> > & matrixChain ,\
                         unsigned left ,\
                         unsigned right)
{
    for (int n = 0; n < right-left+1  ; ++n)
    {
        int i,j;
        for (i = left , j = left+n ; i <= right-n && j <= right ; ++i , ++j)
        {
            if(i == j)
            {
                mulCost[i][j] = 0;
                continue;
            }
            unsigned int min = UINT_MAX;
            unsigned int pos;
            for (int k = i; k < j; ++k)
            {
                unsigned int temp = mulCost[i][k]+mulCost[k+1][j]+\
                                    matrixChain[i].first*matrixChain[k].second*matrixChain[j].second;
                if(min > temp)
                {
                    min = temp;
                    pos = k;
                }
            }
            mulCost[i][j] = min;
            solution[i][j] = pos;
        }
    }
}


void printSolution(int left , int right)
{
    if(left+2 > right)
        return;
    cout<<"from "<<left<<" to "<<right<<" the bracket pos is "<<solution[left][right]<<endl;
    printSolution(left,solution[left][right]);
    printSolution(solution[left][right]+1,right);
}

int main(int argc, char const *argv[])
{
    vector<pair<unsigned int , unsigned int> > matrixChain;
    matrixChain.push_back(pair<unsigned int ,unsigned int>(30,35));
    matrixChain.push_back(pair<unsigned int ,unsigned int>(35,15));
    matrixChain.push_back(pair<unsigned int ,unsigned int>(15,5));
    matrixChain.push_back(pair<unsigned int ,unsigned int>(5,10));
    matrixChain.push_back(pair<unsigned int ,unsigned int>(10,20));
    matrixChain.push_back(pair<unsigned int ,unsigned int>(20,25));

    cout<<"the min cost is:"<<getMinCost(matrixChain)<<endl;
    printSolution(0,MAXTRIX_CHAIN_LENGTH-1);
    while(1);
    return 0;
}