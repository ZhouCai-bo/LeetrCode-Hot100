class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		bool carry = 0;
		ListNode *ptr1 = l1;
		ListNode *ptr2 = l2;
		int tag = 1;
		while (1){
			//ptr1先结束 或者 同时结束
			if ((ptr1->next == nullptr && ptr2->next == nullptr) || ptr1->next == nullptr){
				ListNode *temp = ptr2;
				ptr2->val = isCarried(ptr1->val, ptr2->val, carry);
				stop(ptr2->next, temp, carry);
				return l2;
			}
			//ptr2先结束
			else if (ptr2->next == nullptr){
				ListNode *temp = ptr1;
				ptr1->val = isCarried(ptr1->val, ptr2->val, carry);
				stop(ptr1->next, temp, carry);
				return l1;
			}
			//均未结束
			else{
				ptr1->val = ptr2->val = isCarried(ptr1->val, ptr2->val, carry);
				ptr1 = ptr1->next;
				ptr2 = ptr2->next;
			}
		}
    //实际上不会执行
		return l1;
	}
  //相加并设置进位函数
	int isCarried(int val1, int val2, bool &carry){
		int newval = val1 + val2 + carry;
		carry = 0;
		if (newval >= 10){
			newval %= 10;
			carry = 1;
		}
		return newval;
	}
  //某个链表结束后，另一链表继续与进位相加
	void stop(ListNode *n, ListNode *temp, bool carry){
		while (n!=nullptr && carry){
			n->val = isCarried(0, n->val, carry);
			temp = n;
			n = n->next;
		}
		if (carry)
			temp->next = new ListNode(1);
	}
};
