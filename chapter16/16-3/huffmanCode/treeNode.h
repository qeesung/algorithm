/*************************************************
* @Filename:    treeNode.h
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-09 19:36:31
* @Version:     1.0
* @Description: 二叉树的树节点头文件定义
**************************************************/

#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <iostream>
class TreeNode
{
public:
    TreeNode(float _percent = 0.0 , char _data = 0):percent(_percent),data(_data)
    {
        leftChild = NULL;
        rightChild = NULL;
    }
    float percent;// 存储百分比
    char data;//存储实际的数据 
    TreeNode * leftChild;//左子树节点
    TreeNode * rightChild;//右子树节点
    bool operator<(const TreeNode & node)
    {
        return this->percent < node.percent;
    }

    bool operator>(const TreeNode & node)
    {
        return this->percent > node.percent;
    }

    bool operator==(const TreeNode & node)
    {
        return this->percent == node.percent;
    }
};

#endif