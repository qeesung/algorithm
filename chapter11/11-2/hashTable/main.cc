/**************************************************
 *       Filename:  main.cc
 *    Description:  测试的主函数
 *
 *        Version:  1.0
 *        Created:  2015年06月12日 13时38分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (season), 1245712564@qq.com
 *   Organization:  
 **************************************************/
#include <stdlib.h>
#include "hash_table_test.h"
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>



/** 
 * +++  FUNCTION  +++
 *         Name:  main
 *  Description:  测试的主函数
 */
int main ( int argc, char *argv[] )
{
	CppUnit::TextUi::TestRunner runner;	
	CppUnit::TestSuite * suite = new CppUnit::TestSuite();

	suite->addTest(new CppUnit::TestCaller<HashTableTest>("Test insert by qeesung", &HashTableTest::test_insert));
	suite->addTest(new CppUnit::TestCaller<HashTableTest>("Test delete by qeesung", &HashTableTest::test_delete));
	suite->addTest(new CppUnit::TestCaller<HashTableTest>("Test search by qeesung", &HashTableTest::test_search));
	runner.addTest(suite);
	runner.run("",true);
	return EXIT_SUCCESS;

	return EXIT_SUCCESS;
}				/** ----------  end of function main  ---------- */



