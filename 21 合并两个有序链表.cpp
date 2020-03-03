class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *dhead = new ListNode(0);
		ListNode *curr = dhead;
		while (l1!=nullptr || l2!=nullptr){
            if(l2==nullptr || (l1!=nullptr && l1->val<l2->val)){
                curr->next=l1;
                l1=l1->next;
            }
            else{
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
		}
		return dhead->next;
    }
};
