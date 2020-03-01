class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *dhead = new ListNode(0);
		dhead->next = head;
		ListNode *fast, *slow;
		fast = slow = dhead;
		int ct = 0;
		while (fast->next != nullptr)
		{
			fast = fast->next;
			if (ct == n)
				slow = slow->next;
			else
				ct++;
		}
		slow->next = slow->next->next;
		return dhead->next;
	}
};
