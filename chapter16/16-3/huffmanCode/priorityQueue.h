/*************************************************
* @Filename:    priorityQueue.h
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-09 19:40:40
* @Version:     1.0
* @Description: 优先队列的头文件
**************************************************/

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "treeNode.h"
#include <vector>
#include <iostream>

#define PARENT(i) ((i)>>1)
#define LEFTCHILD(i) ((i)<<1)
#define RIGHTCHILD(i) (((i)<<1)+1)


class PriorityQueue
{
public:
    /**
     * 构造函数
     * 数组的beginIter和endIter来构造优先队列
     */
    PriorityQueue(std::vector<TreeNode>::iterator beginIter , std::vector<TreeNode>::iterator endIter);
    /** 基本操作函数 */
    void insert(const TreeNode & treeNode);
    TreeNode min() const;
    TreeNode extractMin();
    void decreaseKey(unsigned int pos , const TreeNode & newKey);
    int size(){
        return queueNumberCount;
    }
    void print()
    {
        for (int i = 1; i <= queueNumberCount; ++i)
        {
            std::cout<<queueData[i].percent<<"\t";
        }
        std::cout<<std::endl;
    }
private:
    // 定义队列的最大长度
    static const int maxQueueNumber = 30;
    // 用来存放节点数据
    TreeNode queueData[maxQueueNumber+1];
    // 节点元素的计数
    int queueNumberCount;
    // 维护堆的性质
    void minHeapify(const unsigned int pos);
    // 构建最大堆
    void buildMinHeap();
    // 交换两个元素
    void exchange(const unsigned int pos1 , const unsigned int pos2);
};

#endif