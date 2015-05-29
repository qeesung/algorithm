[TOC]


本文中的完整代码你可以在这里：
**[https://github.com/qeesung/algorithm/tree/master/chapter10/10-1/栈](https://github.com/qeesung/algorithm/tree/master/chapter10/10-1/%E6%A0%88)**

或者这里：

顺序栈的实现：**[http://download.csdn.net/detail/ii1245712564/8744663](http://download.csdn.net/detail/ii1245712564/8744663)**
链式栈的实现：**[http://download.csdn.net/detail/ii1245712564/8744679](http://download.csdn.net/detail/ii1245712564/8744679)**
C语言实现链式栈的模板：**[http://download.csdn.net/detail/ii1245712564/8744691](http://download.csdn.net/detail/ii1245712564/8744691)**

找到！

#栈_STACK

`栈（stack）`又名堆栈，它是一种运算受限的线性表。其限制是仅允许在表的一端进行插入和删除运算。这一端被称为栈顶，相对地，把另一端称为栈底。向一个栈插入新元素又称作进栈、入栈或压栈，它是把新元素放到栈顶元素的上面，使之成为新的栈顶元素；从一个栈删除元素又称作出栈或退栈，它是把栈顶元素删除掉，使其相邻的元素成为新的栈顶元素。

这么讲似乎有点抽象，我们就将栈比作一个弹夹，子弹就好比栈中操作的数据元素，我们将子弹一个一个压入弹夹之内（压栈操作），在射击的时候，弹夹将处于弹夹最上方的子弹弹出(出栈操作)。注意，只能弹出处于弹夹最上方的元素，这这是栈操作的一种限制。

栈是一种先进后出(FILO First In Last Out)的数据结构，顾名思义，就是越早进入栈中的元素，进行出栈操作时，这个元素就会越晚被弹出来。好比最先压入弹夹中的子弹是被最后打出的，最后压入的子弹是被最先打出的。

#栈的基本操作

首先定义栈的两个基本操作：

- 压栈(Push(Stack , Ele))
- 出栈(Pop(Stack))
- 清空栈(Clear(Stack))
- 得到栈顶元素(TopValue(Stack))


#栈的代码实现
这里我们将采用两种方式来实现栈，一种是C++模板的形式，一种是C语言的形式，我们在C语言的实现中，仿照C++实现了一个通用栈模板

---

##栈的C语言实现
**_c_stack.h_**
```c
#ifndef C_STACK_h
#define C_STACK_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stackNode_s
{
    struct stackNode_s * next;// 指向下一个节点
};  
typedef struct stackNode_s * StackNode;

struct stack_s
{
    StackNode top;
    StackNode buttom;
};
typedef struct stack_s * Stack;

/** 创建一个新的栈 */
Stack createStack();
/** 压栈 */
bool push(Stack , StackNode);
/** 出栈 */
bool pop(Stack , StackNode *);
/** 得到栈顶元素的值 */
bool topValue(Stack , StackNode *);
#endif
```
>在上面的代码里面，栈节点的结构我们只定义了一个指向下一个节点的指针，并没有任何实际的数据，这里不是错误。

**_c_stack.c_**
```c
#include "c_stack.h"
#include <stdlib.h>
#include <stdio.h>

/** 创建一个栈 */
Stack createStack()
{
    Stack newStack = (Stack)malloc(sizeof(struct stack_s));
    if(newStack == NULL)
        return NULL;
    // 创建一个头部节点，头结点来表示栈底部
    newStack->buttom = (StackNode)malloc(sizeof(struct stackNode_s));
    if(newStack->buttom == NULL)
    {
        free(newStack);
        return NULL;
    }
    // 初始化一些数据
    newStack->buttom->next =NULL;
    newStack->top = newStack->buttom;
    return newStack;
}

/** 入栈操作 */
bool push(Stack stack , StackNode stackNode)
{   
    if(stack == NULL ||\
       stack->top == NULL ||\
       stack->buttom == NULL ||\
       stackNode == NULL)
        return false;
    stackNode->next = NULL;

	/** 对一个stack Node 压栈 */
    stack->top->next = stackNode;
    stack->top = stackNode;
    return true;
}

/** 出栈操作 */
bool pop(Stack stack, StackNode * stackNode)
{
    if(stack == NULL ||\
       stack->top == NULL ||\
       stack->buttom == NULL ||\
       stackNode == NULL)
        return false;
    // 空栈
    if(stack->top == stack->buttom)
        return false;
    /** 找到top的前一个元素 */
    StackNode lastNode = stack->buttom;
    while(lastNode->next!=stack->top)
    {
        lastNode = lastNode->next;
    }

    StackNode tempNode = stack->top;
    *stackNode = tempNode;

    stack->top = lastNode;
    stack->top->next = NULL;
    return true;
}

/** 得到栈顶元素 */
bool topValue(Stack stack , StackNode * stackNode)
{
    if(stack == NULL ||\
       stack->top == NULL ||\
       stack->buttom == NULL ||\
       stackNode == NULL)
        return false;
    // 空栈
    if(stack->top == stack->buttom)
        return false;
    *stackNode = stack->top;
    return true;
}
```
>注意上面只是一个栈的模板，如果我们要添加对应的数据，那么就要实例化这个模板，下面是实例化一个int类型的栈

---

**_c_stack_int.h_**
```cpp
#ifndef C_STACK_INT_H
#define C_STACK_INT_H

#include "c_stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


struct int_stackNode_s
{
    StackNode stackNode;
    int data;// 这个是实际的数据
};

typedef struct int_stackNode_s * IntStackNode;

bool push_intStack(Stack , int number);
bool pop_intStack(Stack , int * number);
bool topValue_intStack(Stack , int * number);
void print_intStack(Stack);
void destory_intStack(Stack);
void clear(Stack);

#endif
```
>基于上面的栈模板，实现对应的int栈操作


**_c_stack_int.c_**
```cpp
#include "c_stack_int.h"
#include <stdlib.h>
/** 释放一个栈的递归操作函数 */
static void freeList(StackNode tempNode);

/** 压栈 */
bool push_intStack(Stack stack , int number)
{
    IntStackNode newNode = (IntStackNode)malloc(sizeof(struct int_stackNode_s));
    if(newNode == NULL) 
        return false;
    newNode->data = number;
    return push(stack , (StackNode)newNode);//这里用模板里面的压栈操作来实现！
}

/** 出栈 */
bool pop_intStack(Stack stack , int * number)
{
    if(number == NULL)
        return false;
    StackNode popNode;
    if(!pop(stack , &popNode))
        return false;
    IntStackNode intPopNode = (IntStackNode)popNode;
    *number = intPopNode->data;
    free(intPopNode);
    return true;
}

/** 得到栈顶元素 */
bool topValue_intStack(Stack stack , int * number)
{
    if(number == NULL)
        return false;
    StackNode topNode;
    if(!topValue(stack , &topNode))
        return false;
    IntStackNode intTopNode = (IntStackNode)topNode;
    *number = intTopNode->data;
    return true;
}

/** 打印一个栈 */
void print_intStack(Stack stack)
{
    if(stack == NULL)
        return;
    StackNode tempNode = stack->buttom->next;
    while(tempNode!=NULL)
    {
        IntStackNode intNode = (IntStackNode)tempNode;
        printf("%d\t",intNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

/** 摧毁一个栈 */
void destory_intStack(Stack stack)
{
    if(stack == NULL ||\
       stack->buttom == NULL ||\
       stack->top == NULL)
        return;
    StackNode tempNode = stack->buttom;
    freeList(tempNode);
}

/** 清空一个栈 */
void clear(Stack stack)
{
    if(stack == NULL ||\
       stack->buttom == NULL ||\
       stack->top == NULL)
        return;
    StackNode tempNode = stack->buttom->next;
    freeList(tempNode);
    stack->top = stack->buttom;
}

static void freeList(StackNode tempNode)
{
    while(tempNode!=NULL)
    {
        StackNode temp = tempNode->next;
        free((IntStackNode)tempNode);
        tempNode = temp;
    }
}
```
>注意在上面的代码里面，压栈操作和出栈操作都不是重新实现一遍，而是通过栈模板的push(),pop()操作来实现的
>```cpp
>push_intStack()  --基于-> push(stack , (StackNode)newNode);
>pop_intStack() --基于-> pop(stack , &popNode)
>topValue_intStack --基于-> topValue(stack , &topNode)
>```

---

>**测试C语言实现的栈**
>
>运行结果
>test push -------------------------------------------
pushed 10
pushed 11
test push -------------------------------------------

>test top -------------------------------------------
top data is 11
test top -------------------------------------------

>test pop -------------------------------------------
get pop number 11
get pop number 10
pop failed
test pop -------------------------------------------

>test all -------------------------------------------
pushed 12
top data is 12
get pop number 12
pop failed
test all -------------------------------------------


##栈的C++实现
>C++里面有一个非常好用的东西，就是模板，我们借用模板之手实现栈,下面是一个通用接口

---
**_stack.h_**
```cpp
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
```
---

>子类化上面的Stack,实现对应的接口功能

**_arrayBaseStack.h_**
```cpp
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
```

>在源文件中实现接口功能

**_arrayBaseStack.cc_**
```cpp
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
```

怎么样，是不是比C语言版本的容易好多

---

>测试C++实现的栈
>运行结果：
>pushed 0
pushed 1
pushed 2
pushed 3
pushed 4
pushed 5
pushed 6
pushed 7
pushed 8
pushed 9
pushed 10
pushed 11

>0	1	2	3	4	5	6	7	8	9	10	11	

>get 11
get 10
get 9
get 8
get 7
get 6
get 5
get 4
get 3
get 2
get 1
get 0


#结论
C++就是比C语言好用啊！( ¯ □ ¯ ) 

