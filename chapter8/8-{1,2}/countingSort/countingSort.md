[TOC]
#计数排序_COUNTINGSORT

我们之前讲过四种基本的排序方法:

[《快速排序_QUICKSORT》:http://blog.csdn.net/ii1245712564/article/details/45749061](http://blog.csdn.net/ii1245712564/article/details/45749061)
[《堆排序_HEAPOSRT》http://blog.csdn.net/ii1245712564/article/details/45534625](http://blog.csdn.net/ii1245712564/article/details/45534625)
[《归并排序_MERGESORT》:http://blog.csdn.net/ii1245712564/article/details/42173549](http://blog.csdn.net/ii1245712564/article/details/42173549)
[《插入排序_INSERTSORT》:http://blog.csdn.net/ii1245712564/article/details/42079225](http://blog.csdn.net/ii1245712564/article/details/42079225)

上面的四种排序方法都有一个共同点，就是他们的排序都是基于`决策树`的。也就是说，他们排序的一句就是通过在元素与元素之间的比较进行的。这种排序的最坏情况下运行时间下界至少为$\Omega (nlogn)$。上面的排序算法中,`堆排序`和`归并排序`的最坏情况y运行时间为$\Omega (nlogn)$,而`快速排序`和`插入排序`的最坏运行时间为$O(n^2)$

>**引理**:任何排序算法都需要做$\Omega (nlogn)$次比较
>
>**证明**:因为决策树是一棵`完全二叉树`，即每一个非叶子节点都有两个孩子节点。我们在这里假设我们输入$n$个元素的数组，决策树的深度为$h$,于是我们可以得到下面的不等式
$$
\begin{align}
n! & \leq 2^h\\
&于是两边同时取对数\\
h & \geq log(n!)\\
& = \Omega(nlogn)
\end{align}
$$
所以任何一种基于决策树的排序算法最坏情况（深度最深）运行时间的下界都为$\Omega(nlogn)$

##计数排序_COUNTINGSORT分析
上面我们讲过，任何基于决策树的排序算法最坏情况下的运行时间为$\Omega(nlogn)$，决策树的核心操作就是比较数组中的两个元素。那有没有一种方法在不比较两个任何两个元素的情况下对数组进行排序呢？

假设现在输入一个规模为$n$的输入$A= \lbrace a_1,a_2,...,a_n \rbrace$,数组中的每一个元素都满足$0 \leq a_i \leq k (1 \leq i \leq n)$, 其中$k = O(n)$。相信你也看到了，上面的数组有一个限制，就是数组里面的每一个元素都在一个同一个区间范围之内.说明数组的里面的元素$a_m$大小是有限的，于是我们创建一个数组$countArray[1...k]$来来保存数组$A$里面每一个元素出现的次数$countArray[a_m]$表示元素$a_m$出现的次数,新建一个数组$outArray[1...n]$来保存排序结果。

下面是C++代码实现：
```cpp
/*************************************************
* @Filename:    countingSort.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-16 13:26:21
* @Version:     1.0
* @Description: 计数排序
**************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/**
 * 计数排序
 * @param inArray  输入的数组
 * @param outArray 输出的数组
 * @param minEle 数组里面的最小元素
 * @param maxEle 数组里面的最大元素
 * @param arraySize 数组元素个数
 */
void countingSort(int inArray[] ,int outArray[], int minEle ,
                  int maxEle , int arraySize )
{
    if(inArray == NULL ||\
       outArray == NULL ||\
       maxEle < minEle ||\
       arraySize < 0)
        return;
    // 新建一个缓存数组来保存比一个inArray[i]元素大的个数
    const int & countArraySize = maxEle - minEle+1;
    int countArray[countArraySize];
    // 初始化count数组
    for (int i = 0; i < countArraySize; ++i)
    {
        countArray[i] = 0;
    }
    // 遍历一遍inArray,统计各个元素的数量
    for (int i = 0; i < arraySize; ++i)
    {
        countArray[inArray[i]-minEle]++;
    }
    // 现在使得计算比inArray[i]小的元素的个数
    for (int i = 1; i < countArraySize; ++i)
    {
        countArray[i] = countArray[i] + countArray[i-1];
    }

    // 再次遍历一遍inArray,将元素放入outArray合适的位置
    for (int i = arraySize-1; i >= 0; --i)
    {
        outArray[countArray[inArray[i]-minEle]-1] = inArray[i];
        countArray[inArray[i]-minEle]--;
    }
}


void printArray(int array[] , int arraySize)
{
    if(array == NULL)
        return;
    for (int i = 0; i < arraySize; ++i)
    {
        cout<<array[i]<<"\t";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    const int & arraySize = 10;
    int inArray[arraySize];
    srand((int)(time(NULL)));
    for (int i = 0; i < arraySize; ++i)
    {
        inArray[i] = rand()%9;
    }
    cout<<"before sort array :"<<endl;
    printArray(inArray , arraySize);

    int outArray[arraySize];
    countingSort(inArray , outArray , 0 ,9 , arraySize);
    cout<<"after sort array:"<<endl;
    printArray(outArray , arraySize);
    while(1);
    return 0;
}
```

>**运行结果:**
>
>before sort array :
4   7   4   5   2   4   6   0   0   2   
after sort array :
0   0   2   2   4   4   4   5   6   7   

---

##代码分析
>**代码分析:**
>`countingSort`函数里面有四个for循环
>
><font color=red>**for循环1**</font>
>```cpp
>    // 初始化count数组
>   for (int i = 0; i < countArraySize; ++i)
    {
        countArray[i] = 0;
    }
>```
>这里的运行时间为$O(countArraySize)$，也就是输入区间的宽度
>
><font color=green>**for循环2**</font>
>```cpp
>    // 遍历一遍inArray,统计各个元素的数量
    for (int i = 0; i < arraySize; ++i)
    {
        countArray[inArray[i]-minEle]++;
    }
>```
>这里遍历一边输入数组，统计输入数组里面的每一个元素的个数，运行时间为$O(n)$
>
><font color=darkblue>**for循环3**</font>
>```cpp
>    // 现在使得计算比inArray[i]小的元素的个数
    for (int i = 1; i < countArraySize; ++i)
    {
        countArray[i] = countArray[i] + countArray[i-1];
    }
>```
>这个循环做了一个非常精妙的事情，上一个循环里面我们统计出每一个元素的个数，这个循环我们统计数组里面比某个元素小的元素的个数，所以运行时间为$O(countArraySize)$
>
><font color=brown>**for循环4**</font>
>```cpp
>    // 再次遍历一遍inArray,将元素放入outArray合适的位置
    for (int i = arraySize-1; i >= 0; --i)
    {
        outArray[countArray[inArray[i]-minEle]-1] = inArray[i];
        countArray[inArray[i]-minEle]--;
    }
>```
>这个循环里面有一个需要注意的地方，那就是循环变量`i`是从`0`到`arrySize`,还是从`arraySize`到`0`,如果我们从`arraySize`到`0`，那么排序算法是稳定的，如果从`0`到`arrySize`，那么排序算法是不稳定的。这里一定要注意。在这个循环里面做了两件事:
>- 将`inArray[i]`元素放入到`outArray`合适的位置，我们知道比`inArray[i]`小的元素个数为`countArray[inArray[i]-minEle]`,说明我们的元素应该放在`outArray`的`countArray[inArray[i]-minEle]-1`（数组应该从0开始，所以需要减去1）上.因为`countArray[inArray[i]-minEle]-1`位置之间的那些位置需要放比`inArray[i]`小的那些元素啊
>- 将`countArray[inArray[i]-minEle]--`,这样是为了避免存在相同的元素，因为我们再统计比自己小的元素的个数的时候是这样做的`countArray[i] = countArray[i] + countArray[i-1]`，我们加上自己的`countArray[i]`的大小，说明在区间`[ countArray[i-1] , countArray[i] ]`之间存放的是所有相同的元素`inArray[i]`
>
>这个循环的运行时间为$O(n)$
>
>通过上面的分析，我们知道计数排序的运行时间为：
>$$
O(countArraySize)+O(n)+O(countArraySize)+O(n)=O(countArraySize+n)
$$
因为我们之前设定为$k=O(n)$,这个设定是必须的，如果我们两个元素，$a_1=0$,$a_2=10000$,如果再按照上面的做法来做，那就得不偿失了。
所以计数排序的运行时间为$O(n)$
