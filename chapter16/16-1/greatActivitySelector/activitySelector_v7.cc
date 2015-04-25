/*************************************************
* @Filename:    activitySelector_v7.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-04-23 14:21:27
* @Version:     1.0
* @Description: 这里采用贪心算法的递归方式来解决最大兼容自问题
**************************************************/
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

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
	//首先找到消耗最小的那个
	int minPos = left;
	int min = 100;
	for(int i = left ; i < right ; ++i)
	{
		if((activities[i].second-activities[i].first) < min)
		{
			min = activities[i].second-activities[i].first;
			minPos = i;
		}
	}
	snprintf(buf , BufSize  , "a%d" , left);
	solution.push_back(string(buf , buf+BufSize));
	memset(buf , BufSize , 0);
	int leftTemp = minPos;
	int rightTemp = minPos;
	/** 找到左边界 */
	while(leftTemp >= left && activities[leftTemp].second > activities[minPos].first )
		leftTemp--;
	/** 找到右边界 */
	while(rightTemp <= right && activities[rightTemp].first < activities[minPos].second)
		rightTemp++;

	return dealGreatActivitySelector(activities , left , leftTemp)+\
		   dealGreatActivitySelector(activities , rightTemp, right)+1; 
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

