# 142.环形链表2
设置两个指针，前指针和后指针，前指针每次走两步，后指针每次走一步。如果前指针无法继续行进则证明无环。

设前指针走的步数为a，后指针走的步数为b，则有a=2b。

设链表总长度为两部分，x+y，x为到达环入口之前的节点个数，y为环内的节点个数。

* （1）两节点相遇时，他们所走的步数差为ny，即是n倍环内节点个数，那么有a-b=ny，与上式结合有a=2ny，b=ny，即他们的步数差为环长度的n倍，此时我们需要知道
环的入口节点。
* （2）观察可知，慢节点当前走的步数为环长度的n倍，在走x步，即总步数为a+nb时，慢节点可以再次到达环入口，那么我们只需要知道a的长度，将快节点重新置为头结
点，两节点同时以1为步长前进，再次相遇时，慢节点的总步数将为a+nb，此时慢节点即是环入口位置。
