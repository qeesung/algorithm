/*************************************************
* @Filename:    priorityQueue.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-09 20:34:48
* @Version:     1.0
* @Description: 优先队列源文件
**************************************************/
#include "priorityQueue.h"
#include <iostream>
#include <climits>


// const int & PriorityQueue::maxQueueNumber = 30;


PriorityQueue::PriorityQueue(std::vector<TreeNode>::iterator beginIter , std::vector<TreeNode>::iterator endIter)
{
    queueNumberCount = 0;
    // copy data to queue data
    while(queueNumberCount != maxQueueNumber &&\
          beginIter != endIter )
    {
        queueData[++queueNumberCount] = *beginIter;
        ++beginIter;
    }
    // 开始建堆
    buildMinHeap();
}

/**
 * 维护堆的性质
 * @param pos 维护的开始节点
 */
void PriorityQueue::minHeapify(const unsigned int pos)
{
    if(pos > queueNumberCount)
        return;
    int leftChild = LEFTCHILD(pos);
    int rightChild = RIGHTCHILD(pos);
    int minPos = pos;
    if(leftChild <= queueNumberCount && \
        queueData[leftChild] < queueData[minPos])
        minPos = leftChild;
    if(rightChild <= queueNumberCount &&\
        queueData[rightChild] <queueData[minPos])
        minPos = rightChild;
    if(minPos != pos)
    {
        exchange(minPos , pos);
        minHeapify(minPos);
    }
}

/**
 * 交换queueData里面的data   
 * @param pos1 位置1
 * @param pos2 位置2
 */
void PriorityQueue::exchange(const unsigned int pos1 ,\
                             const unsigned int pos2)
{
    if(pos1 > queueNumberCount || pos2 > queueNumberCount)
        return;
    TreeNode temp = queueData[pos1];
    queueData[pos1] = queueData[pos2];
    queueData[pos2] = temp;
    return;
}

/**
 * 构建最大堆
 */
void PriorityQueue::buildMinHeap()
{
    for (int i = queueNumberCount/2; i >=1 ; --i)
    {
        minHeapify(i);
    }
}


TreeNode PriorityQueue::min() const
{
    if(queueNumberCount > 0)
        return queueData[1];
    return TreeNode();
}


TreeNode PriorityQueue::extractMin()
{
    if(queueNumberCount <= 0)
        return TreeNode();
    TreeNode minNode = queueData[1];
    exchange(1,queueNumberCount);
    --queueNumberCount;
    minHeapify(1);
    return minNode;
}

void PriorityQueue::decreaseKey(unsigned int pos , const TreeNode & newKey)
{
    if(pos > queueNumberCount || queueData[pos] < newKey)
        return;
    queueData[pos] = newKey;
    while(pos > 1)
    {
        int parentPos = PARENT(pos);
        if(queueData[parentPos] < queueData[pos])
            break;
        exchange(parentPos , pos);
        pos = parentPos;
    }
}

void PriorityQueue::insert(const TreeNode & node)
{
    if(queueNumberCount >= maxQueueNumber)
        return;
    TreeNode maxNode ;
    maxNode.percent = INT_MAX;
    queueData[++queueNumberCount] = maxNode;
    decreaseKey(queueNumberCount , node); 
}


