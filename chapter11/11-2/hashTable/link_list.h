/*************************************************
* @Filename:    link_list.h
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-06-04 03:24:43
* @Version:     1.0
* @Description: 链式链表的头文件
**************************************************/
#ifndef LINK_LIST_H
#define LINK_LIST_H

#include "list.h"
#include <vector>
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
	LinkList(const LinkList<Elem> &);
    ~LinkList();
    // 基本的操作函数
	// 打印到一个vecrtor里
	void printToVec(std::vector<Elem> &);
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
