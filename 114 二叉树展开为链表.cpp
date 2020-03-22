class Solution {
public:
	void flatten(TreeNode* root) {
		TreeNode *curr = root;
		while (curr != nullptr)
		{
			if (curr->left)
			{
				TreeNode *most_right = curr->left;
				while (most_right->right)
					most_right = most_right->right;
				most_right->right = curr->right;
				curr->right = curr->left;
				curr->left = nullptr;
			}
			curr = curr->right;
		}
	}
};
