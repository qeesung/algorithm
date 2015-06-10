/**************************************************
 *       Filename:  directAddr.h
 *    Description:  直接寻址
 *
 *        Version:  1.0
 *        Created:  2015年06月10日 10时57分04秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (season), 1245712564@qq.com
 *   Organization:  
 **************************************************/

#ifndef  DIRECTADDR_INC
#define  DIRECTADDR_INC

#include "dataNode.h"
#include <vector>
#include <string>

/**
 *        Class:  DirectAddr
 *  Description:  直接寻址接口
 */
template < class T >
class DirectAddr
{
	public:
		/** ====================  LIFECYCLE     ======================================= */
		DirectAddr (int _key_min=0 , int _key_max=0);                             /** constructor */
		~DirectAddr();

		bool direct_delete(DataNode<T> &);
		bool direct_insert(DataNode<T> &);
		std::vector<T> direct_search(int);
		void printToVec(std::vector<std::vector<T> > &);
		void clear();
	private:
		/** ====================  DATA MEMBERS  ======================================= */
		void deleteAllNode(DataNode<T> * nodePtr);
		DataNode<T>* array;
		const int table_size; // 存储表的大小
		const int key_min; // 存储键值的最小值
		const int key_max;// 存储键值的最大值
}; /** ----------  end of template class DirectAddr  ---------- */
#include "directAddr.cc"

#endif   /* ----- #ifndef DIRECTADDR_INC  ----- */
