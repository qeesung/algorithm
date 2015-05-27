/*************************************************
* @Filename:    c_stack.c
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-27 12:23:37
* @Version:     1.0
* @Description: c语言版本的通用栈接口源文件，链式接口实现
**************************************************/
#include "c_stack.h"
#include <stdlib.h>
#include <stdio.h>

Stack createStack()
{
    Stack newStack = (Stack)malloc(sizeof(struct stack_s));
    if(newStack == NULL)
        return NULL;
    // 创建一个头部节点
    newStack->buttom = (StackNode)malloc(sizeof(struct stackNode_s));
    if(newStack->buttom == NULL)
    {
        free(newStack);
        return NULL;
    }
    newStack->buttom->next =NULL;
    newStack->top = newStack->buttom;
    return newStack;
}

bool push(Stack stack , StackNode stackNode)
{   
    if(stack == NULL ||\
       stack->top == NULL ||\
       stack->buttom == NULL ||\
       stackNode == NULL)
        return false;
    stackNode->next = NULL;

    stack->top->next = stackNode;
    stack->top = stackNode;
    return true;
}

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
