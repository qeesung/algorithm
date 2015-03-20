<h1>
    <span style="font-family:Comic Sans MS">1.问题描述</span>
</h1>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">一公司购买长钢条，将其切为短钢条出售，假设切割没有成本，公司希望知道最佳的切割方案！假设我们知道一段长度为i的钢条的价格为pi(i = 1,2,3...),钢条长度均为整英寸，下面给出一个价格表：</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px"></span>
    <table border="1" width="400" cellspacing="1" cellpadding="1" align="center">
        <tbody>
            <tr>
                <td>
                    <span style="font-family:Comic Sans MS; font-size:18px">长度i</span>
                </td>
                <td>
                    <span style="font-family:Comic Sans MS; font-size:18px">1&nbsp;</span>
                </td>
                <td>
                    <span style="font-family:Comic Sans MS; font-size:18px">2&nbsp;</span>
                </td>
                <td>
                    <span style="font-family:Comic Sans MS; font-size:18px">3&nbsp;</span>
                </td>
                <td>
                    <span style="font-family:Comic Sans MS; font-size:18px">4&nbsp;</span>
                </td>
                <td>
                    <span style="font-family:Comic Sans MS; font-size:18px">5&nbsp;</span>
                </td>
                <td>
                    <span style="font-family:Comic Sans MS; font-size:18px">6&nbsp;</span>
                </td>
                <td>
                    <span style="font-family:Comic Sans MS; font-size:18px">7&nbsp;</span>
                </td>
                <td>
                    <span style="font-family:Comic Sans MS; font-size:18px">8&nbsp;</span>
                </td>
                <td>
                    <span style="font-family:Comic Sans MS; font-size:18px">9&nbsp;</span>
                </td>
                <td>
                    <span style="font-family:Comic Sans MS; font-size:18px">10</span>
                </td>
            </tr>
            <tr>
                <td>
                    <span style="font-family:Comic Sans MS; font-size:18px">价格pi</span>
                </td>
                <td>
                    <span style="font-family:Comic Sans MS; font-size:18px">1&nbsp;</span>
                </td>
                <td>
                    <span style="font-family:Comic Sans MS; font-size:18px">5&nbsp;</span>
                </td>
                <td>
                    <span style="font-family:Comic Sans MS; font-size:18px">8&nbsp;</span>
                </td>
                <td>
                    <span style="font-family:Comic Sans MS; font-size:18px">9&nbsp;</span>
                </td>
                <td>
                    <span style="font-family:Comic Sans MS; font-size:18px">10</span>
                </td>
                <td>
                    <span style="font-family:Comic Sans MS; font-size:18px">17</span>
                </td>
                <td>
                    <span style="font-family:Comic Sans MS; font-size:18px">17</span>
                </td>
                <td>
                    <span style="font-family:Comic Sans MS; font-size:18px">20</span>
                </td>
                <td>
                    <span style="font-family:Comic Sans MS; font-size:18px">24</span>
                </td>
                <td>
                    <span style="font-family:Comic Sans MS; font-size:18px">30</span>
                </td>
            </tr>
        </tbody>
    </table>
    <span style="font-family:Comic Sans MS; font-size:18px">给定一长度为n的钢条和一张价格表(i =1, 2,3...n)，求切割钢条的方案，使的利润最大,可以不进行切割</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px"><br />
    </span>
</div>
<div>
    <h1>
        <span style="font-family:Comic Sans MS"><span style="font-size:24px">2.动态规划</span></span>
    </h1>
    <div>
        <span style="font-family:Comic Sans MS; font-size:18px">动态规划与分治法比较类似，都是通过求解子问题的解，最终来求出原问题的解。分治法只要是将原问题分解成为若干个独立的子问题，通过子问题来求解原问题的解。而动态规划恰恰相反，动态规划是用来求解子问题重叠的情况，即不同的子问题之间具有相同的公共子问题，在这种情况下分治法会花费大量的时间来计算已经计算过的那部分重叠子问题，效率大大降低，而动态规划权衡时间和空间的因素，将已经计算过的子问题存入一张表内，下次遇到相同的子问题时，直接查表就可以得到结果，大大加快了速度</span>
    </div>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">动态规划通常用来求解最优化问题，一般来说一个问题的最优解有多个，动态规划可以求解出其中的一个最优解，而不是最优解</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">我们通常按照下面的四个步骤来设计一个动态规划问题：</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">1.刻画一个最优解的结构特征。</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">2.递归的定义最优解的值</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">3.计算最优解时，一般采用自下而上的方法来求解</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">4.利用计算出的信息构造出一个最优解</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">下面我们来研究怎么用动态规划计算出一个最优解</span>
