#快速排序
快速排序是一个最坏情况时间复杂度为$\Theta(n^2)$，最好情况下时间复杂度为$O(nlogn)$的排序算法。虽然在最坏情况下的时间复杂为$n^2$，但是快速排序的平均性能非常好，只有$\Theta(nlogn)$，而且我们也可以主动避免快速排序的最差的情况，所以快速排序在排序作业中还是应用比较广泛的。

##快速排序的基本思想

我们现在有一数组$A=\lbrace a_i,a_{i+1},...,a_j \rbrace$，假定我们将数组$A$排序得到数组$B= \lbrace b_i, b_{i+1},...,b_j \rbrace$ ,数组$A$和数组$B$里面的元素全都想用，只是元素的顺序不同。现在我们希望找到数组$A$里面的一个任一元素$a_m$在数组$B$中的位置$k(i \leq k \leq j)$。在排序之前，如果我们一开始就知道位置$k$应该放置元素$a_m$，那么排序岂不是很简单，我们只需要将各个元素放到对应的位置上不久可以了吗？

那下面我们就来找一个数组$A$里面任意元素$a_m$的应该放置的<font color=red>**目标位置$k$**</font>,这个位置$k$应该满足这样的特性$a_{i...k-1} \leq a_k \leq a_{k+1...j}$,就是位置$k$的左边的元素应该不大于$a_k$,位置$k$右边的元素应该不小于元素$a_k$
即：
$$
\underbrace{a_i,a_{i+1},...,a_{k-1}}_{\leq a_k},a_k,
\underbrace{a_{k+1},...,a_{j-1},a_j}_{\geq a_k}
$$
所以我们只需要将大于$ak$的元素移到数组的右边，小于等于$a_k$的元素移到数组的左边就可以啦。

让然后我们对剩下的两个子数组$\dot A=\lbrace a_i,..,a_{k-1} \rbrace$和$\ddot A=\lbrace a_{k+1},...,a_j \rbrace $进行同样的递归操作,直到我们找到所有的元素的目标位置$k$，并将元素放入

总的来说，可以分为下面几个步骤：

- 找到元素$a_j$(这里选择的$a_m$为最优一个元素)的目标位置$k$
- 将位置$j$和位置$k$的元素交换，因为位置$k$就是$a_j$的目标位置，只是现在被元素$a_k$占用着。
- 得到两个子问题$\dot A=\lbrace a_i,..,a_{k-1} \rbrace$和$\ddot A=\lbrace a_{k+1},...,a_j \rbrace $
- 对这两个子问题采用相同的方法，直到每一个元素都放在了目标位置上


##快速排序的代码实现

我们首先采用两种代码实现
```cpp
/*************************************************
* @Filename:    quickSort.cc
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-14 14:48:35
* @Version:     1.0
* @Description: 快速排序的算法实现
**************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void exchange(int array[] , int pos1 , int pos2)
{
    if(array == NULL)
        return;
    int temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}


/**
 * 快速排序的递归算法
 * @param array       将要排序的数组
 * @param leftBorder  排序的左边界
 * @param rightBorder 排序的右边界
 */
void quickSortKernel(int array[] , int leftBorder , int rightBorder)
{
    if(array == NULL || leftBorder >= rightBorder )
        return;
    /** 现在对数据进行原址排序 */
    int i = leftBorder-1;
    int j = leftBorder;
    int x = array[rightBorder];
    for(; j < rightBorder ; ++j)
    {
        if(array[j] <= x)
        {
            exchange(array,++i, j);
        }
    }
    exchange(array ,++i , rightBorder);
    /** 递归的排序数组剩下的部分，将合适的数据放在适合的位置上 */
    quickSortKernel(array , leftBorder , i-1);
    quickSortKernel(array , i+1, rightBorder);
}

/**
 * 快速排序接口
 * @param array 输入的数组
 */
void quickSort(int array[] , int arraySize)
{
    if(array == NULL)
        return ;
    quickSortKernel(array , 0 , arraySize-1);
}

/**
 * 打印数组
 * @param array     数组指针
 * @param arraySize 数组大小
 */
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
    int array[10];
    int arraySize = sizeof(array)/sizeof(int);

    srand((int)(time(NULL)));
    for (int i = 0; i < arraySize; ++i)
    {
        array[i] = rand()%100;
    }

    cout<<"before sort the array："<<endl;
    printArray(array , arraySize);

    quickSort(array , arraySize);

    cout<<"after sort the array:"<<endl;
    printArray(array ,arraySize);

    while(1);
    return 0;
}
```
程序运行结果为：
>before sort the array：
24  71  30  26  16  23  56  21  68  30  
after sort the array:
16  21  23  24  26  30  30  56  68  71  

