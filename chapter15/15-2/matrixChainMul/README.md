<p>
    <span style="font-family:Comic Sans MS; font-size:18px">虽然我们在<a target="_blank" href="http://blog.csdn.net/ii1245712564/article/details/44464689">《动态规划之钢条切割》:http://blog.csdn.net/ii1245712564/article/details/44464689</a>里面已经介绍过动态规划的相关知识，这里还是提一下动态的两大特征：</span>
</p>
<p>
    <span style="font-family:Comic Sans MS; font-size:18px">1.最优子结构，原问题的解是在子问题的最优解的基础上建立起来的</span>
</p>
<p>
    <span style="font-family:Comic Sans MS; font-size:18px">2.重叠子问题，即在不断求解子问题的过程中会产生相同的子问题，而不是一直产生新的子问题</span>
</p>
<p>
    <span style="font-family:Comic Sans MS; font-size:18px"><br />
    </span>
</p>
<h1>
    <span style="font-family:Comic Sans MS; font-size:18px">1.问题描述</span>
</h1>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">现在我们来看一个例子，假设有三个矩阵：</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">A1&lt;10,100&gt; A2&lt;100,5&gt; A3&lt;5,50&gt;</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">令B=A1A2A3,那么求得矩阵B共需要花费多少代价呢？</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px; color:#3366ff"><br />
    </span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px; color:#3366ff">先看一下这种情况：</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">A1乘A2的代价为10*100*5=5000,然后得到一个A4&lt;10,5&gt;的矩阵</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">A4再乘上A3的代价为10*5*50=2500</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">总共花费代价为5000+2500=7500</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px"><span style="font-family:'Comic Sans MS'; font-size:18px">我们知道矩阵相乘是不满足乘法交换律，而是满足乘法结合律的，即我们不可以改变矩阵链中各个矩阵的位置，但是我们可以改变矩阵在矩阵链中相乘的先后顺序</span></span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px; color:#3366ff"><span style="font-family:'Comic Sans MS'; font-size:18px"><br />
    </span></span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px; color:#3366ff"><span style="font-family:'Comic Sans MS'; font-size:18px">那么就有这种情况：</span></span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">先A2乘A3，代价为1000*5*50=25000,得到矩阵A4&lt;100,50&gt;</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">A1再乘上A4，代价为10*100*50=50000</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">总共花费代价为25000+50000=75000</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px"><br />
    </span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">比较上面两种情况，我们知道，通过矩阵的结合律改变矩阵相乘的先后顺序，矩阵相乘的总代价是由区别的。</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px"><br />
    </span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px"><strong>问题</strong>：现在给定一个含有n个矩阵的矩阵链&lt;A1,A2,A3,...,An&gt;（矩阵链输入合法），通过结合律改变矩阵相乘的顺序（通过加括号方法），使得矩阵链花费的代价最小。</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px"><br />
    </span>
</div>
<h1>
    <span style="font-family:Comic Sans MS; font-size:18px">2.问题分析</span>
</h1>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">看到这道题，我们首先想到的是用蛮力法来枚举所有的情况，然后找到最小的花费，但是这样做真的可行吗？</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">我们假设p(n)为n个矩阵链括号化方案的数量：</span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px"><img src="" width="500" height="120" alt="" /><br />
    </span>
