/*************************************************
* @Filename:    c_stack_int.h
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-27 13:25:27
* @Version:     1.0
* @Description: int类型的栈
**************************************************/
#ifndef C_STACK_INT_H
#define C_STACK_INT_H

#include "c_stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


struct int_stackNode_s
{
    StackNode stackNode;
    int data;
};

typedef struct int_stackNode_s * IntStackNode;

bool push_intStack(Stack , int number);
bool pop_intStack(Stack , int * number);
bool topValue_intStack(Stack , int * number);
void print_intStack(Stack);

#endif