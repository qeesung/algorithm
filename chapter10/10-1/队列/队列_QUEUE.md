[TOC]

本文中的所有代码你可以在这里：

[https://github.com/qeesung/algorithm/tree/master/chapter10/10-1/队列](https://github.com/qeesung/algorithm/tree/master/chapter10/10-1/%E9%98%9F%E5%88%97)

或者是这里：

[http://download.csdn.net/detail/ii1245712564/8753843](http://download.csdn.net/detail/ii1245712564/8753843)


找到！

#队列_QUEUE
`队列_QUEUE`是一种特殊的线性表，特殊之处在于它只允许在表的前端（front）进行删除操作，而在表的后端（rear）进行插入操作，和[栈](http://blog.csdn.net/ii1245712564/article/details/46228915)一样，队列是一种操作受限制的线性表。进行插入操作的端称为队尾，进行删除操作的端称为队头。

队列好比就是是食堂排队打饭的队伍(**队列**)，排在最前面的叫做队头(**队列的前端front**)，排在最后面的叫做队尾(**队列的后端rear**)。每得到一份饭，队列前端的同学就离开队列(**出队列 dequeue**),后面新来的童鞋继续排在队列的后端，成为新的队尾(**入队列 enqueue**).

队列的用途很广泛，具有先进先出(FIFO First In First Out)的特性，特别适用于依照数据来的先后顺序进行处理的情况，比如处理多个同等优先级任务，新来一个任务就将其队列，每处理一个任务就出队列，这样任务就会按照来的先后顺序进行处理了。但是如果对于多个不同优先级的任务，一般队列就不能胜任啦，这时候**优先队列**就更适合！优先队列内容请看这里[《优先队列》](http://blog.csdn.net/ii1245712564/article/details/45566159)

#队列的基本操作
一般来说，队列最重要的两个操作就是**入队列**和**出队列**,入队列就是在队列后端添加一个元素，出队列就是在队列前端删除一个元素，我们可以用数组或者是链式表来实现一个队列。
>**队列的基本操作**
>
>- **clear()**:清空队列
>- **Enqueue()**:入队列
>- **Dequeue()**:出队列
>- **frontValue()**:得到队列前端元素
>- **length()**:得到队列长度

下面我们用类模板定义了队列的通用接口
**queue.h**
```cpp
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
```

#队列的代码实现
这里实现的是环形队列的操作，对于一般队列来说，总是保持队列头或者是队列尾不变的，假如保持队列头不变，在每次**dequeue**一个元素以后，就要将后面的元素向前移动一位，这样做是很费时间的，假如队列元素个数为$n$,在**dequeue**一个元素以后，后面的$n-1$个元素就要向前移动，**dequeue**操作运行时间为$O(n)$

一般队列的**dequeue**或者**enqueue**操作太费时间，现在将队列的**dequeue**和**enqueue**的操作进行优化：

- 用额外的两个变量来表示队列头**front**和队列尾**rear**,在队列为空时**front**=**rear**
- **enqueue**一个元素时，将**rear**=**rear**+1,并将入队列的值赋值给**rear**标示的位置
- **dequeue**一个元素时，将**front**位置的元素弹出，并令**front** = **front**+1

>上面操作存在的**缺陷**:
>1. **缺陷1**:将**rear**和**front**这样无限制的增加，迟早会超出数组的有效范围的。
>**解决办法**:在**rear**或者**front**大于数组长度**arraySize**的时候，就要重新回到数组的头部**0**位置，于是我们将**raer**和**front**的操作更新为
>- **rear** = (**rear**+1)%**arraySize**
>- **front** = (**front**+1)%**arraySize**
>
>2. **缺陷2**：在队列为满时就会有**front**=**rear**和队列为空的时候一样，我们就无法分别队列到底是满还是空
>**解决办法**:于是我们新建一个变量**length**来存储队列的长度

---

><font color=red size="5px">**一般队列入队列和出队列的操作**</font>
>
>入队列三个元素A,B,C
>
>![Alt text](http://img.blog.csdn.net/20150530153134742)
>
>
>**出队列一次，元素A被弹出，所有元素前移**
>
>![Alt text](http://img.blog.csdn.net/20150530153025936)
>
>---
>
><font color=green size="5px">**循环队列的入队列和出队列操作**</font>
>
>初始化一个循环队列，新建两个元素指向前端和尾端，初始时,**front**和**rear**指向同一个位置
>![Alt text](http://img.blog.csdn.net/20150530153059710)
>
>入队列一个元素A和B
>
>![Alt text](http://img.blog.csdn.net/20150530153117744)
>![Alt text](http://img.blog.csdn.net/20150530153133484)
>
>现在出队列一个元素，front位置改变，不像一般队列固定在数组头部
>![Alt text](http://img.blog.csdn.net/20150530153322007)
>
>入队列C,D,E,F，满队列的情况，**front=rear**
>![Alt text](http://img.blog.csdn.net/20150530153341149)


---
下面我们来编码实现上面的操作
**arrayBaseQueue.h**
```cpp
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
```
---
**arrayBaseQueue.cc**
```cpp
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
```

---
测试队列的实现的正确性
**arrayBaseQueue_Test.cc**
```cpp
/*************************************************
* @Filename:    arrayBaseQueue_Test.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-28 10:51:34
* @Version:     1.0
* @Description: 测试顺序队列
**************************************************/
#include "arrayBaseQueue.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    ArrayBaseQueue<int> queue(3);
    /** test enqueue */
    for (int i = 0; i < 5; ++i)
    {
        if(queue.enqueue(i))
            std::cout<<"enqueue "<<i<<" done"<<std::endl;
        else
            std::cout<<"enqueue "<<i<<" failed"<<std::endl;
    }
    /** test front_value */
    {
        int temp;
        if(queue.front_value(temp))
            std::cout<<"front value : "<<temp<<std::endl;
        else
            std::cout<<"get front value failed"<<std::endl;
    }

    /** test dequeue */
    for (int i = 0; i < 5; ++i)
    {
        int temp;
        if(queue.dequeue(temp))
            std::cout<<"dequeue "<<temp<<" done!"<<std::endl;
        else
            std::cout<<"dequeue failed"<<std::endl;
    }
    return 0;
}
```

---

>**编译方法:**
>
>**for linux:**
>```bash
>g++ arrayBaseQueue_Test.cc -o queue
>```
>**for windows:**
>1. 随便一个IDE导入源文件就可以
>2. 如果你装有MinGW,就按照linux的编译方法来做
>
>---
>
>**执行方法:**
>
>**for linux:**
>```bash
>./queue
>```
>**for windows:**
>```bash
>queue #（安装了MinGW并在cmd下执行）
>```
>---
>**运行结果:**
>
>enqueue 0 done
enqueue 1 done
enqueue 2 done
enqueue 3 failed
enqueue 4 failed
front value : 0
dequeue 0 done!
dequeue 1 done!
dequeue 2 done!
dequeue failed
dequeue failed

