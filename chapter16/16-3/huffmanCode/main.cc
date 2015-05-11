/*************************************************
* @Filename:    main.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-09 22:45:34
* @Version:     1.0
* @Description: 霍夫曼编码的测试源文件
**************************************************/
#include "huffmanCode.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    if(argc!= 2)
    {
        cerr<<"usage: huffman <filename>";
        return -1;
    }
    buildHuffmanCode(argv[1]);
    return 0;
}