下面采用第二种方法实现了quickSortKernel()函数
```cpp
/**
 * 采用d递归来排序的数组
 * @param array       数组
 * @param leftBorder  左边界
 * @param rightBorder 右边界
 */
void quickSortKernel(int array[] , int leftBorder , int rightBorder)
{
    if(array == NULL || leftBorder >= rightBorder)
        return;
    int i=leftBorder;
    int j = rightBorder-1;
    while(1)
    {
        // i向右边寻找比array[rightBorder]大的元素
        while(i < rightBorder && array[i] <= array[rightBorder])
            ++i;
        // j 向左边寻找比array[rightBorder小的元素]
        while(j >= i && array[j] >= array[rightBorder])
            --j;
        if(j+1 != i)
        {
            exchange(array , i , j);
        }
        else
        {
            break;
        }
    }
    exchange(array , i , rightBorder);
    quickSortKernel(array , leftBorder , i-1);
    quickSortKernel(array , i+1 , rightBorder);
}
```
运行结果为：
>before sort the array：
36  14  24  79  0   71  9   33  77  5   
after sort the array:
0   5   9   14  24  33  36  71  77  79  


上面两种方法起始很相似，都是采用了递归的方法，只是前一种方法找目标位置$k$的方法时候从左边位置开始找，下面这种方法是从两边开始向中间寻找对应的目标位置$k$。

##快速排序的性能分析

如果快速排序输入的数组时一个按照降序排序的数组，那么快速排序的将达到最差运行时间$O(n^2)$,和插入排序一样，如果输入的数组时一个升序排序的数组，快速排序的运行时间还是$O(n^2)$,而插入排序输入一个升序排序的数组，运行时间仅有$O(n)$,连插入排序都比不上了。
那怎么避免快速排序的最差情况呢？我们来分析一下最坏运行时间的发生情况，那就是子数组的极度不平衡。我们知道在每次找到目标位置$k$以后，都会生成两个子数组$\dot A=\lbrace a_i,..,a_{k-1} \rbrace$和$\ddot A=\lbrace a_{k+1},...,a_j \rbrace $，如果这两个数组里面有一个数组为空，而且是保证每一次迭代子数组都必然有一个为空，那么我们得到递归表达式为：
$$
T(n) = T(n-1)+O(1)+O(n)
$$
上面式子里面的$O(1)$为交换两个元素的代价，$O(n)$为遍历一边所有元素需要的代价，由上面的递归式子我们得到
$$
T(n)=O(n^2)
$$
那最优的运行时间在什么情况下发生呢？假设两个字数组的元素个数比为$\dot A : \ddot A = 1:1$,即两个数组里面的元素个数相同，那么我们可以得到递归式：
$$
T(n)=2T(n/2)+O(1)+O(n)
$$
由主定理可得出：
$$
T(n)=O(nlogn)
$$
我们得出最优情况下的运行时间

