/*************************************************
* @Filename:    select.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-22 16:33:30
* @Version:     1.0
* @Description: 选择问题的BFPRT算法
**************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/**
 * 交换数组的两个元素
 * @param array 输入数组
 * @param pos1  位置1
 * @param pos2  位置2
 */
void exchange(int array[] , int pos1 , int pos2)
{
    if(array == NULL || pos1 < 0 || pos2 <0)
        return;
    int temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}

/**
 * 打印一个数组
 * @param array     输入的数组
 * @param arraySize 数组的大小
 */
void printArray(int array[] , int arraySize)
{   
    if(array == NULL || arraySize <= 0)
        return;
    for(int k = 0 ; k < arraySize ; ++k)
    {
        cout<<array[k]<<"\t";
    }
    cout<<endl;
}


/**
 * 插入排序算法
 * @param array     输入的数组
 * @param arraySize 数组大小
 */
void insertSort(int array[] , int arraySize)
{
    if(array == NULL || arraySize <= 0)
        return;
    // 保存第一个元素作为哨兵
    int firstEle = array[0];
    for (int i = 1; i < arraySize; ++i)
    {
        array[0] = array[i];// 设置哨兵
        int j = i;
        // 找到合适的插入位置
        while(array[--j] > array[i])
            ;
        // 将j开始的元素向后移动,终点为i
        int targetNumber = array[i];
        for(int k = i-1 ; k > j ; --k)
        {
            array[k+1] = array[k];
        }
        array[j+1] = targetNumber;
    }
    // 最后再将哨兵插入到合适为位置
    /** 首先找到合适的插入位置 */
    int insertPos = 1;
    for(int k = 1 ; k < arraySize ; ++k)
    {
        if(firstEle <= array[k] )
        {
            insertPos = k;
            break;
        }
    }   
    /** 开始插入元素 */
    for(int k = 1 ; k < insertPos  ; ++k)
    {
        array[k-1] = array[k];
    }
    array[insertPos-1] = firstEle;
}


/**
 * 找到数组中的中位数
 * @param  array       输入的数组
 * @param  lefyBorder  数组左边界
 * @param  rightBorder 数组右边界
    const int & arraySize = rightBorder - leftBorder+1;
 * @return             中位数的坐标
 */
int BFPRT(int array[] , int leftBorder , int rightBorder)
{
    if(array == NULL || leftBorder > rightBorder )
        return -1;
    const int & arraySize = rightBorder - leftBorder +1;
    // 判断元素的个数是否大于五个
    if(arraySize <= 5)
    {
        insertSort(array , arraySize);
        return leftBorder+arraySize/2;
    }
    // 如果元素个数大于五个，那么就五五分组
    const int & groupSize = 5;
    int * groupStart=array;
    int midCount=0;
    for (int i = leftBorder+groupSize; i <= rightBorder; i+=groupSize)
    {
        insertSort(groupStart , groupSize);
        exchange(array , leftBorder+midCount , i-3 );//将中位数放在数组的最前面
        ++midCount;
        groupStart+=groupSize;
    }
    // 剩下的不满五个进行排序
    if(arraySize%groupSize != 0)
    {
        insertSort(groupStart , arraySize%groupSize);
        exchange(array , leftBorder+midCount ,leftBorder + arraySize - arraySize%groupSize + (arraySize%groupSize - 1)/2);
        ++midCount;
    }
    // 现在新选出来的所有中位数都在前midCount里面
    // 返回中位数的中位数
    return BFPRT(array , leftBorder , leftBorder+midCount-1);
}

/**
 * 选择第K大的元素
 * @param array       输入的数组
 * @param leftBorder  左边界
 * @param rightBorder 右边界
 * @param k           第k个
 * @param kthNumber   第k大的数
 */
void BFPRTselect(int array[] , int leftBorder , int rightBorder ,int k ,  int * kthNumber)
{
    if(array == NULL || leftBorder > rightBorder || kthNumber == NULL || k >(rightBorder - leftBorder + 1))
        return ;
    int index = BFPRT(array , leftBorder , rightBorder);
    if(index == -1)
        return;
    cout<<"lefy--->"<<leftBorder<<" right--->"<<rightBorder<<" index:"<<index<<" midNumber :"<<array[index]<<endl;
    exchange(array , index , rightBorder);
    int i = leftBorder-1;
    int j = leftBorder;
    int x = array[rightBorder];

    for(; j < rightBorder ; ++j)
    {
        if(array[j] <= x)
        {
            exchange(array , ++i , j);
        }
    }
    ++i;
    exchange(array , i , rightBorder);
    if(i == leftBorder+k-1 )
    {
        *kthNumber = array[i];
        return ;
    }
    else if(i < leftBorder+k-1)
    {
        BFPRTselect(array , i+1 ,rightBorder , k-(i - leftBorder+1) , kthNumber);
    }
    else if(i > leftBorder+k-1)
    {
        BFPRTselect(array , leftBorder , i-1 , k , kthNumber);
    }
}


int main(int argc, char const *argv[])
{
    const int & arraySize = 10;
    int array[arraySize];
    srand((int)(time(NULL)));
    for(int k = 0 ; k < arraySize ; ++k)
    {
        array[k] = rand()%100;
    }
    cout<<"before sort the array:"<<endl;
    printArray(array , arraySize);

    int kthNumber=-1;
    BFPRTselect(array , 0 ,arraySize-1 ,  2 , &kthNumber);
    cout<<"2th max number is---------------------- "<<kthNumber<<endl;
    printArray(array , arraySize);
    BFPRTselect(array , 0 ,arraySize-1 ,  1 , &kthNumber);
    cout<<"1th max number is---------------------- "<<kthNumber<<endl;
    printArray(array , arraySize);
    BFPRTselect(array , 0 ,arraySize-1 ,  3 , &kthNumber);
    cout<<"3th max number is---------------------- "<<kthNumber<<endl;
    printArray(array , arraySize);
    BFPRTselect(array , 0 ,arraySize-1 ,  6 , &kthNumber);
    cout<<"6th max number is---------------------- "<<kthNumber<<endl;
    printArray(array , arraySize);

    
    cout<<"after sort the array:"<<endl;
    insertSort(array,arraySize);
    printArray(array , arraySize);
    while(1);
    return 0;
}

