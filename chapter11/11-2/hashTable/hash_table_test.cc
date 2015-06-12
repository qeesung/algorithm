/**************************************************
 *       Filename:  hash_table_test.cc
 *    Description:  链接法散列的测试源文件
 *
 *        Version:  1.0
 *        Created:  2015年06月12日 12时25分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (season), 1245712564@qq.com
 *   Organization:  
 **************************************************/


#include "hash_table_test.h"
#include <cppunit/TestAssert.h>

/**
 *       Class:  HashTableTest
 *      Method:  HashTableTest
 * Description:  
 */

HashTableTest::HashTableTest ()
{
	hashTable = new LinkHashTable<int>(3 , hash);
}  /** ----------  end of constructor of template class HashTableTest  ---------- */



void HashTableTest::setUp ()
{
	return ;
}		/** -----  end of method HashTableTest<T>::setUp  ----- */




void HashTableTest::tearDown ()
{
	hashTable->clear();		
	return ;
}		/** -----  end of method HashTableTest<T>::tearDown  ----- */



void HashTableTest::test_insert ()
{
	{
		hashTable->hash_insert(1);
		hashTable->hash_insert(2);
		hashTable->hash_insert(4);
		hashTable->hash_insert(3);
	}
	std::vector<std::vector<int> > retVec;
	hashTable->printToVec(retVec);
	
	std::vector<std::vector<int> > exceptedVec;
	{
		std::vector<int> vec;
		vec.push_back(3);
		exceptedVec.push_back(vec);
	}
	{
		std::vector<int> vec;
		vec.push_back(4);
		vec.push_back(1);
		exceptedVec.push_back(vec);
	}
	{
		std::vector<int> vec;
		vec.push_back(2);
		exceptedVec.push_back(vec);
	}
	CPPUNIT_ASSERT(exceptedVec == retVec);
	return ;
}		/** -----  end of method HashTableTest<T>::test_insert  ----- */
	


void HashTableTest::test_delete ()
{
	{
		hashTable->hash_insert(1);
		hashTable->hash_insert(2);
		hashTable->hash_insert(4);
		hashTable->hash_insert(3);
		hashTable->hash_delete(1);
	}
	std::vector<std::vector<int> > retVec;
	hashTable->printToVec(retVec);
	
	std::vector<std::vector<int> > exceptedVec;
	{
		std::vector<int> vec;
		vec.push_back(3);
		exceptedVec.push_back(vec);
	}
	{
		std::vector<int> vec;
		vec.push_back(4);
		exceptedVec.push_back(vec);
	}
	{
		std::vector<int> vec;
		vec.push_back(2);
		exceptedVec.push_back(vec);
	}
	CPPUNIT_ASSERT(exceptedVec == retVec);
	return ;
}		/** -----  end of method HashTableTest::test_delete  ----- */



void HashTableTest::test_search ()
{
	{
		hashTable->hash_insert(1);
		hashTable->hash_insert(2);
		hashTable->hash_insert(4);
		hashTable->hash_insert(3);
	}
	
	{
		std::vector<int> retVec;
		retVec=hashTable->hash_search(1);
		std::vector<int> exceptedVec;	
		exceptedVec.push_back(4);
		exceptedVec.push_back(1);
		CPPUNIT_ASSERT(retVec == exceptedVec);
	}	
	
	{
		std::vector<int> retVec;
		retVec=hashTable->hash_search(2);
		std::vector<int> exceptedVec;	
		exceptedVec.push_back(2);
		CPPUNIT_ASSERT(retVec == exceptedVec);
	}	
	{
		std::vector<int> retVec;
		retVec=hashTable->hash_search(0);
		std::vector<int> exceptedVec;	
		exceptedVec.push_back(3);
		CPPUNIT_ASSERT(retVec == exceptedVec);
	}	
	return ;
}		/** -----  end of method HashTableTest::test_search  ----- */


int HashTableTest::hash (const int & data)
{
	return data%3;
}		/** -----  end of method HashTableTest::hash  ----- */



