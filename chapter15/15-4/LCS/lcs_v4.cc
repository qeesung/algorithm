/** 这里采用自底向上带有绝决方案的算法实现 */
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

unsigned int dealLCS(std::vector<char>  X , std::vector<char>  Y ,
             std::vector<std::vector<unsigned int> > & tempData);

void printSolution(std::vector<char> X ,\
                   std::vector<std::vector<unsigned int> > & solution ,\
                   size_t i , size_t j)
{
    if(i == 0 || j ==0)
        return;
    if(solution[i][j] == solution[i-1][j])
        printSolution(X,solution,i-1,j);
    else if(solution[i][j] == solution[i][j-1])
        printSolution(X,solution,i,j-1);
    else if(solution[i][j]-1 == solution[i-1][j-1])
    {
        cout<<i<<" "<<j<<" "<<X[i-1]<<"\n";
        printSolution(X,solution , i-1 ,j-1);
    }
}
/**
 * 计算最长公共子序列长度
 * @param  X X序列
 * @param  Y Y序列
 * @return   最大长度
 */
size_t LCS(std::vector<char> &X , std::vector<char> &Y)
{
    if(X.size() == 0 ||  Y.size() == 0)
        return 0;
    /** 创建一个数组来保存临时数据 */
    std::vector<std::vector<unsigned int> > tempData(X.size()+1 , std::vector<unsigned>());
    for (int i = 0; i <= X.size(); ++i)
    {
        for (int j = 0; j <= Y.size(); ++j)
        {
            if(i == 0 || j == 0)
                tempData[i].push_back(0);
            else
                tempData[i].push_back(UINT_MAX);
        }
    }
    dealLCS(X , Y , tempData);//开始进行计算
    printSolution(X,tempData,X.size(),Y.size());
    return tempData[X.size()][Y.size()];
}

/**
 * 实际计算LCS的最大长度
 * @param X        X序列
 * @param Y        Y序列
 * @param tempData 缓存数据
 */
unsigned int dealLCS(std::vector<char>  X , std::vector<char>  Y ,
             std::vector<std::vector<unsigned int> > & tempData)
{
    if(X.size() == 0 || Y.size() == 0)
        return 0;
    for (unsigned int i = 0; i < X.size(); ++i)
    {
        for (unsigned int j = 0; j < Y.size(); ++j)
        {
            if(X[i] == Y[j])
            {
                tempData[i+1][j+1] = tempData[i][j]+1;
            }
            else
            {
                unsigned int temp1 = tempData[i+1][j];
                unsigned int temp2 = tempData[i][j+1];
                tempData[i+1][j+1] = temp1 > temp2 ? temp1 : temp2;
            }

        }
    }
    return tempData[X.size()][Y.size()];
}

int main(int argc, char const *argv[])
{
    char array1[]={'A','B','C','B','D','A','B'};
    char array2[]={'B','D','C','A','B','A'};
    std::vector<char> X(array1 , array1+sizeof(array1));
    std::vector<char> Y(array2 , array2+sizeof(array2));
    cout<<"The Lcs length is :"<<LCS(X,Y)<<endl;
    while(1);
    return 0;
} 