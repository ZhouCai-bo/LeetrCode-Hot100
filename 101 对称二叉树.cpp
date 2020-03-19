class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		string str;
		queue<TreeNode *> q;
		q.push(root);
		int size, next_size = root?1:0;
		while (next_size != 0){
			size = next_size;
			next_size = 0;
			str = "";
			for (int i = 0; i < size; i++){
				auto temp = q.front();
				q.pop();
				if (!temp->left)
					str += '#';
				else{
					str += temp->left->val + '0';
					q.push(temp->left);
					next_size++;
				}
				if (!temp->right)
					str += '#';
				else
				{
					str += temp->right->val + '0';
					q.push(temp->right);
					next_size++;
				}
			}
			if (!check(str))
				return false;
		}
		return true;
	}
	bool check(string &str){
		int left = 0, right = str.size() - 1;
		while (left < right){
			if (str[left] != str[right])
				return false;
			left++;
			right--;
		}
        return true;
	}
};
