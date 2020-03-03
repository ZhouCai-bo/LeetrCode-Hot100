class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return nullptr;
		ListNode *dhead = new ListNode(0);
		ListNode *nextNode, *curr = dhead;
		while (nextNode = getMin(lists)){
			curr->next = nextNode;
			curr = curr->next;
		}
		return dhead->next;
	}
	ListNode * getMin(vector<ListNode*>& lists){
		int min = INT_MAX, index = 0;
		ListNode *temp = nullptr;
		for (int i = 0; i<lists.size(); i++){
			if (lists[i] == nullptr)
				continue;
			if (min > lists[i]->val){
				index = i;
				temp = lists[i];
				min = lists[i]->val;
			}
		}
		if (lists[index]!=nullptr)
			lists[index] = lists[index]->next;
		return temp;
	}
};
