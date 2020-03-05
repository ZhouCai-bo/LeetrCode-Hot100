class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		ListNode *hA = headA;
		ListNode *hB = headB;
		stack<ListNode*> liststack1;
		stack<ListNode*> liststack2;
		if (!headA || !headB)
			return nullptr;
		while (hA)
		{
			liststack1.push(hA);
			hA = hA->next;
		}
		while (hB)
		{
			liststack2.push(hB);
			hB = hB->next;
		}
		/*while (!liststack1.empty())
		{
			cout << liststack1.top()->val<<"xxxx";
			liststack1.pop();
		}*/
		//cout << liststack1.size() << liststack2.size() << endl;
		if (liststack1.top() != liststack2.top())
			return nullptr;
		if (liststack1.size() == 1 && liststack2.size() == 1)
		{
			return liststack1.top();
		}
		ListNode *prev1 = nullptr;
		ListNode *prev2 = nullptr;
		ListNode *temp = liststack1.top();
		liststack1.pop();
		liststack2.pop();
		while (!liststack1.empty() && !liststack2.empty())
		{
			prev1 = liststack1.top();
			prev2 = liststack2.top();
			//cout << prev1 << "xxxx" << prev2 <<endl;
			if (liststack1.top() == liststack2.top())
			{
				temp = liststack1.top();
				liststack1.pop();
				liststack2.pop();
				
				continue;
			}

			else
				return temp;
		}
		return liststack1.empty() ? prev1 : prev2;
	}
};
