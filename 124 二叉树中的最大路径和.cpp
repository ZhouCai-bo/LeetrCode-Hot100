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
	int max_path = INT_MIN;
	int maxPathSum(TreeNode* root) {
		recurse(root);
		return max_path;
	}
	int recurse(TreeNode *node)
	{
		if (!node)
			return 0;
		int left_path = recurse(node->left);
		int right_path = recurse(node->right);
		int tri_path = node->val;
		if (!(left_path <= 0 && right_path <= 0))
		{
			tri_path += left_path > 0 ? left_path : 0;
			tri_path += right_path > 0 ? right_path : 0;
			max_path = max(max_path, tri_path);
			return max(right_path, left_path) + node->val;
		}
        max_path = max(max_path, tri_path);
		return node->val;
	}
};
