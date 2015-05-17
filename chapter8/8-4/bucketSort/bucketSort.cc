/*************************************************
* @Filename:    bucketSort.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-17 14:57:36
* @Version:     1.0
* @Description: 桶排序
**************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

#define BUCKET(i) ((i)/10)

/**
 * 交换容器里面的两个元素
 * @param array 输入的输入
 * @param pos1  位置1
 * @param pos2  位置2
 */
void exchange(std::vector<int> & array , int pos1 , int pos2)
{
    int temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}

/**
 * 打印一个容器
 * @param vec 目标容器
 */
void printVector(std::vector<int> & vec)
{
    for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); ++i)
    {
        cout<<*i<<"\t";
    }
    cout<<endl;
}

/**
 * 对输入的容器进行快速排序
 * 其实可以不用这样，直接用algorithm里面的stablesort(vec.begin, vec.end , comp)
 * 就可以对容器进行排序啦，这里懒得实现链表，所以用vector来实现    
 * @param vec 输入的容器
 * @param left 容器左边界
 * @param right 容器的右边界
 */
void quickSort(std::vector<int> & vec , int left , int right )
{
    if(left >= right)
        return;
    int i = left-1;
    int x = vec[right];
    for(int k = left; k <= right -1 ; ++k)
    {
        if(vec[k] <= x) // 交换两个元素
        {
            exchange(vec , ++i , k );
        }
    }
    exchange(vec , ++i , right);
    quickSort(vec , left , i-1);
    quickSort(vec , i+1 , right);
}

/**
 * 桶排序,这里输入的元素是0-100里面的元素，创建十个桶
 * @param inVec 输入的容器
 */
void bucketSort(std::vector<int> & inVec)
{
    const int & bucketNum = 10;
    // 创建十个桶
    std::vector<std::vector<int> > buckets(bucketNum);
    //遍历一边输入容器
    for (int i = 0; i < inVec.size(); ++i)
    {
        buckets[BUCKET(inVec[i])].push_back(inVec[i]);
    }
    // 开始对每一个桶进行快速排序
    for (int i = 0; i < bucketNum; ++i)
    {
        quickSort(buckets[i] , 0 , buckets[i].size()-1);
    }   

    // 开始从桶里面取出数据
    inVec.clear();
    for (int i = 0; i < bucketNum; ++i)
    {
        std::vector<int> & tempVec = buckets[i];
        cout<<"bucket#."<<i<<" +++ ";
        for (int k = 0; k < tempVec.size(); ++k)
        {
            cout.width(4);
            cout<<tempVec[k]<<"\t";
            inVec.push_back(tempVec[k]);
        }
        cout<<endl;
    }
}



int main(int argc, char const *argv[])
{
    const int & arraySize = 20;
    int inArray[arraySize];
    srand((int)(time(NULL)));
    for (int i = 0; i < arraySize; ++i)
    {
        inArray[i] = rand()%100;
    }

    std::vector<int> vec(inArray , inArray+arraySize);
    cout<<"before sort array :"<<endl;
    printVector(vec);

    bucketSort(vec);
    cout<<"after sort array"<<endl;
    printVector(vec);
    while(1);
    return 0;
}