</div>
<div>
    <span style="font-size:18px"><br />
    </span>
</div>
<h1>
    <span style="font-size:24px">3.问题分析</span>
</h1>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">长度为n的钢条一共有2^(n-1)种切割方法，因为每一个长度为1的节点处都可以选择切或者不切</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">那么我们假设长度为n的钢条切成了k条钢条的时候，利润最大:</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">n = i1+i2+i3+...+ik;</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">ri = pi1+pi2+pi3+...+pik;</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">那么最大利润为：</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">rn = max(pn , r1+rn-1 , r2+rn-2, ...,ri+rn-i , rn-1+r1);(pn为不进行切割的时候的利润,ri+rn-i为在节点i处进行切割,ri为长度为i的钢条最大利润， rn-i为长度n-i的钢条的最大利润)！</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">这里我么通过组合两个相关子问题的最优解，并在所有可能的切割点上选取出最大的的利润，构成原问题的最优解。<span style="background-color:rgb(255,0,0)"><span style="color:#ffff33">我们称钢条切割问题满足最优子结构的性质：问题的最优解由相关子问题的最优解组成，子问题可以独立求解！</span></span></span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px"><span style="background-color:rgb(255,255,255)">我们不妨将上面的问题简化，得到一个简化以后的最优解的结构：</span></span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px"><span style="background-color:rgb(255,255,255)">rn = max(p1+rn-1 , p2+rn-2 ,...,pn+r0);</span></span>
</div>
<div>
    <br />
    
</div>
<h1>
    <span style="font-family:Comic Sans MS; font-size:24px">4.代码实现</span>
</h1>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">自顶向下的代码实现：</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px"></span>
    <pre code_snippet_id="623934" snippet_file_name="blog_20150320_1_4873772" name="code" class="cpp">#include &lt;iostream&gt;
#include &lt;string&gt;
#include &lt;limits.h&gt;

using namespace std;

#define KIND_SIZE 11
/** 每种长度的基本价格 */
int price[]={0,1,5,8,9,10,17,17,20,24,30};

int dealMaxProfit(int n , int maxProfit[]);
/**
 * 得到最大的利润
 * @param  n 钢条长度
 * @return   最大利润
 */
int getMaxProfit(int n)
{   
    if( n &lt; 0 || n &gt; KIND_SIZE)
        return 0;
    int maxProfit[KIND_SIZE];//记录每个长度下的最大利润是多少
    for (int i = 0; i &lt;  KIND_SIZE ; ++i)
    {
        maxProfit[i] = INT_MIN;  
    }
    maxProfit[0] = 0;
    dealMaxProfit(n , maxProfit);
    return maxProfit[n];
}

/**
 * 将每个长度对应的比n小的钢条最大利润都保存在maxProfit里面
 * @param n         钢条长度
 * @param maxProfit 保存最大利润的数组
 * @return          返回长度为n的最大利润
 */
int dealMaxProfit(int n , int maxProfit[])
{
    if( n == 0)
        return 0;
    /** 表示之前已经算过了 */
    if(maxProfit[n]!= INT_MIN)
        return maxProfit[n];
    /** 没有算过那么就算一遍 */
    int max = INT_MIN;
    for (int i = 1; i &lt; n+1; ++i)
    {
        int temp = price[i]+dealMaxProfit(n-i, maxProfit); 
        if(max &lt; temp)
            max = temp;
    }
    maxProfit[n] = max;
    return max;
}


int main(int argc, char const *argv[])
{
    while(1)
    {   
        int steelBarLen; 
        cout&lt;&lt;&quot;Enter the steel Bar Length(0-10)&gt;&quot;;
        cin &gt;&gt; steelBarLen;
        cout&lt;&lt;&quot;Max profit is : &quot;&lt;&lt;getMaxProfit(steelBarLen)&lt;&lt;endl;
    }
    return 0;
}</pre>
    <br />
    
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">自底向上的代码实现：</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px"></span>
    <pre code_snippet_id="623934" snippet_file_name="blog_20150320_2_2525688" name="code" class="cpp">#include &lt;iostream&gt;
#include &lt;limits.h&gt;
#include &lt;string&gt;

using namespace std;
#define KIND_SIZE 11
/** 这个是每一个长度下的单价 */
int price[]={0,1,5,8,9,10,17,17,20, 24 ,30};

int dealMaxProfit(int n , int maxProfit[]);
/**
 * 得到最大的利润
 * @param  n 钢条的长度
 * @return   最大的利润
 */
