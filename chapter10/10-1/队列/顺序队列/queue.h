/*************************************************
* @Filename:    queue.h
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-28 10:24:15
* @Version:     1.0
* @Description: 定义队列的通用接口
**************************************************/

#ifndef QUEUE_H
#define QUEUE_H

template <class Elem>
class Queue
{
public:
    /** 清空队列 */
    virtual void clear()=0;
    /** 入队列 */
    virtual bool enqueue(const Elem & ele)=0;
    /** 出队列 */
    virtual bool dequeue(Elem & ele)=0;
    /** 队列第一个元素 */
    virtual bool front_value(Elem & ele ) const=0;
    /** 队列长度 */
    virtual int length() const=0;
};


#endif