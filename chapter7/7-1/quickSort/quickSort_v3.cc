/*************************************************
* @Filename:    quickSort_v2.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-14 15:11:00
* @Version:     1.0
* @Description: 新版本的快速排序
**************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

/**
 * 交换数组里面的两个元素
 * @param array 传入的数组
 * @param pos1  位置1
 * @param pos2  位置2
 */
void exchange(int array[] , int pos1 , int pos2)
{
    if(array == NULL)
        return;
    int temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}


/**
 * 打印数组
 * @param array     数组指针
 * @param arraySize 数组大小
 */
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


/**
 * 采用d递归来排序的数组
 * @param array       数组
 * @param leftBorder  左边界
 * @param rightBorder 右边界
 */
void quickSortKernel(int array[] , int leftBorder , int rightBorder)
{
    if(array == NULL || leftBorder >= rightBorder)
        return;
    // 为了防止是一个纯升序或者是降序的数组，
    // 现在选取数组中前中后三个元素，得到第二大的那个
    int center = (leftBorder + rightBorder)/2;
    if(array[leftBorder] > array[center] && array[rightBorder] < array[center])
        exchange(array , center , rightBorder);
    else if(array[leftBorder] > array[center] && array[rightBorder] > array[leftBorder])
        exchange(array , leftBorder , rightBorder);

    int i=leftBorder;
    int j = rightBorder-1;
    while(1)
    {
        // i向右边寻找比array[rightBorder]大的元素
        while(i < rightBorder && array[i] <= array[rightBorder])
            ++i;
        // j 向左边寻找比array[rightBorder小的元素]
        while(j >= i && array[j] >= array[rightBorder])
            --j;
        if(j+1 != i)
        {
            exchange(array , i , j);
        }
        else
        {
            break;
        }
    }
    exchange(array , i , rightBorder);
    quickSortKernel(array , leftBorder , i-1);
    quickSortKernel(array , i+1 , rightBorder);

}


/**
 * 快速排序接口
 * @param array 输入的数组
 */
void quickSort(int array[] , int arraySize)
{
    if(array == NULL)
        return ;
    quickSortKernel(array , 0 , arraySize-1);
}

int main(int argc, char const *argv[])
{
    int array[10];
    int arraySize = sizeof(array)/sizeof(int);

    srand((int)(time(NULL)));
    for (int i = 0; i < arraySize; ++i)
    {
        array[i] = rand()%100;
    }

    cout<<"before sort the array:"<<endl;
    printArray(array , arraySize);

    quickSort(array , arraySize);

    cout<<"after sort the array:"<<endl;
    printArray(array ,arraySize);

    while(1);
    return 0;
}