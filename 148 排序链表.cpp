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
    ListNode* sortList(ListNode* head) 
    {
        ListNode *begin = head;
        ListNode *curr , *temp;
        int min = 0;
        while(begin && begin->next)
        {
            curr = begin;
            temp = begin;
            min = curr->val;
            while(curr && (curr=curr->next))
            {
                if(curr->val < min)
                {
                    temp = curr;
                    min = curr->val;
                }
            }
            temp->val = begin->val;
            begin->val = min;
            begin = begin->next;
        }
        return head;
    }
};
