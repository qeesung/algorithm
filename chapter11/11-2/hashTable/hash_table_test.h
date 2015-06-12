/**************************************************
 *       Filename:  hash_table_test.h
 *    Description:  测试链式散列表
 *
 *        Version:  1.0
 *        Created:  2015年06月12日 12时18分18秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (season), 1245712564@qq.com
 *   Organization:  
 **************************************************/

#ifndef  HASH_TABLE_TEST_INC
#define  HASH_TABLE_TEST_INC

#include <cppunit/TestFixture.h>
#include "hash_table.h"
#include <vector>

class HashTableTest : public CppUnit::TestFixture
{
public:	
	// 负责初始化的一些函数
	HashTableTest();
	void setUp();
	void tearDown();

	// 测试插入
	void test_insert();
	// 测试删除
	void test_delete();
	// 测试查找
	void test_search();
private:
	static int hash(const int &);// 一个散列函数
	LinkHashTable<int> * hashTable;
};

#endif   /* ----- #ifndef HASH_TABLE_TEST_INC  ----- */
