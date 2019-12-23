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
不考虑负数时，遍历：
cmax = max(cmax, nums[i])
//遇到0时，cmax将会更新为0后的第一个数字\n
cmin = min(cmin, nums[i])
globalmax = max(globalmax, cmax)

考虑负数情况时，当前最大值\*负数=当前最小值，当前最小值\*负数=当前最大值，因此要交换当前最大最小值。
为什么不在计算乘法之后交换，因为cmax和cmin的赋值有一个比较的过程，先计算在比较其实是当前最大值和上一次最小值在比较，因此不可取。
