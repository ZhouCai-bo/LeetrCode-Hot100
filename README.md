<a href="#142-253">`142-253题`</a>
<a href="#279-"   >`279-   题`</a>
<a id="142-253"/>
# 1.两数之和
暴力求解或者用map容器空间换时间都可以，题解中使用一次迭代的想法很精妙。

# 2.两数之和
设置一个链表存储每位相加之和，注意进位，注意两链表都结束之后若进位为1，则要添加一个节点。<br/>
我的做法是直接在原链表上进行相加，直到其中一个链表结束之后，只更新剩余的那个链表，本来想节省空间，但实际效果不好，反而降低了速度。

# 3. 无重复字符的最长子串 DP实现
* 参数设置：设res[i]表示从s[0]至s[i]之间的最长子串；map<char,int>存储当前最长子串中各字符的索引，max表示最长子串的长度。
* 转移方程：若s[i]在之前的子串中未出现，则res[i]=res[i-1]+1；若s[i]出现过，则res[i]=i-map[s[i]]。
* 参数更新：若s[i]在之前的子串中未出现，更新max，并插入当前键值至map；若s[i]出现过，则新的长度必小于当前最长长度，不用更新max，同时还要更新map，删除重复节点以及之前的所有键值，并插入当前键值。

# 3. 无重复字符的最长子串 滑动窗口实现
right不断向后遍历，遇到重复字符则使left不断后移直至超过重复字符的位置。同时设置一个set保存当前最长子串的字符集合。

# 4. 寻找两个有序数组的中位数 
看到时间复杂度要求想到了二分法，但没想到怎么分的。。。就很难。。。题解的这个转化为偶数个元素的方法也很奇妙。<br/>
https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/

# 5. 最长回文子串
朴素方法，遍历每个元素，以每个元素为中心向左右扩散找最长子串。<br/>
参数设置：med遍历数组的索引，max保存当前最长子串的长度，mL和mR保存当前最长子串的左右索引；cur保存当前子串的长度，L和R不断扩散寻常当前子串的最大左右索引。<br/>
优化：遍历到某个元素有右边有相同元素时，将相同元素加入当前子串，并且不再遍历（跳过相同元素）。

# 10. 正则表达式匹配
好难...<br/>
https://leetcode-cn.com/problems/regular-expression-matching/solution/dong-tai-gui-hua-zen-yao-cong-0kai-shi-si-kao-da-b/

# 11. 盛最多水的容器
朴素解法，双层循环遍历，同时做一个剪枝：第一层循环由左至右，到第二层循环由右至左，等于是遍历的容器左右索引是向里缩进的，那么如果下一次遍历的左或右边界的高度小于其左侧或右侧的任意高度，则本次遍历的容器容积必定小于全局最大，continue即可。

# 11. 盛最多水的容器 双指针实现
在朴素解法的基础上可以得到这个双指针解法，两边同时向内收缩寻找更高的容器壁，找到合适位置计算更新max值之后，最小边收缩，并作下一次判断。

# 15.三数之和
主要问题在消除重复以及降低时间复杂度，朴素解法三层循环的时间复杂度高达O(n*n*n)，先对数组进行排序，然后使用双指针的方式把其中两层循环缩减为一层循环，同时略去重复的答案。

# 17. 电话号码的字母组合
递归回溯遍历所有可能。

# 19. 删除链表的倒数第N个节点
数组转存，分情况考虑链接节点。

# 19. 删除链表的倒数第N个节点 双指针实现
设置快慢两个指针，快指针先走，直至快慢指针相隔n个节点时，快慢指针同步前进，直至快指针的下一节点为nullptr，此时慢指针的下一节点即为但删除节点。
为了方便删除头结点的情况不用另外考虑，设置一个超头节点，快慢指针均从超头开始，最后返回超头节点的下一节点。

# 142.环形链表2
设置两个指针，前指针和后指针，前指针每次走两步，后指针每次走一步。如果前指针无法继续行进则证明无环。

设前指针走的步数为a，后指针走的步数为b，则有a=2b。

设链表总长度为两部分，x+y，x为到达环入口之前的节点个数，y为环内的节点个数。

* （1）两节点相遇时，他们所走的步数差为ny，即是n倍环内节点个数，那么有a-b=ny，与上式结合有a=2ny，b=ny，即他们的步数差为环长度的n倍，此时我们需要知道
环的入口节点。
* （2）观察可知，慢节点当前走的步数为环长度的n倍，在走x步，即总步数为a+nb时，慢节点可以再次到达环入口，那么我们只需要知道a的长度，将快节点重新置为头结
点，两节点同时以1为步长前进，再次相遇时，慢节点的总步数将为a+nb，此时慢节点即是环入口位置。

