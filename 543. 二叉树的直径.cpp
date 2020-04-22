class Solution {
public:
	int maxDeepth = 0;
	int diameterOfBinaryTree(TreeNode* root) {
		recurse(root);
		return maxDeepth;
	}

	int recurse(TreeNode *node) {
		if (!node)
			return 0;
		int left = recurse(node->left);
		int right = recurse(node->right);
		maxDeepth = max(maxDeepth, right + left);
		return max(right, left) + 1;
	}
};
