/*************************************************
* @Filename:    c_stack.h
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-27 12:23:18
* @Version:     1.0
* @Description: c语言版本的通用栈接口头文件，此处为链式结构实现
**************************************************/
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
