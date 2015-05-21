[TOC]
#桶排序_BUCKETSORT

假设你有五百万份试卷，每份试卷的满分都是100分，如果要你对这些试卷按照分数进行排序，天噜啦，五百万份试卷啊，快速排序？堆排序？归并排序？面对这么多的数据，平均下来上面的每一种一种算法至少都要花费$nlogn=5000000log5000000=111267433$单位时间啊，将近一亿多，太慢了。

要是我们这样来做呢，首先买101只桶回来，分别为每一只桶编上0-100标号,我们就只管遍历一边所有的试卷，将分数为n的试卷丢入到编号为n的桶里面，当所有的试卷都放入到相应的桶里面时，我们就已经将所有的试卷按照分数进行排序了。遍历一遍所有数据的时间也就是五百万次，相比与一亿多次，那可是省了不少时间。这里所用到的就是桶排序的思想。

#桶排序的思想
桶排序，顾名思义就是运用桶的思想来将数据放到相应的桶内，再将每一个桶内的数据进行排序，最后把所有桶内数据按照顺序取出来，得到的就是我们需要的有序数据

比如我们有下面的一些数据
>`49 	43	11	61	31	71	53	51	71	84	`

下面我们按照这些数的十位将他们放入桶内
>**将数据放入桶内**
>
>bucket#.0 +++ 
bucket#.1 +++   `11`	
bucket#.2 +++ 
bucket#.3 +++   `31`	
bucket#.4 +++   `49`	  `43`	 
bucket#.5 +++   `53`	 `51`	  
bucket#.6 +++   `61`	
bucket#.7 +++   `71`	 ` 71`	
bucket#.8 +++   `84`	
bucket#.9 +++
 
注意一点，上面的各个桶内的数据是无序的，现在运用一个快速的排序算法对每一个桶内的数据进行排序，可以是快速排序，插入排序，归并排序里面的任何一种

>**对桶内数据进行排序**
>
>bucket#.0 +++ 
bucket#.1 +++   `11`	
bucket#.2 +++ 
bucket#.3 +++   `31`	
<font color=red>**bucket#.4 +++**   `43`	 `49`	</font>
<font color=red>**bucket#.5 +++**   `51`	 `53`	</font>   
bucket#.6 +++   `61`	
bucket#.7 +++   `71`	 ` 71`	
bucket#.8 +++   `84`	
bucket#.9 +++

注意观察上面的红色标示的桶里面的数据顺序已经发生改变，在将各个桶里面的元素进行排序以后，我们需要按照顺序遍历每一个桶，将桶里面的数据按照顺序取出来，得到已经排序的有序序列

>**组合各个桶内的元素**
>`11	31	43	49	51	53	61	71	71	84	`

总之，桶排序的的步骤为：
- <font color=green>**申请**</font>一定数量的桶
- 按照一个设定好的<font color=green>**映射函数**</font>，将序列里面的元素映射到对应的桶里（上面例子的映射函数为BUCKET(i)=i/10）
- <font color=green>**遍历**</font>一遍所有的桶，将各个桶内的元素进行<font color=green>**排序**</font>，排序算法可以采用冒泡排序，插入排序，快速排序，归并排序等等适合的算法
- 将所有桶内的元素按照顺序<font color=green>**组合**</font>起来就是我们需要的有序序列

唯一的难点就是映射函数的设计，映射函数需要保证映射到各个桶里面的元素数量相同，即序列里有$N$个元素，桶数量为$M$，那么每一个桶里面在进行映射函数映射后都应该有$N/M$个元素.我们分析算法的效率，遍历一遍所有元素话费时间$O(n)$,再将所有桶内元素进行排序，每一个桶内的平均排序时间为$(N/M)log(N/M)$,于是我们得到总排序时间为$O(N)+M*(N/M)log(N/M)=O(N)+N(logN-logM)$,如果桶的数量和序列元素的数量相等的话，那么算法将达到最优的效率$O(N)$,但是这个时候也是空间占用最大的时候

如果桶内元素分布不平衡的，将会导致桶排序的算法效率大大降低，我们考虑最坏的情况，映射函数将所有的元素映射到同一个桶里面，再对桶里面元素进行插入排序，运行时间将升$O(N^2)$,所以设计一个性能优良的映射函数尤为重要


#桶排序的代码编写
此处桶内的排序算法采用的是快速排序

