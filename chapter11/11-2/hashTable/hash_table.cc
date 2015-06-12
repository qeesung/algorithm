/**************************************************
 *       Filename:  hash_table.cc
 *    Description:  链接法hash表的实现
 *
 *        Version:  1.0
 *        Created:  2015年06月12日 11时41分14秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (season), 1245712564@qq.com
 *   Organization:  
 **************************************************/


#include "link_list.h"
/**
 *       Class:  LinkHashTable
 *      Method:  LinkHashTable
 * Description:  
 */
template < class T >
LinkHashTable < T >::LinkHashTable (int _table_size , int(*_HASH)(const T &)) :\
		table_size(_table_size),HASH(_HASH)
{
	array = new LinkList<T>[table_size]();
}  /** ----------  end of constructor of template class LinkHashTable  ---------- */


template < class T >
bool LinkHashTable<T>::hash_insert (const T & ele)
{
	int index = HASH(ele);
	if(index >= table_size || index <0)
		return false;
	return array[index].insert(ele);
}		/** -----  end of method LinkHashTable<T>::hash_insert  ----- */


template < class T >
bool LinkHashTable<T>::hash_delete (const T & ele)
{
	int index = HASH(ele);
	if(index >= table_size || index <0)
		return false;
	return array[index].remove(ele);
}		/** -----  end of method LinkHashTable<T>::hash_delete  ----- */


template < class T >
std::vector<T> LinkHashTable<T>::hash_search (int k) const
{
	if(k < 0 || k >= table_size)
		return std::vector<T>(); 
	std::vector<int> vec;
	array[k].printToVec(vec);
	return vec;
}		/** -----  end of method LinkHashTable<T>::hash_search  ----- */



template < class T >
void LinkHashTable<T>::clear ()
{
	for(int i =0 ; i < table_size ; ++i)
	{
		array[i].clear();
	}
	return ;
}		/** -----  end of method LinkHashTable<T>::clear  ----- */


template < class T >
void LinkHashTable<T>::printToVec (std::vector<std::vector<T> > & vec)
{
	for(int i =0 ; i < table_size ; ++i)
	{
		std::vector<int> tempVec;
		array[i].printToVec(tempVec);
		vec.push_back(tempVec);
	}
	return ;
}		/** -----  end of method LinkHashTable<T>::printToVec  ----- */

