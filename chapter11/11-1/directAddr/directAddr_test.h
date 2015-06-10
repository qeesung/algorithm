/**************************************************
 *       Filename:  directAddr_test.h
 *    Description:  对directAddr进行测试
 *
 *        Version:  1.0
 *        Created:  2015年06月10日 12时51分15秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (season), 1245712564@qq.com
 *   Organization:  
 **************************************************/


#ifndef  DIRECTADDR_TEST_INC
#define  DIRECTADDR_TEST_INC

#include <cppunit/TestFixture.h>
#include <string>
#include "dataNode.h"
#include "directAddr.h"

class DirectAddrTest : public CppUnit::TestFixture{

public:
	DirectAddrTest()
	{
		directAddr = new DirectAddr<char>(0,3);	
	}
	void setUp();
	void tearDown();

	/* 测试插入操作 */
	void testInsert();
	/* 测试删除操作 */
	void testDelete();
	/*  测试查询操作 */
	void testSearch();
protected:
	DirectAddr<char> * directAddr;
};

#endif   /* ----- #ifndef DIRECTADDR_TEST_INC  ----- */

