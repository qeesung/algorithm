/**************************************************
 *       Filename:  open_addressing.cc
 *    Description:  开放定址法的源文件
 *
 *        Version:  1.0
 *        Created:  2015年07月08日 10时59分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (season), 1245712564@qq.com
 *   Organization:  
 **************************************************/
#include <stdlib.h>
#include <iostream>
/*
 * 内置的开放位置的探查方法
 * 不过有个限制，类型T必须要由一个key成员 
 */

template <class T>size_t _hash(const T & , size_t )                      ; /* 辅助散列函数 */
template <class T>size_t _hash1(const T & , size_t )                     ; /* 双重散列的辅助函数 */
template <class T>size_t linear_probing(const T & , size_t, size_t )    ; /* 一次探查*/
template <class T>size_t quadratic_probing(const T & , size_t, size_t ) ; /* 二次探查*/
template <class T>size_t double_hashing(const T & , size_t, size_t )    ; /* 双重散列 */

/**
 *       Class:  OpenAddressingTable
 *      Method:  OpenAddressingTable
 * Description:  创建一个开放定址表
 */
template < class T >
OpenAddressingTable < T >::OpenAddressingTable (size_t _array_size , Hash_Func_Type _hash_func):\
		array_size(_array_size),HASH(_hash_func)
{
	/* 如果用户没有设置散列函数，那么就缺省的设置一个 */
	if(HASH == NULL)
		HASH =	linear_probing;

	/* 申请数组内存 */
	array_ptr = new T[array_size];
	status_array_ptr = new ELE_STATUS[array_size];
	for(int i = 0 ; i < array_size ; ++i)
	{
		status_array_ptr[i] = EMPTY;
	}
}  /** ----------  end of constructor of template class OpenAddressingTable  ---------- */


/**
 *       Class:  OpenAddressingTable
 *      Method:  ~OpenAddressingTable
 * Description:  destructor
 */
template < class T >
OpenAddressingTable< T >::~OpenAddressingTable ()
{
	delete [] array_ptr; 
	delete [] status_array_ptr; 
}  /** ----------  end of destructor of template class OpenAddressingTable  ---------- */



/**
 *  插入一个元素
 */
template < class T >
bool OpenAddressingTable<T>::hash_insert (const T & t)
{
	size_t i = 0;
	while(i!= array_size)
	{
		size_t j = HASH(t , i , array_size);
		if(status_array_ptr[j] != FULL)
		{
			array_ptr[j] = t;	
			status_array_ptr[j] = FULL;
			return true;
		}
		++i;
	}
	std::cerr<<"hash table overflow"<<std::endl;
	return false;
}		/** -----  end of method OpenAddressingTable<T>::hash_insert  ----- */



template < class T >
bool OpenAddressingTable<T>::hash_search (const T & t , T & target) const
{
	size_t i = 0;
	while(i != array_size)
	{
		size_t j = HASH(t , i , array_size)	;
		if(status_array_ptr[j] == EMPTY)
			return false;
		else if (status_array_ptr[j] == FULL)
		{
			if(array_ptr[j].key == t.key )	
			{
				target = array_ptr[j];
				return true;
			}
		}
		++i;
	}
	target = T();
	return false;
}			/** -----  end of method OpenAddressingTable<T>::hash_search  ----- */



template < class T >
bool OpenAddressingTable<T>::hash_delete (const T & t)
{
	size_t i = 0;	
	while(i !=array_size)
	{
		size_t j = HASH(t , i , array_size);
		if(status_array_ptr[j] == EMPTY)
			return false;
		else if (status_array_ptr[j] == FULL)
		{
			if(array_ptr[j].key == t.key )	
			{
				status_array_ptr[j] = DELETED;
				return true;
			}
		}
		++i;
	}
	return false;
}		/** -----  end of method OpenAddresingTable<T>::hash_delete  ----- */



template < class T >
size_t _hash (const T & t , size_t array_size) 
{
	return t.key%array_size;
}		/** -----  end of method OpenAddressingTable<T>::_hash  ----- */



/**
 * 一次探查  
 */
template < class T >
size_t linear_probing (const T & t, size_t offset , size_t array_size) 
{
	return (_hash(t , array_size)+offset)%array_size;
}		/** -----  end of method OpenAddresingTable<T>::linear_probing  ----- */



/**
 *  二次探查
 */
template < class T >
size_t quadratic_probing (const T & t , size_t offset , size_t array_size) 
{
	return (_hash(t , array_size)+offset*offset)%array_size;
}		/** -----  end of method OpenAddressingTable<T>::quadratic_probing  ----- */


/**
 *  双重散列的第二个辅助函数
 */
template < class T >
size_t _hash1 (const T & t  , size_t array_size) 
{
	return (1+t.key%(array_size-1));
}		/** -----  end of method OpenAddressingTable<T>::_hash1  ----- */


/**
 *  双重散列
 */
template < class T >
size_t double_hashing (const T & t , size_t offset , size_t array_size) 
{
	return (_hash(t , array_size)+offset*_hash1(t , array_size))%array_size ;
}		/** -----  end of method OpenAddressingTable<T>::double_hash  ----- */

template < class T >
void OpenAddressingTable<T>::hash_clear ()
{
	for(int i = 0 ; i < array_size ; ++i)
	{
		status_array_ptr[i] = EMPTY;
	}
	return ;
}		/** -----  end of method OpenAddressingTable<T>::hash_clear  ----- */

