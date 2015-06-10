/*************************************************
* @Filename:    arrayBaseQueue_Test.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-28 10:51:34
* @Version:     1.0
* @Description: 测试顺序队列
**************************************************/
#include "arrayBaseQueue.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    ArrayBaseQueue<int> queue(3);
    /** test enqueue */
    for (int i = 0; i < 5; ++i)
    {
        if(queue.enqueue(i))
            std::cout<<"enqueue "<<i<<" done"<<std::endl;
        else
            std::cout<<"enqueue "<<i<<" failed"<<std::endl;
    }
    /** test front_value */
    {
        int temp;
        if(queue.front_value(temp))
            std::cout<<"front value : "<<temp<<std::endl;
        else
            std::cout<<"get front value failed"<<std::endl;
    }

    /** test dequeue */
    for (int i = 0; i < 5; ++i)
    {
        int temp;
        if(queue.dequeue(temp))
            std::cout<<"dequeue "<<temp<<" done!"<<std::endl;
        else
            std::cout<<"dequeue failed"<<std::endl;
    }
    return 0;
}