[TOC]

本文中的所有代码都可以在这里:
[https://github.com/qeesung/algorithm/tree/master/chapter10/10-2](https://github.com/qeesung/algorithm/tree/master/chapter10/10-2)
或者这里：
[http://download.csdn.net/detail/ii1245712564/8775457](http://download.csdn.net/detail/ii1245712564/8775457)
找到
#链表_LINKLIST
链表的按照存储的方式分类可以分为两种，一种是内存连续的`顺序链表`，一种是内存不连续的`链式链表`，在本文中主要介绍更为灵活的链式链表，后文中出现的链表都默认为链式链表。

`链表`是一种物理存储单元上非连续、非顺序的存储结构，数据元素的逻辑顺序是通过链表中的指针链接次序实现的。链表由一系列结点（链表中每一个元素称为结点）组成，结点可以在运行时动态生成。每个结点包括两个部分：一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域。


#链表的结构
链表顾名思义就是一个表，表里面的每一项item存储一个数据，多个item串在一起就构成了链表

链表里面的一个项item，item里面装着我们需要的数据:
![Alt text](http://img.blog.csdn.net/20150605181806325)


将多个item串成一串，就构成了一个表结构:
![Alt text](http://img.blog.csdn.net/20150605181703263)

在链表里面，我们将这样一个item称为链表节点ListNode，那到底这些item是怎么把彼此串起来的呢？我们来看一下ListNode内部的信息

##链表节点_LinkNode
链表的基本元素就是一个**链表节点ListNode**,也就是我们上面所说的一个item，链表节点中包含两个信息，一个是**数据data**,一个是指向下一个节点的**指针next**。

![Alt text](http://img.blog.csdn.net/20150605181841675)

##链表节点连接
注意ListNode信息里面有一个叫做next的指针，它的作用就是用于指向下一个节点，那这就好办啦，我们可以将next指针指向下一个listNode，下一个listNode的next指针又可以指向其他的listNode,这样我们从第一个链表节点开始，通过next指针就可以访问所有的链表节点元素了！

![Alt text](http://img.blog.csdn.net/20150605181859849)


#链表的基本操作
链表有两个基本的操作：

- 插入元素
- 删除元素

链表节点时数据的载体，插入元素就是插入一个节点，删除元素就是删除一个节点

##节点的插入_INSERTNODE
假如现在我们要在链表的两个节点**Node1**和**Node2**之间插入一个新的节点**Node3**。
![Alt text](http://img.blog.csdn.net/20150605181802683)
可以大致分为下面几个步骤：

- 保存**Node1**指向**Node2**的指针，即保存**Next1**
- 将**Node1**的**Next**指针指向新的节点**Node3**
- 将**Node3**的**Next**指针设为之前保存起来的指向**Node2**的指针

![Alt text](http://img.blog.csdn.net/20150605181816910)
该操作的运行时间为$O(1)$

##节点的删除_REMOVENODE
有插入就有删除，假设有三个链表节点**Node1**,**Node2**,**Node3**,
现在需要将节点**Node2**删除。

![Alt text](http://img.blog.csdn.net/20150605181953965)

可以大致分为下面几个步骤：

- 保存**Node2**指向**Node3**的指针，即保存**Next2**
- 将**Next1**指向的节点**Node2**删除
- 把**Next1**赋值为之前保存的指向**Node3**的指针

![Alt text](http://img.blog.csdn.net/20150605182007615)
该操作的运行时间为$O(1)$

##访问链表元素_VISITNODE
对于一个链表，我们可以从链表的表头开始访问到链表里面的任意一个元素，因为链表的每一个节点都有一个指向下一个节点的指针next。

假设一链表有三个节点**Node1**，**Node2**，**Node3**,表头为**Node1**,现在我们需要访问第三个节点的数据
![Alt text](http://img.blog.csdn.net/20150605181908703)
![Alt text](http://img.blog.csdn.net/20150605182044572)
![Alt text](http://img.blog.csdn.net/20150605182101529)
![Alt text](http://img.blog.csdn.net/20150605182116879)
![Alt text](http://img.blog.csdn.net/20150605182135584)
这样我们就找到了第三个节点，并取出其中的元素

##链表基本操作接口_INTERFACE
**list.h**
```cpp
#ifndef List_H
#define List_H

/** 链表可以自由的实现其他功能，这里只列出了一小部分 */
template <class Elem>
class List
{
public:
    // 在链表头插入一个元素
    virtual bool insert(const Elem &) = 0;
    // 在链表尾插入一个元素
    virtual bool append(const Elem &) = 0;
    // 移除链表里面的一个元素
    virtual bool remove(const Elem &) = 0;
    // 清空链表里面额的所有元素
    virtual void clear() = 0;
    // 打印整个链表
    virtual void print() = 0;
};

#endif
```

#链表的编码实现
**link_list.h**
```cpp
#ifndef LINK_LIST_H
#define LINK_LIST_H

#include "list.h"
/**
 * 定义链表的节点
 */
template <class Elem>
class ListNode 
{
public:
    Elem data;// 实际的数据
    ListNode<Elem> * next;// 指向下一个节点
};  

/** 子类化List，实现接口功能 */
template <class Elem>
class LinkList : public List<Elem>
{
private:
    ListNode<Elem> * header;// 链表的表头
    void freeList(ListNode<Elem> * startNode);//迭代释放从start开始的所有节点
public:
    // 构造函数和析构函数
    LinkList();
    ~LinkList();
    // 基本的操作函数
    // 在链表头插入一个元素
    bool insert(const Elem &);
    // 在链表尾插入一个元素
    bool append(const Elem &);
    // 移除链表里面的一个元素
    bool remove(const Elem &);
    // 清空链表里面额的所有元素
    void clear();
    // 打印整个链表
    void print();
};
#include "link_list.cc"
#endif
```
>相对于List的接口，我们新添加了一个header指针指向链表的表头，我们可以以这个指针为入口，找到链表中的所有元素！

**link_list.cc**
```cpp
#include <iostream>
// 构造函数和析构函数
template <class Elem>
LinkList<Elem>::LinkList()
{
    // 首先创建一个链表的表头
    header = new ListNode<Elem>();
    header->next = NULL;
}

/** 迭代的释放节点指针开始的所有节点 */
template <class Elem>
void LinkList<Elem>::freeList(ListNode<Elem> * startNode)
{
    while(startNode != NULL)
    {
        ListNode<Elem> * tempNode = startNode->next;
        delete startNode;
        startNode = tempNode;
    }
    return;
}


template <class Elem>
LinkList<Elem>::~LinkList()
{
    //递归的释放整个链表
    freeList(header);
}

// 基本的操作函数

// 在链表头插入一个元素
template <class Elem>
bool LinkList<Elem>::insert(const Elem & ele)
{
    ListNode<Elem> * newNode = new ListNode<Elem>();
    if(newNode == NULL)
        return false;
    newNode->next=NULL;
    newNode->data = ele;

    ListNode<Elem>  * tempNode = header->next;
    header->next = newNode;
    newNode->next = tempNode;
    return true;
}

// 在链表尾插入一个元素
template <class Elem>
bool LinkList<Elem>::append(const Elem & ele)
{
    // tempNode里面现在就指向最后一个元素
    ListNode<Elem> * newNode = new ListNode<Elem>();
    if(newNode == NULL)
        return false;
    newNode->next = NULL;
    newNode->data = ele;
    // 首先找到链表末尾
    ListNode<Elem> * lastNode = header;
    while(lastNode->next !=NULL)
    {
        lastNode = lastNode->next;
    }
    // 追加节点
    lastNode->next = newNode;
    return true;
}

// 移除链表里面的一个元素
template <class Elem>
bool LinkList<Elem>::remove(const Elem & ele)
{
    // 在链表里面找到对应的元素
    ListNode<Elem> * targetNode = header;
    while(targetNode->next!=NULL && targetNode->next->data!=ele)
    {
        targetNode = targetNode->next;
    }
    if(targetNode->next == NULL)// 没有找到目标元素
        return false;

    ListNode<Elem> * tempNode = targetNode->next->next;
    delete targetNode->next;
    targetNode->next = tempNode;
    return true;
}

// 清空链表里面额的所有元素
template <class Elem>
void LinkList<Elem>::clear()
{
    freeList(header->next);
    header->next = NULL;
}

// 打印整个链表
template <class Elem>
void LinkList<Elem>::print()
{
    ListNode<Elem> * tempNode = header;
    while(tempNode->next!=NULL)
    {
        std::cout<<tempNode->next->data<<"\t";
        tempNode = tempNode->next;
    }
    std::cout<<std::endl;
}
```

**link_list_test.cc**
```cpp
#include <iostream>
#include "link_list.h"

int main(int argc, char const *argv[])
{
    LinkList<int> list;
    // insert three elements
    std::cout<<"Insert 1 2 3"<<std::endl;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.print();
    list.clear();
    std::cout<<std::endl;

    // append three elements
    std::cout<<"append 1 2 3"<<std::endl;
    list.append(1);
    list.append(2);
    list.append(3);
    list.print();
    list.clear();
    std::cout<<std::endl;

    // append three elements then remove one of them
    std::cout<<"append 1 2 3 then remove 3"<<std::endl;
    list.append(1);
    list.append(2);
    list.append(3);
    list.remove(3);
    list.print();
    list.clear();
    std::cout<<std::endl;

    return 0;
}
```

>**编译方法：**
>
>g++ link_list_test.cc -o link_list_test
>
>---
>
>**运行方法:**
>
>./link_list_test
>
>---
>
>**运行结果:**
>
>Insert 1 2 3
3	2	1	
append 1 2 3
1	2	3	
append 1 2 3 then remove 3
1	2	


#链表总结
既然链表有这么大的优势，那么以后直接就抛弃传统的数组，就用链表吧！这样当然不行，链表和数组之间各有各的优势，各自有各自的使用场景:

- **链表**:可以在常数时间$O(1)$之内完成对数据完成对数据的删除添加操作，但是对数据的访问操作的运行时间却需要在线性时间$O(n)$，链表的数据访问是不支持直接访问的，因为链表的节点的数据不是顺序分布的，在内存(一般在堆里面)里面看到的链表的数据分布可能是这样的：
![Alt text](http://img.blog.csdn.net/20150605182219997)
所以链表适用于对数据频繁插入删除的情形
- **数组**：数组可以在常数时间$O(1)$内对数据进行访问，因为数组的元素分布内在存中是连续的，可以直接数组起始地址加上一个偏移量找到对应的元素，数组在内存里面的部分可能是这样的：
![Alt text](http://img.blog.csdn.net/20150605182252196)
而如果要对数据进行删除和添加，那么运行时间为$O(n)$，所以数组适用于对数据访问比较频繁的情形。


