class Codec {
	public:
		// Encodes a tree to a single string.
		string serialize(TreeNode* root) {
			if (!root)
				return "";
			stringstream ss;
			queue<TreeNode *> q;  
			TreeNode *temp = root;
			q.push(temp);
			ss << temp->val << " ";
			while (!q.empty()){
				temp = q.front();
				q.pop();
				if (!temp->left) ss << "n ";
				else
				{
					ss << temp->left->val << " ";
					q.push(temp->left);
				}
				if (!temp->right) ss <<  "n ";
				else
				{
					ss << temp->right->val << " ";
					q.push(temp->right);
				}
			}
			return ss.str();
		}

		// Decodes your encoded data to tree.
		TreeNode* deserialize(string data) {
			if (data == "")
				return nullptr;
			stringstream ss(data);
			string ts;
			queue<TreeNode *> q;
			ss >> ts;
			TreeNode *root = new TreeNode(stoi(ts));
			q.push(root);
			TreeNode *temp;
			while (!q.empty()){
				temp = q.front();
				q.pop();

				ss >> ts;
				if (ts != "n"){
					temp->left = new TreeNode(stoi(ts));
					q.push(temp->left);
				}
				ss >> ts;
				if (ts != "n"){
					temp->right = new TreeNode(stoi(ts));
					q.push(temp->right);
				}
			}
			return root;
		}
	};
