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
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode *forward = head , *backward = head;   
        while(1)
        {
            if(!backward || !backward->next)
                return NULL;
            backward = backward->next->next;
            forward = forward->next;
            if(backward == forward)
                break;
        }
        //计算环入口节点
        backward = head;
        while(backward != forward)
        {
            backward = backward->next;
            forward = forward->next;
        }
        return forward;
    }
};
