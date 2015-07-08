/**************************************************
 *       Filename:  data_type.h
 *    Description:  散列表操作的基本类型
 *
 *        Version:  1.0
 *        Created:  2015年07月08日 14时03分34秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (season), 1245712564@qq.com
 *   Organization:  
 **************************************************/

#ifndef  DATA_TYPE_INC
#define  DATA_TYPE_INC

#include <string>
class DataType 
{
public:
	DataType(size_t _key=0 , const std::string & _data=""):\
		key(_key),data(_data){}
	size_t key; /* 键值 */
	std::string data; /* 数据 */
};

#endif   /* ----- #ifndef DATA_TYPE_INC  ----- */
