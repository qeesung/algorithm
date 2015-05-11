/*************************************************
* @Filename:    huffmanCode.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-09 22:03:12
* @Version:     1.0
* @Description: 霍夫曼编码的源文件
**************************************************/

#include "huffmanCode.h"
#include "priorityQueue.h"
#include "treeNode.h"
#include <iostream>
#include <fstream>
#include <vector>

void buildHuffmanCode(const std::string & filename)
{
    // 读取文件里面的code，假设文件里面只包含26个小写英语字母
    const int ascDiff = (int)'a';
    const int & letterKind = 26;
    int letterCount[letterKind];
    int sum = 0;
    for (int i = 0; i < letterKind; ++i)
    {
        letterCount[i] = 0;
    }
    // open the file
    std::ifstream infile(filename.c_str() , std::ios::in);
    std::string readLine;
    while(infile >> readLine)
    {
        for(std::string::iterator iter = readLine.begin() ; iter!= readLine.end() ; ++iter)
        {
            if('a'<=*iter && 'z'>= *iter)
            {
                letterCount[(int)*iter - ascDiff]++;
                sum++;
            }
        }
    }
    // create treeNode
    std::vector<TreeNode> recordVec;
    for (int i = 0; i < letterKind; ++i)
    {
        if(letterCount[i] != 0)
        {
            float percent = letterCount[i]/(float)sum;
            TreeNode newNode(percent , (char)(i+'a')) ;
            recordVec.push_back(newNode);
        }
    }
    // 下面开始构建最小堆
    PriorityQueue pQueue(recordVec.begin() , recordVec.end());
    pQueue.print();
    // 下面开始建立编码树
    TreeNode newNode;
    while(pQueue.size() > 1)
    {
        // get the min
        TreeNode minNode1 = pQueue.extractMin();
        TreeNode minNode2 = pQueue.extractMin();
        newNode.percent =  minNode1.percent+minNode2.percent;

        std::cout<<minNode1.percent<<"+"<<minNode2.percent<<"="<<newNode.percent<<std::endl;
        TreeNode * newTreeNode1 = new  TreeNode(); 
        *newTreeNode1 = minNode1;
        TreeNode * newTreeNode2 = new  TreeNode(); 
        *newTreeNode2 = minNode2;

        newNode.leftChild = newTreeNode1;
        newNode.rightChild = newTreeNode2;

        pQueue.insert(newNode);
    }
    // 编码树构建成功
    // 这里的newNode就是我们目标编码树
    std::string str;
    printHuffmanTree(&newNode , str);
}

void printHuffmanTree(TreeNode * tree , const std::string & prefix)
{
    if(tree == NULL)
        return;
    if(tree->leftChild == NULL && tree->rightChild == NULL)
    {
        std::cout<<tree->data<<" ----> "<<prefix<<std::endl;
    }
    printTree(tree->leftChild , prefix+"0");
    printTree(tree->rightChild , prefix+"1");
}   