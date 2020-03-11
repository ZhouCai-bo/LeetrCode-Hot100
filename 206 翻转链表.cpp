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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode *nhead = head , *temp1 = nhead->next , *temp2 = temp1->next;

        nhead->next = nullptr;
        while(temp2)
        {
            temp1->next = nhead;
            nhead = temp1;
            temp1 = temp2;
            temp2 = temp2->next;
        }
        temp1->next = nhead;
        nhead = temp1;

        return nhead;
    }
};