为什么上面两种情况会有如此大的区别呢？我们可以将问题划分为两个子问题的情形用二叉树表示出来，如果每次划分数组，其中一个子数组为空，那么每次只能使问题的规模减小1，那么这棵二叉树的深度也将会是$n$,而二叉树每一层的代价就是遍历一遍数组的代价$O(n)$,于是最差的代价就是$n*O(n)=O(n^2)$,在最优情况下，由于两个子数组时等同大小的，于是每次都能使问题的规模减少为原来的一半，那么二叉树的深度也就是$logn$,每一层的遍历代价都是$O(n)$,所以最优情况下的运行后时间代价为$O(nlogn)$

我们推广到一般情况下来看，假设我们得到的两个子数组里面的元素比为$|\dot A=\lbrace a_i,..,a_{k-1}| : |\ddot A=\lbrace a_{k+1},...,a_j \rbrace| = 1-\alpha:\alpha  (\alpha \leq 0.5)$，那么假设这棵二叉树的最浅深度为$h_1$,最深深度为$h_2$,于是我们得到下面的不等式
$$
\begin{align}
n\times\alpha^h_1 & \leq 1\\
\alpha^h_1 & \leq \frac1n\\
两边同时&取对数\\
h_1 & \leq \frac{-logn}{log\alpha}
\end{align}
$$
我们知道二叉树的最浅深度至少为$\frac{-logn}{log\alpha}$

同理可知
$$
\begin{align}
n\times（1-\alpha)^{h_2} & \leq 1\\
（1-\alpha)^{h_2} & \leq \frac1n\\
两边同时&取对数\\
h_2 & \leq \frac{-logn}{log(1-\alpha)}
\end{align}
$$
我们知道二叉树的最深深度至少为$\frac{-logn}{log(1-\alpha)}$于是我们按照最深深度来计算在此情况下的运行时间的上界为$O(n) \times \frac{-logn}{log(1-\alpha)} = O(nlogn) $可见只要$\alpha \neq 1$的任何情况下，都能保证运行时间$O(nlogn)$,最多只是常数因子大一点小一点而已。

通过上面分析可知只要我们保证两个子数组里面任何一个都不为空，那么运行时间都是$nlogn$,所以我们改进上面的算法：
```cpp
/**
 * 采用d递归来排序的数组
 * @param array       数组
 * @param leftBorder  左边界
 * @param rightBorder 右边界
 */
void quickSortKernel(int array[] , int leftBorder , int rightBorder)
{
    if(array == NULL || leftBorder >= rightBorder)
        return;
    // 为了防止是一个纯升序或者是降序的数组，
    // 现在选取数组中前中后三个元素，得到第二大的那个
    int center = (leftBorder + rightBorder)/2;
    if(array[leftBorder] > array[center] && array[rightBorder] < array[center])
        exchange(array , center , rightBorder);
    else if(array[leftBorder] > array[center] && array[rightBorder] > array[leftBorder])
        exchange(array , leftBorder , rightBorder);

    int i=leftBorder;
    int j = rightBorder-1;
    while(1)
    {
        // i向右边寻找比array[rightBorder]大的元素
        while(i < rightBorder && array[i] <= array[rightBorder])
            ++i;
        // j 向左边寻找比array[rightBorder小的元素]
        while(j >= i && array[j] >= array[rightBorder])
            --j;
        if(j+1 != i)
        {
            exchange(array , i , j);
        }
        else
        {
            break;
        }
    }
    exchange(array , i , rightBorder);
    quickSortKernel(array , leftBorder , i-1);
    quickSortKernel(array , i+1 , rightBorder);

}
```
输入一个数组，首先取出数组头部，数组尾部，数组中部的三个元素，得到这三个元素的第二大的那个元素作为主元，你也可以不这么选，你选出前面三个元素其实也可以。我们只要保证没有一个子数组为空即可！

运行结果为：
>before sort the array:
92  17  47  13  89  13  58  25  42  10  
after sort the array:
10  13  13  17  25  42  47  58  89  92  




