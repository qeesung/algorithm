/*************************************************
* @Filename:    quickSort.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-14 14:48:35
* @Version:     1.0
* @Description: 快速排序的算法实现
**************************************************/

#include <iostream>

using namespace std;


void exchange(int array[] , int pos1 , int pos2)
{
    if(array == NULL)
        return;
    int temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}


/**
 * 快速排序的递归算法
 * @param array       将要排序的数组
 * @param leftBorder  排序的左边界
 * @param rightBorder 排序的右边界
 */
void quickSortKernel(int array[] , int leftBorder , int rightBorder)
{
    if(array == NULL || leftBorder >= rightBorder )
        return;
    /** 现在对数据进行原址排序 */
    int i = leftBorder-1;
    int j = leftBorder;
    int x = array[rightBorder];
    for(; j < rightBorder ; ++j)
    {
        if(array[j] <= x)
        {
            exchange(array,++i, j);
        }
    }
    exchange(array ,++i , rightBorder);
    /** 递归的排序数组剩下的部分，将合适的数据放在适合的位置上 */
    quickSortKernel(array , leftBorder , i-1);
    quickSortKernel(array , i+1, rightBorder);
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

int main(int argc, char const *argv[])
{
    int array[]={10,9,8,7,6,5,4,3,2,1,0};
    int arraySize = sizeof(array)/sizeof(int);

    cout<<"before sort the array："<<endl;
    printArray(array , arraySize);

    quickSort(array , arraySize);

    cout<<"after sort the array:"<<endl;
    printArray(array ,arraySize);

    while(1);
    return 0;
}