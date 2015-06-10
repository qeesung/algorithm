/**************************************************
 *       Filename:  main.cc
 *    Description:	主函数
 *
 *        Version:  1.0
 *        Created:  2015年06月10日 13时50分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (season), 1245712564@qq.com
 *   Organization:  
 **************************************************/
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

	suite->addTest(new CppUnit::TestCaller<DirectAddrTest>("Test insert by qeesung", &DirectAddrTest::testInsert));
	suite->addTest(new CppUnit::TestCaller<DirectAddrTest>("Test insert by qeesung", &DirectAddrTest::testDelete));
	suite->addTest(new CppUnit::TestCaller<DirectAddrTest>("Test insert by qeesung", &DirectAddrTest::testSearch));
	runner.addTest(suite);
	runner.run("",true);
	return EXIT_SUCCESS;
}				/** ----------  end of function main  ---------- */
