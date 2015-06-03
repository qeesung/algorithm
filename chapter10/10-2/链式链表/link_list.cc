/*************************************************
* @Filename:    link_list.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-06-04 03:37:28
* @Version:     1.0
* @Description: 实现链式链表的接口
**************************************************/

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