</div>
<div>
    <div>
        <span style="font-family:Comic Sans MS; font-size:18px">通过计算，我们知道，通过蛮力法来求解这个问题，那么括号化方案的数量将是与n呈指数增长的关系的。</span>
    </div>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px"><br />
    </span>
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px">那我们通过运用动态规划的策略来解决这个问题：</span>
</div>
<div>
    <span style="font-family:Comic Sans MS"></span>
    <div style="font-size:15px; line-height:35px">
        <span style="font-size:18px">1.刻画一个最优解的结构特征。</span>
    </div>
    <div style="font-size:15px; line-height:35px">
        <span style="font-size:18px">2.递归的定义最优解的值</span>
    </div>
    <div style="font-size:15px; line-height:35px">
        <span style="font-size:18px">3.计算最优解时，一般采用自下而上的方法来求解</span>
    </div>
    <div style="font-size:15px; line-height:35px">
        <span style="font-size:18px">4.利用计算出的信息构造出一个最优解</span>
    </div>
    <div style="font-size:15px; line-height:35px">
        <span style="font-size:18px"><strong>步骤一：最优括号化方案的结构特征</strong></span>
    </div>
    <div style="line-height:35px">
        <span style="font-size:18px">动态规划的第一步是寻找最优子结构，通过子问题的最优解来构造原问题的最优解。为方便起见，我们用A&lt;i...j&gt;表示矩阵链&lt;Ai,Ai+1,...,Aj-i,Aj&gt;,为了将矩阵链括号化，我们需要在位置k(k&gt;=i &amp;&amp; k &lt; j)处将矩阵链分开为A&lt;i...k&gt;和A&lt;k+1...j&gt;。也就是说我们首先计算A&lt;i...k&gt;和A&lt;k+1...j&gt;的子矩阵的代价，然后再加上A&lt;i...k&gt;,A&lt;k+1...j&gt;两者相乘的代价。</span>
    </div>
    <div style="line-height:35px">
        <span style="font-size:18px"><strong>步骤二：一个递归解决方案</strong></span>
    </div>
    <div style="line-height:35px">
        <span style="font-size:18px">我们假设：</span>
    </div>
    <div style="line-height:35px">
        <span style="font-size:18px">m[i...j]为矩阵链A&lt;i...j&gt;的标量乘法次数的最小值，那么矩阵链A&lt;1...j&gt;的标量乘法次数为m[1...j]</span>
    </div>
    <div style="line-height:35px">
        <span style="font-size:18px">ri为矩阵Ai的行数，ci为矩阵Ai的列数，那么A1&lt;50,500&gt; r1 = 50,c1=500</span>
    </div>
    <div style="line-height:35px">
        <span style="font-size:18px"><br />
        </span>
    </div>
    <div style="line-height:35px">
        <span style="font-size:18px">于是:</span>
    </div>
    <div style="line-height:35px">
        <span style="font-size:18px">当A&lt;i..j&gt;=Ai,即矩阵链里矩阵数量为1时，m[i...j]=0</span>
    </div>
    <div style="line-height:35px">
        <span style="font-size:18px">当j&gt;i时,首先计算两个子问题的最小乘法次数，分别是m[i...k]和m[k+1...j],然后加上A&lt;i...k&gt;乘上A&lt;k+1...j&gt;的乘法次数ri*ck*cj，有</span>
    </div>
    <div style="line-height:35px">
        <span style="font-size:18px">m[i...j]=m[i...k]+m[k+1...j]+<span style="font-family:'Comic Sans MS'; font-size:18px; line-height:35px">ri*ck*cj</span></span>
    </div>
    <div style="line-height:35px">
        <span style="font-size:18px"><span style="font-family:'Comic Sans MS'; font-size:18px; line-height:35px">上面的公式中k是已知的，但是在实际中我们是不知道的，于是K有[i...j)种选择，那么递归方程式有：</span></span>
    </div>
    <div>
        <ul>
            <li>
                <span style="font-size:18px; line-height:35px">m[i...j]=0，i=j</span>
            </li>
            <li>
                <span style="font-size:18px; line-height:35px">m[i...j]=min{ m[i,i]+m[i+1,j]+ri*ci*cj , m[i,i+1]+m[i+2,j]+ri*c(i+1)*cj , &nbsp;... , m[i,j-1]+m[j,j]+ri*c(j-1)*cj}</span>
            </li>
        </ul>
        <div>
            <span style="font-size:18px; line-height:35px">m[i,j]保存的是最小的相乘次数，我们用s[i,j]来保存在A&lt;i...j&gt;里面的括号的分割点</span>
        </div>
    </div>
    <div>
        <span style="font-size:18px; line-height:35px"><strong>步骤三：计算最优代价</strong></span>
    </div>
    <div>
        <span style="font-size:18px; line-height:35px">我们知道在矩阵A&lt;1..n&gt;中，矩阵的子问题数量为：<img src="" align="top" width="120" height="40" alt="" />，因为每个子问题都是在在1-n之间选择两个不相等的点i,j，即为<img src="" width="35" height="40" align="top" alt="" />，最后再加上i,j相等的情况n。而每一个子问题都是从A&lt;i...j&gt;里面选出一个k出来，有n种选择，所以，问题的规模=子问题的数量*子问题有多少种选择=O(n^2)*O(n)=O(n^3)</span>
    </div>
    <div>
        <span style="font-size:18px; line-height:35px"><br />
        </span>
    </div>
    <div>
        <span style="font-size:18px; line-height:35px">这里首先采用自上而下带备份的迭代方法实现：</span>
    </div>
    <div>
        <span style="font-size:18px; line-height:35px"></span>
        <pre name="code" class="cpp">#include &lt;utility&gt;
#include &lt;iostream&gt;
#include &lt;vector&gt;
#include &lt;limits.h&gt;

using namespace std;

#define MAXTRIX_CHAIN_LENGTH 3

unsigned int mulCost[MAXTRIX_CHAIN_LENGTH][MAXTRIX_CHAIN_LENGTH];
unsigned int dealMinCost(std::vector&lt;pair&lt;unsigned ,unsigned&gt; &gt; &amp; matrixChain ,\
                         unsigned left ,\
                         unsigned right);
