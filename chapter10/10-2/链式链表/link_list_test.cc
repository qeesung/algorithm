/*************************************************
* @Filename:    link_list_test.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-06-04 04:36:16
* @Version:     1.0
* @Description: 测试链表的正确性
**************************************************/
#include <iostream>
#include "link_list.h"

int main(int argc, char const *argv[])
{
    LinkList<int> list;
    // insert three element
    std::cout<<"Insert 1 2 3"<<std::endl;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.print();
    list.clear();
    std::cout<<std::endl;

    // append three element
    std::cout<<"append 1 2 3"<<std::endl;
    list.append(1);
    list.append(2);
    list.append(3);
    list.print();
    list.clear();
    std::cout<<std::endl;

    // append three element the remove one of them
    std::cout<<"append 1 2 3 then remove 3"<<std::endl;
    list.append(1);
    list.append(2);
    list.append(3);
    list.remove(3);
    list.print();
    list.clear();
    std::cout<<std::endl;

    return 0;
}