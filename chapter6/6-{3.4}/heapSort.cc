/*************************************************
* @Filename:    heapSort.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-06 10:32:10
* @Version:     1.0
* @Description: 堆排序
**************************************************/

#include <iostream>
using namespace std;
// 二叉树的基本操作
#define PARENT(i) ((i)>>1)
#define LEFTCHILD(i) ((i)<<1)
#define RIGHTCHILD(i) (((i)<<1)+1)



void printArray(int * array);
/**
 * 交换数组两个位置的元素
 * @param array 数组
 * @param pos1  位置1
 * @param pos2  位置2
 */
void exchange(int * array , int pos1 , int pos2)
{
    if(array == NULL)
        return;
    int temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}
/**
 * 维护最大堆的性质
 * @param array 传入的堆数组，注意此数组是从位置1开始，位置0存放堆的大小
 * @param pos   需要更新的位置
 */
void maxHeapify(int * array , int pos)
{
    if(array == NULL)
        return;
    if(pos > array[0])// 超出堆的大小
        return;
    int leftChild = LEFTCHILD(pos);
    int rightChild = RIGHTCHILD(pos);
    // 找到最大的那个
    int maxPos = pos;
    if(leftChild <= array[0] && array[leftChild] > array[pos] )
        maxPos = leftChild;
    if(rightChild <= array[0] && array[rightChild] > array[maxPos])
        maxPos = rightChild;
    // 交换父节点与子节点
    if(maxPos != pos)
    {
        exchange(array , maxPos , pos);
        maxHeapify(array , maxPos);
    }
}

/**
 * 堆排序
 * @param array 传入需要排序的数组,注意此数组是从位置1开始，位置0存放数组数组元素的个数   
 */
void heapSort(int * array)
{
    if(array == NULL)
        return;
    // 首先构建最大堆
    for(int k = array[0]/2 ; k >=1 ; --k)
    {
        maxHeapify(array , k);
    }
    int arraySize = array[0];
    //下面开始每次都取出堆里面堆顶位置的元素,再次进行堆性质维护
    for(int k = array[0] ; k >=2 ; --k)
    {
        exchange(array , 1, k);
        array[0] -= 1;
        maxHeapify(array , 1);
    }
    array[0] = arraySize;
}


void printArray(int * array)
{
    if(array == NULL)
        return;
    int arraySize = array[0];
    for(int k = 1 ; k <= arraySize ; ++k)
    {
        cout<<array[k]<<"\t";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int array[]={0,4,1,3,2,16,9,10,14,8,7};
    array[0] = sizeof(array)/sizeof(int) - 1;
    cout<<"before sort:"<<endl;
    printArray(array);
    heapSort(array);
    cout<<"after sort:"<<endl;
    printArray(array);
    while(1);
    return 0;
}