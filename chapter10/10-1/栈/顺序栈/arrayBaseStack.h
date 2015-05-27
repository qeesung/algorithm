/*************************************************
* @Filename:    arrayBaseStack.h
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-27 10:32:43
* @Version:     1.0
* @Description: 顺序栈的头文件
**************************************************/

#ifndef ARRAYBASE_STACK_H
#define ARRAYBASE_STACK_H

#include "stack.h"

template <class Elem>
class ArrayBaseStack : public Stack<Elem>
{
private:
    int top;// 指示栈顶位置
    int size;// 指示整个栈的长度
    Elem * array;// 指示数组
public:
    ArrayBaseStack(int _size=10);
    ~ArrayBaseStack();

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

#include "arrayBaseStack.cc"

#endif