# 146.LRU缓存机制
使用数据结构：list双链表存储键对值信息，以及最近最久未使用的替换顺序。map表，存储int->pair的映射，作为快速检索的工具。
* get（）函数：在map中寻找索引，无则返回-1，有则返回键值，同时将访问到的节点置于list首位。
* put（）函数：先检索将要插入的节点是否在list中，在则将其置于list首位，不在则寻找空位，无空位则释放list中的最后一个节点，然后插入。

# 148.排序链表
这道题作出来有点侥幸。。。题目要求时间复杂度为O(nlogn)，我使用的方法类似于选择排序，其时间复杂度为O(n^2)

# 148.排序链表 归并排序实现
* 使用快慢指针找到链表的中点，分割链表进行归并排序
* 自底向上合并

# 152.乘积最大子序列
采用动态规划的方法设置全局最大值和当前最大值。
不考虑负数时，遍历：<br/>
cmax = max(cmax, nums[i])<br/>
//遇到0时，cmax将会更新为0后的第一个数字\n<br/>
cmin = min(cmin, nums[i])<br/>
globalmax = max(globalmax, cmax)

考虑负数情况时，当前最大值\*负数=当前最小值，当前最小值\*负数=当前最大值，因此要交换当前最大最小值。<br/>
为什么不在计算乘法之后交换，因为cmax和cmin的赋值有一个比较的过程，先计算在比较其实是当前最大值和上一次最小值在比较，因此不可取。

# 155.最小栈
因为寻找最小值需要遍历，所以选择链表作为主要数据结构。<br/>
因为要返回最小值，如果在每次需要的时候遍历寻找则会花费较多时间，因此采用保存全局最小值的策略。<br/>
在push的时候判断当前插入值是否小于全局最小值，更新全局最小值。<br/>
在pop的时候判断当前出栈值是否是最小值，若是，则更新全局最小值。

# 155.最小栈  双栈实现
使用一个数据栈，一个辅助栈的方式完成。<br/>
辅助栈中存放的其实是第n各元素之前的最小值，进行优化后，将相同的最小值只存一次。<br/>
在push操作的判断条件是'mins.top() <= x'，是因为如果进栈了两次当前最小值，那么在出栈判断时也应该相应的出栈两次，那么如果mins栈只存一次该最小值的话势必会出现问题。

# 160.相交链表
时间击败了85%的题解  空间击败了9%的题解。。。可以说是空间换时间的绝佳尝试了。。。<br/>
一开始的思路是遍历，找到相同的节点后，再向后遍历（这里可能理解错题目了，是相同的节点，不是相同的值得节点，好像直接找到相同的节点就直接可以输出了？）<br/>
然后想到如果从后往前遍历的话更简单，但是单链表无法从后往前遍历，于是想到了使用栈，考虑到两个链表有一个为空、都为空、都只有一个节点等问题，写出了这个题解，感觉有些地方多此一举了。。。

# 169.多数元素
算是一种暴力解法吧，记录每种元素的数量，然后找到众数。<br/>
可以直接采用双重循环的方式遍历，但这样的时间复杂度过高，因此选择了map容器，也算是练习使用map。

# 198.打家劫舍
看到题目的第一反应是找到规律，一开始想到结果必是偶数项之和与奇数项之和的最大值，然后发现自己忽略了[2,1,1,2]类似的情况。<br/>
然后想到这类题目应该是动态规划，但奈何找不到状态转移方程，看了题解之后才恍然大悟，惭愧惭愧。。。<br/>
其实题解已经很详细了，就是遇到下一个房子时，我们选择抢，或者不抢：<br/>
* 抢，则意味着这间房子的前一间不能进入，则有max = 倒数第二间之前max + 当前房间值
* 不抢，则以为这当前最大值 max = 倒数第一间之前max

二者取更大的值，则可计算得到当前房间之前的最大值。

# 200.岛屿数量
大致思路是在遍历到1之后找到岛屿的边界，再继续遍历。<br/>
一开始想到使用一个visited数组来保存是否访问过的情况，后来看到题解，只要把访问过的点置0即可。<br/>
这道题也是复习了深度优先和广度优先遍历算法的实现。

# 206.翻转链表
一开始用栈做了一下，发现超时了。。。<br/>
然后想到类似于动态规划的方式遍历，这不是迭代吗。。。<br/>
我同时保存了三个指针，有点费空间，不过大体思路和其他题解一样，保存当前节点和后两个节点，更改下一节点的next指向，同时要保存下下节点。