/**
 * 求解最小花费
 * @param  matrixChain 矩阵链
 * @return             最小花费
 */
unsigned int getMinCost(std::vector&lt;pair&lt;unsigned , unsigned&gt; &gt; &amp; matrixChain)
{
    if(matrixChain.size() &lt;=1)
        return 0;
    dealMinCost(matrixChain ,0, matrixChain.size()-1);
    return mulCost[0][MAXTRIX_CHAIN_LENGTH-1];
}

unsigned int dealMinCost(std::vector&lt;pair&lt;unsigned ,unsigned&gt; &gt; &amp; matrixChain ,\
                         unsigned left ,\
                         unsigned right)
{
    if(left &gt;= right)
        return 0;
    if(mulCost[left][right]!=0)//如果之前算过，那么就直接返回之前的结果
        return mulCost[left][right];
    unsigned int min = UINT_MAX;
    for (int i = left; i &lt; right; ++i)
    {
        unsigned int temp = dealMinCost(matrixChain ,left,i)+\
                            dealMinCost(matrixChain , i+1, right)+\
                            matrixChain[left].first*matrixChain[i].second*matrixChain[right].second;
        if(min &gt; temp)
            min = temp;
    }
    mulCost[left][right] = min;
    return min;
}


int main(int argc, char const *argv[])
{
    vector&lt;pair&lt;unsigned int , unsigned int&gt; &gt; matrixChain;
    matrixChain.push_back(pair&lt;unsigned int ,unsigned int&gt;(10,100));
    matrixChain.push_back(pair&lt;unsigned int ,unsigned int&gt;(100,5));
    matrixChain.push_back(pair&lt;unsigned int ,unsigned int&gt;(5,50));

    cout&lt;&lt;&quot;the min cost is:&quot;&lt;&lt;getMinCost(matrixChain)&lt;&lt;endl;
    return 0;
}
</pre>
        <div>
            <span style="font-size:18px; line-height:35px"><br />
            </span>
        </div>
        下面这个方法是自下而上的算法：
    </div>
    <div>
        <span style="font-size:18px; line-height:35px"></span>
        <pre name="code" class="cpp">#include &lt;utility&gt;
#include &lt;iostream&gt;
#include &lt;vector&gt;
#include &lt;limits.h&gt;

using namespace std;

#define MAXTRIX_CHAIN_LENGTH 3

unsigned int mulCost[MAXTRIX_CHAIN_LENGTH][MAXTRIX_CHAIN_LENGTH];
unsigned int dealMinCost(std::vector&lt;pair&lt;unsigned ,unsigned&gt; &gt; &amp; matrixChain ,\
                         unsigned left ,\
                         unsigned right);
/**
 * 求解最小花费
 * @param  matrixChain 矩阵链
 * @return             最小花费
 */
unsigned int getMinCost(std::vector&lt;pair&lt;unsigned , unsigned&gt; &gt; &amp; matrixChain)
{
    if(matrixChain.size() &lt;=1)
        return 0;
    dealMinCost(matrixChain ,0, matrixChain.size()-1);
    return mulCost[0][MAXTRIX_CHAIN_LENGTH-1];
}


unsigned int dealMinCost(std::vector&lt;pair&lt;unsigned ,unsigned&gt; &gt; &amp; matrixChain ,\
                         unsigned left ,\
                         unsigned right)
{
    for (int n = 0; n &lt; right-left+1  ; ++n)
    {
        int i,j;
        for (i = left , j = left+n ; i &lt;= right-n &amp;&amp; j &lt;= right ; ++i , ++j)
        {
            if(i == j)
            {
                mulCost[i][j] = 0;
                continue;
            }
            unsigned int min = UINT_MAX;
            for (int k = i; k &lt; j; ++k)
            {
                unsigned int temp = mulCost[i][k]+mulCost[k+1][j]+\
                                    matrixChain[i].first*matrixChain[k].second*matrixChain[j].second;
                if(min &gt; temp)
                    min = temp;
            }
            mulCost[i][j] = min;
        }
    }
}


