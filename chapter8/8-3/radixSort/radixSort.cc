/*************************************************
* @Filename:    radixSort.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-17 13:06:32
* @Version:     1.0
* @Description: 基数排序
**************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/**
 * 打印数组
 * @param array     输入的数组
 * @param arraySize 数组大小
 */
void printArray(int array[] , int arraySize)
{
    for (int i = 0; i < arraySize; ++i)
    {
        cout<<array[i]<<"\t";
    }
    cout<<endl;
}


/**
 * 基数排序
 * @param array     输入要排序的数组
 * @param minEle    最小元素
 * @param maxEle    最大元素    
 * @param arraySize 数组大小
 * @param radix     基于个位十位还是百位等等排序
 */
void countingSort(int array[] , int minEle , int maxEle , int arraySize , int radix)
{
    if(array == NULL ||\
       minEle > maxEle ||\
       arraySize < 0 ||\
       radix < 0)
        return;
    // 新建一个临时计数数组
    const int & countArraySize = maxEle-minEle+1;
    int countArray[countArraySize];
    // 初始化计数数组
    for (int i = 0; i < countArraySize; ++i)
    {
        countArray[i] = 0;
    }
    // 新建一个临时的输出数组,用来存储输出排序的结果
    int sortedArray[arraySize];

    // 遍历一遍数组数组，统计各个元素对应的radix的数量
    for (int i = 0; i < arraySize; ++i)
    {
        countArray[array[i]%radix/(radix/10)]++;
    }

    // 统计比一个元素小的元素个数
    for (int i = 1; i < countArraySize; ++i)
    {
        countArray[i] = countArray[i] + countArray[i-1];
    }

    // 将元素放入sortedArray里面合适的位置
    for (int i = arraySize-1; i >=0; --i)
    {
        sortedArray[countArray[array[i]%radix/(radix/10)] - 1] = array[i];
        countArray[array[i]%radix/(radix/10)]--;
    }

    // 将元素复制回去,感觉这里有点慢，可不可以进行原址排序？
    for (int i = arraySize-1; i >=0; --i)
    {
        array[i] = sortedArray[i];
    }
    return;
}


/**
 * 基数排序
 * @param array     输入的数组
 * @param arraySize 数组大小
 * @param maxRadix  数组里面元素的最大位
 * @param minRadix  数组里面元素的最小位
 */
void radixSort(int array[] , int arraySize , int minRadix  ,  int maxRadix)
{
    if(array == NULL || arraySize < 0 || maxRadix <= 0 || minRadix <=0 || minRadix > maxRadix)
        return;
    // 得到基数开始位置
    int tempRadix = 1;
    for (int i = 1; i < minRadix; ++i)
    {
        tempRadix *= 10;
    }
    // 开始进行排序
    for (int i = minRadix; i < maxRadix ; ++i)
    {
        tempRadix *= 10;
        countingSort(array , 0 , 9 , arraySize , tempRadix);
        cout<<tempRadix<<" -----------"<<endl;
        printArray(array , arraySize);
    }
    return;
}


int main(int argc, char const *argv[])
{
    const int & arraySize = 10;
    int inArray[arraySize];
    srand((int)(time(NULL)));
    for (int i = 0; i < arraySize; ++i)
    {
        inArray[i] = rand()%1000;
    }
    cout<<"before sort array :"<<endl;
    printArray(inArray , arraySize);

    radixSort(inArray , arraySize , 1 ,4 );
    cout<<"after sort array"<<endl;
    printArray(inArray , arraySize);
    while(1);
    return 0;
}