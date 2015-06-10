/**************************************************
 *       Filename:  dataNode.cc
 *    Description:  dataNode源文件
 *
 *        Version:  1.0
 *        Created:  2015年06月10日 11时09分08秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (season), 1245712564@qq.com
 *   Organization:  
 **************************************************/

/**
 *       Class:  DataNode
 *      Method:  DataNode
 * Description:  
 */
template < class T >
DataNode < T >::DataNode (int _key , T _data , DataNode<T> * _next):key(_key),data(_data),next(_next)
{
}  /** ----------  end of constructor of template class DataNode  ---------- */




/**
 *       Class:  DataNode
 *      Method:  get_key
 */
template < class T >
inline  int DataNode<T>::get_key (  ) const
{
	return key;
}		/** -----  end of method DataNode<T>::get_key  ----- */

/**
 *       Class:  DataNode
 *      Method:  set_key
 */
template < class T >
inline  void DataNode<T>::set_key ( int value )
{
	key	= value;
	return ;
}		/** -----  end of method DataNode<T>::set_key  ----- */



/**
 *       Class:  DataNode
 *      Method:  get_data
 */
template < class T >
inline  T DataNode<T>::get_data (  ) const
{
	return data;
}		/** -----  end of method DataNode<T>::get_data  ----- */

/**
 *       Class:  DataNode
 *      Method:  set_data
 */
template < class T >
inline  void DataNode<T>::set_data ( T value )
{
	data	= value;
	return ;
}		/** -----  end of method DataNode<T>::set_data  ----- */


