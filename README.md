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

