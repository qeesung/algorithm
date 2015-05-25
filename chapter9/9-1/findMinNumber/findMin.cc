/*************************************************
* @Filename:    findMin.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-21 10:21:21
* @Version:     1.0
* @Description: 找到数组最小值
**************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>

using namespace std;

/**
 * 找到最小的元素
 * @param  array     输入的数组
 * @param  arraySize 数组大小
 * @param  minNumber 输出最小值
 * @return           最小值在数组里面的位置
 */
int findMin(int array[] , int arraySize , int * minNumber)
{
    if(array == NULL || arraySize < 0 || minNumber == NULL)
        return -1;
    int minPos = -1;
    int minNumberTemp=INT_MAX;
    for (int i = 0; i < arraySize; ++i)
    {
        if(array[i] < minNumberTemp)
        {
            minNumberTemp=array[i];
            minPos = i;
        }
    }
    *minNumber = minNumberTemp;
    return minPos;
}

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

    int minNumber ;
    int minPos;
    if((minPos = findMin(array , arraySize , &minNumber))== -1)
        cout<<"can not find min number"<<endl;
    else
        cout<<"find the min number "<<minNumber<<" at pos "<<minPos+1<<endl;
    while(1);
    return 0;
}

