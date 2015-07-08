/**************************************************
 *       Filename:  main.cc
 *    Description:  主测试文件
 *
 *        Version:  1.0
 *        Created:  2015年07月08日 14时27分28秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (season), 1245712564@qq.com
 *   Organization:  
 **************************************************/
#include <stdlib.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include "open_addressing_test.h"


/** 
 * +++  FUNCTION  +++
 *         Name:  main
 *  Description:  主函数
 */
int main ( int argc, char *argv[] )
{
	CppUnit::TextUi::TestRunner runner;	
	CppUnit::TestSuite * suite = new CppUnit::TestSuite();

	suite->addTest(new CppUnit::TestCaller<OpenAddressingTest>("test1 by qeesung", &OpenAddressingTest::test1));
	suite->addTest(new CppUnit::TestCaller<OpenAddressingTest>("test2 by qeesung", &OpenAddressingTest::test2));
	suite->addTest(new CppUnit::TestCaller<OpenAddressingTest>("test3 by qeesung", &OpenAddressingTest::test3));
	runner.addTest(suite);
	runner.run("",true);
	return EXIT_SUCCESS;
}	
