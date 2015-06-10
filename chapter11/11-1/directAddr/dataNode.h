/**************************************************
 *       Filename:  dataNode.h
 *    Description:  基本的数据节点
 *
 *        Version:  1.0
 *        Created:  2015年06月10日 11时01分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (season), 1245712564@qq.com
 *   Organization:  
 **************************************************/

#ifndef  DATANODE_INC
#define  DATANODE_INC

#include <cstdio>

/**
 *        Class:  DataNode
 *  Description:  基本的节点
 */
template < class T >
class DataNode
{
	public:
		/** ====================  LIFECYCLE     ======================================= */
		DataNode (int key = 0 , T data=T() ,DataNode<T> * next = NULL);                             /** constructor */
		/** ====================  ACCESSORS     ======================================= */
		void set_key(int);
		int get_key() const;

		void set_data(T);
		T get_data() const;

		DataNode<T> * next;
	private:
		/** ====================  DATA MEMBERS  ======================================= */
		int key;// 对应的键值
		T data;// 对应的数据
}; /** ----------  end of template class DataNode  ---------- */


#include "dataNode.cc"
#endif   /* ----- #ifndef DATANODE_INC  ----- */
