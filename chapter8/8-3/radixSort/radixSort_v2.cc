/*************************************************
* @Filename:    radixSort_v2.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-19 16:41:51
* @Version:     1.0
* @Description: 基数排序基于最优桶排序
**************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

// 定义桶排序的映射函数
#define BUCKET(i) (i)
// 定义十只桶
const int & bucketNumber = 10;

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
 * 桶排序
 * @param inArray 数组数组
 * @param arraySize 数组大小
 * @param radix   对应的基数,只能是10的倍数
 */
void bucketSort(int inArray[] , int arraySize , int radix)
{
	if(inArray == NULL || arraySize < 0 ||radix<0 ||radix%10!=0)
		return;
	/** 创建桶 */
	std::vector<int> buckets[bucketNumber];
	/** 将输入数组里面的数分类放到桶里面 */
	for (int i = 0; i < arraySize; ++i)
	{
		buckets[BUCKET(inArray[i]%radix/(radix/10))].push_back(inArray[i]);
	}
	/** 将桶里面的数组按顺序组合起来 */
	int arrayPos = 0;
	for (int i = 0; i < bucketNumber && arrayPos < arraySize; ++i)
	{
		std::vector<int> & tempVec = buckets[i];
		for (std::vector<int>::iterator iter = tempVec.begin(); iter != tempVec.end(); ++iter)
		{	
			inArray[arrayPos++] = *iter;
		}
	}
}


/**
 * 基数排序
 * @param inArray   输入的数组	
 * @param arraySize 数组大小
 */
void radixSort(int inArray[] , int arraySize , int maxPlace)
{
	if(inArray == NULL || arraySize< 0 || maxPlace < 1)
		return;
	int radixBasic=1;
	for (int i = 0; i < maxPlace; ++i)
	{
		radixBasic*=10;
		bucketSort(inArray , arraySize , radixBasic);
        cout<<radixBasic<<" -----------"<<endl;
		printArray(inArray,arraySize);
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

    radixSort(inArray , arraySize , 3);
    cout<<"after sort array"<<endl;
    printArray(inArray , arraySize);
    return 0;
}