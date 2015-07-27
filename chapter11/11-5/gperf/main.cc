/**************************************************
 *       Filename:  main.cc
 *    Description:  主文件
 *
 *        Version:  1.0
 *        Created:  2015年07月27日 19时12分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (season), 1245712564@qq.com
 *   Organization:  
 **************************************************/
#include <stdlib.h>
#include <iostream>
#include <string>
#include "./person_data.hpp"
#include "person_data_type.h"

using namespace std;

/** 
 * +++  FUNCTION  +++
 *         Name:  main
 *  Description:  主函数
 */
int main ( int argc, char *argv[] )
{
	while(1)
	{
		string query_name;
		cout<<"Enter name >";
		cin>>query_name;
		if (query_name == ".")
			break;
		cout<<endl;
		person_data_type * result = Perfect_Hash::query_person(query_name.c_str(), query_name.length());
		if (result == NULL)
			cout<<"Can't find "<<query_name<<endl<<endl;
		else
		{
			cout<<"+++++++++++ "<<query_name<<" +++++++++++"<<endl;
			cout<<"age : "<<result->age<<endl;
			string sex_name = "male";
			if(result->sex)
				sex_name = "female";
			cout<<"sex : "<<sex_name<<endl<<endl;;
		}
	}
	return EXIT_SUCCESS;
}				/** ----------  end of function main  ---------- */

