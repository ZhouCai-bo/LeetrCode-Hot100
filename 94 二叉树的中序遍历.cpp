class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode *> st;
		vector<int> res;
		TreeNode *curr = root;
		while (!st.empty() || curr)
		{
			while (curr)
			{
				st.push(curr);
				curr = curr->left;
			}
			curr = st.top();
			st.pop();
			res.push_back(curr->val);
			curr = curr->right;
		}
		return res;
	}
};
