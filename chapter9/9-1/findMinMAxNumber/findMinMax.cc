/*************************************************
* @Filename:    findMinMax.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-21 10:35:35
* @Version:     1.0
* @Description: 以3n/2的速度找到一个数组里面的最大值最小值
**************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/**
 * 打印一个数组
 * @param array     输入的数组
 * @param arraySize 数组大小
 */
void printArray(int array[] , int arraySize)
{
    if(array == NULL || arraySize <0)
        return;
    for (int i = 0; i < arraySize; ++i)
    {
        cout<<array[i]<<"\t";
    }
    cout<<endl;
}

class MinMaxPair
{
public:
    MinMaxPair(int _minPos = -1 , int _maxPos = -1):minPos(_minPos),maxPos(_maxPos){}
    size_t minPos;
    size_t maxPos;
    bool operator==(const MinMaxPair & pair)
    {
        return (this->minPos == pair.minPos && this->maxPos == pair.maxPos);
    }
};  

MinMaxPair findMinMax(int array[] , int arraySize , int * minNumber , int * maxNumber)
{
    if(array == NULL || arraySize <= 0 || minNumber == NULL || maxNumber == NULL)
        return MinMaxPair();

    int maxNumberTemp = array[0];
    int minNumberTemp = array[0];
    size_t maxPos=-1;
    size_t minPos=-1;
    int i = 1;
    if(arraySize%2 == 0)// 一共有偶数个元素
    {
        i=2;
        // 比较数组前两个元素
        maxNumberTemp = array[0];
        minNumberTemp = array[1];
        maxPos = 0;
        minPos = 1;
        if(array[0] < array[1])
        {
            maxNumberTemp = array[1];
            minNumberTemp = array[0];
            maxPos = 1;
            minPos = 0;
        }
    }
    for (; i < arraySize ; i+=2)
    {
        int temp1 = array[i];
        int temp2 = array[i+1];
        int tempPos1 = i;
        int tempPos2 = i+1;
        if(array[i] > array[i+1])
        {
            temp1 = array[i+1];
            temp2 = array[i];
            tempPos1 = i+1;
            tempPos2 = i;
        }
        if(minNumberTemp > temp1)
        {
            minNumberTemp = temp1;
            minPos = tempPos1;
        }

        if(maxNumberTemp < temp2)
        {
            maxNumberTemp = temp2;
            maxPos = tempPos2;
        }
    }
    *maxNumber = maxNumberTemp;
    *minNumber = minNumberTemp;
    return MinMaxPair(minPos , maxPos);
}

int main(int argc, char const *argv[])
{
    const int & arraySize = 10;
    int array[arraySize];
    srand((int)time(NULL));
    for (int i = 0; i < arraySize; ++i)
    {
        array[i] = rand()%100;
    }
    cout<<"input array is :"<<endl;
    printArray(array , arraySize);

    int maxNumber;
    int minNumber;
    MinMaxPair minMaxPos;
    if((minMaxPos = findMinMax(array , arraySize , &minNumber , &maxNumber))== MinMaxPair())
        cout<<"can not find min numbe & max number"<<endl;
    else
    {
        cout<<"find the min number "<<minNumber<<" at pos "<<minMaxPos.minPos+1<<endl;
        cout<<"find the max number "<<maxNumber<<" at pos "<<minMaxPos.maxPos+1<<endl;

    }
    while(1);
    return 0;
}