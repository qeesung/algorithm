/**************************************************
 *       Filename:  open_addressing_test.h
 *    Description:  开放定址散列表的测试头文件
 *
 *        Version:  1.0
 *        Created:  2015年07月08日 13时50分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (season), 1245712564@qq.com
 *   Organization:  
 **************************************************/

#ifndef  OPEN_ADDRESSING_TEST_INC
#define  OPEN_ADDRESSING_TEST_INC

#include <cppunit/TestFixture.h>
#include "data_type.h"
#include "open_addressing.h"

/**
 *        Class:  OpenAddressingTest
 *  Description:  开放定址的测试
 */
class OpenAddressingTest : public CppUnit::TestFixture
{
	public:
		/** ====================  LIFECYCLE     ======================================= */
		OpenAddressingTest ();                             /** constructor */
		/** ====================  MUTATORS      ======================================= */
		void setUp();
		void tearDown();

		void test1();
		void test2();
		void test3();
		//void test4();
		//void test5();
	private:
		/** ====================  DATA MEMBERS  ======================================= */
		OpenAddressingTable<DataType> * open_addressing_table;

}; /** -----  end of class OpenAddressingTest  ----- */

#endif   /* ----- #ifndef OPEN_ADDRESSING_TEST_INC  ----- */
