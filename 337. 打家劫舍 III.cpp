/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int rob(TreeNode* root) {
		auto res = recurse(root);
		return max(res.first, res.second);
	}
	pair<int, int> recurse(TreeNode *node)
	{
		if (!node)
			return make_pair(0, 0);
		auto left = recurse(node->left);
		auto right = recurse(node->right);
		int get = node->val + left.second + right.second;
		int ban = max(left.first, left.second) + max(right.first, right.second);
		return make_pair(get, ban);
	}
};