int main(int argc, char const *argv[])
{
    vector&lt;pair&lt;unsigned int , unsigned int&gt; &gt; matrixChain;
    matrixChain.push_back(pair&lt;unsigned int ,unsigned int&gt;(10,100));
    matrixChain.push_back(pair&lt;unsigned int ,unsigned int&gt;(100,5));
    matrixChain.push_back(pair&lt;unsigned int ,unsigned int&gt;(5,50));

    cout&lt;&lt;&quot;the min cost is:&quot;&lt;&lt;getMinCost(matrixChain)&lt;&lt;endl;
    return 0;
}
</pre>
        <strong>步骤四：构造最优解</strong>
    </div>
    <div>
        <span style="font-size:18px; line-height:35px">在A&lt;i...j&gt;中，我们需要对A&lt;i...j&gt;进行一次划分，以得到最优解，所以我们只需记录A&lt;i...j&gt;的划分点k即可，所以代码如下：</span>
    </div>
    <div>
        <span style="font-size:18px; line-height:35px">其中solution[i][j]就是用来保存A&lt;i...j&gt;的划分点k的，printSolution是用来递归打印解决方案的函数</span>
    </div>
    <div>
        <span style="font-size:18px; line-height:35px"></span>
        <pre name="code" class="cpp">#include &lt;utility&gt;
#include &lt;iostream&gt;
#include &lt;vector&gt;
#include &lt;limits.h&gt;

using namespace std;

#define MAXTRIX_CHAIN_LENGTH 6

unsigned int mulCost[MAXTRIX_CHAIN_LENGTH][MAXTRIX_CHAIN_LENGTH];
unsigned int solution[MAXTRIX_CHAIN_LENGTH][MAXTRIX_CHAIN_LENGTH];
unsigned int dealMinCost(std::vector&lt;pair&lt;unsigned ,unsigned&gt; &gt; &amp; matrixChain ,\
                         unsigned left ,\
                         unsigned right);
/**
 * 求解最小花费
 * @param  matrixChain 矩阵链
 * @return             最小花费
 */
unsigned int getMinCost(std::vector&lt;pair&lt;unsigned , unsigned&gt; &gt; &amp; matrixChain)
{
    if(matrixChain.size() &lt;=1)
        return 0;
    dealMinCost(matrixChain ,0, matrixChain.size()-1);
    return mulCost[0][MAXTRIX_CHAIN_LENGTH-1];
}


unsigned int dealMinCost(std::vector&lt;pair&lt;unsigned ,unsigned&gt; &gt; &amp; matrixChain ,\
                         unsigned left ,\
                         unsigned right)
{
    for (int n = 0; n &lt; right-left+1  ; ++n)
    {
        int i,j;
        for (i = left , j = left+n ; i &lt;= right-n &amp;&amp; j &lt;= right ; ++i , ++j)
        {
            if(i == j)
            {
                mulCost[i][j] = 0;
                continue;
            }
            unsigned int min = UINT_MAX;
            unsigned int pos;
            for (int k = i; k &lt; j; ++k)
            {
                unsigned int temp = mulCost[i][k]+mulCost[k+1][j]+\
                                    matrixChain[i].first*matrixChain[k].second*matrixChain[j].second;
                if(min &gt; temp)
                {
                    min = temp;
                    pos = k;
                }
            }
            mulCost[i][j] = min;
            solution[i][j] = pos;
        }
    }
}


void printSolution(int left , int right)
{
    if(left+2 &gt; right)
        return;
    cout&lt;&lt;&quot;from &quot;&lt;&lt;left&lt;&lt;&quot; to &quot;&lt;&lt;right&lt;&lt;&quot; the bracket pos is &quot;&lt;&lt;solution[left][right]&lt;&lt;endl;
    printSolution(left,solution[left][right]);
    printSolution(solution[left][right]+1,right);
}

int main(int argc, char const *argv[])
{
    vector&lt;pair&lt;unsigned int , unsigned int&gt; &gt; matrixChain;
    matrixChain.push_back(pair&lt;unsigned int ,unsigned int&gt;(30,35));
    matrixChain.push_back(pair&lt;unsigned int ,unsigned int&gt;(35,15));
    matrixChain.push_back(pair&lt;unsigned int ,unsigned int&gt;(15,5));
    matrixChain.push_back(pair&lt;unsigned int ,unsigned int&gt;(5,10));
    matrixChain.push_back(pair&lt;unsigned int ,unsigned int&gt;(10,20));
    matrixChain.push_back(pair&lt;unsigned int ,unsigned int&gt;(20,25));

    cout&lt;&lt;&quot;the min cost is:&quot;&lt;&lt;getMinCost(matrixChain)&lt;&lt;endl;
    printSolution(0,MAXTRIX_CHAIN_LENGTH-1);
    while(1);
    return 0;
}</pre>
        <br />
        <br />
        
    </div>
    <div>
        <span style="font-size:18px; line-height:35px"><br />
        <br />
        <br />
        </span>
    </div>
    <div>
        <span style="font-size:18px; line-height:35px"><br />
        <br />
        </span>
    </div>
    <div style="font-size:15px; font-family:'microsoft yahei'; line-height:35px">
        <br />
        
    </div>
    <br />
    
</div>
<div>
    <span style="font-family:Comic Sans MS; font-size:18px"><br />
    </span>
</div>