int getMaxProfit(int n)
{
    if(n &lt; 0 || n &gt; KIND_SIZE)
        return 0;
    int maxProfit[KIND_SIZE];
    for (int i = 0; i &lt; KIND_SIZE; ++i)
    {
        maxProfit[i] = INT_MIN;
    }
    maxProfit[0] = 0;
    dealMaxProfit(n , maxProfit);
    return maxProfit[n];
}

/**
 * 处理得到&lt;n长度的利润
 * @param  n         钢条的长度
 * @param  maxProfit 最大的利润
 * @return           对应长度为n的最大的利润
 */
int dealMaxProfit(int n , int maxProfit[])
{
    if(n == 0)
        return 0;
    for (int i = 1; i &lt;= n; ++i)
    {
        int max = INT_MIN;
        for (int j = 1; j &lt;= i; ++j)
        {// 每次都是将最优子结构求出来，再求上层的
            int temp = price[j]+maxProfit[i-j];
            if(max &lt; temp)
                max = temp;
        } 
        maxProfit[i] = max;
    }
}

int main(int argc, char const *argv[])
{
    while(1)
    {   
        int steelBarLen; 
        cout&lt;&lt;&quot;Enter the steel Bar Length(0-10)&gt;&quot;;
        cin &gt;&gt; steelBarLen;
        cout&lt;&lt;&quot;Max profit is : &quot;&lt;&lt;getMaxProfit(steelBarLen)&lt;&lt;endl;
    }
    return 0;
}</pre>
    <div>
        <span style="font-family:Comic Sans MS; font-size:18px"><br />
        </span>
    </div>
    但是上面的代码只是求解了最终的最大的利润，并没有算出具体的解决方案
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">我们不妨观察一下最优解的结构：</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px"><span style="font-family:'Comic Sans MS'; font-size:18px">rn = max(p1+rn-1 , p2+rn-2 ,...,pn+r0);</span></span>
</div>
<div>
    <span style="font-family:Comic Sans MS"><span style="font-size:18px">最优的解是由子问题的最优解构成，钢条要么在长度为i处切割，要么不切割，所有我们就用一个数组来保存对应长度n应该从位置i(不截断情况i=n)截断的数据</span></span>
</div>
<div>
    <span style="font-family:Comic Sans MS"><span style="font-size:18px">即devidePos[n]=i;</span></span>
</div>
<div>
    <span style="font-family:Comic Sans MS"><span style="font-size:18px">于是我们将上面的算法进行改进，使其可以求出截断的方案</span></span>
</div>
<div>
    <span style="font-family:Comic Sans MS"><span style="font-size:18px"><br />
    </span></span>
</div>
<div>
    <span style="font-family:Comic Sans MS"><span style="font-size:18px">自顶向下的代码实现：</span></span>
</div>
<div>
    <span style="font-family:Comic Sans MS"><span style="font-size:18px"></span></span>
    <pre code_snippet_id="623934" snippet_file_name="blog_20150320_3_2511135" name="code" class="cpp">/**
&nbsp;* 这个是自顶向下的求法
&nbsp;*/
#include &lt;iostream&gt;
#include &lt;string&gt;
#include &lt;limits.h&gt;
&nbsp;#include &lt;stdio.h&gt;


using namespace std;


#define KIND_SIZE 11
/** 每种长度的基本价格 */
int price[]={0,1,5,8,9,10,17,17,20,24,30};


int dealMaxProfit(int n , int maxProfit[] , int devidePos[]);
/**
&nbsp;* 得到最大的利润
&nbsp;* @param &nbsp;n 钢条长度
&nbsp;* @return &nbsp; 最大利润
&nbsp;*/
int getMaxProfit(int n , int devidePos[])
{ &nbsp;&nbsp;
&nbsp; &nbsp; if( n &lt; 0 || n &gt; KIND_SIZE)
&nbsp; &nbsp; &nbsp; &nbsp; return 0;
&nbsp; &nbsp; int maxProfit[KIND_SIZE];//记录每个长度下的最大利润是多少
&nbsp; &nbsp; for (int i = 0; i &lt; &nbsp;KIND_SIZE ; ++i)
&nbsp; &nbsp; {
&nbsp; &nbsp; &nbsp; &nbsp; maxProfit[i] = INT_MIN;
&nbsp; &nbsp; &nbsp; &nbsp; devidePos[i] = i;&nbsp;
&nbsp; &nbsp; }
&nbsp; &nbsp; maxProfit[0] = 0;
&nbsp; &nbsp; dealMaxProfit(n , maxProfit , devidePos);
&nbsp; &nbsp; return maxProfit[n];
}


