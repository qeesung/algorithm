/*************************************************
* @Filename:    randomizedSelect_v2.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-22 09:46:01
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
    int left = 0;
    int right = arraySize-1;
    int kTemp = k;
    while(left <= right)
    {
        // 采用快速排序的思想
        // 防止最坏的情况发生
        int mid=(left+right)/2;
        int midPos = right;
        if((array[left] > array[mid] && array[mid] > array[right]) ||\
        (array[left] < array[mid] && array[mid] < array[right]) )
            midPos = mid;
        else if((array[mid] > array[left] && array[left] > array[right]) ||
                (array[mid] < array[left] && array[left] < array[right]) )
            midPos = left;
        if(midPos != right)
            exchange(array , midPos , right);

        // 首先找到主元
        int i = left-1;
        int j = left; 
        int x = array[right];
        for(; j < right ; ++j)
        {
            if(array[j] <= x)
            {
                exchange(array , ++i , j);
            }
        }
        ++i;
        exchange(array , i , right);
        if(i == kTemp+left-1)// 找到第k大的元素
        {
            *kthNumber = array[i];
            return;
        }
        else if (i<kTemp+left-1)
        {
            kTemp = kTemp-(i-left+1);
            left = i+1;
        }
        else if(i > kTemp+left-1)
        {
            right = i-1;
        }
    }
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
    cout<<"2th max number is---------------------- "<<kthNumber<<endl;
    printArray(array , arraySize);
    randomizedSelect(array , arraySize , &kthNumber , 1);
    cout<<"1th max number is---------------------- "<<kthNumber<<endl;
    printArray(array , arraySize);
    randomizedSelect(array , arraySize , &kthNumber , 3);
    cout<<"3th max number is---------------------- "<<kthNumber<<endl;
    printArray(array , arraySize);
    randomizedSelect(array , arraySize , &kthNumber , 6);
    cout<<"6th max number is---------------------- "<<kthNumber<<endl;
    printArray(array , arraySize);
    while(1);
    return 0;
}