```cpp
/*************************************************
* @Filename:    bucketSort.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-17 14:57:36
* @Version:     1.0
* @Description: 桶排序
**************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;
// 桶排序映射函数
#define BUCKET(i) ((i)/10)

/**
 * 交换容器里面的两个元素
 * @param array 输入的输入
 * @param pos1  位置1
 * @param pos2  位置2
 */
void exchange(std::vector<int> & array , int pos1 , int pos2)
{
    int temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}

/**
 * 打印一个容器
 * @param vec 目标容器
 */
void printVector(std::vector<int> & vec)
{
    for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); ++i)
    {
        cout<<*i<<"\t";
    }
    cout<<endl;
}

/**
 * 对输入的容器进行快速排序
 * 其实可以不用这样，直接用algorithm里面的stablesort(vec.begin, vec.end , comp)
 * 就可以对容器进行排序啦，这里懒得实现链表，所以用vector来实现    
 * @param vec 输入的容器
 * @param left 容器左边界
 * @param right 容器的右边界
 */
void quickSort(std::vector<int> & vec , int left , int right )
{
    if(left >= right)
        return;
    int i = left-1;
    int x = vec[right];
    for(int k = left; k <= right -1 ; ++k)
    {
        if(vec[k] <= x) // 交换两个元素
        {
            exchange(vec , ++i , k );
        }
    }
    exchange(vec , ++i , right);
    quickSort(vec , left , i-1);
    quickSort(vec , i+1 , right);
}

/**
 * 桶排序,这里输入的元素是0-100里面的元素，创建十个桶
 * @param inVec 输入的容器
 */
void bucketSort(std::vector<int> & inVec)
{
    const int & bucketNum = 10;
    // 创建十个桶
    std::vector<std::vector<int> > buckets(bucketNum);
    //遍历一边输入容器
    for (int i = 0; i < inVec.size(); ++i)
    {
        buckets[BUCKET(inVec[i])].push_back(inVec[i]);
    }
    // 开始对每一个桶进行快速排序
    for (int i = 0; i < bucketNum; ++i)
    {
        quickSort(buckets[i] , 0 , buckets[i].size()-1);
    }   

    // 开始从桶里面取出数据
    inVec.clear();
    for (int i = 0; i < bucketNum; ++i)
    {
        std::vector<int> & tempVec = buckets[i];
        cout<<"bucket#."<<i<<" +++ ";
        for (int k = 0; k < tempVec.size(); ++k)
        {
            cout.width(4);
            cout<<tempVec[k]<<"\t";
            inVec.push_back(tempVec[k]);
        }
        cout<<endl;
    }
}



int main(int argc, char const *argv[])
{
    const int & arraySize = 10;
    int inArray[arraySize];
    srand((int)(time(NULL)));
    for (int i = 0; i < arraySize; ++i)
    {
        inArray[i] = rand()%100;
    }

    std::vector<int> vec(inArray , inArray+arraySize);
    cout<<"before sort array :"<<endl;
    printVector(vec);

    bucketSort(vec);
    cout<<"after sort array"<<endl;
    printVector(vec);
    return 0;
}
```
>**运行结果**:
>before sort array :
48	85	2	71	25	48	53	42	50	25	
>
bucket#.0 +++    2	
bucket#.1 +++ 
bucket#.2 +++   25	  25	
bucket#.3 +++ 
bucket#.4 +++   42	  48	  48	
bucket#.5 +++   50	  53	
bucket#.6 +++ 
bucket#.7 +++   71	
bucket#.8 +++   85	
bucket#.9 +++ 
>
after sort array:
2	25	25	42	48	48	50	53	71	85	


#总结
桶排序适用于可以根据数据的特性将数据进行分堆处理的情况，比如数组只在0-100之间，那么我们可以按照十位相同，对数据进行分堆装桶。但是分堆装桶必须保证后一个桶的所有元素都大于(升序)/小于(降序)前一个桶内的所有元素，否则映射函数无效！

桶排序`里面的映射好比`哈希散列表`的映射，我们如果如果要使桶排序快速高效，那么就要设计一个适合的映射函数。并且桶排序涉及到对时间和时空两方面的权衡，随着桶数量的增加，桶排序算法的性能也会增加（最好情况桶的数量与序列元素数量相等$N=M$），同时空间的占用也会增加，所以在设计桶排序算法的时候，应该根据实际情况，做出相应的设计。