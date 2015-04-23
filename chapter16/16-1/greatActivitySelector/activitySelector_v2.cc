/*************************************************
* @Filename:    activitySelector_v2.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-04-23 12:58:05
* @Version:     1.0
* @Description: 带有解决方案的最大兼容子集-动态规划自上而下的算法
**************************************************/
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/** 最大活动的数目 */
#define MAX_ACTIVITY_NUM 20

size_t dealGreatActivitySelector(std::vector<pair<int , int> > & activities , int left , int right);
size_t great[MAX_ACTIVITY_NUM][MAX_ACTIVITY_NUM];//用来存储i到j的最大子集数目
size_t solution[MAX_ACTIVITY_NUM][MAX_ACTIVITY_NUM];//用来存储选择
pair<int , int> border[MAX_ACTIVITY_NUM][MAX_ACTIVITY_NUM];//用来存储边界值
/**
 * 最大的兼容子集			
 * @param  activities 活动的链表，已经按照结束时间的先后顺序拍好了
 * @return            返回最大兼容的数量
 */
size_t greateActivitySelector(std::vector<pair<int , int> > & activities)
{
	if(activities.size() == 0)
		return 0;
	dealGreatActivitySelector(activities , 0 , activities.size()-1);
	return great[0][activities.size()-1];
}

/**
 * 实际处理最大兼容子集的函数
 * @param  activities 活动
 * @param  left       左边界
 * @param  right      右边界
 * @return            left到right的最大兼容子集数
 */
size_t dealGreatActivitySelector(std::vector<pair<int , int> > & activities , int left , int right)
{
	if(left > right)
		return 0;
	// 只有一个活动
	if(left == right)
	{
		great[left][right] = 1;
		solution[left][right] = left;
		return 1;
	}
	if(great[left][right] != 0)
		return great[left][right];// 之前已经算过
	//求解过程
	int max = 0;
	int pos = left;
	pair<int , int> borderTemp;
	for (int i = left; i <= right ; ++i)
	{
		////////////////////////////
		//以i为基准，向两边找到不与i活动相交的集合 //
		////////////////////////////
		int leftTemp = i;
		int rightTemp = i;
		/** 找到左边界 */
		while(leftTemp >= left && activities[leftTemp].second > activities[i].first )
			leftTemp--;
		/** 找到右边界 */
		while(rightTemp <= right && activities[rightTemp].first < activities[i].second)
			rightTemp++;
		int temp = dealGreatActivitySelector(activities , left , leftTemp)+\
				   dealGreatActivitySelector(activities , rightTemp , right)+1;
		if(temp > max)
		{
			max = temp;
			pos = i ;
			borderTemp = pair<int , int>(leftTemp , rightTemp);
		}
	}
	solution[left][right] = pos;
	border[left][right] = borderTemp;
	great[left][right] = max;
	return max;
}


void printSolution(int left , int right)
{
	if(left > right)
		return;
	if(left == right)
	{
		cout<<"from "<<left<<" to "<<right<<" -----> "<<solution[left][right]<<endl;
		return;
	}
	cout<<"from "<<left<<" to "<<right<<" -----> "<<solution[left][right]<<endl;
	printSolution(left , border[left][right].first);
	printSolution(border[left][right].second , right);
	return;
}

int main(int argc, char const *argv[])
{
	std::vector<pair<int , int> > activities;
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
	printSolution(0 , activities.size()-1);
	return 0;
}