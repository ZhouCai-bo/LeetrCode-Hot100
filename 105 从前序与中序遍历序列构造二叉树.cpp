class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		stack<TreeNode *> st;
		set<int> used;
		TreeNode *curr;
		if (preorder.size() == 0)
			return nullptr;
		TreeNode *root = new TreeNode(preorder[0]);
		used.insert(root->val);
		curr = root;
		//int child_val = next(preorder);
		int next=1;
		//while (child_val != INT_MAX)
		while (next<preorder.size())
		{
			int child_val=preorder[next];
			int child_pos = find(inorder, curr->val, child_val, used);
			if (child_pos == 0)
			{
				curr = st.top();
				st.pop();
				continue;
			}
			if (child_pos == -1)
			{
				curr->left = new TreeNode{ child_val };
				st.push(curr);
				curr = curr->left;
			}
			else if (child_pos == 1)
			{
				curr->right = new TreeNode{ child_val };
				st.push(curr);
				curr = curr->right;
			}
			++next;
			//child_val = next(preorder);
		}
		return root;
	}

	int find(vector<int>& inorder, int curr_val, int target, set<int> &used)
	{
		int curr_pos, target_pos;
		for (int i = 0; i<inorder.size(); i++)
		{
			if (inorder[i] == curr_val)
				curr_pos = i;
			if (inorder[i] == target)
				target_pos = i;
		}
		if ((curr_pos - 1<0 || used.find(inorder[curr_pos - 1]) != used.end())
			&& (curr_pos + 1 >= inorder.size() || used.find(inorder[curr_pos + 1]) != used.end()))
			return 0;
		used.insert(inorder[target_pos]);
		return curr_pos>target_pos ? -1 : 1;
	}
	/*int next(vector<int>& preorder)
	{
		int i = 1, child_val = INT_MAX;
		while (i<preorder.size())
		{
			if (preorder[i] != preorder[0])
			{
				child_val = preorder[i];
				preorder[i] = preorder[0];
				break;
			}
			++i;
		}
		return child_val;
	}*/
};
