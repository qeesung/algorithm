>├── main.cc            # 主文件
>├── person_data.gperf  # 关键词文件
>├── person_data.hpp    # gperf生成的源文件
>├── person_data_type.h # 类型定义文件
>└── README.md 
>
>0 directories, 5 files


---

[TOC]

<font color="red">注意</font>

本文中的所有代码你都可以在这里:

[https://github.com/qeesung/algorithm/tree/master/chapter11/11-5/gperf](https://github.com/qeesung/algorithm/tree/master/chapter11/11-5/gperf)（这里会及时更新）

或者是这里:

[http://download.csdn.net/detail/ii1245712564/8936303](http://download.csdn.net/detail/ii1245712564/8936303)

找到
#散列表之完美散列

我们都知道散列表的查找和删除操作的平均时间代价为$\Theta(1)$,也就是说在一般情况下散列表是可以很快的找到目标元素的，但是散列表也有罢工的时候，比如设计了一个差劲的散列函数导致所有的键值都具有相同的散列值，那么查找和删除元素的代价就与操作链表差不多了

那有没有什么散列表武功秘籍之类的，遵循一定的章法就可以设计出一个最坏运行时间都是$O(1)$的散列函数呢？

答案是肯定的，如果关键字集合是动态的话，那么设计出适应关键字任意变化的散列函数是很难做到的，换句话说，如果我们在不知道所有关键字或者关键字变化的情况下想设计一个最坏运行时间是$O(1)$的散列函数是很艰难的。按照这种说法，如果在知道全部关键字，且关键字不再变化的情况下我们就可以设计这样一个接近完美的散列函数了？是的，但是设计的过程还是需要借助一些工具，后面我们将慢慢介绍

#完美散列(perfect hashing)

>**完美散列的定义**
> 
>在关键字集不再变化的情况下，运用某种散列技术，将所有的关键字存入散列表中，可以在最坏运行时间为$O(1)$的情况下完成对散列表的查找工作，这种散列方法就是**完美散列**

下面我们将介绍一种手工设计的`完美散列`的方法，再介绍一种工具设计`完美散列`的方法。

#两级散列法

何为`两级散列法`？就是将关键字散列两次来确定目标元素的位置，且两次散列的散列方案都是采用全域散列(不懂全域散列的小伙伴看这里:[全域散列法](http://blog.csdn.net/ii1245712564/article/details/46649157#%E4%B9%98%E6%B3%95%E6%95%A3%E5%88%97%E6%B3%95))

两级散列法大致分为下面两步:

1. 第一级散列从全域散列函数簇中选取一个散列函数$h_1$,将$m$个元素散列到$n$个槽中
2. 第二级的散列有点特殊，在[《散列表值链接法》](http://blog.csdn.net/ii1245712564/article/details/46490501)里面我们知道一旦元素发生冲突，就用链表来存储所有散列值相同的元素。但是这里我们采用的是一个新的散列表，也就是`二级散列表`来解决一级散列表元素冲突的问题，将映射到槽$j$的元素再从`二级散列表`$S_j$的全域散列函数簇选取出一个散列函数$h_2$对元素进行再次散列，最终确定目标位置。

但是为了确保`二级散列表`上不发生冲突，需要将散列表$S_j$的大小$m_j$为散列到槽$j$中元素的平方,即$m_j = n_j^2$


**举个栗子：**

>利用完全散列基础存储关键字集合$K=\lbrace 10,22,37,40,52,60,70,72,75\rbrace$。外层散列函数为$h(k)=((a*k+b)mod\ p)mod\ m(a=3,b=42,p=101,m=9)$,将散列到槽$j$中的元素用散列函数$h_j(k)=((a_j*k+b_j)\ modp)\ modm_j$
>
>>![Alt text](http://img.blog.csdn.net/20150727114125711)

#gperf工具来自动生成完美散列函数

`gperf`是一个完美散列函数的生成器，对于一些给定的字符串，`gperf`生成一个`C/C++`版本的散列函数和一个散列表，可以通过一个字符串在生成的散列表里面进行查找操作。散列函数是完美的，也就是说散列表四没有冲突的，在查找操作中最多只需要一次字符串的比较操作。

使用`gperf`一般分为下面三个步骤：

- 首先将所有的关键字按照一定的格式写入到一个任意的文件中，后缀最好是`*.gperf`
- 用`gperf`编译该写入关键字的目标文件，最终会生成一个`*.hpp`文件
- 将生成的`*.hpp`文件用`#include`包含到自己的源文件中编译即可


##gperf的安装
首先到`gperf`官网([http://www.gnu.org/software/gperf/](http://www.gnu.org/software/gperf/))载`gperf`的源码,下载以后将是一个压缩包，对压缩包进行解压安装
```bash
cd ~/download
tar -xzvf gperf-3.0.4.tar.gz -C /tmp/gperf_source_code
cd /tmp/gperf_source_code
./configure
make
make install
```

现在我们来看看是否安装正确，在命令行中输入`gperf -v`,如果显示一下信息，说明我们已经安装成功了
>GNU gperf 3.0.4
Copyright (C) 1989-1998, 2000-2004, 2006-2009 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Written by Douglas C. Schmidt and Bruno Haible.

##gperf关键字文件的书写格式

我们可以将我们所有的关键字输入到一个文件中，然后用`gperf`再将该文件编译成我们需要的`C/C++`源码，下面我们就先来看一下关键字文件的书写格式
> declarations
   %%
   keywords
   %%
   functions

文件分为三个部分，分别是`declarations`,`keywords`,`functions`，这三部分分别代表什么意思呢？

>**declarations**
>
>这部分主要是用来声明的，声明的内容主要包括一些头文件，以及`keywords`的结构。
>
>那什么是`keywords`的结构啊？简单来说，`gperf`的关键字是字符串类型的，我们要通过关键字来搜寻关键字对应的数据，比如我们要在散列表里面存储一些人的信息，主要包括`姓名`，`年龄`，`性别`，我们需要通过`姓名`来得到额外的两个信息，于是我们可以这样定义`keywords`的结构
>```
>%{
>enum SEX{MALE=0,FEMALE=1};
>%}
>struct Person_Data{char * name ; unsigned int age ; SEX sex };
>```
>其中`%{...%}`之间可以插入一段C代码，在`gperf`编译该文件的时候就可以将这段代码插入到生成的源文件中去,还有需要注意的就是结构的第一个元素必须是`chat *`或者是`const char *`类型的
> 
> ---
> **keywords**
>在这一段里面我们主要写入我们的关键字，按照上面的栗子，我们写入的`keyword`结构必须要和之前在`declarations`中声明的结构一样
>```
>qeesung,23,MALE
>tom,18,MALE
>lucy,22,FEMALE
>```
>---
>**functions**
>
>`functions`里面主要是可以写一些C代码，在`gperf`编译该文件的时候，就可以将这些函数插入到生成的`C/C++`文件中取

对于`gperf`更加详细的说明以参见[gperf官方文档](http://www.gnu.org/software/gperf/)以及文章[使用gperf 实现高效的 C/C++ 命令行处理](http://www.ibm.com/developerworks/cn/linux/l-gperf.html)

##gperf应用举例

还是上面的栗子，现在需要将人的一些信息记录到散列表中，并且需要在单位时间内就可以完成对表的查询，那么我们首先写一个关键字文件

**person_data.gperf**
```
%{                                                                                                                                      
#include "person_data_type.h"                                                                                                           
#include <cstring>                                                                                                                      
%}                                                                                                                                      
struct person_data_type;                                                                                                                
%%                                                                                                                                      
qeesung,23,MALE                                                                                                                         
tom,18,MALE                                                                                                                             
beryl,20,FEMALE                                                                                                                         
cat,12,MALE                                                                                                                             
adolph,78,MALE                                                                                                                          
lucy,22,FEMALE                                                                                                                          
william,45,MALE                                                                                                                         
linus,46,MALE                                                                                                                           
jack,7,MALE                                                                                                                             
alice,20,FEMALE                                                                                                                         
%%  
```

用`gperf`编译一下这个文件
```
gperf -t  -L C++ -N query_person -G  person_data.gperf > person_data.hpp
#-t 选项说明自定义了keywords结构体
#-L 指定输出的语言类型这里选定了C++
#-N 指定查找散列表的函数名字
#-G 将散列表设为全局可见的
```

最后生成一个`person_data.hpp`文件

最后在我们的源文件中包含`person_data.hpp`文件
**main.cc**
```cpp
/**************************************************
 *       Filename:  main.cc
 *    Description:  主文件测试gperf
 *
 *        Version:  1.0
 *        Created:  2015年07月27日 19时12分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  qeesung (season), 1245712564@qq.com
 *   Organization:  
 **************************************************/
#include <stdlib.h>
#include <iostream>
#include <string>
#include "./person_data.hpp"
#include "person_data_type.h"

using namespace std;

/** 
 * +++  FUNCTION  +++
 *         Name:  main
 *  Description:  主函数
 */
int main ( int argc, char *argv[] )
{
	while(1)
	{
		string query_name;
		cout<<"Enter name >";
		cin>>query_name;
		if (query_name == ".")
			break;
		cout<<endl;
		person_data_type * result = Perfect_Hash::query_person(query_name.c_str(), query_name.length());
		if (result == NULL)
			cout<<"Can't find "<<query_name<<endl<<endl;
		else
		{
			cout<<"+++++++++++ "<<query_name<<" +++++++++++"<<endl;
			cout<<"age : "<<result->age<<endl;
			string sex_name = "male";
			if(result->sex)
				sex_name = "female";
			cout<<"sex : "<<sex_name<<endl<<endl;;
		}
	}
	return EXIT_SUCCESS;
}				/** ----------  end of function main  ---------- */

```

**编译运行：**
>**编译**
>
>g++ main.cc -o query_person
>
>--- 
>**运行**
>
>./query_person
>
>---
>**运行结果**
>
>Enter name >qeesung

>+++++++++++ qeesung +++++++++++
>age : 23
>sex : male

>Enter name >lucy

>+++++++++++ lucy +++++++++++
>age : 22
>sex : female

>Enter name >tomcat

>Can't find tomcat

>Enter name >cat

>+++++++++++ cat +++++++++++
>age : 12
>sex : male

>Enter name >


