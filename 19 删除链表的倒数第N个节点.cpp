class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		vector<ListNode *> list;
		ListNode *curr = head;
		while (curr != nullptr){
			list.push_back(curr);
			curr = curr->next;
		}
		int size = list.size();
        if(size==0)
            return nullptr;
        if(size==1)
            return nullptr;
        else if(n==1)
            list[size - n - 1]->next = nullptr;
        else if(n==size)
            head = head->next;
        else
            list[size - n - 1]->next = list[size - n + 1];
		return head;
	}
};
