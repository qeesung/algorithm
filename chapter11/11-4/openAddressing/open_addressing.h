/**************************************************
 *       Filename:  open_addressing.h
 *    Description:  开放定置法头文件
 *
 *        Version:  1.0
 *        Created:  2015年07月08日 10时21分51秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (season), 1245712564@qq.com
 *   Organization:  
 **************************************************/

#ifndef  OPEN_ADDRESSING_INC
#define  OPEN_ADDRESSING_INC


/** 
 *        Class:  OpenAddressingTable
 *  Description:  开放定址法的散列表
 */

template < class T >
class OpenAddressingTable
{
	public:
		typedef size_t (*Hash_Func_Type)( const T & , size_t , size_t);// [> 定义散列函数的指针 <]
		/* 描述表的一个位置的状态 */
		enum ELE_STATUS{
			EMPTY=0,// 空的
			DELETED=1,// 被删除的
			FULL=2 //有元素的
		};
		// ====================  LIFECYCLE     =======================================
		OpenAddressingTable (size_t array_size ,Hash_Func_Type _hash_func=NULL) ; /** constructor      */
		~OpenAddressingTable ()                                                 ; /** destructor       */
		/** ====================  MUTATORS      ======================================= */
		bool hash_insert(const T & t)                    ; /*  向散列表中插入新的元素 */
		bool hash_search(const T & t , T & target) const ; /*  在散列表中查找键值 */
		bool hash_delete(const T & t)                    ; /* 在散列表中删除键值对应的元素 */
		void hash_clear();

	private:
		/** ====================  DATA MEMBERS  ======================================= */
		T * array_ptr                 ; /*  散列表的数组指针 */
		const size_t array_size       ; /* 散列表数组的大小 */
		ELE_STATUS * status_array_ptr ; /* 用于存放各个位置的状态信息*/
		Hash_Func_Type HASH			  ; /* 采用的散列函数,这个函数用户也可以自己指定 */
	
}; /** -----  end of template class OpenAddressingTable  ----- */

#include "open_addressing.cc"
#endif   /* ----- #ifndef OPEN_ADDRESSING_INC  ----- */
