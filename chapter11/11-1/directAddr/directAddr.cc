/**************************************************
 *       Filename:  directAddr.cc
 *    Description:  直接寻址的源文件
 *
 *        Version:  1.0
 *        Created:  2015年06月10日 11时29分52秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (season), 1245712564@qq.com
 *   Organization:  
 **************************************************/

#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <typeinfo>

/**
 *       Class:  DirectAddr
 *      Method:  DirectAddr
 * Description:  构造函数 
 */
template < class T >
DirectAddr < T >::DirectAddr (int _key_min , int _key_max):key_min(_key_min),\
															   key_max(_key_max),table_size(_key_max - _key_min+1)
{
	array = new DataNode<T>[table_size]();
	for ( int i = 0 ; i< table_size ; ++i )
	{
		array[i].next = NULL;	
	}

}  /** ----------  end of constructor of template class DirectAddr  ---------- */


/**
 *       Class:  DirectAddr
 *      Method:  ~DirectAddr
 * Description:  destructor
 */
	template < class T >
DirectAddr< T >::~DirectAddr ()
{
	clear();
	delete [] array;
}  /** ----------  end of destructor of template class DirectAddr  ---------- */


/**
 *  插入一个新的元素
 */
	template < class T >
bool DirectAddr<T>::direct_insert (DataNode<T> & node)
{
	if(node.get_key() <key_min || node.get_key()>key_max)
		return false;	
	DataNode<T> * tempNode = array[node.get_key() - key_min].next;
	DataNode<T> * newNode = new DataNode<T>(node.get_key() , node.get_data(), tempNode);
	if(newNode == NULL)
		return false;
	array[node.get_key() - key_min].next = newNode;
	return true;
}		/** -----  end of method DirectAddr<T>::direct_insert  ----- */




template < class T >
bool DirectAddr<T>::direct_delete (DataNode<T> & node)
{
	if(node.get_key()<key_min || node.get_key()>key_max)
		return false;
	DataNode<T> * targetNode = &array[node.get_key() - key_min];
	/*  找到需要删除的点 */
	while(targetNode->next != NULL && targetNode->next->get_data()!=node.get_data())
	{
		targetNode = targetNode->next;
	}
	if(targetNode->next == NULL)
		return false;
	// 找到节点，开始删除
	DataNode<T> * tempNode = targetNode->next->next;
	delete targetNode->next; 
	targetNode->next = tempNode;
	return true;
}		/** -----  end of method DirectAddr<T>::direct_delete  ----- */


template < class T >
std::vector<T> DirectAddr<T>::direct_search (int key)
{
	if(key<key_min || key>key_max)
		return std::vector<T>();
	std::vector<T> retVec;
	DataNode<T> * tempNode = array[key - key_min].next;
	while(tempNode != NULL)
	{
		retVec.push_back(tempNode->get_data());
		tempNode = tempNode->next;
	}
	return retVec;
}		/** -----  end of method DirectAddr<T>::direct_search  ----- */


	template < class T >
void DirectAddr<T>::clear ()
{
	for(int i = 0 ; i < table_size ; ++i)
	{
		deleteAllNode(array[i - key_min].next);
	}
	return ;
}		/** -----  end of method DirectAddr<T>::clear  ----- */



template < class T >
void DirectAddr<T>::deleteAllNode (DataNode<T> * nodePtr)
{
	if(nodePtr ==  NULL)
		return;
	while(nodePtr != NULL)
	{
		DataNode<T> * tempNode = nodePtr->next;	
		delete nodePtr;
		nodePtr = tempNode;
	}
	return ;
}		/** -----  end of method DirectAddr<T>::deleteAllNode  ----- */



template < class T >
void DirectAddr<T>::printToVec (std::vector<std::vector<T> > & vec)
{
	for ( int i = 0 ; i < table_size;++i )
	{
		std::vector<T> tempVec;
		DataNode<T> * tempNode = array[i - key_min].next;
		while(tempNode!=NULL)
		{
			tempVec.push_back(tempNode->get_data());
			tempNode=tempNode->next;
		}
		vec.push_back(tempVec);
	}
}		/** -----  end of method DirectAddr<T>::printToStr  ----- */

