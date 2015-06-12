/**************************************************
 *       Filename:  hashTable.h
 *    Description:  链接法散列表
 *
 *        Version:  1.0
 *        Created:  2015年06月12日 11时19分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (season), 1245712564@qq.com
 *   Organization:  
 **************************************************/

#ifndef  HASHTABLE_INC
#define  HASHTABLE_INC

#include "link_list.h"
#include <vector>


/**
 *        Class:  LinkHashTable
 *  Description:  链接法散列表
 */
template < class T >
class LinkHashTable
{
	public:
		/** ====================  LIFECYCLE     ======================================= */
		LinkHashTable (int table_size=0 , int(*_HASH)(const T &)=0);                             /** constructor */
		/** ====================  MUTATORS      ======================================= */
		bool hash_insert(const T &); /*插入操作*/ 
		bool hash_delete(const T &);  /*删除操作*/ 
		std::vector<T> hash_search(int) const; /*查找操作*/ 
		void clear();
		void printToVec(std::vector<std::vector<T> > & );
	private:
		/** ====================  DATA MEMBERS  ======================================= */
		int (*HASH)(const T &);// 定义一个散列函数指针
		LinkList<T> * array; //链表的数组 
		const size_t table_size;// 散列表的大小
}; /** ----------  end of template class LinkHashTable  ---------- */




#include "hash_table.cc"
#endif   /* ----- #ifndef HASHTABLE_INC  ----- */
