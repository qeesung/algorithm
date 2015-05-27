/*************************************************
* @Filename:    c_stack_int.c
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-27 13:28:42
* @Version:     1.0
* @Description: int类型的栈的实现
**************************************************/
#include "c_stack_int.h"
#include <stdlib.h>

bool push_intStack(Stack stack , int number)
{
    IntStackNode newNode = (IntStackNode)malloc(sizeof(struct int_stackNode_s));
    if(newNode == NULL) 
        return false;
    newNode->data = number;
    return push(stack , (StackNode)newNode);
}

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