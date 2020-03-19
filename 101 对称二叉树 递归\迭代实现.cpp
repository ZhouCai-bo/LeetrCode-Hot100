//迭代
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		queue<TreeNode *> q;
		q.push(root);
		q.push(root);
		while (!q.empty())
		{
			auto t1 = q.front(); q.pop();
			auto t2 = q.front(); q.pop();
			if (!t1 && !t2)
				continue;
			if (!t1 || !t2)
				return false;
			if (t1->val != t2->val)
				return false;

			q.push(t1->left);
			q.push(t2->right);
			q.push(t1->right);
			q.push(t2->left);
		}
		return true;
	}
};

//递归
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		return reverseCheck(root, root);
	}

	bool reverseCheck(TreeNode *t1, TreeNode *t2)
	{
		if (!t1 && !t2)
			return true;
		if (!t1 || !t2)
			return false;
		if (t1->val != t2->val)
			return false;
		return reverseCheck(t1->left, t2->right) && reverseCheck(t1->right, t2->left);
	}
};
