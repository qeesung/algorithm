[TOC]

<b><font color="red">注意:</font></b>
本文中的所有代码你可以在这里：
[https://github.com/qeesung/algorithm/tree/master/chapter11/11-1/directAddr](https://github.com/qeesung/algorithm/tree/master/chapter11/11-1/directAddr)(这里的会及时更新)
或者这里：
[http://download.csdn.net/detail/ii1245712564/8793509](http://download.csdn.net/detail/ii1245712564/8793509)
找到
#散列表之直接寻址表
`散列表`是实现字典操作的一个有效的数据结构，尽管在最坏情况下，散列表的查找和删除的最坏时间代价为$\Theta (n)$,但是在实际中，散列表的性能是很好的，在一些合理的假设下，散列表的查找和删除操作的平均时间代价为$\Theta(1)$,下面将要介绍的就是诸多散列表中的最简单直接的一种:`直接散列表`。

在讲直接寻址表之前,先来看个栗子:假设现在有十个排成一排带锁的箱子，每一个箱子都有一把钥匙，将所有的钥匙从[1-10]编号，现在随便给你其中的一把钥匙$key_i$，要你找到要是对应的箱子。一个一个试么？正常的小伙伴肯定是通过钥匙的编号$i$找到第$i$个箱子就行啦。

在许多的编程语言里面都用到了这种直接通过$key$找到数据的思想，最简单的就是`数组`啦，数组是可以直接访问的，通过数组的起始地址加上一个偏移量得到目标数据的存储地址。这种方法是很快的，可以在$\Theta(1)$时间内完成。直接寻址表就借助了数组这种可以直接访问的优势。

#直接寻址表的定义
假设有一个数据集合$U=\lbrace d_1,d_2,d_3,...,d_n\rbrace$,该数据集合里面的每一个元素$d_i$都有一个对应的键值$key_i$和数据$data_i$。集合中的任意一个$key_i$都是在$[0,m]$之间的整数。新建一个数组$A[0..m]$,遍历一遍集合$U$,将其中的数据$d_i$放到$A[key_i]$中。
![Alt text](http://img.blog.csdn.net/20150613130844136)

 
#直接寻址表的操作
直接寻址表的基本操作有:

- **INSERT**:插入一个元素
- **DELETE**:删除一个元素
- **SEARCH**:查找一个元素

>**问题**:要是集合$U$的元素键值并不唯一，即$key_i$和$key_j$$(i \neq j)$有可能相等，那么在相等的情况下该怎么办呢？
>
>**回答**:采用链表的形式将相同键值的元素串成一串，全都挂在$A[key_i]$的后面，比如键值1重复：
>![Alt text](http://img.blog.csdn.net/20150613130901226)


#直接寻址表的代码实现
首先看一下有那些文件
```bash
├── dataNode.cc 数据节点源文件
├── dataNode.h 数据节点头文件
├── directAddr.cc 直接寻址法源文件
├── directAddr.h 直接寻址法的头文件
├── directAddr_test.cc cppunit测试直接寻址源文件
├── directAddr_test.h cppunit测试设备的定义头文件
├── main.cc 测试主文件
├── Makefile
└── README.md
0 directories, 9 files
```
##dataNode的定义
dataNode是基础的数据节点
**dataNode.h**
```cpp
#ifndef  DATANODE_INC
#define  DATANODE_INC

#include <cstdio>

/**
 *        Class:  DataNode
 *  Description:  基本的节点
 */
template < class T >
class DataNode
{
	public:
		/** ====================  LIFECYCLE     ======================================= */
		DataNode (int key = 0 , T data=T() ,DataNode<T> * next = NULL);                             /** constructor */
		/** ====================  ACCESSORS     ======================================= */
		void set_key(int);
		int get_key() const;

		void set_data(T);
		T get_data() const;

		DataNode<T> * next;
	private:
		/** ====================  DATA MEMBERS  ======================================= */
		int key;// 对应的键值
		T data;// 对应的数据
}; /** ----------  end of template class DataNode  ---------- */


#include "dataNode.cc"
#endif   /* ----- #ifndef DATANODE_INC  ----- */
```
>`dataNode`里面有两个基本数据:key和data

**dataNode.cc**
```cpp
/**
 *       Class:  DataNode
 *      Method:  DataNode
 * Description:  构造函数
 */
template < class T >
DataNode < T >::DataNode (int _key , T _data , DataNode<T> * _next):key(_key),data(_data),next(_next)
{
}  /** ----------  end of constructor of template class DataNode  ---------- */




/**
 *       Class:  DataNode
 *      Method:  get_key
 */
template < class T >
inline  int DataNode<T>::get_key (  ) const
{
	return key;
}		/** -----  end of method DataNode<T>::get_key  ----- */

/**
 *       Class:  DataNode
 *      Method:  set_key
 */
template < class T >
inline  void DataNode<T>::set_key ( int value )
{
	key	= value;
	return ;
}		/** -----  end of method DataNode<T>::set_key  ----- */



/**
 *       Class:  DataNode
 *      Method:  get_data
 */
template < class T >
inline  T DataNode<T>::get_data (  ) const
{
	return data;
}		/** -----  end of method DataNode<T>::get_data  ----- */

/**
 *       Class:  DataNode
 *      Method:  set_data
 */
template < class T >
inline  void DataNode<T>::set_data ( T value )
{
	data	= value;
	return ;
}		/** -----  end of method DataNode<T>::set_data  ----- */
```

##直接寻址表的定义
**directAddr.h**
```cpp
#ifndef  DIRECTADDR_INC
#define  DIRECTADDR_INC

#include "dataNode.h"
#include <vector>
#include <string>

/**
 *        Class:  DirectAddr
 *  Description:  直接寻址接口
 */
template < class T >
class DirectAddr
{
	public:
		/** ====================  LIFECYCLE     ======================================= */
		DirectAddr (int _key_min=0 , int _key_max=0);                             /** constructor */
		~DirectAddr();

		bool direct_delete(DataNode<T> &);
		bool direct_insert(DataNode<T> &);
		std::vector<T> direct_search(int);
		void printToVec(std::vector<std::vector<T> > &);
		void clear();
	private:
		/** ====================  DATA MEMBERS  ======================================= */
		void deleteAllNode(DataNode<T> * nodePtr);
		DataNode<T>* array;
		const int table_size; // 存储表的大小
		const int key_min; // 存储键值的最小值
		const int key_max;// 存储键值的最大值
}; /** ----------  end of template class DirectAddr  ---------- */

#include "directAddr.cc"
#endif   /* ----- #ifndef DIRECTADDR_INC  ----- */
```
**directAddr.cc**
```cpp
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <typeinfo>

/**
 *       Class:  DirectAddr
 *      Method:  DirectAddr
 * Description:  构造函数 
 */
template < class T >
DirectAddr < T >::DirectAddr (int _key_min , int _key_max):key_min(_key_min),\
															   key_max(_key_max),table_size(_key_max - _key_min+1)
{
	array = new DataNode<T>[table_size]();
	for ( int i = 0 ; i< table_size ; ++i )
	{
		array[i].next = NULL;	
	}

}  /** ----------  end of constructor of template class DirectAddr  ---------- */


/**
 *       Class:  DirectAddr
 *      Method:  ~DirectAddr
 * Description:  destructor
 */
	template < class T >
DirectAddr< T >::~DirectAddr ()
{
	clear();
	delete [] array;
}  /** ----------  end of destructor of template class DirectAddr  ---------- */


/**
 *  插入一个新的元素
 */
	template < class T >
bool DirectAddr<T>::direct_insert (DataNode<T> & node)
{
	if(node.get_key() <key_min || node.get_key()>key_max)
		return false;	
	DataNode<T> * tempNode = array[node.get_key() - key_min].next;
	DataNode<T> * newNode = new DataNode<T>(node.get_key() , node.get_data(), tempNode);
	if(newNode == NULL)
		return false;
	array[node.get_key() - key_min].next = newNode;
	return true;
}		/** -----  end of method DirectAddr<T>::direct_insert  ----- */




template < class T >
bool DirectAddr<T>::direct_delete (DataNode<T> & node)
{
	if(node.get_key()<key_min || node.get_key()>key_max)
		return false;
	DataNode<T> * targetNode = &array[node.get_key() - key_min];
	/*  找到需要删除的点 */
	while(targetNode->next != NULL && targetNode->next->get_data()!=node.get_data())
	{
		targetNode = targetNode->next;
	}
	if(targetNode->next == NULL)
		return false;
	// 找到节点，开始删除
	DataNode<T> * tempNode = targetNode->next->next;
	delete targetNode->next; 
	targetNode->next = tempNode;
	return true;
}		/** -----  end of method DirectAddr<T>::direct_delete  ----- */


template < class T >
std::vector<T> DirectAddr<T>::direct_search (int key)
{
	if(key<key_min || key>key_max)
		return std::vector<T>();
	std::vector<T> retVec;
	DataNode<T> * tempNode = array[key - key_min].next;
	while(tempNode != NULL)
	{
		retVec.push_back(tempNode->get_data());
		tempNode = tempNode->next;
	}
	return retVec;
}		/** -----  end of method DirectAddr<T>::direct_search  ----- */


	template < class T >
void DirectAddr<T>::clear ()
{
	for(int i = 0 ; i < table_size ; ++i)
	{
		deleteAllNode(array[i - key_min].next);
	}
	return ;
}		/** -----  end of method DirectAddr<T>::clear  ----- */



template < class T >
void DirectAddr<T>::deleteAllNode (DataNode<T> * nodePtr)
{
	if(nodePtr ==  NULL)
		return;
	while(nodePtr != NULL)
	{
		DataNode<T> * tempNode = nodePtr->next;	
		delete nodePtr;
		nodePtr = tempNode;
	}
	return ;
}		/** -----  end of method DirectAddr<T>::deleteAllNode  ----- */



template < class T >
void DirectAddr<T>::printToVec (std::vector<std::vector<T> > & vec)
{
	for ( int i = 0 ; i < table_size;++i )
	{
		std::vector<T> tempVec;
		DataNode<T> * tempNode = array[i - key_min].next;
		while(tempNode!=NULL)
		{
			tempVec.push_back(tempNode->get_data());
			tempNode=tempNode->next;
		}
		vec.push_back(tempVec);
	}
}		/** -----  end of method DirectAddr<T>::printToStr  ----- */
```
##测试文件
测试直接寻址表是否可以正确运行
**main.cc**
```cpp
#include <stdlib.h>
#include "directAddr.h"
#include "directAddr_test.h"
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>


/** 
 * +++  FUNCTION  +++
 *         Name:  main
 *  Description:  主函数
 */
int main ( int argc, char *argv[] )
{
	CppUnit::TextUi::TestRunner runner;	
	CppUnit::TestSuite * suite = new CppUnit::TestSuite();

	suite->addTest(new CppUnit::TestCaller<DirectAddrTest>("Test insert by qeesung",\
	 &DirectAddrTest::testInsert));
	suite->addTest(new CppUnit::TestCaller<DirectAddrTest>("Test delete by qeesung",\
	 &DirectAddrTest::testDelete));
	suite->addTest(new CppUnit::TestCaller<DirectAddrTest>("Test search by qeesung",\
	 &DirectAddrTest::testSearch));
	runner.addTest(suite);
	runner.run("",true);
	return EXIT_SUCCESS;
}				/** ----------  end of function main  ---------- */
```
##编译运行

```cpp
├── dataNode.cc 数据节点源文件
├── dataNode.h 数据节点头文件
├── directAddr.cc 直接寻址法源文件
├── directAddr.h 直接寻址法的头文件
├── directAddr_test.cc cppunit测试直接寻址源文件
├── directAddr_test.h cppunit测试设备的定义头文件
├── main.cc 测试主文件
├── Makefile
└── README.md
0 directories, 9 files
```

**编译方法**

- 如果你的电脑有`cppunit`的动态链接库
```bash
make 
```
- 如果没有`cppunit`的动态链接库,你可以在你的源文件yourSourceFile.cc里面包含`#include "directAddr.h"`,就可以使用直接寻址表
```bash
g++ yourSourceFile.cc -o target
```

**执行程序**
```bash
./testDirectAddr(or ./yourTarget)
```

<b><font color="red">注意:</font></b>
本文中的所有代码你可以在这里：
[https://github.com/qeesung/algorithm/tree/master/chapter11/11-1/directAddr](https://github.com/qeesung/algorithm/tree/master/chapter11/11-1/directAddr)(这里的会及时更新)
或者这里：
[http://download.csdn.net/detail/ii1245712564/8793509](http://download.csdn.net/detail/ii1245712564/8793509)
找到

#总结

直接寻址表比较适用于键值范围不大，而且键值分布比较均匀的情况，比如我们只有两个数据(key:1,data),(key:10000,data),如果使用直接寻址表，那么就要分配100001大小的数组来保存这两个数据，太浪费了，所以在键值范围太大，而且数据太少的情况下不建议使用直接寻址表。


