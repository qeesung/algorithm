/*************************************************
* @Filename:    linkedStack.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-27 11:33:19
* @Version:     1.0
* @Description: 链式栈的实现
**************************************************/
#include <stdexcept>
#include <iostream>

template <class Elem> 
LinkedStack<Elem>::LinkedStack()
{
    /** 首先创建一个头部 */
    buttom = new BasicNode<Elem>;
    buttom->next = NULL;
    top = buttom;
    m_length = 0;
}

template <class Elem> 
LinkedStack<Elem>::~LinkedStack()
{
    /** 释放所有节点元素 */
    while(buttom!=NULL)
    {
        BasicNode<Elem> * tempNode = buttom->next;
        delete buttom;
        buttom = tempNode;
    }
}

template <class Elem>
void LinkedStack<Elem>::clear()
{
    BasicNode<Elem> * tempNode = buttom->next;
    while(tempNode)
    {
        BasicNode<Elem> * temp = tempNode->next;
        delete tempNode;
        tempNode = temp;
    }
}

template <class Elem>
bool LinkedStack<Elem>::push(const Elem & ele)
{
    try
    {
        BasicNode<Elem> * newNode = new BasicNode<Elem>;
        newNode->next = NULL;
        newNode->data = ele;
        top->next = newNode;
        top = newNode;
        ++m_length;
        return true;
    }catch(...)
    {
        return false;
    }
}

template <class Elem>
bool LinkedStack<Elem>::pop(Elem & ele)
{
    if(top == buttom)
        return false;
    /** 得到top的上一个元素 */
    BasicNode<Elem> * lastNode = buttom;
    while(lastNode->next!=top)
    {
        lastNode = lastNode->next;
    }

    BasicNode<Elem> * tempNode = top;
    top = lastNode;
    top->next = NULL;

    ele = tempNode->data;
    delete tempNode;
    --m_length;
    return true;
}


template <class Elem>
bool LinkedStack<Elem>::topValue(Elem & ele )const
{
    if(top == buttom)
        return false;
    ele = top->data;
    return true;
}

// 得到栈长度
template <class Elem>
int  LinkedStack<Elem>::length() const
{
    return m_length;
}

// 打印整个栈
template <class Elem>
void LinkedStack<Elem>::printStack() const
{
    BasicNode<Elem> * tempNode = buttom->next;
    while(tempNode != NULL)
    {
        std::cout<<tempNode->data<<"\t";
        tempNode = tempNode->next;
    }
    std::cout<<std::endl;
}