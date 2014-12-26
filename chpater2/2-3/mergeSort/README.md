<h1>
    带哨兵的归并排序
</h1>
<div>
    <span style="font-size:18px">在引入归并排序之前，先简单介绍分治法，因为归并排序的主要思想就是分治</span>
</div>
<h2>
    <span style="font-size:18px">1.分治法</span>
</h2>
<div>
    <span style="font-size:18px">许多有用的算法结构都是递归的，为了解决一个问题，递归的调用其自身来解决该问题的分裂成的若干个子问题。</span>
</div>
<div>
    <span style="font-size:18px">分治法的主要思想就是：将原问题分解成若干个类似的，具有相同性质的子问题，然后递归的求解这些子问题，直到一个返回条件不再递归的调用自身，最后自下而上的将子问题的解合并起来，构成原问题的解，我们这里的归并排序就是基于此核心思想的</span>
</div>
<div>
    <span style="font-size:18px"><br />
    </span>
</div>
<div>
    <span style="font-size:18px">分治在每层递归都有三个步骤：</span>
</div>
<div>
    <ol>
        <li>
            <span style="font-size:18px"><strong>分解</strong>原问题为若干个相似的子问题，这些子问题是原问题的较小规模的实例</span>
        </li>
        <li>
            <span style="font-size:18px"><strong>解决</strong>这些子问题，递归的求解这些子问题，直到到较小规模的子问题，直接解决</span>
        </li>
        <li>
            <span style="font-size:18px"><strong>合并</strong>子问题的解成原问题的解</span>
        </li>
    </ol>
    <h2>
        <span style="font-size:18px">2.归并排序</span>
    </h2>
</div>
<div>
    <span style="font-size:18px">上面介绍的解决分治问题的思想用在这里的归并排序上：</span>
</div>
<div>
    <ol>
        <li>
            <span style="font-size:18px"><strong>分解</strong>输入的具有n个元素的序列，然后将该序列分解成两个n/2大小的子序列</span>
        </li>
        <li>
            <span style="font-size:18px"><span style="font-size:18px"><strong>递归</strong>的求解两个大小为n/2的子序列，直到遇到不能再分成子序列(只有一个元素的时候)，就不再递归调用，而是直接求解，因为只有一个元素的时候，那么这个序列一定是有序的</span></span>
        </li>
        <li>
            <span style="font-size:18px"><strong>归并</strong>各个阶段的子问题的解，最后构成原问题的解</span>
        </li>
    </ol>
    <div>
        <span style="font-size:18px">比如现在有一个数组:{10,6,9,3,1,8,2,5,4,7},，现在需要将该数组分解成两个子数组:{1<span style="font-size:18px">0,6,9,3,1</span>}和{<span style="font-size:18px">8,2,5,4,7</span>}，然后再将这个两个子数组分解成对应的子数组:{10,6,9},{3,1}和{8,2,5}和{4,7}，以此类推，直到子数组只剩下一个元素</span>
    </div>
</div>
<div>
    <span style="font-size:18px"><br />
    </span>
</div>
<div>
    <span style="font-size:18px"><img src="http://img.blog.csdn.net/20141226173005073?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvaWkxMjQ1NzEyNTY0/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center" alt="" /><br />
    </span>
</div>
<div>
    <br />
    
</div>
<div>
    <span style="font-size:18px">当只有一个元素的时候，那么就开始自下而上的将子问题归并(此处按照升序来实现)</span>
</div>
<div>
    <span style="font-size:18px">比如</span>
</div>
<div>
    <span style="font-size:18px"><img src="http://img.blog.csdn.net/20141226173453906?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvaWkxMjQ1NzEyNTY0/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center" alt="" /></span>
</div>
<div>
    <span style="font-size:18px">这个分解到最终的子序列，那么就将{10},{6},将10和6进行相比较，发现6明显小于10，就将6放在10的前面，于是就得到了</span>
</div>
<div>
    <img src="http://img.blog.csdn.net/20141226174127746?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvaWkxMjQ1NzEyNTY0/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center" alt="" style="font-size:18px" />
</div>
<div>
    <span style="font-size:18px">注意下载这里的子数组{6,10}<strong><em>已经有序</em></strong>，那么再将上一个子问题得到的解array1={6,10}与array2={9}进行归并，分别去除array1和array2的第一个元素，发现{6}小于{9}，那么就将array1的第一个元素取出来放在一个新的数组里面temp={6}，再次去除array1和array2的第一个元素比较，发现{10}大于{9}，那么就将{9}放入temp里面得到{6,9}，最后将10放入temp里面得到一个<strong><em>有序的</em></strong>子序列{6,9,10}</span>
</div>
<div>
    <span style="font-size:18px"><img src="http://img.blog.csdn.net/20141226175420056?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvaWkxMjQ1NzEyNTY0/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center" alt="" /></span>
</div>
<div>
    <span style="font-size:18px"><br />
    </span>
</div>
<div>
    <span style="font-size:18px">我们发现，归并此子问题都是基于上一个子问题的解已经有序的基础上面进行的，因为每次都需要将第一个元素拿出来比较，第一个元素也就是序列里面最小的那个元素，通过将所有子问题进行归并求解得到：</span>
