/*************************************************
* @Filename:    list.h
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-06-04 03:27:27
* @Version:     1.0
* @Description: 链表的通用接口
**************************************************/
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