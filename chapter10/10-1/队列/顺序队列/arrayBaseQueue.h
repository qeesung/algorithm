/*************************************************
* @Filename:    arrayBaseQueue.h
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-28 10:29:42
* @Version:     1.0
* @Description: 顺序队列
**************************************************/
#ifndef ARRAY_BASE_QUEUE_H
#define ARRAY_BASE_QUEUE_H
#include "queue.h"
#include <cstdlib>
#include <stdexcept>

/** 定义队列的最大大小 */
#define QUEUE_MAX_SIZE 100

template <class Elem> 
class ArrayBaseQueue : public Queue<Elem>
{
private:
    size_t front ;
    size_t rear;
    size_t m_length;// 队列的长度
    size_t array_size;// 队列分配数组的大小
    Elem * array;// 数组指针
public:
    ArrayBaseQueue(size_t _array_size=10) throw(std::bad_alloc);
    ~ArrayBaseQueue() throw();

    /** 清空队列 */
    void clear();
    /** 入队列 */
    bool enqueue(const Elem & ele);
    /** 出队列 */
    bool dequeue(Elem & ele);
    /** 队列第一个元素 */
    bool front_value(Elem & ele ) const;
    /** 队列长度 */
    int length() const;
};

#include "arrayBaseQueue.cc"

#endif