/*************************************************
* @Filename:    main.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-27 10:52:06
* @Version:     1.0
* @Description: 主测试函数
**************************************************/
#include "arrayBaseStack.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    ArrayBaseStack<int> stack(10);
    for (int i = 0; i < 12; ++i)
    {
        if(stack.push(i))
            std::cout<<"pushed "<<i<<std::endl;
        else 
            std::cout<<"push "<<i<<" error"<<std::endl;
    }  
    stack.printStack();
    for (int i = 0; i < 12; ++i)
    {
        int number ;
        if(stack.pop(number))
            std::cout<<"get "<<number<<std::endl;
        else
            std::cout<<"stack is empty"<<std::endl;
    }
    while(1);
    return 0;
}