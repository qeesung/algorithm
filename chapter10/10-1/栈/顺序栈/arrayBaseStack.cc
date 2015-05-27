/*************************************************
* @Filename:    arrayBaseStack.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-27 10:25:01
* @Version:     1.0
* @Description: 顺序栈的实现
**************************************************/
// #include "arrayBaseStack.h"
#include <iostream>

template <class Elem>
ArrayBaseStack<Elem>::ArrayBaseStack(int _size):size(_size)
{
    array = new Elem[size];
    top=-1;
}

template <class Elem>
ArrayBaseStack<Elem>::~ArrayBaseStack()
{
    delete [] array;
}

template <class Elem>
void ArrayBaseStack<Elem>::clear()
{
    top = -1;
}

template <class Elem>
bool ArrayBaseStack<Elem>::push(const Elem & ele)
{
    if(top == size-1)
        return false;
    array[++top]=ele;
    return true;
}

template <class Elem>
bool ArrayBaseStack<Elem>::pop(Elem & ele)
{
    if(top == -1)
        return false;
    ele = array[top--];
    return true;
}


template <class Elem>
bool ArrayBaseStack<Elem>::topValue(Elem & ele )const
{
    if(top == -1)
        return false;
    ele = array[top];
    return true;
}

// 得到栈长度
template <class Elem>
int  ArrayBaseStack<Elem>::length() const
{
    return top+1;
}

// 打印整个栈
template <class Elem>
void ArrayBaseStack<Elem>::printStack() const
{   
    for (int i = 0; i <= top; ++i)
    {
        std::cout<<array[i]<<"\t";
    }
    std::cout<<std::endl;
}