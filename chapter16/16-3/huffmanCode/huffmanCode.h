/*************************************************
* @Filename:    huffmanCode.h
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-09 20:34:37
* @Version:     1.0
* @Description: 霍夫曼编码压缩
**************************************************/

#ifndef HUFFMAN_CODE_H
#define HUFFMAN_CODE_H

#include <string>
#include <iostream>
#include "treeNode.h"

void buildHuffmanCode(const std::string & filename);// 构建前缀码
void printHuffmanTree(TreeNode * tree , const std::string & prefix);

#endif
