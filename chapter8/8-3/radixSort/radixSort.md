[TOC]
#基数排序_RADIXSORT
基数排序是一种基于**[计数排序_COUNTINGSORT](http://blog.csdn.net/ii1245712564/article/details/45768545)**或者是**最优桶排序**(当然也可以基于其他排序算法，只不过计数排序对于基数排序来说应该是最快的了，因为二者的拼音都是`jishupaixu`,哈哈)的一种可以在线性时间$O(n)$完成的排序算法。博主在做基数排序的功课的时候，发现有些博文里面写到`基数排序`就是`桶排序`，我觉得基数排序和桶排序是不同的，虽然二者都用到了桶的思想，但是二者在桶里面做的事情是完全不一样的：

- 基数排序只是借用十只桶来为0-9这十个基数进行排序分堆（可以说是最优的桶排序），反复的在保持稳定的情况下，对个位，十位。。。分别进行桶排序
- 而桶排序里面的桶不一定是十个桶，可以是任意多的桶，只是桶的数量会影响排序的速度，桶排序主要是将元素映射到桶里面，再在各个桶里面进行排序，最后再将各个桶里面的数组归并在一起(我们将会在后面的文章介绍桶排序)

对于一般的排序算法来说，都是通过元素和元素之间的大小比较来决定元素的大小顺序的，这类算法在最差情况至少也要花费$O(nlogn)$.但是是对于基数排序来说并不是这样做的，在基数排序里面可以说一次元素与元素之间的比较都没有，都是通过统计数组里面的元素个数来实现的。

##基数排序的思想

基数排序的思想其实很简单，就是对序列中的各个数首先以个位为排序依据对各个数字进行排序，然后再以十位为排序依据对各个数进行排序，以此类推，将所有位都进行排序，那么最后得到的序列就是有序序列。

>**问题一**:要是各个数的位数不一样长怎么办？比如有些数字最大十位，有些数字最大百位
>
>**答案**：以序列中位数最长的为基准，位数不够的补零，比如位数最高为百位，那么数字45就补零为045

>---

>**问题2**：为什么不从高位开始来排序，而是从个位开始排序
>
>**答案**：因为数位越高，说明占有的比重就越高，个位的排序是为了决定在十位相同的情况下，各个数的顺序，而十位的排序就可以直接忽略个位的排序，十位的排序是为了决定在百位相同的情况下，各个数的位置

假设我们有这样一个序列：
913	75	794	629	48	375	958	630	190	632	
现在我们对其进行基数排序
>**步骤一**:对各个数进行<font color=green>**补齐**</font>
>913	<font color=red>0</font>75	794	629	<font color=red>0</font>48	375	958	630	190	632	
>
>---
>
>**步骤二**：对<font color=green>**个位**</font>进行排序
>63<font color=red>0</font>	19<font color=red>0</font>	63<font color=red>2</font>	91<font color=red>3</font>	79<font color=red>4</font>	07<font color=red>5</font>	37<font color=red>5</font>	04<font color=red>8</font>	95<font color=red>8</font>	62<font color=red>9</font>	
>
>---
>
>**步骤三**：对<font color=green>**十位**</font>进行排序
>9<font color=red>1</font>3	6<font color=red>2</font>9	6<font color=red>3</font>0	6<font color=red>3</font>2	0<font color=red>4</font>8	9<font color=red>5</font>8	0<font color=red>7</font>5	3<font color=red>7</font>5	1<font color=red>9</font>0	7<font color=red>9</font>4	
>
>---
>
>**步骤三**：对<font color=green>**百位**</font>进行排序
><font color=red>0</font>48	<font color=red>0</font>75	<font color=red>1</font>90	<font color=red>3</font>75	<font color=red>6</font>29	<font color=red>6</font>30	<font color=red>6</font>32	<font color=red>7</font>94	<font color=red>9</font>13	<font color=red>9</font>58

ok,上面分析了基数排序的过程，我们知道就是逐位进行排序就可以啦，但是具体要怎么排才最快呢？`冒泡排序`，`插入排序`，`快速排序`。。。其实这些排序对于一般的输入数组来说速度是比较快的，但是别忘了这里有一个限定条件，那就是我们需要排序的数是的区间是在$[0,9]$之间的，那么自然就是计数排序啦，或者是最优的桶排序(有十个桶)。下面我们用两种方法分别实现这两种排序

##基数排序算法实现
下面的是基于计数排序和最优桶排序的代码实现。你可以在这里下载到完整的源码：
[《基数排序_RADIXSORT》:http://download.csdn.net/detail/ii1245712564/8717167](http://download.csdn.net/detail/ii1245712564/8717167)

###<font color="#B452CD">**基于计数排序的基数排序**</font>
>**计数排序的代码**
```cpp
/**
 * 基数排序
 * @param array     输入要排序的数组
 * @param minEle    最小元素
 * @param maxEle    最大元素    
 * @param arraySize 数组大小
 * @param radix     基于个位十位还是百位等等排序
 */
void countingSort(int array[] , int minEle , int maxEle , int arraySize , int radix)
{
    if(array == NULL ||\
       minEle > maxEle ||\
       arraySize < 0 ||\
       radix < 0)
        return;
    // 新建一个临时计数数组
    const int & countArraySize = maxEle-minEle+1;
    int countArray[countArraySize];
    // 初始化计数数组
    for (int i = 0; i < countArraySize; ++i)
    {
        countArray[i] = 0;
    }
    // 新建一个临时的输出数组,用来存储输出排序的结果
    int sortedArray[arraySize];

    // 遍历一遍数组数组，统计各个元素对应的radix的数量
    for (int i = 0; i < arraySize; ++i)
    {
        countArray[array[i]%radix/(radix/10)]++;
    }

    // 统计比一个元素小的元素个数
    for (int i = 1; i < countArraySize; ++i)
    {
        countArray[i] = countArray[i] + countArray[i-1];
    }

    // 将元素放入sortedArray里面合适的位置
    for (int i = arraySize-1; i >=0; --i)
    {
        sortedArray[countArray[array[i]%radix/(radix/10)] - 1] = array[i];
        countArray[array[i]%radix/(radix/10)]--;
    }

    // 将元素复制回去,感觉这里有点慢，可不可以进行原址排序？
    for (int i = arraySize-1; i >=0; --i)
    {
        array[i] = sortedArray[i];
    }
    return;
}
```
这里函数接口里面传入一个`radix`参数,这个`radix`参数只能是10的倍数的数字，`array[i]%radix/(radix/10)`则是取出对应位的数字
>**基数排序代码**

```cpp
/**
 * 基数排序
 * @param array     输入的数组
 * @param arraySize 数组大小
 * @param maxRadix  数组里面元素的最大位
 * @param minRadix  数组里面元素的最小位
 */
void radixSort(int array[] , int arraySize , int minRadix  ,  int maxRadix)
{
    if(array == NULL || arraySize < 0 || maxRadix <= 0 || minRadix <=0 || minRadix > maxRadix)
        return;
    // 得到基数开始位置
    int tempRadix = 1;
    for (int i = 1; i < minRadix; ++i)
    {
        tempRadix *= 10;
    }
    // 开始进行排序
    for (int i = minRadix; i < maxRadix ; ++i)
    {
        tempRadix *= 10;
        countingSort(array , 0 , 9 , arraySize , tempRadix);
        cout<<tempRadix<<" -----------"<<endl;
        printArray(array , arraySize);
    }
    return;
}
```
在基数排序里面调用计数排序为各个位进行排序
>**main函数代码**

```cpp
int main(int argc, char const *argv[])
{
    const int & arraySize = 10;
    int inArray[arraySize];
    srand((int)(time(NULL)));
    for (int i = 0; i < arraySize; ++i)
    {
        inArray[i] = rand()%1000;
    }
    cout<<"before sort array :"<<endl;
    printArray(inArray , arraySize);

    radixSort(inArray , arraySize , 1 ,4);
    cout<<"after sort array"<<endl;
    printArray(inArray , arraySize);
    while(1);
    return 0;
}
```

>运行结果：
>before sort array :
856	365	404	162	279	512	547	665	70	298	
10 -----------
70	162	512	404	365	665	856	547	298	279	
100 -----------
404	512	547	856	162	365	665	70	279	298	
after sort array
404	512	547	856	162	365	665	70	279	298	

###<font color="#9ACD32">**基于最优桶排序的基数排序**</font>
>**桶排序代码**

```cpp
// 定义桶排序的映射函数
#define BUCKET(i) (i)
// 定义十只桶
const int & bucketNumber = 10;

/** some code */
/**
 * 桶排序
 * @param inArray 数组数组
 * @param arraySize 数组大小
 * @param radix   对应的基数,只能是10的倍数
 */
void bucketSort(int inArray[] , int arraySize , int radix)
{
	if(inArray == NULL || arraySize < 0 ||radix<0 ||radix%10!=0)
		return;
	/** 创建桶 */
	std::vector<int> buckets[bucketNumber];
	/** 将输入数组里面的数分类放到桶里面 */
	for (int i = 0; i < arraySize; ++i)
	{
		buckets[BUCKET(inArray[i]%radix/(radix/10))].push_back(inArray[i]);
	}
	/** 将桶里面的数组按顺序组合起来 */
	int arrayPos = 0;
	for (int i = 0; i < bucketNumber && arrayPos < arraySize; ++i)
	{
		std::vector<int> & tempVec = buckets[i];
		for (std::vector<int>::iterator iter = tempVec.begin(); iter != tempVec.end(); ++iter)
		{	
			inArray[arrayPos++] = *iter;
		}
	}
}
```
这里桶排序的映射函数`BUCKET(i)`就是映射到`i`本身，也就是有n个数字，那么就创建n个桶，这是速度最快的桶排序，同时也是最浪费空间的桶排序。这里输入的`radix`只能是10的倍数
>**基数排序代码**

```cpp

/**
 * 基数排序
 * @param inArray   输入的数组	
 * @param arraySize 数组大小
 */
void radixSort(int inArray[] , int arraySize , int maxPlace)
{
	if(inArray == NULL || arraySize< 0 || maxPlace < 1)
		return;
	int radixBasic=1;
	for (int i = 0; i < maxPlace; ++i)
	{
		radixBasic*=10;
		bucketSort(inArray , arraySize , radixBasic);
        cout<<radixBasic<<" -----------"<<endl;
		printArray(inArray,arraySize);
	}
	return;
}
```
>**main函数代码**

```cpp
int main(int argc, char const *argv[])
{
    const int & arraySize = 10;
    int inArray[arraySize];
    srand((int)(time(NULL)));
    for (int i = 0; i < arraySize; ++i)
    {
        inArray[i] = rand()%1000;
    }
    cout<<"before sort array :"<<endl;
    printArray(inArray , arraySize);

    radixSort(inArray , arraySize , 3);
    cout<<"after sort array"<<endl;
    printArray(inArray , arraySize);
    return 0;
}
```

>输出结果：
before sort array :
74	864	595	545	957	804	194	942	454	892	
10 -----------
942	892	74	864	804	194	454	595	545	957	
100 -----------
804	942	545	454	957	864	74	892	194	595	
1000 -----------
74	194	454	545	595	804	864	892	942	957	
after sort array
74	194	454	545	595	804	864	892	942	957	