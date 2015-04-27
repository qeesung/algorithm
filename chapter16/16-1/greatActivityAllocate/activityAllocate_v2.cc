/*************************************************
* @Filename:    activityAllocate_v2.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-04-27 14:36:36
* @Version:     1.0
* @Description: 活动分配问题，采用贪心算法来求解，每次选出最大兼容自己作为贪心策略
**************************************************/

/**
* 这里我们首先采用贪心策略求出一个集合里面的最大兼容子集
* 然后将这个最大兼容子集共用一个教室
* 然后再求出剩下的活动的最大兼容子集，放入下一个教室
* 这样一直循环，直到没有活动为止
* 这里一共用到两次贪心策略
*/

#include <iostream>
#include <utility>
#include <vector>
#include <set>

using namespace std;
/**
 * 选出最大活动兼容子集
 * @param  activities 活动列表
 * @param  selected   选出来的活动
 * @param  solution   这次有哪些活动被选出来
 * @return            活动数量
 */
unsigned int greateActivitySelector(\
    std::vector<pair<unsigned int , unsigned int> > & activities,\
    std::set<unsigned int> & selected,\
    std::vector<unsigned int> & solution)
{
    solution.clear();
    /** 这里主要采用迭代的方式进行 */

    /** 确认还有活动 */
    if(activities.size() - selected.size() == 0)
        return 0;
    unsigned int count = 0;
    unsigned int finishTime = 0;
    unsigned int i = 0;

    while(i < activities.size() && selected.count(i) != 0)// 选出没有被选中过的
        ++i;
    if(i >= activities.size())
        return 0;
    solution.push_back(i);
    selected.insert(i);
    finishTime = activities[i].second;
    ++count;

    for (; i < activities.size(); ++i)
    {
        // 找出没有选中的，而且是兼容的
        while(i < activities.size())
        {
            if(selected.count(i) == 0)
            {
                if(activities[i].first > finishTime)
                    break;
            }
            ++i;
        }
        if(i >= activities.size())
            break;
        // 表明已经找到，现在更新数据
        solution.push_back(i);
        selected.insert(i);
        finishTime = activities[i].second;
        ++count;
    }
    return count;
}
/**
 * 计算分配教室的最优解
 * @param  activities 活动列表
 * @return            最少教室数
 */
unsigned int greatActivityAllocate(std::vector<pair<unsigned int , unsigned int> > & activities)
{
    std::vector<unsigned int> solution;// 从来存储解决方案
    std::set<unsigned int> selected;//用来存储活动时候被选择
    unsigned int count = 0;
    while(selected.size() < activities.size())
    {
        greateActivitySelector(activities , selected , solution);
        cout<<"classroom"<<count<<":";
        for (int i = 0; i < solution.size(); ++i)
        {
            cout<<"a"<<solution[i]<<"\t";
        }
        cout<<endl;
        ++count;
    }
    return count;
}


int main(int argc, char const *argv[])
{
    std::vector<pair<unsigned int , unsigned int> > activities;
    activities.push_back(pair<unsigned , unsigned>(1,8));
    activities.push_back(pair<unsigned , unsigned>(1,10));
    activities.push_back(pair<unsigned , unsigned>(12,16));
    activities.push_back(pair<unsigned , unsigned>(9,17));

    unsigned int classroomNum = greatActivityAllocate(activities);
    cout<<"activities use at least "<<classroomNum<<" classroom(s)"<<endl;
  
    while(1);
    return 0;
}