</div>
<div>
    <span style="font-size:18px"><img src="http://img.blog.csdn.net/20141226175729468?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvaWkxMjQ1NzEyNTY0/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center" alt="" /><br />
    </span>
</div>
<div>
    <span style="font-size:18px"><br />
    </span>
</div>
<div>
    <span style="font-size:18px">代码实现如下：</span>
</div>
<div>
    <span style="font-size:18px"><br />
    </span>
</div>
<div>
    <br />
    
</div>
<div>
    <span style="font-size:18px"></span>
    <pre code_snippet_id="563693" snippet_file_name="blog_20141226_1_2849988" name="code" class="cpp">#include &lt;stdio.h&gt;
#include &lt;limits.h&gt;
#include &lt;stdlib.h&gt;

//归并排序的核心操作
//输入一个子数组，具有左边界left以及右边界right
void MERGE(int subArray[],const int left, const int right)
    if(left &gt;= right)
        return;
    int center = (left+right)/2;
    MERGE(subArray,left,center);
    MERGE(subArray,center+1,right);
    //创建两个子数组
    int leftArrayLength = center-left+2;
    int rightArrayLength = right-center+1;
    int leftSubArray[leftArrayLength];//这里需要添加一个无穷大的哨兵，避免每次的边界检测
    int rightSubArray[rightArrayLength];
    int i,j;
    int k;
/*  printf(&quot;%d+++%d\n&quot;,leftArrayLength,rightArrayLength );
    printf(&quot;%s+++++++center:%d++++left:%d+++++right:%d+++\n&quot;,&quot;left&quot;,center,left,right );
*/  for(i=0;i&lt;leftArrayLength-1;++i)
    {
        leftSubArray[i]=subArray[i+left];
    }
/*  printf(&quot;\n&quot;);
    printf(&quot;%s+++++++center:%d++++left:%d+++++right:%d+++\n&quot;,&quot;right&quot;,center,left,right );
*/  for(j=0;j&lt;rightArrayLength-1;++j)
    {
        rightSubArray[j]=subArray[j+center+1];
    }
    leftSubArray[leftArrayLength-1]=INT_MAX;//哨兵
    rightSubArray[rightArrayLength-1]=INT_MAX;

    //开始归并,依次取出最小的放入到目标数组里面
    i=0;
    j=0;
    for(k=left;k&lt;=right;++k)
    {
        if(leftSubArray[i] &gt;= rightSubArray[j])
        {
            subArray[k]=rightSubArray[j];
            ++j;
        }
        else
        {
            subArray[k]=leftSubArray[i];
            ++i;
        }
    }
}


void mergeSort(int inputArray[] ,const int arrayLength)
{
    MERGE(inputArray,0,arrayLength-1);
}



int main(int argc, char const *argv[])
{
    int i=0;
    int array[]={10,6,9,3,1,8,2,5,4,7}; 
    mergeSort(array,sizeof(array)/sizeof(int));
    for(i=0;i&lt;sizeof(array)/sizeof(int);++i)
    {
        printf(&quot;%d\t&quot;,array[i]);
    }
    printf(&quot;\n&quot;);
    return 0;
}</pre>
    <div>
        <br />
        
    </div>
    <span style="font-size:18px">最后得到排序的结果：</span>
</div>
<div>
    <img src="http://img.blog.csdn.net/20141226183042672?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvaWkxMjQ1NzEyNTY0/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center" alt="" />
</div>
<div>
    <br />
    
</div>
<div>
    <span style="font-size:18px">算法效率分析：</span>
</div>
<div>
    <span style="font-size:18px">可知这里采用二分法来实现的,所以对应的输入规模为n排序所需的单位时间为：T(n)=2T(n/2)+D(n)+C(n)</span>
</div>
<div>
    <ul>
        <li>
            <span style="font-size:18px">D(n)是拆分成子问题的消耗，因为这里是指定出子序列的左右边界来拆分的，所以只需要常数时间量Theta(1)</span>
        </li>
        <li>
            <span style="font-size:18px">C(n)是将子问题归并的消耗，因为没实现一层的归并，那么就需要操作n个数，C(n)基本为cn(c为一常数)，记做Theta(n)</span>
        </li>
        <li>
            <span style="font-size:18px">2T(n/2)就是讲规模为n的问题划分为两个子问题所需要的消耗</span>
        </li>
    </ul>
    <div>
        <span style="font-size:18px">那么知道:</span>
    </div>
    <div>
        <ul>
            <li>
                <span style="font-size:18px">T(n)=Theta(1),n=1</span>
            </li>
            <li>
                <span style="font-size:18px">T(n)=2T(n/2)+cn,n&gt;1</span>
            </li>
        </ul>
        <div>
            <span style="font-size:18px">&nbsp; &nbsp; &nbsp;求解上面的方程可知归并排序的时间复杂度为：Theta(nlogn)</span>
        </div>
    </div>
</div>
<div>
    <span style="font-size:18px"><br />
    </span>
</div>
<div>
    <br />
    <br />
    
</div>