/**
&nbsp;* 将每个长度对应的比n小的钢条最大利润都保存在maxProfit里面
&nbsp;* @param n &nbsp; &nbsp; &nbsp; &nbsp; 钢条长度
&nbsp;* @param maxProfit 保存最大利润的数组
&nbsp;* @return &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;返回长度为n的最大利润
&nbsp;*/
int dealMaxProfit(int n , int maxProfit[] , int devidePos[])
{
&nbsp; &nbsp; if( n == 0)
&nbsp; &nbsp; &nbsp; &nbsp; return 0;
&nbsp; &nbsp; /** 表示之前已经算过了 */
&nbsp; &nbsp; if(maxProfit[n]!= INT_MIN)&nbsp;
&nbsp; &nbsp; &nbsp; &nbsp; return maxProfit[n];
&nbsp; &nbsp; /** 没有算过那么就算一遍 */
&nbsp; &nbsp; int max = INT_MIN;
&nbsp; &nbsp; int pos = n;xia
&nbsp; &nbsp; for (int i = 1; i &lt; n+1; ++i)
&nbsp; &nbsp; {
&nbsp; &nbsp; &nbsp; &nbsp; int temp = price[i]+dealMaxProfit(n-i, maxProfit &nbsp;,devidePos);&nbsp;
&nbsp; &nbsp; &nbsp; &nbsp; if(max &lt; temp)
&nbsp; &nbsp; &nbsp; &nbsp; {
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; max = temp;
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; pos = i;
&nbsp; &nbsp; &nbsp; &nbsp; }
&nbsp; &nbsp; }
&nbsp; &nbsp; maxProfit[n] = max;
&nbsp; &nbsp; devidePos[n] = pos;
&nbsp; &nbsp; return max;
}


void printCutSolution(int n , int devidePos[])
{
&nbsp; &nbsp; if(n &lt; 0 || n &gt;= KIND_SIZE)
&nbsp; &nbsp; &nbsp; &nbsp; return ;
&nbsp; &nbsp; if( n == devidePos[n])
&nbsp; &nbsp; {
&nbsp; &nbsp; &nbsp; &nbsp; printf(&quot;%s\n&quot;, &quot;not devide&quot; );
&nbsp; &nbsp; &nbsp; &nbsp; return;
&nbsp; &nbsp; }
&nbsp; &nbsp; printf(&quot;%d steel bar devide into %d and %d \n&quot;, n , n - devidePos[n] , devidePos[n] );
&nbsp; &nbsp; printCutSolution(n - devidePos[n] , devidePos);
}


int main(int argc, char const *argv[])
{


&nbsp; &nbsp; while(1)
&nbsp; &nbsp; { &nbsp;&nbsp;
&nbsp; &nbsp; &nbsp; &nbsp; int devidePos[KIND_SIZE];
&nbsp; &nbsp; &nbsp; &nbsp; int steelBarLen;&nbsp;
&nbsp; &nbsp; &nbsp; &nbsp; cout&lt;&lt;&quot;Enter the steel Bar Length(0-10)&gt;&quot;;
&nbsp; &nbsp; &nbsp; &nbsp; cin &gt;&gt; steelBarLen;
&nbsp; &nbsp; &nbsp; &nbsp; cout&lt;&lt;&quot;Max profit is : &quot;&lt;&lt;getMaxProfit(steelBarLen , devidePos)&lt;&lt;endl;
&nbsp; &nbsp; &nbsp; &nbsp; printCutSolution(steelBarLen , devidePos);
&nbsp; &nbsp; }
&nbsp; &nbsp; return 0;


}</pre>
    <div>
        <span style="font-family:Comic Sans MS"><span style="font-size:18px"><br />
        </span></span>
    </div>
    自底向上的代码实现：
</div>
<div>
    <span style="font-family:Comic Sans MS"><span style="font-size:18px"></span></span>
    <pre code_snippet_id="623934" snippet_file_name="blog_20150320_4_1308886" name="code" class="cpp">#include &lt;iostream&gt;
#include &lt;limits.h&gt;
#include &lt;stdio.h&gt;
#include &lt;string&gt;

using namespace std;
#define KIND_SIZE 11
/** 这个是每一个长度下的单价 */
int price[]={0,1,5,8,9,10,17,17,20, 24 ,30};

int dealMaxProfit(int n , int maxProfit[] , int devidePos[]);
/**
 * 得到最大的利润
 * @param  n 钢条的长度
 * @return   最大的利润
 */
