/*************************************************
* @Filename:    pQueue.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-07 16:49:55
* @Version:     1.0
* @Description: 优先队列
**************************************************/


#include <iostream>
#include <climits>

using namespace std;

/**
* 优先队列的基本操作
*/
#define PARENT(i) ((i)>>1)
#define LEFTCHILD(i) ((i)<<1)
#define RIGHTCHILD(i) (((i)<<1)+1)
#define MAX_HEAP_ARRAY_SIZE 20

/**
 * 交换数组的两个位置的元素
 * @param array 目标数组
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
 * 维护最大堆的性质
 * @param array 输入的最大堆
 * @param pos   维护的位置
 */
void maxHeapify(int array[] , int pos)
{
    if( array == NULL | pos > array[0])
        return;
    int leftChild = LEFTCHILD(pos);
    int rightChild = RIGHTCHILD(pos);
    int maxPos = pos;
    if(leftChild <= array[0] && \
        array[leftChild] > array[maxPos])
        maxPos = leftChild;
    if(rightChild <= array[0] && \
        array[rightChild] > array[maxPos])
        maxPos = rightChild;
    if(maxPos != pos)
    {
        exchange(array , maxPos , pos);
        maxHeapify(array , maxPos);
    }
}


/**
 * 建堆
 * @param array 将要建堆的数组
 */
void buildHeap(int array[])
{
    if(array == NULL || array[0] == 0)
        return ;
    for(int k = array[0]/2 ; k >= 1  ; --k)
    {
        maxHeapify(array , k);
    }
}

/**
 * 下面是优先队列的基本操作
 */


void increseKey(int array[] , int pos , int newKeyValue);
/**
 * 在优先队列一个插入一个元素
 * @param array   优先队列
 * @param element 将要插入的元素
 */
void insert(int array[] , int element)
{
    if(array == NULL)
        return;
    if(array[0] >= 19)
    {
        cerr<<"Thy  priority queue is FULL"<<endl;
        return;
    }
    array[0]++;
    array[array[0]] = INT_MIN;
    increseKey(array , array[0], element);
}

/**
 * 得到优先队列里面的最大值
 * @param  array 输入的优先队列   
 * @return       堆里面的最大值
 */
int maximum(int array[])
{
    if(array == NULL || array[0] == 0)
    {
        cerr<<"The prority queue is EMPTY"<<endl;
        return INT_MIN;
    }
    return array[1];
}

/**
 * 取出优先队列里面的最大值
 * @param  array 优先队列
 * @return       最大值
 */
int extractMax(int array[])
{
    if(array == NULL || array[0] == 0)
    {
        cout<<"The priority queue is EMPTY"<<endl;
        return INT_MIN;
    }
    int maxNum = array[1];
    array[1] = array[array[0]];
    array[0]--;
    maxHeapify(array , 1);
    return maxNum;
}

/**
 * 增加一个优先队列里面元素的键值
 * @param array       优先队列
 * @param pos         位置
 * @param newKeyValue 新的键值
 */
void increseKey(int array[] , int pos , int newKeyValue)
{
    if(array == NULL || pos > array[0] || newKeyValue < array[pos])
    {
        cerr<<"increse new key value failed"<<endl;
        return;
    }
    array[pos] = newKeyValue;
    while(pos > 1)
    {
        int fatherPos = PARENT(pos);
        if(array[pos] > array[fatherPos])
        {
            exchange(array , pos , fatherPos);
            pos = fatherPos;
        }
        else 
            break;
    }
    return;
}

/**
 * 打印优先队列
 * @param array 优先队列
 */
void printQueue(int array[])
{
    cout<<"heap size : "<<array[0]<<" ---->";
    for (int i = 1; i <= array[0]; ++i)
    {
        cout<<array[i]<<"\t";
    }
    cout<<endl;
}


int main(int argc, char const *argv[])
{
    int array[]={0,4,1,3,2,16,9,10,14,8,7,0,0,0,0,0,0,0,0,0};
    array[0] = 10;
    cout<<"before builld heap:"<<endl;
    printQueue(array);
    buildHeap(array);
    cout<<"after build heap:"<<endl;
    printQueue(array);
    cout<<"the max number is:"<<maximum(array)<<endl;
    cout<<"extract maximum is :"<<extractMax(array)<<endl;
    cout<<"after extract maximum number:"<<endl;
    printQueue(array);
    cout<<"increse pos 4 to 11:"<<endl;
    increseKey(array , 4, 11);
    printQueue(array);
    cout<<"insert a new element 13:"<<endl;
    insert(array , 13);
    printQueue(array);
    return 0;
}