# 207.课程表 拓扑排序实现
记录节点入度，将入度为0的节点放入队列，对队列进行遍历，每次将front节点的出度节点的入度减一，若得到一个入度为0的新节点，则将其放入队列，继续 遍历，直至队列为空。<br/>
那么当队列为空时，有两种情况，要么所有节点都已遍历，要么有部分节点形成了环，设置一整型数记录遍历过的节点数量，比较后输出。（直接递减numCourse也可以）

# 207.课程表 DFS寻找环
分析题目后可知，若图中存在环，则课程必不能全部学习完，因此采取dfs寻找图中的环。<br/>
设置一个状态数组，记录各节点的访问现状，0表示此节点未访问，-1表示从此节点开始无环，1表示此节点已访问。<br/>
遍历过程中：
* 遍历到-1节点，则直接返回true，因为从此节点出发无环且已经遍历过此节点；
* 遍历到1节点，则说明dfs又回到了本次遍历已经过的节点，则表示有环，返回false；
* 遍历到0节点，则表示此节点未遍历，则进入递归下一层dfs。

若完成从任意遍历均未返回false，则表示改图无环，返回true，否则返回false。

# 208.实现前缀树Trie
这道题的关键我觉得是找到合适的数据结构，前缀树不太熟悉导致我开始做的时候用了二叉树，看到解答错误的测试用例才明白是树。<br/>
然后想到应该用数组做，想来想去没找到存储数据的方法，最后看了博客才知道该怎么存数据。<br/>
二维数组tr保存节点信息，初始化为0，对于节点tr[i][j]=x,若x==0，则表示节点i没有通过表示字符j的边连接的节点，若x!=0,则表示节点i通过表示字符j的边连接到节点x。<br/>
由于数组索引无法使用char类型，所以用map表将字符a-z与0-25一一对应。<br/>
最后在使用数组tag表示节点是否是终结点。<br/>
本来想用vector，但是leetcode编译"vector<vector<int>> tr(100000,vector<int>(26,0))"报错，原因未知。

# 215.数组中第k个最大元素
首先想到了一种很朴素的解决方法，直接排序，然后返回下标。<br/>
然后就先找到一种速度较快的排序方法，想到归并排序，快速而且稳定。<br/>
然后就写了一边数组的归并排序，想了半天数据结构。。。<br/>
看了题解发现使用最小堆解决，但我对堆是在不了解。。。希望在了解堆之后再来重写这道题。

# 221.最大正方形
看到这道题的第一反应是和200.岛屿数量好像，下意识就想到用BFS，然后写了一百行跑完，内存和时间都只在前5%。。。<br/>
具体想法是找到正方形的左上节点，从该节点出发，存储围绕节点的右边和左边节点入队列，若队列长度满足3，则验证队列中节点的所有右边和下边节点是否是1，是的话则入队列，如此反复，直至到达边界或者队列长度不满足条件。<br/>
由于直接遍历会导致某些节点重复入队列，所以创建了一个散列表做访问控制。

# 221.最大正方形 DP实现
观察可知规律：以matrix[i][j] = 1为右下角节点的最大正方形的边长为其上、下、左上节点为右下节点的最大正方形的边长+1。<br/>
则设以二维数组v，v[i][j]表示该节点为右下角节点的最大正方形的边长。<br/>
可知数组v的第一行与第一列与matrix相同。

# 226.翻转二叉树
这道题没什么好说的，遍历二叉树，交换其左右子树即可。

# 234.回文链表
本能的想到用栈转存，然后再次遍历链表并和出栈元素意义对比，那么既然需要转存的话，不如直接用数组方便，所以最后选择用数组转存，再用双指针的思想，做回文判断。

# 234.回文链表 递归实现
递归的一大特点就是从后往前处理，这正和我们要做的判别工作线能够符合，于是想到使用递归，为此我们要保存链表头指针和一个不断深入递归的指针。

# 236.二叉树的最近公共祖先
啊，这美妙的递归。<br/>
其实看到这道题就想到要找个方法自底向上遍历，先是想到用栈保存一个节点的全部祖先，在找到距栈顶最近的同是另一个节点的祖先的元素。<br/>
然后想到用递归，先找到一个节点之后开始回溯，每回溯一步都检查当前节点是否是另一节点的祖先，但我写的递归是在太笨重，拿不出手，看到题解后，采用官方的递归策略。<br/>
官方的第二种策略直接使用散列表在遍历的时候存储父节点，也是精妙。<br/>
下面直接复制了一段题解：<br/>

