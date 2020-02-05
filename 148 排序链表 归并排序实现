class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        return mergeSort(head);
    }

    ListNode* mergeSort(ListNode* head)
    {
        if(!head || !head->next)
            return head;
        //快慢指针分割链表
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *mid = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            //mid指向slow的前一个位置，将来设置其下一节点为null
            mid = slow;
            slow = slow->next;
            
        }
        mid->next = nullptr;
        ListNode *L1 = mergeSort(head);
        ListNode *L2 = mergeSort(slow);
        return merge(L1,L2);
    }
    ListNode* merge(ListNode *L1 , ListNode *L2)
    {
        if(!L1)
            return L2;
        if(!L2)
            return L1;
        if(L1->val < L2->val)
        {
            L1->next = merge(L1->next , L2);
            return L1;
        }
        else
        {
            L2->next = merge(L2->next , L1);
            return L2;
        }     
    }
};
