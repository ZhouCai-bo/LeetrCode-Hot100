class Solution {
public:
	int sum;
	int pathSum(TreeNode* root, int sum) {
		this->sum = sum;
        map<int,int> prefix;
        prefix[0] = 1;
		return recurse(root, prefix, 0);
	}
	int recurse(TreeNode *node, map<int,int> &prefix, int temp)
	{
		if(!node)
            return 0;
        temp += node->val;
        int ans = prefix[temp - sum];
        prefix[temp]++;
        ans += recurse(node->left, prefix, temp) + recurse(node->right, prefix, temp);
        prefix[temp]--;
        return ans;
	}
};