首先分析公共祖先一共可以分为以下三种情况：<br/>
* 如果一个节点的左右都能达到终点，那么当前节点一定是公共祖先。
* 如果当前节点左树可以找到一个值，当前节点值等于另一个值，那么祖先也就是当前值。
* 如果当前节点右树可以找到一个值，当前节点值等于另一个值，那么祖先也一定就是当前值。

这三种情况用代码表示就是:
* left=1，right=1，mid=0
* left=1，right=0，mid=1
* left=0，right=2，mid=1

作者：charlotte-28
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/guan-fang-di-gui-da-an-ti-jie-yi-dong-by-charlotte/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

# 238.除自身外数组元素的乘积
这几天递归写的有点多，看到先想递归。<br/>
大体思路是递归阶段不断向下传前面元素的乘积，然后回溯阶段不断返回后面元素的乘积，前后相乘得到当前元素的除自身外数组的乘积。<br/>
就是空间复杂度有点高？

# 239.滑动窗口最大值 动态规划实现
先初始化局部最大值索引maxIndex和输出数组res，然后从第k个元素开始遍历：
* 若新元素大于局部最大值，则更新局部最大值索引，并且更新输出数组；
* 若新元素小于局部最大值且局部最大值离开滑动窗口，则调用函数寻找新的局部最大值索引，更新局部最大值索引以及输出数组；
* 其他情况，更新输出数组追加一个等于前一个局部最大值索引的元素。

# 239.滑动窗口最大值 双向队列实现
使用一个双向队列，队头是当前窗口的最大值，当队头元素因为离开窗口或者更大元素进队列时出队列，则对头元素将被更新。<br/>
初始化前k个元素，然后从第k+1各元素开始遍历：
* 若队头元素离开窗口，则执行pop_front；
* 更新队尾，将队尾所有小于向前元素的元素出队列，因为他们必不会成为某一刻的最大值；
* 当前元素进队列；
* 在结果数组res追加一个等于队头元素的新元素。

# 240.搜索二维矩阵II
通过对角线元素分割数组，缩小遍历范围。<br/>
通过对角线找到第一个大于target的元素，该元素左上矩阵比target小，右下元素比target大，则只需遍历剩余数组。

# 240.搜索二维数组II 伪动态规划实现
从左下节点或者右上节点出发（这里选择右上节点），从右向左，从上至下遍历：
* matrix[i][j]==target
返回true；
* matrix[i][j]<target
说明这一行剩余元素都小于target，且右边矩阵的元素都大于target，则进入下一行的同一列；
* matrix[i][j]>target
说明该元素还有可能出现在本行的剩余元素中，继续向左遍历；
* 若抵达数组界限，则说明无目标元素，返回false。

<a id="279-"/>
# 279.完全平方数 BFS实现
每一层的新入队列节点都是其父节点减去一个不大于它的平方数的差，逐层遍历，直至某层的节点值为0，则说明找到了最短路径，同时为了避免重复遍历，设置一个备忘录数组，数组存储已经访问过的值val，访问过的值不再次生成新的节点，因为即使这条路径的长度要么大于最短路径，要么等于最短路径。<br/>
第一次写BFS使用了逐层递归的做法，答案超时，然后按照题解的做法使用节点结构体，还是超时。

# 279.完全平方数 BFS实现
没想到这道题也可以BP，直接复制一段状态转移方程的推导：
* 假设最少个平方数m = ƒ(n) 
* 且n的值满足： ∑(A[i] * A[i]) = n ，A是满足题设的平方数根的最小数组
* 令 k 为数组A的最大值。 令  d + k * k = n ;  d >= 0; 
   *  注意：一定要是满足m最小的时候的k值,一味的取最大平方数,就是贪心算法了
* 则有 f(d) + f(k*k) = f(n);
* 显然 f(k*k) = 1; 则  f(d) + 1 = f(n); 因为 d = n - k*k;
* 则可以推出ƒ(n - k * k) + 1 = ƒ(n) ;  且 k * k <= n;

# 283.移动零
简单的双指针，有一点重构的思想，前指针指向将要插入的位置，后指针遍历寻找不为零的元素，并将该元素插入至前指针的位置，后指针到达边缘时，用零填补前指针后的所有元素。

