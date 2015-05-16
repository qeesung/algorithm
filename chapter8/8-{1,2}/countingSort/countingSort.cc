/*************************************************
* @Filename:    countingSort.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-16 13:26:21
* @Version:     1.0
* @Description: 计数排序
**************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/**
 * 计数排序
 * @param inArray  输入的数组
 * @param outArray 输出的数组
 * @param minEle 数组里面的最小元素
 * @param maxEle 数组里面的最大元素
 * @param arraySize 数组元素个数
 */
void countingSort(int inArray[] ,int outArray[], int minEle ,
                  int maxEle , int arraySize )
{
    if(inArray == NULL ||\
       outArray == NULL ||\
       maxEle < minEle ||\
       arraySize < 0)
        return;
    // 新建一个缓存数组来保存比一个inArray[i]元素大的个数
    const int & countArraySize = maxEle - minEle+1;
    int countArray[countArraySize];
    // 初始化count数组
    for (int i = 0; i < countArraySize; ++i)
    {
        countArray[i] = 0;
    }
    // 遍历一遍inArray,统计各个元素的数量
    for (int i = 0; i < arraySize; ++i)
    {
        countArray[inArray[i]-minEle]++;
    }
    // 现在使得计算比inArray[i]小的元素的个数
    for (int i = 1; i < countArraySize; ++i)
    {
        countArray[i] = countArray[i] + countArray[i-1];
    }

    // 再次遍历一遍inArray,将元素放入outArray合适的位置
    for (int i = arraySize-1; i >= 0; --i)
    {
        outArray[countArray[inArray[i]-minEle]-1] = inArray[i];
        countArray[inArray[i]-minEle]--;
    }
}


void printArray(int array[] , int arraySize)
{
    if(array == NULL)
        return;
    for (int i = 0; i < arraySize; ++i)
    {
        cout<<array[i]<<"\t";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    const int & arraySize = 10;
    int inArray[arraySize];
    srand((int)(time(NULL)));
    for (int i = 0; i < arraySize; ++i)
    {
        inArray[i] = rand()%9;
    }
    cout<<"before sort array :"<<endl;
    printArray(inArray , arraySize);

    int outArray[arraySize];
    countingSort(inArray , outArray , 0 ,9 , arraySize);
    cout<<"after sort array"<<endl;
    printArray(outArray , arraySize);
    while(1);
    return 0;
}