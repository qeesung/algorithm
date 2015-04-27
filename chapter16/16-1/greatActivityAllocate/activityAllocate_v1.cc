/*************************************************
* @Filename:    activityAllocate_v1.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-04-27 14:02:51
* @Version:     1.0
* @Description: 活动分配问题，采用贪心算法来求解
**************************************************/

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

/**
 * 定义时间的类型
 */
enum TIME_T{
    START_T,//开始时间类型
    END_T//结束事件类型
};

/** 时间的排序谓词 */
bool timeCompare(pair<unsigned int , TIME_T> a ,\
    pair<unsigned int , TIME_T> b)
{
    return a.first < b.first;
}

/**
 * 得到活动的最少占用教室数量
 * @param  activities 活动链表
 * @return            最小数量
 */
unsigned int greatActivityAllocate(std::vector<pair<unsigned int , unsigned int> > & activities) throw(logic_error)
{
    // 首先需要将活动里面的时间提取出来
    std::vector<pair<unsigned int , TIME_T> > timeVec;
    for (std::vector<pair<unsigned int , unsigned int> >::iterator iter = activities.begin();\
                 iter != activities.end(); ++iter)
    {
        if(iter->first > iter->second)
            throw logic_error("end time should greater than start time");
        timeVec.push_back(pair<unsigned int , TIME_T>(iter->first , START_T));
        timeVec.push_back(pair<unsigned int , TIME_T>(iter->second , END_T));
    }
    // 按照first , 排序timeVec
    stable_sort(timeVec.begin() , timeVec.end() , timeCompare);
    // 遍历timeVec数组
    unsigned int freeNum = 0;
    unsigned int busyNum = 0;
    for (std::vector<pair<unsigned int , TIME_T> >::iterator iter = timeVec.begin();\
                 iter != timeVec.end(); ++iter)
    {
        // 是开始时间，那么说明需要分配一间教室
        // 那么现在需要从freeNum里面开始分配
        if(iter->second == START_T)
        {
            // 空间教室数量为0，那么需要从资源里面新加一间教室
                busyNum++;
            if(freeNum != 0)
                freeNum--;
        }
        else// 这里是结束时间
        {
            // 那么需要从忙的教室里面归还一间教室
            busyNum--;
            freeNum++;
        }
    }
    // 到最后所有教室都会被归还，那么freeNum里面就是被使用过的教书总量
    return freeNum;
}

int main(int argc, char const *argv[])
{
    std::vector<pair<unsigned int , unsigned int> > activities;
    activities.push_back(pair<unsigned , unsigned>(1,10));
    activities.push_back(pair<unsigned , unsigned>(12,16));
    activities.push_back(pair<unsigned , unsigned>(9,17));
    activities.push_back(pair<unsigned , unsigned>(1,8));
    try{
        unsigned int classroomNum = greatActivityAllocate(activities);
        cout<<"activities use at least "<<classroomNum<<" classroom(s)"<<endl;
    }catch(logic_error e)
    {
        cerr<<e.what()<<endl;
    }
    while(1);
    return 0;
}
