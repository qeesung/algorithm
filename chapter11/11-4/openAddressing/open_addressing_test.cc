/**************************************************
 *       Filename:  open_addressing_test.cc
 *    Description:  开放定址的测试源文件
 *
 *        Version:  1.0
 *        Created:  2015年07月08日 14时01分47秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (season), 1245712564@qq.com
 *   Organization:  
 **************************************************/

#include <stdlib.h>
#include <cppunit/TestAssert.h>
#include "open_addressing_test.h"

template <class T>size_t double_hashing(const T & , size_t, size_t )    ; /* 双重散列 */
/**
 *       Class:  OpenAddressingTest
 *      Method:  OpenAddressingTest
 * Description:  constructor
 */
OpenAddressingTest::OpenAddressingTest ()
{
	open_addressing_table = new OpenAddressingTable<DataType>(13 , double_hashing); /* 创建一个大小为13的散列表 */
}  /** -----  end of method OpenAddressingTest::OpenAddressingTest  (constructor)  ----- */


/**
 *  初始化
 */
void OpenAddressingTest::setUp ()
{
	open_addressing_table->hash_clear();
	return ;
}		/** -----  end of method OpenAddressingTest::setUp  ----- */


void OpenAddressingTest::tearDown ()
{
	return ;
}		/** -----  end of method OpenAddressingTest::tearDown  ----- */


/**
 *  测试1
 */
void OpenAddressingTest::test1 ()
{
	CPPUNIT_ASSERT(open_addressing_table->hash_insert(DataType(1 , "This is 1")));
	CPPUNIT_ASSERT(open_addressing_table->hash_insert(DataType(14 , "This is 14")));
	CPPUNIT_ASSERT(open_addressing_table->hash_insert(DataType(2 , "This is 2")));

	DataType target(0,"0");
	CPPUNIT_ASSERT(open_addressing_table->hash_search(DataType(1,""),target));
	CPPUNIT_ASSERT(target.key == 1);
	CPPUNIT_ASSERT(target.data == "This is 1");

	CPPUNIT_ASSERT(open_addressing_table->hash_search(DataType(2,""),target));
	CPPUNIT_ASSERT(target.key == 2);
	CPPUNIT_ASSERT(target.data == "This is 2");
	return ;
}		/** -----  end of method OpenAddressingTest::test1  ----- */



void OpenAddressingTest::test2 ()
{
	open_addressing_table->hash_insert(DataType(1 , "This is 1"));
	open_addressing_table->hash_insert(DataType(14 , "This is 14"));
	open_addressing_table->hash_insert(DataType(2 , "This is 2"));

	CPPUNIT_ASSERT(open_addressing_table->hash_delete(DataType(1,"")));

	DataType target(0,"0");
	CPPUNIT_ASSERT(!open_addressing_table->hash_search(DataType(1,""),target));

	CPPUNIT_ASSERT(open_addressing_table->hash_search(DataType(2,""),target));
	CPPUNIT_ASSERT(target.key == 2);
	CPPUNIT_ASSERT(target.data == "This is 2");
	return ;
}		/** -----  end of method OpenAddressingTest::test2  ----- */

void OpenAddressingTest::test3 ()
{
	open_addressing_table->hash_insert(DataType(1 , "This is 1"));
	open_addressing_table->hash_insert(DataType(14 , "This is 14"));
	open_addressing_table->hash_insert(DataType(2 , "This is 2"));

	CPPUNIT_ASSERT(open_addressing_table->hash_delete(DataType(14,"")));

	DataType target(0,"0");
	CPPUNIT_ASSERT(!open_addressing_table->hash_search(DataType(14,""),target));

	CPPUNIT_ASSERT(open_addressing_table->hash_search(DataType(2,""),target));
	CPPUNIT_ASSERT(target.key == 2);
	CPPUNIT_ASSERT(target.data == "This is 2");
	return ;
}		/** -----  end of method OpenAddressingTest::test3  ----- */
