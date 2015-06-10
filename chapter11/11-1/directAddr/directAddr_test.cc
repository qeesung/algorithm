/**************************************************
 *       Filename:  directAddr_test.cc
 *    Description:  测试的源文件
 *
 *        Version:  1.0
 *        Created:  2015年06月10日 13时06分46秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (season), 1245712564@qq.com
 *   Organization:  
 **************************************************/

#include <cppunit/TestAssert.h>
#include "directAddr_test.h"
#include <iostream>
#include <vector>



void DirectAddrTest::setUp ()
{
	return ;
}		/** -----  end of method DirectAddrTest::setUp  ----- */



void DirectAddrTest::tearDown ()
{
	directAddr->clear();
	return ;
}		/** -----  end of method DirectAddrTest::tearDowm  ----- */



void DirectAddrTest::testInsert ()
{
	{
		DataNode<char> node1(1,'a');
		directAddr->direct_insert(node1);
	}
	{
		DataNode<char> node1(2,'b');
		directAddr->direct_insert(node1);
	}
	{
		DataNode<char> node1(1,'c');
		directAddr->direct_insert(node1);
	}
	// 得到输出
	std::vector<std::vector<char> > retVec;
	directAddr->printToVec(retVec);

	// 期望的输出
	std::vector<std::vector<char> > exceptedVec;
	exceptedVec.push_back(std::vector<char>());
	{
		std::vector<char> vec1;
		vec1.push_back('c');
		vec1.push_back('a');
		exceptedVec.push_back(vec1);
	}
	{
		std::vector<char> vec1;
		vec1.push_back('b');
		exceptedVec.push_back(vec1);
	}
	exceptedVec.push_back(std::vector<char>());
	CPPUNIT_ASSERT(exceptedVec.size() == retVec.size());
	int i = 0;
	while(i < exceptedVec.size())
	{
		CPPUNIT_ASSERT(exceptedVec[i] == retVec[i]);
		++i;
	}
	return ;
}		/** -----  end of method DirectAddrTest::testInsert  ----- */




void DirectAddrTest::testDelete ()
{
	/*  insert the node */
	{
		DataNode<char> node1(1,'a');
		directAddr->direct_insert(node1);
	}
	{
		DataNode<char> node1(2,'b');
		directAddr->direct_insert(node1);
	}
	{
		DataNode<char> node1(1,'c');
		directAddr->direct_insert(node1);
	}
	/*  delete the node */
	{
		DataNode<char> node1(1,'a');
		directAddr->direct_delete(node1);
	}
	// 得到输出
	std::vector<std::vector<char> > retVec;
	directAddr->printToVec(retVec);

	// 期望的输出
	std::vector<std::vector<char> > exceptedVec;
	exceptedVec.push_back(std::vector<char>());
	{
		std::vector<char> vec1;
		vec1.push_back('c');
		exceptedVec.push_back(vec1);
	}
	{
		std::vector<char> vec1;
		vec1.push_back('b');
		exceptedVec.push_back(vec1);
	}
	exceptedVec.push_back(std::vector<char>());
	CPPUNIT_ASSERT(exceptedVec.size() == retVec.size());
	int i = 0;
	while(i < exceptedVec.size())
	{
		CPPUNIT_ASSERT(exceptedVec[i] == retVec[i]);
		++i;
	}
	return ;
}		/** -----  end of method DirectAddrTest::testDelete  ----- */



void DirectAddrTest::testSearch ()
{
	
	/*  insert the node */
	{
		DataNode<char> node1(1,'a');
		directAddr->direct_insert(node1);
	}
	{
		DataNode<char> node1(2,'b');
		directAddr->direct_insert(node1);
	}
	{
		DataNode<char> node1(1,'c');
		directAddr->direct_insert(node1);
	}
	// search the key 1
	std::vector<char> retVec = directAddr->direct_search(1);
	std::vector<char> exceptedVec;
	exceptedVec.push_back('c');
	exceptedVec.push_back('a');
	CPPUNIT_ASSERT(retVec == exceptedVec);
	return ;
}		/** -----  end of method DirectAddrTest::testSearch  ----- */



