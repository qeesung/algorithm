/**************************************************
 *       Filename:  person_data_type.h
 *    Description:  人结构信息头文件
 *
 *        Version:  1.0
 *        Created:  2015年07月27日 19时10分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (season), 1245712564@qq.com
 *   Organization:  
 **************************************************/

#ifndef  PERSON_DATA_TYPE_INC
#define  PERSON_DATA_TYPE_INC

enum SEX
{
	MALE=0,
	FEMALE=1
};

struct person_data_type
{
	const char * name;
	unsigned int age;
	SEX sex;
};

#endif   /* ----- #ifndef PERSON_DATA_TYPE_INC  ----- */
