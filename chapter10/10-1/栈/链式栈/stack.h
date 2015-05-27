/*************************************************
* @Filename:    stack.h
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-27 10:26:35
* @Version:     1.0
* @Description: 所有栈类型的父类，用于定义接口
**************************************************/
#ifndef STACK_H
#define STACK_H

// 此类不可实例化
template <class Elem> 
class Stack
{
public:
    // 清空栈
    virtual void clear() = 0;
    // 压入栈
    virtual bool push(const Elem & ele) =0;
    // 出栈
    virtual bool pop(Elem & ele)=0;
    // 得到栈顶元素
    virtual bool topValue(Elem & ele )const =0;
    // 得到栈长度
    virtual int length() const =0;
};  

#endif