int getMaxProfit(int n , int devidePos[])
{
    if(n &lt; 0 || n &gt; KIND_SIZE)
        return 0;
    int maxProfit[KIND_SIZE];
    for (int i = 0; i &lt; KIND_SIZE; ++i)
    {
        maxProfit[i] = INT_MIN;
        devidePos[i] = i;
    }
    maxProfit[0] = 0;
    dealMaxProfit(n , maxProfit , devidePos);
    return maxProfit[n];
}

/**
 * 处理得到&lt;n长度的利润
 * @param  n         钢条的长度
 * @param  maxProfit 最大的利润
 * @return           对应长度为n的最大的利润
 */
int dealMaxProfit(int n , int maxProfit[] , int devidePos[])
{
    if(n == 0)
        return 0;
    for (int i = 1; i &lt;= n; ++i)
    {
        int max = INT_MIN;
        int pos=i;
        for (int j = 1; j &lt;= i; ++j)
        {// 每次都是将最优子结构求出来，再求上层的
            int temp = price[j]+maxProfit[i-j];
            if(max &lt; temp)
            {
                max = temp;
                pos = j;
            }
        } 
        devidePos[i] = pos;
        maxProfit[i] = max;
    }
}

void printCutSolution(int n , int devidePos[])
{
    if(n &lt; 0 || n &gt;= KIND_SIZE)
        return ;
    if( n == devidePos[n])
    {
        printf(&quot;%s\n&quot;, &quot;not devide&quot; );
        return;
    }
    printf(&quot;%d steel bar devide into %d and %d \n&quot;, n , n - devidePos[n] , devidePos[n] );
    printCutSolution(n - devidePos[n] , devidePos);
}

int main(int argc, char const *argv[])
{
    while(1)
    {   
        int devidePos[KIND_SIZE];
        int steelBarLen; 
        cout&lt;&lt;&quot;Enter the steel Bar Length(0-10)&gt;&quot;;
        cin &gt;&gt; steelBarLen;
        cout&lt;&lt;&quot;Max profit is : &quot;&lt;&lt;getMaxProfit(steelBarLen , devidePos)&lt;&lt;endl;
        printCutSolution(steelBarLen , devidePos);
    }
    return 0;
}</pre>
    <br />
    之前我么在描述问题的时候假设过切割钢条不消耗费用，假设现在改变条件，钢条每切割一次，代价为c，那么最佳的决绝方案是什么呢？其实这个问题和上面的问题比较类似，我们只用每次减去代价c就可以了，代码实现如下：
</div>
<div>
    <span style="font-family:Comic Sans MS"><span style="font-size:18px"></span></span>
    <pre code_snippet_id="623934" snippet_file_name="blog_20150320_5_2407148" name="code" class="cpp">#include &lt;iostream&gt;
#include &lt;limits.h&gt;
using namespace std;

#define KIND_SIZE 11
#define COST 2 /** 切割的花费 */
/** 每种长度的基本价格 */
int price[]={0,1,5,8,9,10,17,17,20,24,30};

int dealMaxProfit(int , int *);
int getMaxProfit(int n)
{
    if(n &lt;=0 || n &gt;= KIND_SIZE)
        return 0;
    int maxProfit[KIND_SIZE];
    for (int i = 0; i &lt;KIND_SIZE; ++i)
    {
        maxProfit[i] = INT_MIN;
    }
    dealMaxProfit(n , maxProfit);
    return maxProfit[n];
}

int dealMaxProfit(int n , int maxProfit[])
{
    maxProfit[0] = 0;
    for (int i = 1; i &lt; KIND_SIZE; ++i)
    {
        int max = INT_MIN;
        for (int j = 1; j &lt; i ; ++j)
        {
            int maxTemp = price[j]+maxProfit[i-j]-COST;
            if(max &lt; maxTemp)
                max = maxTemp;
        }
        max = max&gt;price[i]?max:price[i];
        maxProfit[i] = max;
    }
    return maxProfit[n];
}

int main(int argc, char const *argv[])
{
    while(1)
    {   
        int steelBarLen; 
        cout&lt;&lt;&quot;Enter the steel Bar Length(0-10)&gt;&quot;;
        cin &gt;&gt; steelBarLen;
        cout&lt;&lt;&quot;Max profit is : &quot;&lt;&lt;getMaxProfit(steelBarLen)&lt;&lt;endl;
    }
    return 0;
}</pre>
    <br />
    <br />
    <br />
    
</div>
<div>
    <span style="font-family:Comic Sans MS"><br />
    </span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px"><br />
    </span>
</div>