# 287.重复数
没有注意到题目条件元素大小在1-n之间，想到排序和散列表，都被题目的要求否决，然后想到朴素的两层循环。。。
看到题解再知道用快慢指针求解，把题目抽象为找寻链表的环入口节点，复制一段题解：
算法流程：
* 双指针第一次相遇： 设两指针 fast，slow 指向链表头部 head，fast 每轮走 2 步，slow 每轮走 1 步；<br/>
第一种结果： fast 指针走过链表末端，说明链表无环，直接返回 null；<br/>
TIPS: 若有环，两指针一定会相遇。因为每走 1 轮，fast 与 slow 的间距 +1，fast 终会追上 slow；<br/>
第二种结果： 当fast == slow时， 两指针在环中 第一次相遇 。下面分析此时fast 与 slow走过的 步数关系 ：<br/>
设链表共有 a+b 个节点，其中链表头部到链表入口有 a 个节点（不计链表入口节点）， 链表环有 b 个节点（这里需要注意，a 和 b 是未知数）；设两指针分别走了 f，s 步，则有：fast 走的步数是slow步数的 2 倍，即 f = 2s；）<br/>
fast 比 slow多走了 n 个环的长度，即 f = s + nb；（ 解析： 双指针都走过 aa 步，然后在环内绕圈直到重合，重合时 fast 比 slow 多走环的长度整数倍 ）；<br/>
以上两式相减得：f = 2nb，s = nb，即fast和slow 指针分别走了 2n，n 个环的周长
* 目前情况分析：
如果让指针从链表头部一直向前走并统计步数k，那么所有走到链表入口节点时的步数 是：k=a+nb（先走 a 步到入口节点，之后每绕 1 圈环（ b 步）都会再次到入口节点）。<br/>
而目前，slow 指针走过的步数为 nb 步。因此，我们只要想办法让 slow 再走 aa 步停下来，就可以到环的入口。<br/>
但是我们不知道 a 的值。依然使用双指针法。我们构建一个指针，此指针需要有以下性质：此指针和slow 一起向前走 a 步后，两者在入口节点重合。那么从哪里走到入口节点需要 aa 步？答案是链表头部head。
* 双指针第二次相遇：
slow指针 位置不变 ，将fast指针重新指向链表头部节点；slow和fast同时每轮向前走 1 步；<br/>
TIPS：此时 f = 0，s = nb ；<br/>
当 fast 指针走到f = af=a 步时，slow 指针走到步s = a+nbs=a+nb，此时 两指针重合，并同时指向链表环入口 。<br/>
返回slow指针指向的节点。

作者：jyd
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

# 297. 二叉树的序列化与反序列化
思路是找到一种二叉树的遍历方式得到序列，根据序列的特点进行反序列化，这里我使用了层序遍历，题解里有其他遍历方法。<br/>
层序遍历得到的系列除过第一个字符为根节点外，其余节点两个一对是某个节点的左右子树，容易想到用一个队列存储不为空的节点，然后每次从序列中取两个元素作为队列头元素的左右子树的value，左右子树不为空时，说明他们可能右子树，则进队列。

# 300. 最长上升子序列
* DP求解
* 状态定义：res[i]，表示第i各元素及其后面元素的最大上升子序列；max表示最长上升子序列的长度。
* 转移方程：从后往前遍历，对于j∈[ i,nums.size() )，每轮计算res[i]时，遍历该区间：<br/>
1.若nums[j] > nums[i]，则元素nums[j]及之后元素的最长上升子序列'可以'接在nums[i]之后，则更新res[i]为res[j] + 1，同时更新max；<br/>
2.若nums[j] <= nums[i]，则元素nums[j]及之后元素的最长上升子序列'无法'接在nums[i]之后,继续遍历。
* 上述所有情况可以总结为res[i] = max(res[i] , res[j] + 1) for j in[i , nums.size())。
* 初始状态设置：res[i]所有元素置1，即最短每个元素单独最为一个序列，长度为1。
* 返回值：max

# 301. 删除无效的括号
找到一种遍历方法，遍历所有可能性，然后进行判断，这里采用了DFS剪枝的方法。<br/>
剪枝策略：rightcnt+1 < leftcnt

# 309. 最佳买卖股票时机含冷冻期 递归实现 超时
采用DFS遍历，剪枝策略：buyprice < prices[index]。<br/>
递归的深度太大导致超时。

# 309. 最佳买卖股票时机含冷冻期 DP实现 
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/dong-tai-gui-hua-shen-ru-fen-xi-by-wang-yan-19/

# 312.戳气球
https://leetcode-cn.com/problems/burst-balloons/solution/dui-fen-zhi-fa-ti-jie-de-jie-du-by-chuck-bass/

# 322.零钱兑换 分治法 超时
* 问题解为res[x]，将x分解为res[x]=res[i]+res[x-i]，x∈(0,i)。
* 回归条件：res[i]可由一枚硬币构成 || res[i]无法由硬币构成。
但是分治法还是需要大量的递归调用，因此超时。
