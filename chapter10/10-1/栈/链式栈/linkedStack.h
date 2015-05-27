/*************************************************
* @Filename:    linkedStack.h
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-27 11:33:52
* @Version:     1.0
* @Description: 链式栈的头文件
**************************************************/
#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "stack.h"

// 栈里面的基本元素节点
template <class Elem>
class BasicNode
{
public:
    Elem data;
    BasicNode * next;
};  

template <class Elem>
class LinkedStack : public Stack<Elem>
{
private:
    BasicNode<Elem> * buttom;
    BasicNode<Elem> * top;
    int m_length;
public:
    LinkedStack();
    ~LinkedStack();

    // 清空栈
    void clear() ;
    // 压入栈
    bool push(const Elem & ele);
    // 出栈
    bool pop(Elem & ele);
    // 得到栈顶元素
    bool topValue(Elem & ele )const;
    // 得到栈长度
    int  length() const;
    // 打印整个栈
    void printStack() const;
};  

#include "linkedStack.cc"

#endif