/*************************************************
* @Filename:    arrayBaseQueue.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-28 10:36:11
* @Version:     1.0
* @Description: 顺序队列的具体实现源文件
**************************************************/
#include <iostream>
#include <stdexcept>

template <class Elem>
ArrayBaseQueue<Elem>::ArrayBaseQueue(size_t _array_size) throw(std::bad_alloc)
{
    array_size = _array_size;
    if(array_size > QUEUE_MAX_SIZE)
        array_size = QUEUE_MAX_SIZE;
    try{
        array = new Elem[array_size];
        if(array == NULL)
            throw std::bad_alloc();
    }catch(std::bad_alloc e)
    {
        std::cout<<"create queue failed "<<std::endl;
        throw;
    }
    front == 0;
    rear = front;
    m_length = 0;
}

template <class Elem>
ArrayBaseQueue<Elem>::~ArrayBaseQueue() throw()
{
    delete []array;
}


/** 清空队列 */
template <class Elem>
void ArrayBaseQueue<Elem>::clear()
{
    front = rear = 0;
    m_length = 0;
}

/** 入队列 */
template <class Elem>
bool ArrayBaseQueue<Elem>::enqueue(const Elem & ele)
{   
    /** 队列已满 */
    if(m_length == array_size)
        return false;
    /** 环形队列 */
    array[rear] = ele;
    rear = (rear+1)%array_size;
    ++m_length;
    return true;
}

/** 出队列 */
template <class Elem>
bool ArrayBaseQueue<Elem>::dequeue(Elem & ele)
{
    /** 队列为空 */
    if(m_length == 0)
        return false;
    ele = array[front];
    front = (front+1)%array_size;
    --m_length;
    return true;
}

/** 队列第一个元素 */
template <class Elem>
bool ArrayBaseQueue<Elem>::front_value(Elem & ele ) const
{
    if(m_length == 0)
        return false;
    ele = array[front];
    return true;
}

/** 队列长度 */
template <class Elem>
int ArrayBaseQueue<Elem>::length() const
{
    return m_length;
}
