/*************************************************
* @Filename:    randomizedSelect_v1.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-21 12:28:43
* @Version:     1.0
* @Description: 选择数组里面第k大的元素的递归版本
**************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * 交换数组里面POS1和POS2里面的元素
 * @param array 传入的数组
 * @param pos1  位置1
 * @param pos2  位置2
 */
void exchange(int array[] , int pos1 , int pos2)
{
    int temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}

void randomizedSelectKernel(int array[], int leftBorder , int rightBorder ,int * kthNumber , int k);
/**
 * 找到数组里面第k大的元素
 * @param  array     输入的数组
 * @param  arraySize 数组大小
 * @param  kthNumber 第k大元素的大小         
 * @param  k         第k大的元素
 */
void randomizedSelect(int array[] , int arraySize , int * kthNumber , int k)
{
    if(array == NULL || arraySize <= 0 || kthNumber == NULL || k <0 || k >= arraySize)
        return;
    randomizedSelectKernel(array, 0 , arraySize-1 , kthNumber , k);
}


/**
 * 找到leftBorder到rightBorder中第k大的元素
 * @param  array       输入的数组
 * @param  leftBorder  左边界
 * @param  rightBorder 右边界
 * @param  kthNumber   第k大的元素的实际值
 * @param  k           第k大的元素
 * @return             对应的位置
 */
void randomizedSelectKernel(int array[], int leftBorder , int rightBorder ,int * kthNumber , int k)
{
    if(leftBorder > rightBorder)
        return ;
    // 这里采用快速排序的思想来完成
    int i = leftBorder-1;
    int j = leftBorder;
    int x = array[rightBorder];
    // 首先找到主元
    for(; j < rightBorder ; ++j)
    {
        if(array[j] <= x)
        {
            exchange(array , j , ++i);
        }
    }
    ++i;
    exchange(array , i , rightBorder);
    // 现在位置i就是需要放置主元的地方
    if(i == leftBorder+k-1)
        *kthNumber = array[i];
    else if(i > leftBorder+k-1)
        randomizedSelectKernel(array , leftBorder , i-1 , kthNumber , k);
    else if(i < leftBorder+k-1)
        randomizedSelectKernel(array , i+1, rightBorder , kthNumber , k-(leftBorder-i+1));
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

    int kthNumber=-1;
    randomizedSelect(array , arraySize , &kthNumber , 2);
    cout<<"2th max number is "<<kthNumber<<endl;
    randomizedSelect(array , arraySize , &kthNumber , 1);
    cout<<"1th max number is "<<kthNumber<<endl;
    randomizedSelect(array , arraySize , &kthNumber , 3);
    cout<<"3th max number is "<<kthNumber<<endl;
    randomizedSelect(array , arraySize , &kthNumber , 6);
    cout<<"6th max number is "<<kthNumber<<endl;
    while(1);
    return 0;
}


