/*************************************************
* @Filename:    activitySelector_v6.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-04-23 14:35:43
* @Version:     1.0
* @Description: 迭代的贪心算法解决最大兼容子集
**************************************************/

#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define BufSize 20
// 用来存储解决方案
char buf[BufSize];
std::vector<string> solution;

size_t dealGreatActivitySelector(std::vector<pair<int , int> > & activities , int left , int right);
size_t greateActivitySelector(std::vector<pair<int , int> > & activities)
{
	if(activities.size() == 0)
		return 0;
	return dealGreatActivitySelector(activities , 1 , activities.size()-1);
}


size_t dealGreatActivitySelector(std::vector<pair<int , int> > & activities , int left , int right)
{
	if(left > right)
		return 0;
	int count = 1;
	snprintf(buf , BufSize  , "a%d" , left);
	solution.push_back(string(buf , buf+BufSize));
	memset(buf , BufSize , 0);

	int lastPos=left;
	for (int i = left+1; i <= right; ++i)
	{
		// 不断的寻找边界
		while(i<= right && activities[i].first < activities[lastPos].second)
			++i;
		if(i > right)
			break;
		//找到就加入到solution里面
		snprintf(buf , BufSize  , "a%d" , i);
		solution.push_back(string(buf , buf+BufSize));
		memset(buf , BufSize , 0);	
		lastPos = i; 
		count++;
	}
	return count;
}

void printSolution()
{
	for (std::vector<string>::iterator i = solution.begin(); i != solution.end(); ++i)
	{
		cout<<*i<<"\t";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	std::vector<pair<int , int> > activities;
	activities.push_back(pair<int , int>(0,0));
	activities.push_back(pair<int , int>(1,4));
	activities.push_back(pair<int , int>(3,5));
	activities.push_back(pair<int , int>(0,6));
	activities.push_back(pair<int , int>(5,7));
	activities.push_back(pair<int , int>(3,9));
	activities.push_back(pair<int , int>(5,9));
	activities.push_back(pair<int , int>(6,10));
	activities.push_back(pair<int , int>(8,11));
	activities.push_back(pair<int , int>(8,12));
	activities.push_back(pair<int , int>(2,14));
	activities.push_back(pair<int , int>(12,16));
	cout<<"The max selectors is : "<<greateActivitySelector(activities)<<endl;
	printSolution();
	return 0;
}