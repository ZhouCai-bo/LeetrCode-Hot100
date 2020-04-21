class Solution {
public:
	TreeNode* convertBST(TreeNode* root) {
		int curr = 0;
		recurse(root, curr);
		return root;
	}

	void recurse(TreeNode *node, int &curr)
	{
		if (!node)
			return;
		recurse(node->right, curr);
		node->val += curr;
		curr = node->val;
		recurse(node->left, curr);
	}	
};
