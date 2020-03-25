/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode *low=head,*fast=head;
        while(fast->next && fast->next->next)
        {
            fast=fast->next->next;
            low=low->next;
            if(low==fast)
                return true;
        }
        return false;
    }
};
