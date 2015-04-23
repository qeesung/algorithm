/*************************************************
* @Filename:    activitySelector_v3.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-04-23 13:13:54
* @Version:     1.0
* @Description: 最大兼容自己的自下而上的动态规划算法
**************************************************/

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/** 最大活动的数目 */
#define MAX_ACTIVITY_NUM 20

void dealGreatActivitySelector(std::vector<pair<int , int> > & activities , int left , int right);
size_t great[MAX_ACTIVITY_NUM+1][MAX_ACTIVITY_NUM+1];//用来存储i到j的最大子集数目
/**
 * 最大的兼容子集			
 * @param  activities 活动的链表，已经按照结束时间的先后顺序拍好了
 * @return            返回最大兼容的数量
 */
size_t greateActivitySelector(std::vector<pair<int , int> > & activities)
{
	if(activities.size() == 0)
		return 0;
	dealGreatActivitySelector(activities , 1 , activities.size()-1);
	return great[1][activities.size()-1];
}

/**
 * 实际处理最大兼容子集的函数
 * @param  activities 活动
 * @param  left       左边界
 * @param  right      右边界
 * @return            left到right的最大兼容子集数
 */
void dealGreatActivitySelector(std::vector<pair<int , int> > & activities , int left , int right)
{
	// 只有一个活动，初始化
	for (int i = left; i < right; ++i)
	{
		great[i][i-1] = 0;
	}
	for(int k = 0 ; k <= right-left ; ++k)
	{
		for (int i = left; i <=right ; ++i)
		{
			int max = 0;
			for(int j = i ; j <= i+k ; ++j)
			{
				// 首先需要计算左右边界
				int leftTemp = j;
				int rightTemp = j;
				/** 找到左边界 */
				while(leftTemp >= i && activities[leftTemp].second > activities[j].first )
					leftTemp--;
				/** 找到右边界 */
				while(rightTemp <= i+k && activities[rightTemp].first < activities[j].second)
					rightTemp++;
				int temp = great[i][leftTemp]+great[rightTemp][i+k]+1;
				if(max < temp)
					max = temp;
			}
			great[i][i+k] = max;
		}
	}
	for (int i = 0; i <= activities.size(); ++i)
	{
		for(int k = 0 ; k <= activities.size(); ++k)
		{
			cout<<great[i][k]<<"\t";
		}
		cout<<endl;;
	}
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
	return 0;
}